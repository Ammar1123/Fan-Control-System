
#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum{
	AREF=0x00 , AVCC=0x40 , INTERNAL=0xC0
}ADC_VREF_SEL;


typedef enum{
	ADLAR_RIGHT=0x00, ADLAR_LEFT=0x20
}ADC_ADLAR_SEL;


typedef enum{
	ADC0, ADC1, ADC2, ADC3, ADC4, ADC5, ADC6, ADC7
}ADC_MUX_SEL;


typedef enum{
	DISABLE,ENABLE=0x80
}ADC_ENABLE;


typedef enum{
	FCPU_2=0x00, FCPU_4=0x02,FCPU_8=0x03,FCPU_16=0x04,FCPU_32=0x05,FCPU_64=0x06,FCPU_128=0x07
}ADC_PRESCALAR_SEL;


typedef enum{
	POLLING = 0x00, INT_ENABLED = 0x08
}ADC_MODE;


typedef enum{
	AUTOTRIGGER_DISABLE, AUTOTRIGGER_ENABLE = 0x20
}ADC_AUTOTRIGGER_ENABLE;


typedef enum{
	FREE_RUNNING, ANALOG_COMPARATOR=0x20, EXTERNAL_INT0=0x40, TIMER0_CMP=0x60, TIMER0_OF=0x80, TIMER1B_CMP=0xA0, TIMER1_OF=0xC0, TIMER1_CAPTURE=0xE0
}ADC_AUTOTRIGGER_SOURCE;


typedef struct{
ADC_VREF_SEL vref;
ADC_ADLAR_SEL adlar;
ADC_ENABLE enable;
ADC_PRESCALAR_SEL prescalar;
ADC_MODE mode;
ADC_AUTOTRIGGER_ENABLE autotriggerEnable;
ADC_AUTOTRIGGER_SOURCE autotriggerSource;
}ADC_configPtr;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Function that takes adc config pointer and initialize the adc as needed
 * You can configure your adc init by passing the ADC_configPtr to the function
 */
void ADC_init(const ADC_configPtr* configPtr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel using polling
 * and returns the digital data after conversion.
 */
uint16 ADC_readChannel(ADC_MUX_SEL channelNum);
#endif
