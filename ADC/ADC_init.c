/**
 * @file ADC_init.c
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
 * Este archivo contiene rutinas de inicialización y de manejo del ADC del LPC 1769
 * fabricado por NXP.
*/

#include <chip.h>

#include "ADC_init.h"

/**
 * @var ADC_Setup es una estuctura del tipo ADC_CLOCK_SETUP_T que guarda los parámetros
 * de la inicialización del ADC.
*/
static ADC_CLOCK_SETUP_T ADC_setup;

/**
 * @fn void init_ADC (void)
 * @brief Esta función se encargará de inicializar el ADC, según lo estipule lo indicado
 * en el archivo de configuración del ADC
 * @return Nothing
 */

void init_ADC (void)
{
  Chip_ADC_Init(LPC_ADC, &ADC_setup);

#if ENABLE_ADC_CHANNEL_0
  Chip_ADC_EnableChannel (LPC_ADC, ADC_CH0, ENABLE);
  Chip_IOCON_PinMux (LPC_IOCON, ADC0_PORT_PIN, IOCON_MODE_INACT, ADC0_FUNC);
  Chip_ADC_Int_SetChannelCmd (LPC_ADC, ADC_CH0, ENABLE);
#endif

#if ENABLE_ADC_CHANNEL_1
  Chip_ADC_EnableChannel (LPC_ADC, ADC_CH1, ENABLE);
  Chip_IOCON_PinMux (LPC_IOCON, ADC1_PORT_PIN, IOCON_MODE_INACT, ADC1_FUNC);
  Chip_ADC_Int_SetChannelCmd (LPC_ADC, ADC_CH1, ENABLE);
#endif

#if ENABLE_ADC_CHANNEL_2
  Chip_ADC_EnableChannel (LPC_ADC, ADC_CH2, ENABLE);
  Chip_IOCON_PinMux (LPC_IOCON, ADC2_PORT_PIN, IOCON_MODE_INACT, ADC2_FUNC);
  Chip_ADC_Int_SetChannelCmd (LPC_ADC, ADC_CH2, ENABLE);
#endif

#if ENABLE_ADC_CHANNEL_3
  Chip_ADC_EnableChannel (LPC_ADC, ADC_CH3, ENABLE);
  Chip_IOCON_PinMux (LPC_IOCON, ADC3_PORT_PIN, IOCON_MODE_INACT, ADC3_FUNC);
  Chip_ADC_Int_SetChannelCmd (LPC_ADC, ADC_CH3, ENABLE);
#endif

#if ENABLE_ADC_CHANNEL_4
  Chip_ADC_EnableChannel (LPC_ADC, ADC_CH4, ENABLE);
  Chip_IOCON_PinMux (LPC_IOCON, ADC4_PORT_PIN, IOCON_MODE_INACT, ADC4_FUNC);
  Chip_ADC_Int_SetChannelCmd (LPC_ADC, ADC_CH4, ENABLE);
#endif

#if ENABLE_ADC_CHANNEL_5
  Chip_ADC_EnableChannel (LPC_ADC, ADC_CH5, ENABLE);
  Chip_IOCON_PinMux (LPC_IOCON, ADC5_PORT_PIN, IOCON_MODE_INACT, ADC5_FUNC);
  Chip_ADC_Int_SetChannelCmd (LPC_ADC, ADC_CH5, ENABLE);
#endif

#if ENABLE_ADC_CHANNEL_6
  Chip_ADC_EnableChannel (LPC_ADC, ADC_CH6, ENABLE);
  Chip_IOCON_PinMux (LPC_IOCON, ADC6_PORT_PIN, IOCON_MODE_INACT, ADC6_FUNC);
  Chip_ADC_Int_SetChannelCmd (LPC_ADC, ADC_CH6, ENABLE);
#endif

#if ENABLE_ADC_CHANNEL_7
  Chip_ADC_EnableChannel (LPC_ADC, ADC_CH7, ENABLE);
  Chip_IOCON_PinMux (LPC_IOCON, ADC7_PORT_PIN, IOCON_MODE_INACT, ADC7_FUNC);
  Chip_ADC_Int_SetChannelCmd (LPC_ADC, ADC_CH7, ENABLE);
#endif

  Chip_ADC_SetSampleRate(LPC_ADC, &ADC_setup, SAMPLE_RATE)

  NVIC_ClearPendingIRQ(ADC_IRQn);
  NVIC_EnableIRQ(ADC_IRQn);

#if BURST_MODE_ENABLE
  Chip_ADC_SetBurstCmd(LPC_ADC, ENABLE);
#endif

}
