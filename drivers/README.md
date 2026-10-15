# Puzhong-A2 Drivers

A collection of reusable C drivers for the **Puzhong-A2 development board**, based on the STC89C52 (8051) microcontroller.

These drivers provide basic hardware control and timing functions. Each driver is organized into separate `.c` and `.h` files for easier reuse and maintenance.

The project uses a shared system timer and centralized scheduling to manage multiple drivers without blocking the main loop.

## Drivers

### Timer

The timer driver provides a system-wide time reference with a resolution of **1 millisecond (ms)**.

- `timer_init()` — Initializes Timer0 and starts the system timer.
- `timer_get()` — Returns the elapsed time in milliseconds since the timer started.

The minimum time unit supported by the system is **1 ms**.

### Button

The button driver provides input detection for the four buttons on the Puzhong-A2 development board.

- `button_read(Button button)` — Reads the current button state.
- `button_get(Button button)` — Gets the button state.

Both functions accept `BUTTON1`, `BUTTON2`, `BUTTON3`, or `BUTTON4` as an argument.

**Return values:**
- `1` — Button is pressed.
- `0` — Button is not pressed.

### Buzzer

The buzzer driver provides non-blocking sound playback for the passive buzzer on the Puzhong-A2 development board.

- `buzzer_play(unsigned int frequency, unsigned int duration_time)` — Starts playing a sound.
  - `frequency` — Sound frequency in hertz (Hz).
  - `duration_time` — Playback duration in milliseconds (ms).
- `buzzer_update(unsigned long interval)` — Updates the buzzer state and controls sound playback.
  - `interval` — Actual elapsed time in milliseconds (ms) since the previous update.

Call `buzzer_update()` periodically from the main loop or a centralized scheduler to maintain playback without blocking other tasks.

## Number Driver

An 8-digit seven-segment display driver for the STC89C52 microcontroller.

### Functions

**`number_set(unsigned char pos, unsigned char num)`**

Sets the number displayed at a specified position.

- `pos`: Display position (`0–7`).
- `num`: Number to display (`0–9`), or `10` for a blank display.
- Call this function whenever you want to change a displayed number.

**`number_setdot(unsigned char pos)`**

Turns on the decimal point at a specified position.

- `pos`: Display position (`0–7`).

**`number_cleardot(unsigned char pos)`**

Turns off the decimal point at a specified position.

- `pos`: Display position (`0–7`).

**`number_update(void)`**

Updates the display by scanning one digit per call.

- Parameters: None.
- Must be called repeatedly, preferably from a timer interrupt at a fixed interval.
- Does not need to be called manually after every `number_set()` operation.

### Usage

```c
number_set(0, 5);       // Display 5 at position 0
number_set(1, 8);       // Display 8 at position 1
number_setdot(0);       // Turn on decimal point at position 0
number_cleardot(0);     // Turn off decimal point at position 0
number_set(1, 10);      // Clear position 1
```

**Important:** Use `number_set()` whenever the displayed number needs to change. Call `number_update()` continuously through a periodic timer interrupt to maintain the display.

# Matrix Keypad Driver

A 4×4 matrix keypad driver for the 8051 microcontroller.

## Usage

```c
unsigned char keypad_get(void);
```

Returns the ID of the pressed key.

**Return value:**
- `0`: No key is pressed.
- `1–16`: ID of the pressed key.

**Note:** The function waits until the key is released before returning its ID. This function is blocking.

# 8×8 LED Matrix Driver

A simple 8×8 LED matrix driver for the 8051 microcontroller using the 74HC595 shift register.

## Functions

### `display_set(unsigned char col, unsigned char row)`

Turns on a specified pixel.

- `col`: Column index (0–7).
- `row`: Row index (0–7).

### `display_clear(void)`

Clears all pixels in the display buffer.

### `display_update(void)`

Scans one row of the LED matrix per call.

Should be called approximately every 1 ms to maintain a stable display.

## Example

```c
#include "display.h"

void main(void)
{
    display_clear();
    display_set(2, 3);
    display_set(3, 3);

    while (1)
    {
        if (tick - last_update >= 1)
        {
            last_update = tick;
            display_update();
        }
    }
}
```

*Assumes `tick` is updated every 1 ms by the timer module and `last_update` is initialized to 0. The example omits timer setup and shared-counter synchronization.*

## Notes

- Coordinates range from 0 to 7.
- Display data is stored in an 8-byte array.
- `display_set()` and `display_clear()` modify the buffer.
- `display_update()` updates the hardware one row at a time.