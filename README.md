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


## Led & Resistor
In order to protect leds it is required to use resistor to lower current that the led get from the power source.
Depending on the led color and the led specification you need to adjust the resistor value.

We recommand using for 5V with 20mA the following resistor to protect your leds :
- Red : 220 Ohm
- Orange : 220 Ohm
- Green : 180 Ohm
- Blue : 120 Ohm
- White : 120 Ohm

On Arduino we can use PWM pin instead of resistor to lower current that led received to protect them.

On the following diagram led marked with '*' are placed on PWM pin and code use this feature.

Please check the forward voltage of the led you are using to adjust the resistor value or pwm value.

PWM Value of AUX pin can be set using the serial Monitor. It allows to choose the output voltage delivered by the Arduino Pin. 
You can find more information on the Manual


# Board Extensibility

![Alt text](./LightMagicBoardWiringWithI2C_bb.png?raw=true "Ecto-1 Light and Magic Board Extensibility Wiring")
