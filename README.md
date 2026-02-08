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
ON
OFF
BLINK_SLOW
BLINK_FAST

## Learning Outcome
This project focuses on embedded system logic,
FSM design, and architecture rather than low-level drivers.
