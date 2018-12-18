// Example 4 - Receive a number as text and convert it to an int

const byte numChars = 32;
char receivedChars[numChars];

boolean newData = false;

int dataNumber = 0;


void recvWithEndMarker() {
  static byte ndx = 0;
  char endMarker = '\n';
  char rc;

  if (Serial.available() > 0) {
    rc = Serial.read();

    if (rc != endMarker) {
      receivedChars[ndx] = rc;
      ndx++;
      if (ndx >= numChars) {
        ndx = numChars - 1;
      }
    }
    else {
      receivedChars[ndx] = '\0'; // terminate the string
      ndx = 0;
      newData = true;
    }
  }
}

void showNewNumber() {
	if (newData == true) {
		dataNumber = 0;
		dataNumber = atoi(receivedChars);
//		Serial.print("Data Number: ");
//		Serial.println(dataNumber);

		newData = false;
		if (Setpoint != dataNumber) {
			Setpoint = dataNumber;
			change = true;
		} else {
			change = false;
		}
	}
	if (dataNumber == 11200) {
		trigger = !trigger;
	}

	if (trigger) {
		myPID.SetTunings(255, 2.3, 2.3);
		myPID.SetSampleTime(1);
	} else {
		myPID.SetTunings(250, 2.3, 8.3);
		myPID.SetSampleTime(1);
	}
}
