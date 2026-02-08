# Event-Driven Multi-Mode FSM Controller

## Overview
This project demonstrates an event-driven embedded system
architecture using multiple finite state machines (FSMs).
The system is software-simulated and does not use real hardware.

## Architecture
UART Input --> Command FSM --> Application FSM --> LED Output

Timer → TIMEOUT Event

Timer generates TIMEOUT events independently.

## Features
- Event-driven design (no delays)
- Multiple FSMs
- Clean separation of concerns
- Easy migration to real MCU

## Commands
- ON
- OFF
- BLINK_SLOW
- BLINK_FAST

## STATE TABLE
  | Current State | Event       | Action       | Next State |
| ------------- | ----------- | ------------ | ---------- |
| OFF           | SHORT_PRESS | LED ON       | ON         |
| OFF           | LONG_PRESS  | —            | OFF        |
| ON            | SHORT_PRESS | —            | BLINK_SLOW |
| ON            | LONG_PRESS  | LED OFF      | OFF        |
| BLINK_SLOW    | TIMEOUT     | LED_Toggle() | BLINK_SLOW |
| BLINK_SLOW    | SHORT_PRESS | —            | BLINK_FAST |
| BLINK_SLOW    | LONG_PRESS  | LED OFF      | OFF        |
| BLINK_FAST    | TIMEOUT     | LED_Toggle() | BLINK_FAST |
| BLINK_FAST    | SHORT_PRESS | —            | ON         |
| BLINK_FAST    | LONG_PRESS  | LED OFF      | OFF        |


## Learning Outcome
This project focuses on embedded system logic,
FSM design, and architecture rather than low-level drivers.
