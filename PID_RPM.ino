void PID_setup()
{
  //Configure Timer2
  timer2.setup();

  //Initial Start
  oldTime = timer2.get_count();

	Input = 0;
	Setpoint = 0;
	Output = 0;

	//turn the PID on
	myPID.SetMode(AUTOMATIC);
	myPID.SetSampleTime(1);
	myPID.SetOutputLimits(-255, 255);
}

void RPM(double* r1)
{

	newPosition = myEnc.read();

	unsigned long foo = timer2.get_count();
	double bar = (foo - oldTime) / 2.0;			//Time in micro seconds
	oldTime = foo;

	revs = (newPosition - oldPosition);					//Distance in pulses
	float temp1 = (revs / bar) * k_RPM;

	oldPosition = newPosition;
	*r1 = temp1;

//	Serial.print(revs);
//	Serial.print("\t");
//	Serial.print(bar);
//	Serial.print("\t");
//	Serial.print(temp1);
//	Serial.print("\t");

}

void Smooth_RPM(double* r1)
{
  double rpm = 0;

	for (double i = 0; i < repetitions; i++)
  {
    RPM(r1);
    rpm+= *r1;
  }
	*r1 = rpm / (double) repetitions;

}

