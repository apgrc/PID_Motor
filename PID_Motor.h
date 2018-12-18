/*
 * main.h
 *
 *  Created on: Dec 7, 2017
 *      Author: alex
 */

#ifndef PID_MOTOR_H_
#define PID_MOTOR_H_

//Test declaration

//PID declarations
#include <PID_v1.h>

#define PIN_OUTPUT1 9
#define PIN_OUTPUT2 10

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
double Kp = 255.0, Ki = 2.00, Kd = 2.0;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
int positionTolerance = 20;


//Encoder declarations
#include <Encoder.h>
Encoder myEnc(2,3);

volatile long oldPosition = -999;
volatile long newPosition = 999;

int thisPosition = 0;
float controlRPM = 0;


//Time declarations
#include <eRCaGuy_Timer2_Counter.h>

//Initial variables
float countsPerRevolution = 20400;
float k_RPM = (6e7 / countsPerRevolution);		//micro seconds to minutes
float revs = 0;

byte repetitions = 1;

unsigned long oldTime;

//Serial declarations
bool change = false;
bool trigger = false;


#endif /* PID_MOTOR_H_ */
