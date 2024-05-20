// Tapaus 3, Sensoriyksikko, Arduino lahdekoodi

/*
* ROMANTIC LIGHTING SENSOR
*
* USES PREVIOUSLY PAIRED XBEE ZB RADIOS
* by Rob Faludi http://faludi.com
* 
* edited for thesis purposes
* by Kosti Hiltunen
*/

/*
    CONFIGURATION
    SENDER: (REMOTE SENSOR RADIO)
    ATID1234 (PAN ID)
    ATDH -> set to SH of partner radio
    ATDL -> set to SL of partner radio
    ATJV1 -> rejoin with coordinator on startup
    ATD02 pin 0 in analog in mode
    ATIR64 sample rate 100 millisecs (hex 64)
    * THE LOCAL RADIO _MUST_ BE IN API MODE *
    RECEIVER: (LOCAL RADIO)
    ATID1234 (PAN ID)
    ATDH -> set to SH of partner radio
    ATDL -> set to SL of partner radio
*/

// creating values for led pins and for a variable
int LED = 11;
int debugLED = 13;
int analogValue = 0;

// initializing led pins and serial connection
void setup() {
    pinMode(LED, OUTPUT);
    pinMode(debugLED, OUTPUT);
    Serial.begin(9600);
}
void loop() {

    // Make sure everything we need is in the buffer
    if (Serial.available() >= 21) {

        // Look for the start byte
        if (Serial.read() == 0x7E) {

            //Blink debug LED to indicate when data is received
            digitalWrite(debugLED, HIGH);
            delay(10);
            digitalWrite(debugLED, LOW);

            // Read the variables that we're not using out of the buffer
            for (int i = 0; i<18; i++) {
                byte discard = Serial.read();
            }
            // Read needed values
            int analogHigh = Serial.read();
            int analogLow = Serial.read();
            analogValue = analogLow + (analogHigh * 256);
        }
    }

    // Sending values to XBee module
    String strValue = String(analogValue);
    Serial.println(strValue);
}