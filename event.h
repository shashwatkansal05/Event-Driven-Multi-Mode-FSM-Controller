#ifndef EVENT_H
#define EVENT_H

typedef enum {
    EVENT_NONE = 0,
    EVENT_CMD_ON,
    EVENT_CMD_OFF,
    EVENT_CMD_BLINK_SLOW,
    EVENT_CMD_BLINK_FAST,
    EVENT_TIMEOUT
} event_t;

#endif
