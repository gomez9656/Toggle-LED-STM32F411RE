/*
 * main.c
 *
 *  Created on: 23/01/2021
 *      Author: PC
 */

#include "stm32f4xx.h"
#include "main.h"
#include <string.h>

/*
 * Functions prototypes
 */
void SystemCoreClockConfig();
void Error_handler();
void TIMER5_Init(void);

TIM_HandleTypeDef htimer5;


int main(){

	/* Basic initialization */
	HAL_Init();
	SystemCoreClockConfig();

	TIMER5_Init();

	while(1);

	return 0;
}

/*
 * You can use it when you need an specific clock
 * By default will be internal clock
 */
void SystemCoreClockConfig(){

}

void TIMER5_Init(void){

	htimer5.Instance = TIM5;
	htimer5.Init.Prescaler = 24;
	htimer5.Init.Period = 64000 - 1 ;

	if (HAL_TIM_Base_Init(&htimer5) != HAL_OK){
		Error_handler();
	}

}

void Error_handler(void){
	while(1);
}
