/*
william.jeffrey.harding@gmail.com
 */

int hotTimer = 100;  //the amount of time the pulse is sent (if too high the mosfet will blow!)
int delayTimer = 1000;  //

//Each cylanoid reffers to a specific Value
//read from right to left (one's place to thousand's place)
//13 / 1st cylanoid X*1
//12 / 2nd cylanoid X*10
//11 / 3rd cylanoid X*100
//10 / 4th cylanoid X*1000

int triggerCount = 4;  //really won't likely be more than four triggers

//each cylanoid is set to a pin here
int triggerPins[] = {
  13, 12, 11, 10
};

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  for (int thisPin = 0; thisPin < triggerCount; thisPin++) {
    pinMode(triggerPins[thisPin], OUTPUT);
  }

}

// the loop routine runs over and over again forever:
void loop() {
  
  for (int thisPin = 0; thisPin < triggerCount; thisPin++) {
    // turn the pin on:
    digitalWrite(triggerPins[thisPin], HIGH);
    delay(hotTimer);
    // turn the pin off:
    digitalWrite(triggerPins[thisPin], LOW);
    delay(delayTimer);
  }
}
