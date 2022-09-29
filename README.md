# Arduino MCP4922

Use an Arduino Uno (or other compatible microcontroller board) to set the output voltage of a dual-channel DAC (MCP4922). This project uses PlatformIO to compile and flash the MCU. Refer to the MCP4922 datasheet (PDF included in repository) for more information as well as the pinout reference.

## Flashing the MCU

1. Clone this repository:

```bash
git clone git@github.com:lukasvasadi/arduino-dac.git
```

2. Install the PlatformIO extension through the VS Code extensions manager and open the project directory in VS Code. PlatformIO will automatically prepare the development environment.

3. With the Arduino connected to the host computer, compile and flash the source code. Note that if using a different MCU supported by PlatformIO, the `platformio.ini` file will have to be modified to reflect the correct target.
