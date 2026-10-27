# Arduino Light & Temperature Monitor

An Arduino Uno project that reads a photoresistor and a thermistor and displays their analog readings on a 1602a 16×2 LCD.

## Features

- Reads light levels using a photoresistor (LDR).
- Reads temperature-related changes using a thermistor.
- Displays both readings on an LCD.
- Updates the display every 250 milliseconds.

## Hardware

- Arduino Uno
- 1602a 16×2 LCD
- Photoresistor (LDR)
- Thermistor
- Two 10 kΩ resistors for the thermistor circuit
- One 10 kΩ resistor for the photoresistor circuit
- Potentiometer for LCD contrast
- Breadboard and jumper wires

The two resistors in the thermistor circuit and the resistor in the photoresistor circuit gave better readings during experimentation.

## Wiring

### LCD Connections

| LCD Pin    | Arduino Uno              |
| ---------- | ------------------------ |
| RS         | D12                      |
| Enable (E) | D11                      |
| D4         | D5                       |
| D5         | D4                       |
| D6         | D3                       |
| D7         | D2                       |
| VSS        | GND                      |
| VDD        | 5V                       |
| VO         | Potentiometer middle pin |
| R/W        | GND                      |
| LED+ (A)   | 5V                       |
| LED− (K)   | GND                      |

Connect the potentiometer's two outer pins to 5V and GND, and its middle pin to LCD pin VO.

### Photoresistor Circuit

Connect the photoresistor and 10 kΩ resistor as a voltage divider:

```text
5V
 |
Photoresistor (LDR)
 |
 +------ A0
 |
10 kΩ resistor
 |
GND
```

### Thermistor Circuit

Connect the thermistor and two 10 kΩ resistors as follows:

```text
5V
 |
Thermistor
 |
 +------ A1
 |
10 kΩ resistor
 |
10 kΩ resistor
 |
GND
```

The two fixed resistors are connected in series.

## How It Works

The Arduino reads the analog values from A0 and A1.

- **Light:** The A0 reading is divided by 10 before being displayed.
- **Temperature:** The raw A1 reading is displayed directly.

Both readings update every 250 milliseconds.

**Note:** Neither reading uses a calibrated physical unit. The light reading is not in lux, and the temperature reading is not in degrees Celsius or Fahrenheit.

## Original Build Photo

The original setup is available in [`photo.jpg`](photo.jpg).

The photo shows the actual breadboard build, but the wiring is chaotic and does not clearly explain the circuit.

## Running the Project

1. Assemble the circuit using the wiring instructions above.
2. Open `sensors_and_LCD/sensors_and_LCD.ino` in the Arduino IDE.
3. Select **Arduino Uno** and the correct port.
4. Upload the sketch.
5. Adjust the LCD contrast potentiometer slowly until the text is clearly visible. If the screen lights up but the text is invisible or difficult to read, this is the first adjustment to try.
6. Observe the sensor readings on the LCD as the light and temperature conditions change.

## Software

The project uses the built-in Arduino `LiquidCrystal` library.
