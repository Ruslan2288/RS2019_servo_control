#include "motorController.h"

void MotorsInit( TIM_HandleTypeDef *timHandle ) 
{
	timHandle->Instance->CCR1 = 75;
	timHandle->Instance->CCR2 = 75;
	timHandle->Instance->CCR3 = 75;
	timHandle->Instance->CCR4 = 75;
	HAL_Delay(100);
	
	timHandle->Instance->CCR1 = 0;
	timHandle->Instance->CCR2 = 0;
	timHandle->Instance->CCR3 = 0;
	timHandle->Instance->CCR4 = 0;
	HAL_Delay(100);
}

void SetMotorThrust( int Force, TIM_HandleTypeDef *timHandle, int timChanel )
{
	switch (timChanel)
	{
		
		case 1:
		timHandle->Instance->CCR1 = Force; break;		
		case 2:
		timHandle->Instance->CCR1 = Force; break;		
		case 3:
		timHandle->Instance->CCR1 = Force; break;	
		case 4:
		timHandle->Instance->CCR1 = Force; break;	
		default:break;
		
	}
}