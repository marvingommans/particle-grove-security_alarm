int LED4 = 4; // digital pin D6
int LED5 = 5;
int LED6 = 6;
int BUTTON = 2; // digital pin D2
int buttonPressed = 0; // default value for times that button is pressed
bool toggleButton = true; // var to check if the button has been clicked
unsigned long lastReset;

// setup() runs once, when the device is first turned on.
void setup() {
  // Initialization of pinModes
  pinMode(BUTTON, INPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  Serial.begin(9600);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
    blinkMyLed();
  // read value of input pin
  if (digitalRead(BUTTON) == HIGH)
  {
    if (toggleButton)
    {
      buttonPressed ++;
      // turn of the trigger of the button click to avoid trigger in next loop until releasing
      toggleButton = false;
       Serial.println("1");
      delay (50);
    }
    // check if button is pressed more than 1 time or more
    if (buttonPressed > 1)
    {
      // write outputvalues, set to high
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, LOW);
      Serial.println("beweging");
      delay (5000);
      buttonPressed = 0;
    }
 
  }
  else
  {
    // write outputvalues, set back to low
    digitalWrite(LED4, LOW);
    // button has been released, so trigger can be catched again in next loop
    toggleButton = true;
  }

       if (millis() - lastReset > 15000) {
           lastReset += 15000;
            buttonPressed = 0;
    }
}

void blinkMyLed()
{
  static unsigned long lastBlinkTime = 0;
  if (millis() - lastBlinkTime >= 1000UL)
  {
    digitalWrite(LED5, !digitalRead(LED5)); //toggles the led
    lastBlinkTime = millis();
  }
}

