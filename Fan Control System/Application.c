/*
 * Application.c
 *
 *  Created on: Oct 7, 2022
 *      Author: amaar
 */
#include <avr/io.h>
#include "Timer0.h"
#include "dcmotor.h"
#include "gpio.h"
#include "common_macros.h"
#include "ADC.h"
#include "lm35_sensor.h"
#include "LCD.h"

typedef enum
{
	OFF,ON
}FANSTATE;

int main(void){
	uint8 Temp = 0;
	FANSTATE Fan;
	ADC_configPtr ADC_Config = {INTERNAL, ADLAR_RIGHT, ENABLE, FCPU_8, POLLING, AUTOTRIGGER_DISABLE, FREE_RUNNING};

	LCD_init();
	ADC_init(&ADC_Config);
	DcMotor_Init();

	LCD_displayStringRowColumn(0,4,"Fan is :");
	LCD_displayStringRowColumn(1,4,"Temp is : ") ;

	while(1){
		Temp = LM35_getTemperature();

		if ( Fan == ON)
		{
			LCD_displayStringRowColumn(0, 13, "ON");
			LCD_displayCharacter(' ');
		}
		else if ( Fan == OFF)
		{
			LCD_displayStringRowColumn(0, 13, "OFF");
		}


		if (Temp < 30){
			Fan = OFF;
			DcMotor_Rotate(STOP,0);
		}
		else if (Temp > 30 && Temp <60){
			Fan = ON;
			DcMotor_Rotate(CLOCKWISE,25);

		}
		else if (Temp > 60 && Temp <90){
			Fan = ON;
			DcMotor_Rotate(CLOCKWISE,50);
		}
		else if (Temp > 90 && Temp <120){
			Fan = ON;
			DcMotor_Rotate(CLOCKWISE,75);
		}
		else if (Temp >= 120){
			Fan = ON;
			DcMotor_Rotate(CLOCKWISE,100);
		}

		LCD_moveCursor(1,13);
		if(Temp >= 100)
		{
			LCD_intergerToString(Temp);
		}
		else
		{
			LCD_intergerToString(Temp);
			LCD_displayCharacter(' '); // If temperature is less than 3 digits
		}
	}

}
