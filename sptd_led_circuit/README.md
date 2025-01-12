# SPTD Switch LED Circuit

I do not own this circuit, it was created and published by [hackster.io](https://www.hackster.io/Ayeon0122/reading-a-spdt-switch-c43547), to whom all rights belong.

- [SPTD Switch LED Circuit](#sptd-switch-led-circuit)
  - [The Circuit](#the-circuit)
    - [Components](#components)
    - [Circuit](#circuit)
      - [SPTD Switch](#sptd-switch)
      - [LED1](#led1)
      - [LED2](#led2)
  - [The Code](#the-code)
  - [Theory](#theory)

<div style="display: grid; grid-template-columns: repeat(2, 1fr); gap: 10px;">
    <img src='./IMG_9729.png' width='25%'/>
    <img src='./IMG_9730.png' width='25%'/>
    <img src='./IMG_9731.png' width='25%'/>
    <img src='./IMG_9732.png' width='25%'/>
</div>

## The Circuit

### Components

- Solderless Breadboard x1
- LEDs x2
- Resistors (220 ohms) x2
- Hookup Wires x8
- SPTD Switch x1
- Arduino Uno x1
- USB Connector x1

Remember to install Arduino IDE

### Circuit

Remember, power given to the positive rail on a breadboard means the power becomes accessible at any input along it's path. This is the same for the negative rail, which must be connected to the GND of the Arduino to complete the circuit.

-> Can mean either wire or pin connection

Arduino Power:
3.3v -> RH (right-hand, 2) +Rail2
GND -> RH '-Rail2'

Positive Rail2: Receives Power from Arduino
Out -> J15

'-Rail1' -> '-Rail2'

Circuit Matrix:

#### SPTD Switch

F: 15, 16, 17 -> SPTD Switch
H: 16 -> Arduino: Digital: -3
J: 15 -> +Rail2
J: 17 -> -Rail2

#### LED1

'-Rail1' -> +LED1
A: 30 -> -LED1
E: 30 -> R220
F: 30 -> R220
J: 30 -> Arduino: Digital: 13

#### LED2

'-Rail1' -> +LED1
A: 40 -> -LED1
E: 40 -> R220
F: 40 -> R220
J: 40 -> Arduino: Digital: 12

## The Code

[Setup Constant Variables]('./sptd_led_circuit.ino#L18')

[Set INPUTS & OUTPUTS]('./sptd_led_circuit.ino#L26')

[Create empty variable]('./sptd_led_circuit.ino#L37')

[Store switch variable value]('./sptd_led_circuit.ino#L43')

[If-Else statement that reads whether switch value is HIGH (3.3v)]('./sptd_led_circuit.ino#L46')

## Theory
