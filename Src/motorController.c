#include "motorController.h"

#define MAX_CCR 110
#define MIX_CCR 30
#define DEAD_ZONE_OF_CCR 5

int constrain( int value, int minValue, int maxValue )
{
	if( value > maxValue )
	{
		value = 100;
	}
	else if( value < minValue )
	{
		value = -100;
	}
	return value;
	
}

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
	
	Force = constrain( Force, -100, 100 );
	
	int ccr = 75 + Force/2;
	
	ccr = constrain( ccr, MIX_CCR, MAX_CCR );
	
	if ( ccr < 75 + DEAD_ZONE_OF_CCR && ccr > 0 )
	{
		ccr = 75 + DEAD_ZONE_OF_CCR;
	}
	else if( ccr > 75 - DEAD_ZONE_OF_CCR && ccr < 0 )
	{
		ccr = 75 - DEAD_ZONE_OF_CCR;
	}
	
	switch ( timChanel )
	{
		
		case 1:
		timHandle->Instance->CCR1 = ccr; break;		
		case 2:
		timHandle->Instance->CCR2 = ccr; break;		
		case 3:
		timHandle->Instance->CCR3 = ccr; break;	
		case 4:
		timHandle->Instance->CCR4 = ccr; break;	
		default: break;
		
	}
}
