#include "PID_Motor.h"


void setup() {
	//Set PWM frecuency to 31 kHZ
	byte config;
	config = TCCR1B;
	config = config & B11111000;
	config = config | 1;
	TCCR1B = config;
	PID_setup();
	Serial.begin(115200);
	Serial.println("<Arduino is ready>");
}

void loop() {
	recvWithEndMarker();
	showNewNumber();

	if (true)
	{
		PID_position();

		Serial.print(Input);
		Serial.print("\t");
		Serial.println(Output);

	} else {
		RPM(&Input);
		myPID.Compute();

		Serial.print(Input);
		Serial.print("\t");
		Serial.println(Output);
	}

	if (Output < 0) {
		analogWrite(PIN_OUTPUT1, abs(Output));
		analogWrite(PIN_OUTPUT2, 0);
	} else {
		analogWrite(PIN_OUTPUT1, 0);
		analogWrite(PIN_OUTPUT2, abs(Output));
	}
}
