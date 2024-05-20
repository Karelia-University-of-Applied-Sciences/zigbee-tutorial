// Tapaus 2, LED-yksikko

const int ledPin = 13; // led pin on arduino

char incomingByte; // a variable for incoming serial data

void setup() {

  // initialize serial communication:
  Serial.begin(9600);
  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
}

// Reading serial connection and changing pins value accordingly
void loop() {

  if (Serial.available() > 0) {
    incomingByte = Serial.read();

    if (incomingByte == 'H') {
      digitalWrite(ledPin, HIGH);
    }

    if (incomingByte == 'L') {
      digitalWrite(ledPin, LOW);
    }
  }
}