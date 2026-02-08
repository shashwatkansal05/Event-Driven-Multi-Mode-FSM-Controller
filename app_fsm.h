#ifndef APP_FSM_H
#define APP_FSM_H

#include "event.h"

void app_fsm_init(void);
void app_fsm_handle(event_t event);

#endif
