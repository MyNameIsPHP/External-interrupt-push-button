// this constant won't change:
const int buttonPin = 2; //  we will use pin 2 for interrupt
int timer = 100;  // The higher the number, the slower the timing.

// Variables will change:
int buttonPushCounter = 0;

void setup() {
  // use a for loop to initialize each pin as an output:
  for (int thisPin = 3; thisPin <= 8; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }

  // setup for interrupt 0 with rising mode; ISR is blink function.
  attachInterrupt(digitalPinToInterrupt(buttonPin), changeMode, RISING);

  // initialize serial communication:
  Serial.begin(9600);
}

void loop() {
  if (buttonPushCounter == 1) {
    // Press the button for the 1st time : 6 LEDs will be on.
    for (int thisPin = 3; thisPin <= 8; thisPin++) {
      // turn the pin on:
      digitalWrite(thisPin, HIGH);
    }
  } else if (buttonPushCounter == 2) {
    // Press the button a 2nd time: 6 LEDs will turn off.
    for (int thisPin = 3; thisPin <= 8; thisPin++) {
      // turn the pin off:
      digitalWrite(thisPin, LOW);
    }
  } else if (buttonPushCounter == 3) {
    // Press button a 3rd time: run "Knight Rider" mode. (read “7_Lead array effect”).
    // loop from the lowest pin to the highest:
    for (int thisPin = 3; thisPin <= 8; thisPin++) {
      // turn the pin on:
      digitalWrite(thisPin, HIGH);
      delay(timer);
      // turn the pin off:
      digitalWrite(thisPin, LOW);
    }
    // loop from the highest pin to the lowest:
    for (int thisPin = 8; thisPin >= 3; thisPin--) {
      // turn the pin on:
      digitalWrite(thisPin, HIGH);
      delay(timer);
      // turn the pin off:
      digitalWrite(thisPin, LOW);
    }
  } else if (buttonPushCounter == 4) {
    //Press button a 4th time: turn off the 6 LEDs and reset the button Push Counter.
    for (int thisPin = 3; thisPin <= 8; thisPin++) {
      // turn the pin off:
      digitalWrite(thisPin, LOW);
    }
  }
  // Delay a little bit to avoid bouncing
  delay(50);
}

// switch the mode every button push 
void changeMode() {
  // increase the push counter
  buttonPushCounter++;
  // reset the counter if it's over 4
  if (buttonPushCounter == 5) {
    buttonPushCounter = 1;
  }
}