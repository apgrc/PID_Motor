
void PID_position()
{
	encoder();

	if (abs(Setpoint - newPosition) > positionTolerance)
	{
		Input = newPosition;
		myPID.Compute();
	}
	else
	{
		Output = 0;
	}
}
