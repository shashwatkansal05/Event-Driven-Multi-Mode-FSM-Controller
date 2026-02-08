#include "event.h"
#include "uart_sim.h"
#include "command_fsm.h"
#include "app_fsm.h"
#include "timer_sim.h"

int main(void) {

    event_t event;

    app_fsm_init();

    while (1) {

        /* Simulate timer tick */
        timer_tick();
        if (timer_expired()) {
            app_fsm_handle(EVENT_TIMEOUT);
        }

        /* Get UART command */
        event = uart_get_event();

        if (event != EVENT_NONE) {
            event = command_fsm_handle(event);
            app_fsm_handle(event);
        }
    }
}
