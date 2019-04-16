/**
 * @file ADC_handler.c
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
 * @def WEAK
 * @brief redefinición del atributo 'weak'
 */

#define WEAK __attribute__ ((weak))

/**
 * @def WEAK
 * @brief redefinición de 'alias(#f)' incorporando el modificador 'weak'
 */

#define ALIAS(f) __attribute__ ((weak, alias (#f)))

/**
 * @fn void ADC_default_function (uint16_t data_ADC)
 * @brief Función genérica de lectura de los valores recibidos al leer el ADC luego de
 * una rutina de interrupción. En caso de seteat en ADC_init.h el flag correspondiente
 * a debugging y en el caso de que esté habilitada la impresión por consola en el IDE
 * podremos ver el valor leído por consola.
 * @param data_ADC dato de lectura del ADC que queremos procesar
 * @see Semihosting in LPC1769, MCUExpressoIDE.
 * @return Nothing
*/

void ADC_default_function (uint16_t data_ADC)
{
  uint16_t data = data_ADC;
#if ACTIVE_ADC_DEBUG
  DEBUGOUT("El valor del ADC es:  0x%04x\r\n", data);
#else
  data = 0;
#endif
}

/**
 * @fn void ADCn_store_data (void)
 * @brief Donde 'n' es el número de canal de ADC. Estas funciones se encuentran
 * aliaseadas a una función genérica. En caso de redefinirlas, esa redefinición
 * pisará la defición genérica colocada aquí.
 * @return Nothing
*/

void ADC0_store_data (uint16_t) ALIAS(ADC_default_function);
void ADC1_store_data (uint16_t) ALIAS(ADC_default_function);
void ADC2_store_data (uint16_t) ALIAS(ADC_default_function);
void ADC3_store_data (uint16_t) ALIAS(ADC_default_function);
void ADC4_store_data (uint16_t) ALIAS(ADC_default_function);
void ADC5_store_data (uint16_t) ALIAS(ADC_default_function);
void ADC6_store_data (uint16_t) ALIAS(ADC_default_function);
void ADC7_store_data (uint16_t) ALIAS(ADC_default_function);

/**
 * @fn void ADC_IRQHandler (void)
 * @brief Esta función se encargará de manejar las interrrupciones causadas por los
 * diferentes canales del ADC. Podrá parecer algo larga para una rutina de atención
 * de interrupciones, pero el volúmen sólo se debe a la cantidad de elementos de
 * compilación condicional.
 * @return Nothing
*/

void ADC_IRQHandler (void)
{
  NVIC_DisableIRQ(ADC_IRQn);

#if ENABLE_ADC_CHANNEL_0
  uint16_t data_ADC0;
  Chip_ADC_IntSetChannelCmd (LPC_ADC, ADC_CH0, DISABLE);
  Chip_ADC_ReadValue(LPC_ADC, ADC_CH0, &data_ADC0);
  ADC0_store_data(data_ADC0);
#endif

#if ENABLE_ADC_CHANNEL_1
  uint16_t data_ADC1;
  Chip_ADC_IntSetChannelCmd (LPC_ADC, ADC_CH1, DISABLE);
  Chip_ADC_ReadValue(LPC_ADC, ADC_CH1, &data_ADC1);
  ADC1_store_data(data_ADC1);
#endif

#if ENABLE_ADC_CHANNEL_2
  uint16_t data_ADC2;
  Chip_ADC_IntSetChannelCmd (LPC_ADC, ADC_CH2, DISABLE);
  Chip_ADC_ReadValue(LPC_ADC, ADC_CH2, &data_ADC2);
  ADC2_store_data(data_ADC2);
#endif

#if ENABLE_ADC_CHANNEL_3
  uint16_t data_ADC3;
  Chip_ADC_IntSetChannelCmd (LPC_ADC, ADC_CH3, DISABLE);
  Chip_ADC_ReadValue(LPC_ADC, ADC_CH3, &data_ADC3);
  ADC3_store_data(data_ADC3);
#endif

#if ENABLE_ADC_CHANNEL_4
  uint16_t data_ADC4;
  Chip_ADC_IntSetChannelCmd (LPC_ADC, ADC_CH4, DISABLE);
  Chip_ADC_ReadValue(LPC_ADC, ADC_CH4, &data_ADC4);
  ADC4_store_data(data_ADC4);
#endif

#if ENABLE_ADC_CHANNEL_5
  uint16_t data_ADC5;
  Chip_ADC_IntSetChannelCmd (LPC_ADC, ADC_CH5, DISABLE);
  Chip_ADC_ReadValue(LPC_ADC, ADC_CH5, &data_ADC5);
  ADC5_store_data(data_ADC5);
#endif

#if ENABLE_ADC_CHANNEL_6
  uint16_t data_ADC6;
  Chip_ADC_IntSetChannelCmd (LPC_ADC, ADC_CH6, DISABLE);
  Chip_ADC_ReadValue(LPC_ADC, ADC_CH6, &data_ADC6);
  ADC6_store_data(data_ADC6);
#endif

#if ENABLE_ADC_CHANNEL_7
  uint16_t data_ADC7;
  Chip_ADC_IntSetChannelCmd (LPC_ADC, ADC_CH7, DISABLE);
  Chip_ADC_ReadValue(LPC_ADC, ADC_CH7, &data_ADC7);
  ADC7_store_data(data_ADC7);
#endif

  NVIC_EnableIRQ(_LPC_ADC_IRQ);

#if ENABLE_ADC_CHANNEL_0
  Chip_ADC_Int_SetChannelCmd(_PC_ADC, ADC_CH0, ENABLE);
#endif

#if ENABLE_ADC_CHANNEL_1
  Chip_ADC_Int_SetChannelCmd(_PC_ADC, ADC_CH1, ENABLE);
#endif

#if ENABLE_ADC_CHANNEL_2
  Chip_ADC_Int_SetChannelCmd(_PC_ADC, ADC_CH2, ENABLE);
#endif

#if ENABLE_ADC_CHANNEL_3
  Chip_ADC_Int_SetChannelCmd(_PC_ADC, ADC_CH3, ENABLE);
#endif

#if ENABLE_ADC_CHANNEL_4
  Chip_ADC_Int_SetChannelCmd(_PC_ADC, ADC_CH4, ENABLE);
#endif

#if ENABLE_ADC_CHANNEL_5
  Chip_ADC_Int_SetChannelCmd(_PC_ADC, ADC_CH5, ENABLE);
#endif

#if ENABLE_ADC_CHANNEL_6
  Chip_ADC_Int_SetChannelCmd(_PC_ADC, ADC_CH6, ENABLE);
#endif

#if ENABLE_ADC_CHANNEL_7
  Chip_ADC_Int_SetChannelCmd(_PC_ADC, ADC_CH7, ENABLE);
#endif
}
