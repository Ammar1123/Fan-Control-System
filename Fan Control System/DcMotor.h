/*
 * DcMotor.h
 *
 *  Created on: Oct 7, 2022
 *      Author: amaar
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "std_types.h"


typedef enum
{
	CLOCKWISE, ANTICLOCKWISE , STOP
}DCMOTOR_STATE;

void DcMotor_Init(void);

void DcMotor_Rotate(DCMOTOR_STATE state,uint8 speed);




#endif /* DCMOTOR_H_ */
