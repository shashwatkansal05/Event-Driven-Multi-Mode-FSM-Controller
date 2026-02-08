#include "command_fsm.h"

event_t command_fsm_handle(event_t uart_event) {
    /* In this simple project, UART events
       are directly forwarded */
    return uart_event;
}
