#include "timer_sim.h"

static int counter = 0;
static int timeout = 0;

void timer_set(int time) {
    timeout = time;
    counter = 0;
}

void timer_tick(void) {
    counter++;
}

int timer_expired(void) {
    if (counter >= timeout && timeout != 0) {
        counter = 0;
        return 1;
    }
    return 0;
}
