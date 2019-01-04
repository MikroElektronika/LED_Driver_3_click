/*
Example for LED_Driver3 Click

    Date          : Jan 2018.
    Author        : MikroE Team

Test configuration FT90x :
    
    MCU                : FT900
    Dev. Board         : EasyFT90x v7 
    FT90x Compiler ver : v2.2.1.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes I2C module
- Application Initialization - Driver initialize
- Application Task - (code snippet) - Changes color and intensity of light

*/

#include "Click_LED_Driver3_types.h"
#include "Click_LED_Driver3_config.h"

void systemInit()
{
    mikrobus_i2cInit( _MIKROBUS1, &_LEDDRIVER3_I2C_CFG[0] );
    Delay_ms( 100 );
}

void applicationInit()
{
    leddriver3_i2cDriverInit( (T_LEDDRIVER3_P)&_MIKROBUS1_GPIO, (T_LEDDRIVER3_P)&_MIKROBUS1_I2C, 0x38 );
}

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

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
    	applicationTask();
    }
}
