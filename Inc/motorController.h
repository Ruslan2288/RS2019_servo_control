#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include "main.h"


void SetMotorThrust( int Force, TIM_HandleTypeDef *timHandle, int timChanel );
void MotorsInit( TIM_HandleTypeDef *timHandle );


#endif