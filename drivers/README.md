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