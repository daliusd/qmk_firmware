#include "flow.h"
#include <stdint.h>

extern const uint16_t flow_config[FLOW_COUNT][3];

// Represents the states a flow key can be in
typedef enum {
    flow_up_unqueued,
    flow_up_queued,
    flow_up_queued_used,
    flow_down_unused,
    flow_down_used,
} flow_state_t;

flow_state_t flow_state[FLOW_COUNT] = { [0 ... FLOW_COUNT - 1] = flow_up_unqueued };
bool flow_pressed[FLOW_COUNT][2] = { [0 ... FLOW_COUNT - 1] = {false, false} };
bool flow_timers_active[FLOW_COUNT] = { [0 ... FLOW_COUNT - 1] = false };
uint16_t flow_timers[FLOW_COUNT] = { [0 ... FLOW_COUNT - 1] = 0 };

bool is_flow_cancel_key(uint16_t keycode) {
    for (int i = 0; i < FLOW_COUNT; i++) {
        if (flow_config[i][0] == keycode) {
            return true;
        }
    }
    return false;
}

bool is_flow_ignored_key(uint16_t keycode) {
    for (int i = 0; i < FLOW_COUNT; i++) {
        if (flow_config[i][0] == keycode) {
            return true;
        }
    }

    // TODO: add all modifier keys here
    if (keycode == KC_LSFT || keycode == KC_RSFT) {
        return true;
    }

    return false;
}

bool update_flow(
    uint16_t keycode,
    bool pressed
) {
    bool pass = true;
    bool flow_key_list_triggered[FLOW_COUNT] = { [0 ... FLOW_COUNT - 1] = false };
    bool flow_key_list_pressed[FLOW_COUNT] = { [0 ... FLOW_COUNT - 1] = false };

    bool flow_triggered = false;
    bool flow_second_key_pressed = false;

    for (uint8_t i = 0; i < FLOW_COUNT; i++) {
        // Layer key
        if (keycode == flow_config[i][0]) {
            if (pressed) {
                flow_pressed[i][0] = true;
                if (flow_timers_active[i]) {
                    flow_timers_active[i] = false;
                    flow_pressed[i][1] = true; // keycode pressed
                    flow_triggered = true;
                    flow_key_list_pressed[i] = true;
                    flow_key_list_triggered[i] = true;
                }
            } else {
                flow_pressed[i][0] = false;
            }
            if (flow_pressed[i][1]) {
                flow_second_key_pressed = true;
            }
        // KC key
        } else if (keycode == flow_config[i][1]) {
            if (pressed) {
                flow_pressed[i][1] = true;
                if (flow_pressed[i][0]) {
                    flow_key_list_triggered[i] = true;
                    flow_triggered = true;
                    flow_key_list_pressed[i] = true;
                    pass = false;
                 } else {
                    flow_timers[i] = timer_read();
                    flow_timers_active[i] = true;
                    pass = false;
                 }
            } else {
                flow_pressed[i][1] = false;
                if (flow_pressed[i][0]) {
                    flow_key_list_triggered[i] = true;
                    flow_triggered = true;
                    pass = false;
                } else if ((flow_state[i] == flow_down_unused)
                        || (flow_state[i] == flow_down_used)) {
                    flow_key_list_triggered[i] = true;
                    flow_triggered = true;
                    pass = false;
                }
            }
        }
    }

    for (uint8_t i = 0; i < FLOW_COUNT; i++) {
        if (flow_key_list_triggered[i]) {
            if (flow_key_list_pressed[i]) {
                if (flow_state[i] == flow_up_unqueued) {
                    register_code(flow_config[i][2]);
                }
                flow_state[i] = flow_down_unused;
            } else {
                // Trigger keyup
                switch (flow_state[i]) {
                case flow_down_unused:
                    // If we didn't use the mod while trigger was held, queue it.
                    if (!flow_pressed[i][1]) {
                        flow_state[i] = flow_up_queued;
                    }
                    break;
                case flow_down_used:
                    // If we did use the mod while trigger was held, unregister it.
                    if (!flow_pressed[i][1]) {
                        flow_state[i] = flow_up_unqueued;
                        unregister_code(flow_config[i][2]);
                    }
                    break;
                default:
                    break;
                }
            }
        } else if (!flow_triggered) {
            if (pressed) {
                if (is_flow_cancel_key(keycode)
                        && flow_state[i] != flow_up_unqueued
                        && !flow_second_key_pressed) {
                    // Cancel oneshot on designated cancel keydown.
                    flow_state[i] = flow_up_unqueued;
                    unregister_code(flow_config[i][2]);
                }
                if (!is_flow_ignored_key(keycode)) {
                    switch (flow_state[i]) {
                    case flow_up_queued:
                        flow_state[i] = flow_up_queued_used;
                        break;
                    case flow_up_queued_used:
                        flow_state[i] = flow_up_unqueued;
                        unregister_code(flow_config[i][2]);
                        break;
                    default:
                        break;
                    }
                }
            } else {
                if (!is_flow_ignored_key(keycode)) {
                    // On non-ignored keyup, consider the oneshot used.
                    switch (flow_state[i]) {
                    case flow_down_unused:
                        flow_state[i] = flow_down_used;
                        break;
                    case flow_up_queued:
                        flow_state[i] = flow_up_unqueued;
                        unregister_code(flow_config[i][2]);
                        break;
                    case flow_up_queued_used:
                        flow_state[i] = flow_up_unqueued;
                        unregister_code(flow_config[i][2]);
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }

    return pass;
}

void flow_matrix_scan(void) {
    for (int i = 0; i < FLOW_COUNT; i++) {
        // TODO: replace 30 with a configurable value
        if (flow_timers_active[i] && timer_elapsed(flow_timers[i]) > 30) {
            flow_timers_active[i] = false;
            register_code(flow_config[i][1]);
        }
    }
}
