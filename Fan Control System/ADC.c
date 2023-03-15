/*
 * ADC.c
 *
 *  Created on: Oct 4, 2022
 *      Author: amaar
 */

#include "ADC.h"
#include "common_macros.h"
#include "avr/io.h"

void ADC_init(const ADC_configPtr* configPtr){
	ADMUX |= configPtr->vref | configPtr->adlar;
	ADCSRA |= configPtr->enable | configPtr->mode | configPtr->autotriggerEnable | configPtr->prescalar;
	SFIOR |= configPtr->autotriggerSource;
}

uint16 ADC_readChannel(uint8 ch_num){
	uint16 data;
	ADMUX = (ADMUX &= 0xE0) | (ch_num & 0x3F) ;
	SET_BIT(ADCSRA,6);
	while(BIT_IS_CLEAR(ADCSRA,4)){

	}
	SET_BIT(ADCSRA,4);
	data = ADC;
	return data;
}
