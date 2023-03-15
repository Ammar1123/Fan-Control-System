/*
 * DcMotor.c
 *
 *  Created on: Oct 7, 2022
 *      Author: amaar
 */

#include "gpio.h"
#include "std_types.h"
#include "DcMotor.h"
#include "common_macros.h"
#include <avr/io.h>

void DcMotor_Init(void){
	/* configure pin PC0 and PC1 as output pins */
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,LOGIC_HIGH);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,LOGIC_HIGH);

	/* Motor is stop at the beginning */
	GPIO_writePin(PORTB_ID ,PIN0_ID,LOGIC_LOW);
	GPIO_writePin(PORTB_ID ,PIN1_ID ,LOGIC_LOW);

}

void DcMotor_Rotate(DCMOTOR_STATE state,uint8 speed){

	PWM_Timer0_Init(speed);

	if(state == CLOCKWISE)
	{
		GPIO_writePin(PORTB_ID ,PIN0_ID,LOGIC_LOW);
		GPIO_writePin(PORTB_ID ,PIN1_ID ,LOGIC_HIGH);
	}

	else if(state == ANTICLOCKWISE)
	{

		GPIO_writePin(PORTB_ID ,PIN0_ID,LOGIC_HIGH);
		GPIO_writePin(PORTB_ID ,PIN1_ID ,LOGIC_LOW);
	}

	else if(state == STOP)
	{
		GPIO_writePin(PORTB_ID ,PIN0_ID,LOGIC_LOW);
		GPIO_writePin(PORTB_ID ,PIN1_ID ,LOGIC_LOW);
	}

}
