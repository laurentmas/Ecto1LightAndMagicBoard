# Ecto1LightAndMagicBoard

This is the repository of GhostBusters Ecto-1 Light & Magic Board.

Those sample code are shared to help you to implement additional extensibility for your Ecto-1 Model.

They have been developped to work with our Light & Magic Board.

Light & Magic Board instruction Manual is available on this link : 

More information on Light & Magic Board can be found here : 

Light & Magic Board in Action video : 

Instruction to upload code into Arduino can be found there : https://www.arduino.cc/en/Guide/Environment#uploading

Instruction to install Arduino library can be found there (We recommand using library manager): https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries

Useful link that helps troubleshooting arduino issue : https://www.instructables.com/5-Most-Common-Arduino-Nano-Clone-Problems-and-Thei/

## Arduino UI Configuration
Serial Monitor configuration must be set to 115200 baud to be able to see debug logs on the UI.

## Light & Magic board and Extensibility Arduino Power Wiring
Do not forget to power both Light & Magic board and Extensibility Arduino as specified in the following schema.

If you forget to power Light & Magic board or extensibility ardunio then you may have issue with IC2 Communication.

## I2C Communication Infos

The Slave Arduino will communicate with Primary Arduino on I2C Channel.
The Slave must be configured to listen on Port Id 24 in decimal [0x18 in hexadecimal]

The Master action will be sent in pair of 2 bytes. 
- First byte is the command Id (from 1 to 20, and 215 to 217).
- Second byte is the Action. 0 or 1 for OFF/ON, or a value (for music track Id, Volume Level, Oscilloscope Id).


Here the information on the Command Id :
 - 1  : ALL OFF
 - 2  : Demo Mode ON/OFF
 - 2' : Oscilloscope Sequence [1-8]
 - 3  : Strobe Lights ON/OFF
 - 4  : Projector Light ON/OFF
 - 5  : Fog Lights ON/OFF
 - 6  : Dashboard & Main Lights ON/OFF
 - 7  : Roof Top Lights ON/OFF
 - 8  : Brake Light ON/OFF 
 - 9  : Vol - [0-30]
 - 10 : Vol + [0-30]
 - 11 : ALL OFF
 - 12 : Hazard Lights ON/OFF
 - 13 : Left Turn Light ON/OFF
 - 14 : Right Turn ON/OFF
 - 15 : Klaxon Sound ON/OFF
 - 16 : Engine Sound ON/OFF
 - 17 : Siren Sound ON/OFF
 - 18 : AUX1 ON/OFF
 - 19 : Music ON / Next / OFF
 - 20 : Strobe Lights ON/OFF
 - 20': Demo Mode ON/OFF

## Led & Resistor
In order to protect leds it is required to use resistor to lower current that the led get from the power source.
Depending on the led color and the led specification you need to adjust the resistor value.

We recommand using for 5V with 20mA the following resistor to protect your leds :
- Red : 220 Ohm
- Orange : 220 Ohm
- Green : 180 Ohm
- Blue : 120 Ohm
- White : 120 Ohm

On Arduino we can use PWM pin with a small resistor to lower the current that led received to dim them.

On the following diagram led marked with '*' are placed on PWM pin and code use this feature.

Please check the forward voltage of the led you are using to adjust the resistor value or pwm value.

# Board Extensibility

![Alt text](./LightMagicBoardWiringWithI2C_bb.png?raw=true "Ecto-1 Light and Magic Board Extensibility Wiring")
