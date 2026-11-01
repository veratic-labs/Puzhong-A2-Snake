# Puzhong A2 — 8051 Microcontroller Project

A collection of reusable hardware drivers and a Snake game developed for the **Puzhong A2 development board**, based on the 8051 microcontroller.

The main focus of this project is developing reliable hardware drivers and understanding how microcontrollers interact with physical components, particularly the importance of timing and signal stability.

## Project Structure

```text
├── drivers/      # Reusable hardware drivers
└── game/         # Snake game implementation
```

## Drivers

The `drivers/` directory contains drivers for the following hardware components:

- **Buttons** — Independent button input detection and debouncing.
- **Matrix Keypad** — 4×4 matrix keypad scanning.
- **LED Matrix** — 8×8 LED matrix display control.
- **Timer** — Timer-based timekeeping and scheduling.
- **7-Segment Display** — Multiplexed numerical display.
- **Buzzer** — Sound generation and frequency control.

These drivers can be reused to develop new applications on the Puzhong A2 development board or on compatible hardware with equivalent circuit connections.

**Note:** The 7-segment display and LED matrix cannot be used simultaneously due to shared hardware connections.

## Snake Game

The `game/` directory contains a Snake game implemented using the hardware drivers.

The game includes:

- Snake head movement and direction control.
- Snake body movement and growth.
- Food generation and collision detection.

The game demonstrates how individual hardware drivers can be integrated into a complete embedded application.

## Development Experience

The most important part of this project was developing and testing the hardware drivers.

Unlike software that operates entirely within a computer, embedded systems must interact directly with physical hardware. This requires careful consideration of **timing, signal stability, and hardware behaviour**.

Several components made these challenges particularly clear:

- **Buttons:** Mechanical contact bouncing requires debouncing to ensure reliable input detection.
- **LED Matrix:** Multiplexed scanning requires consistent timing and sufficient refresh frequency to maintain a stable display.
- **Buzzer:** Sound generation depends on precise timing to control frequency and duration.

Through this project, I gained a better understanding of how software timing affects physical outputs and why reliable hardware interaction is an essential part of embedded systems development.

## Hardware Compatibility

The drivers are designed for the **Puzhong A2 development board**.

Developers using this board, or hardware with equivalent circuit designs and pin connections, can use the drivers as a starting point for their own embedded applications.

Hardware-specific configurations may need to be adjusted when using different boards or clock frequencies.

For circuit schematics and board specifications, please refer to the manufacturer's documentation.