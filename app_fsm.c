#include "app_fsm.h"
#include "led_sim.h"
#include "timer_sim.h"
#include "config.h"

typedef enum {
    STATE_OFF,
    STATE_ON,
    STATE_BLINK_SLOW,
    STATE_BLINK_FAST
} app_state_t;

static app_state_t current_state;

void app_fsm_init(void) {
    current_state = STATE_OFF;
    led_off();
}

void app_fsm_handle(event_t event) {

    switch (current_state) {

    case STATE_OFF:
        if (event == EVENT_CMD_ON) {
            led_on();
            current_state = STATE_ON;
        }
        break;

    case STATE_ON:
        if (event == EVENT_CMD_OFF) {
            led_off();
            current_state = STATE_OFF;
        } else if (event == EVENT_CMD_BLINK_SLOW) {
            timer_set(BLINK_SLOW_TIME);
            current_state = STATE_BLINK_SLOW;
        } else if (event == EVENT_CMD_BLINK_FAST) {
            timer_set(BLINK_FAST_TIME);
            current_state = STATE_BLINK_FAST;
        }
        break;

    case STATE_BLINK_SLOW:
        if (event == EVENT_TIMEOUT) {
            led_toggle();
        } else if (event == EVENT_CMD_OFF) {
            led_off();
            current_state = STATE_OFF;
        }
        break;

    case STATE_BLINK_FAST:
        if (event == EVENT_TIMEOUT) {
            led_toggle();
        } else if (event == EVENT_CMD_OFF) {
            led_off();
            current_state = STATE_OFF;
        }
        break;
    }
}
