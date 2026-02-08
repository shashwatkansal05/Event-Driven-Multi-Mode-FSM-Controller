#include <stdio.h>
#include "led_sim.h"

static int led_state = 0;

void led_on(void) {
    led_state = 1;
    printf("LED ON\n");
}

void led_off(void) {
    led_state = 0;
    printf("LED OFF\n");
}

void led_toggle(void) {
    led_state = !led_state;
    printf("LED TOGGLE -> %s\n", led_state ? "ON" : "OFF");
}
