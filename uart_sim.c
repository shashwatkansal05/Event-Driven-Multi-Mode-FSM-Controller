#include <stdio.h>
#include <string.h>
#include "uart_sim.h"

event_t uart_get_event(void) {
    char cmd[20];

    printf("\nEnter command: ");
    scanf("%s", cmd);

    if (strcmp(cmd, "ON") == 0) return EVENT_CMD_ON;
    if (strcmp(cmd, "OFF") == 0) return EVENT_CMD_OFF;
    if (strcmp(cmd, "BLINK_SLOW") == 0) return EVENT_CMD_BLINK_SLOW;
    if (strcmp(cmd, "BLINK_FAST") == 0) return EVENT_CMD_BLINK_FAST;

    return EVENT_NONE;
}
