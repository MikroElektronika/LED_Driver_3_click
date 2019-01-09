![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# LED_Driver3 Click

- **CIC Prefix**  : LEDDRIVER3
- **mikroSDK**    : YES
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : Jan 2018.

---

### Software Support

We provide a library for the LED_Driver3 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2301/led-driver-3-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Library carries functions necessary to have complete control over all functionalities of the click board.

Key functions :

- ``` void leddriver3_setIntensity(uint8_t intensity) ``` - Set intensity of LED light
- ``` void leddriver3_setRGB_Color(uint8_t red, uint8_t green, uint8_t blue) ``` - Set color in RGB format
- ``` void leddriver3_setColor(uint32_t color) ``` - Set color using one of predefined values

**Examples Description**

The demo application is composed of three sections :

- System Initialization - Initializes I2C module used for LED Driver 3 click.
- Application Initialization - Driver initialization
- Application Task - (code snippet) - Sequentialy changes intensity and color of the LED light with delays
of one second between each operation.


```.c
void applicationTask()
{
    leddriver3_setIntensity(_LEDDRIVER3_INCREMENT | _LEDDRIVER3_INTENSITY_8);
    leddriver3_setTimer(_LEDDRIVER3_TIMER_8ms | _LEDDRIVER3_TIMER_16ms);        // 24 ms
    leddriver3_setColor(_LEDDRIVER3_COLOR_RED);
    Delay_1sec();
    
    leddriver3_setIntensity(_LEDDRIVER3_CONSTANT | _LEDDRIVER3_INTENSITY_16);
    leddriver3_setColor(_LEDDRIVER3_COLOR_YELLOW);
    Delay_1sec();
    leddriver3_setColor(_LEDDRIVER3_COLOR_BLUE);
    Delay_1sec();
    leddriver3_setRGB_Color(0x40, 0x7F, 0x80);
    Delay_1sec();
}
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2301/led-driver-3-click) page.

mikroE Libraries used in the example:

- I2C

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
