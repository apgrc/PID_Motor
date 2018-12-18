void encoder() {
	newPosition = myEnc.read();
	if (newPosition != oldPosition) {
		oldPosition = newPosition;
//		Serial.println(newPosition);
	}
}
