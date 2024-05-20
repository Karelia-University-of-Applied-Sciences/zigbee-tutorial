// Tapaus 2, Painokytkinyksikko

const int buttonPin = 2; // button pin on arduino

int buttonState; // state of hardware button
int ledState = 0; // state of led at the other end

void setup() {

  // initialize the BUTTON pin as an input
  pinMode(buttonPin, INPUT);

  // initialize serial communication
  Serial.begin(9600);
}

// reading state of button and sending serial data according to it
void loop() {
 
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == 1 && ledState == 0) {
    Serial.print('H');
	  ledState = 1;
  } 
  
  if (buttonState == 0 && ledState == 1) {
    Serial.print('L');
	  ledState = 0;
  }
}