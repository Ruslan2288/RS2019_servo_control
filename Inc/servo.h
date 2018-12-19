#ifndef SERVO_H
#define SERVO_H

#include "main.h"


float SetServoAngle( int angle, ADC_HandleTypeDef *adcHandle, TIM_HandleTypeDef *timHandle );

#endif
