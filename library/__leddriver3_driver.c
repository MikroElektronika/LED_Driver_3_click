/*
    __leddriver3_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__leddriver3_driver.h"
#include "__leddriver3_hal.c"

/* ------------------------------------------------------------------- MACROS */
// COLOR SET
const uint32_t _LEDDRIVER3_COLOR_RED    = 0x5F6080;
const uint32_t _LEDDRIVER3_COLOR_ORANGE = 0x5F6280;
const uint32_t _LEDDRIVER3_COLOR_YELLOW = 0x5F7480;
const uint32_t _LEDDRIVER3_COLOR_GREEN  = 0x407F80;
const uint32_t _LEDDRIVER3_COLOR_BLUE   = 0x40609F;
const uint32_t _LEDDRIVER3_COLOR_WHITE  = 0x5F7F9F;
const uint32_t _LEDDRIVER3_COLOR_PURPLE = 0x58609C;
const uint32_t _LEDDRIVER3_COLOR_OFF = 0x000000;

// SET TIMER
const uint8_t _LEDDRIVER3_TIMER_8ms = 0xE1;
const uint8_t _LEDDRIVER3_TIMER_16ms = 0xE2;
const uint8_t _LEDDRIVER3_TIMER_32ms = 0xE4;
const uint8_t _LEDDRIVER3_TIMER_64ms = 0xE8;
const uint8_t _LEDDRIVER3_TIMER_128ms = 0xE0;

// SET INTENSITY
const uint8_t _LEDDRIVER3_INTENSITY_1 = 0x01;
const uint8_t _LEDDRIVER3_INTENSITY_2 = 0x02;
const uint8_t _LEDDRIVER3_INTENSITY_4 = 0x04;
const uint8_t _LEDDRIVER3_INTENSITY_8 = 0x08;
const uint8_t _LEDDRIVER3_INTENSITY_16 = 0x10;

const uint8_t _LEDDRIVER3_INCREMENT = 0xA0;
const uint8_t _LEDDRIVER3_DECREMENT = 0xC0;
const uint8_t _LEDDRIVER3_CONSTANT = 0x20;




/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __LEDDRIVER3_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __LEDDRIVER3_DRV_SPI__

void leddriver3_spiDriverInit(T_LEDDRIVER3_P gpioObj, T_LEDDRIVER3_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __LEDDRIVER3_DRV_I2C__

void leddriver3_i2cDriverInit(T_LEDDRIVER3_P gpioObj, T_LEDDRIVER3_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __LEDDRIVER3_DRV_UART__

void leddriver3_uartDriverInit(T_LEDDRIVER3_P gpioObj, T_LEDDRIVER3_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

void leddriver3_setIntensity(uint8_t intensity)
{
    uint8_t writeReg[1];
    writeReg[0] = intensity;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress,writeReg,1,END_MODE_STOP);
}

void leddriver3_setRGB_Color(uint8_t red, uint8_t green, uint8_t blue)
{
    uint8_t writeReg[ 3 ];
    
    if(red < 0x40 || red > 0x5F)
        writeReg[ 0 ] = 0x40;
    else
        writeReg[ 0 ] = red;
        
    if(green < 0x60 || green > 0x7F)
        writeReg[ 1 ] = 0x60;
    else
        writeReg[ 1 ] = green;
        
    if(blue < 0x80 || blue > 0x9F)
        writeReg[ 2 ] = 0x80;
    else
        writeReg[ 2 ] = blue;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress,&writeReg[0],1,END_MODE_RESTART);
    hal_i2cWrite(_slaveAddress,&writeReg[1],1,END_MODE_RESTART);
    hal_i2cWrite(_slaveAddress,&writeReg[2],1,END_MODE_STOP);
}

void leddriver3_setColor(uint32_t color)
{
    uint8_t writeReg[ 3 ];
    writeReg[ 0 ] = color;
    writeReg[ 1 ] = color >> 8;
    writereg[ 2 ] = color >> 16;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress,&writeReg[0],1,END_MODE_RESTART);
    hal_i2cWrite(_slaveAddress,&writeReg[1],1,END_MODE_RESTART);
    hal_i2cWrite(_slaveAddress,&writeReg[2],1,END_MODE_STOP);
}

void leddriver3_shutDown()
{
    uint8_t writeReg[1];
    writeReg[0] = 0x00;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress,writeReg,1,END_MODE_STOP);
}

void leddriver3_setTimer(uint8_t time)
{
    uint8_t writeReg[1];
    writeReg[0] = time;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress,writeReg,1,END_MODE_STOP);
}

/* -------------------------------------------------------------------------- */
/*
  __leddriver3_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */