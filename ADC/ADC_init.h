/**
 * @file ADC_init.h
 * @author Guillermo Ariel Muena Vidal <guillermuena@est.frba.utn.edu.ar>
 * @version 1.0
 * @section LICENSE
 *
 * Copyright (C) 2019  Guillermo Ariel Muena Vidal
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * General Public License for more details at
 * https://www.gnu.org/licenses/gpl.html
 *
 * @section DESCRIPTION
 *
 * Este archivo contiene los defines necesarios para que la incialización de los
 * diferentes canales del LPC1769 fabricado por NXP.
*/

#include <chip.h>

/**
* @def ENABLE_ADC_CHANNEL_n donde n es el número de canal del ADC que queremos
* habilitar. Con el define n en true podemos habilitar el ADC correspondiente
* @see void init_ADC (void)
*/

#define ENABLE_ADC_CHANNEL_0 false
#define ENABLE_ADC_CHANNEL_1 false
#define ENABLE_ADC_CHANNEL_2 false
#define ENABLE_ADC_CHANNEL_3 false
#define ENABLE_ADC_CHANNEL_4 false
#define ENABLE_ADC_CHANNEL_5 false
#define ENABLE_ADC_CHANNEL_6 false
#define ENABLE_ADC_CHANNEL_7 false

/**
* @def ADCn_PORT_PIN donde n es el número de canal del ADC que queremos usar. Este
* define permite saber el puerto y el pin asociado a cada canal del ADC del LPC1769
* @see void init_ADC (void)
* @see void Chip_IOCON_PinMux (LPC_IOCON *pIOCON, uint8_t port, uint8_t pin,
* uint32_t mode, uint8_t func)
*/

#define ADC0_PORT_PIN 0,23
#define ADC1_PORT_PIN 0,24
#define ADC2_PORT_PIN 0,25
#define ADC3_PORT_PIN 0,26
#define ADC4_PORT_PIN 1,30
#define ADC5_PORT_PIN 1,31
#define ADC6_PORT_PIN 0,3
#define ADC7_PORT_PIN 0,2

/**
* @def ADCn_FUNC donde n es el número de canal del ADC que queremos usar. Este
* define permite saber la función que indica el trabajo bajo la función de ADC de los
* pines del ADC del LPC1769.
* @see void init_ADC (void)
* @see void Chip_IOCON_PinMux (LPC_IOCON *pIOCON, uint8_t port, uint8_t pin,
* uint32_t mode, uint8_t func)
*/

#define ADC0_FUNC IOCON_FUNC1
#define ADC1_FUNC IOCON_FUNC1
#define ADC2_FUNC IOCON_FUNC1
#define ADC3_FUNC IOCON_FUNC1
#define ADC4_FUNC IOCON_FUNC3
#define ADC5_FUNC IOCON_FUNC3
#define ADC6_FUNC IOCON_FUNC2
#define ADC7_FUNC IOCON_FUNC2

/**
 * @def BURST_MODE_ENABLE es el define que nos permite inicializar el ADC del LPC1769
 * en modo 'burst'
 * @see void init_ADC (void)
 */

#define BURST_MODE_ENABLE false

/**
 * @def ACTIVE_ADC_DEBUG es el define que permite imprimir por consola los datos leídos
 * por el ADC. Usar esto requiere Semihosting del proyecto dentro del IDE.
 * @see void ADC_default_function (uint16_t data_ADC)
 * @see Semihosting in LPC1769, MCUExpressoIDE.
 */

#define ACTIVE_ADC_DEBUG false
