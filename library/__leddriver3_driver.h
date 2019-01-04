/*
    __leddriver3_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __leddriver3_driver.h
@brief    LED_Driver3 Driver
@mainpage LED_Driver3 Click
@{

@image html sch.jpg

@}

@defgroup   LEDDRIVER3
@brief      LED_Driver3 Click Driver
@{

| Global Library Prefix | **LEDDRIVER3** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Jan 2018.**      |
| Developer             | **MikroE Team**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _LEDDRIVER3_H_
#define _LEDDRIVER3_H_

/** 
 * @macro T_LEDDRIVER3_P
 * @brief Driver Abstract type 
 */
#define T_LEDDRIVER3_P    const uint8_t*

/** @defgroup LEDDRIVER3_COMPILE Compilation Config */              /** @{ */

//  #define   __LEDDRIVER3_DRV_SPI__                            /**<     @macro __LEDDRIVER3_DRV_SPI__  @brief SPI driver selector */
   #define   __LEDDRIVER3_DRV_I2C__                            /**<     @macro __LEDDRIVER3_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __LEDDRIVER3_DRV_UART__                           /**<     @macro __LEDDRIVER3_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup LEDDRIVER3_VAR Variables */                           /** @{ */

// COLOR SET
extern const uint32_t _LEDDRIVER3_COLOR_RED;
extern const uint32_t _LEDDRIVER3_COLOR_ORANGE;
extern const uint32_t _LEDDRIVER3_COLOR_YELLOW;
extern const uint32_t _LEDDRIVER3_COLOR_GREEN;
extern const uint32_t _LEDDRIVER3_COLOR_BLUE;
extern const uint32_t _LEDDRIVER3_COLOR_WHITE;
extern const uint32_t _LEDDRIVER3_COLOR_PURPLE;
extern const uint32_t _LEDDRIVER3_COLOR_OFF;

// SET TIMER
extern const uint8_t _LEDDRIVER3_TIMER_8ms;
extern const uint8_t _LEDDRIVER3_TIMER_16ms;
extern const uint8_t _LEDDRIVER3_TIMER_32ms;
extern const uint8_t _LEDDRIVER3_TIMER_64ms;
extern const uint8_t _LEDDRIVER3_TIMER_128ms;

// SET INTENSITY
extern const uint8_t _LEDDRIVER3_INTENSITY_1;
extern const uint8_t _LEDDRIVER3_INTENSITY_2;
extern const uint8_t _LEDDRIVER3_INTENSITY_4;
extern const uint8_t _LEDDRIVER3_INTENSITY_8;
extern const uint8_t _LEDDRIVER3_INTENSITY_16;

extern const uint8_t _LEDDRIVER3_INCREMENT;
extern const uint8_t _LEDDRIVER3_DECREMENT;
extern const uint8_t _LEDDRIVER3_CONSTANT;

                                                                       /** @} */

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup LEDDRIVER3_INIT Driver Initialization */              /** @{ */

#ifdef   __LEDDRIVER3_DRV_SPI__
void leddriver3_spiDriverInit(T_LEDDRIVER3_P gpioObj, T_LEDDRIVER3_P spiObj);
#endif
#ifdef   __LEDDRIVER3_DRV_I2C__
void leddriver3_i2cDriverInit(T_LEDDRIVER3_P gpioObj, T_LEDDRIVER3_P i2cObj, uint8_t slave);
#endif
#ifdef   __LEDDRIVER3_DRV_UART__
void leddriver3_uartDriverInit(T_LEDDRIVER3_P gpioObj, T_LEDDRIVER3_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void leddriver3_gpioDriverInit(T_LEDDRIVER3_P gpioObj);
                                                                       /** @} */
/** @defgroup LEDDRIVER3_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Function set intensity of light
 *
 * @param[in] intensity        intensity of light
 *
 * Set options:
    increase the light width intensity
    decrease the light width intensity
    constant the light width intensity
 *
 */
void leddriver3_setIntensity(uint8_t intensity);

/**
 * @brief Function set RGB color
 *
 * @param[in] red        red led
 * @param[in] green      green led
 * @param[in] blue       blue led
 *
 * The function sets the color of the rgb LEDs through the parameters for red, green and blue.
 */
void leddriver3_setRGB_Color(uint8_t red, uint8_t green, uint8_t blue);

/**
 * @brief Function set color
 *
 * @param[in] color        RGB color
 *
 * Set color:
      RED,
      GREEN,
      BLUE,
      YELLOW,
      WHITE,
      PURPLE,
      ORANGE and OFF.
 *
 */
void leddriver3_setColor(uint32_t color);

/**
 * @brief Function set timer for increase or decrease light
 *
 * @param[in] timer        time in ms
 *
 */
void leddriver3_setTimer(uint8_t time);

/**
 * @brief shut down mode
 *
 */
void leddriver3_shutDown();






                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_LED_Driver3_STM.c
    @example Click_LED_Driver3_TIVA.c
    @example Click_LED_Driver3_CEC.c
    @example Click_LED_Driver3_KINETIS.c
    @example Click_LED_Driver3_MSP.c
    @example Click_LED_Driver3_PIC.c
    @example Click_LED_Driver3_PIC32.c
    @example Click_LED_Driver3_DSPIC.c
    @example Click_LED_Driver3_AVR.c
    @example Click_LED_Driver3_FT90x.c
    @example Click_LED_Driver3_STM.mbas
    @example Click_LED_Driver3_TIVA.mbas
    @example Click_LED_Driver3_CEC.mbas
    @example Click_LED_Driver3_KINETIS.mbas
    @example Click_LED_Driver3_MSP.mbas
    @example Click_LED_Driver3_PIC.mbas
    @example Click_LED_Driver3_PIC32.mbas
    @example Click_LED_Driver3_DSPIC.mbas
    @example Click_LED_Driver3_AVR.mbas
    @example Click_LED_Driver3_FT90x.mbas
    @example Click_LED_Driver3_STM.mpas
    @example Click_LED_Driver3_TIVA.mpas
    @example Click_LED_Driver3_CEC.mpas
    @example Click_LED_Driver3_KINETIS.mpas
    @example Click_LED_Driver3_MSP.mpas
    @example Click_LED_Driver3_PIC.mpas
    @example Click_LED_Driver3_PIC32.mpas
    @example Click_LED_Driver3_DSPIC.mpas
    @example Click_LED_Driver3_AVR.mpas
    @example Click_LED_Driver3_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __leddriver3_driver.h

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