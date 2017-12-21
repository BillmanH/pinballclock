/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int bmpDel  = 100;
int cyl1out = A0;
int cyl1in  = A1;
int tmpChar =  0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);
  pinMode(cyl1out, OUTPUT);
  pinMode(cyl1in, INPUT);  
  //cyl1zero();
}

// the loop routine runs over and over again forever:
void loop() {
  cyl1goto();
}

//   _____                 _   _                 
//  |  ____   _ _ __   ___| |_(_) ___  _ __  ___ 
//  | |_ | | | | '_ \ / __| __| |/ _ \| '_ \/ __|
//  |  _|| |_| | | | | (__| |_| | (_) | | | \__ \
//  |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
//                                             

int cyl1read() {
  int temp = 0;
  temp = digitalRead(cyl1in);
  return temp;
}

void cyl1bump() {
  digitalWrite(cyl1out, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(bmpDel);              // wait for a second
  digitalWrite(cyl1out, LOW);    // turn the LED off by making the voltage LOW
  delay(bmpDel);               // wait for a second
}

void cyl1zero() {
  int temp = 0;
  delay(bmpDel);
  temp = cyl1read();
  while(temp != 0) {
    cyl1bump();
    temp = cyl1read();
  }
}

void getChar() {
  while(Serial.available() == 0) {
  }
  tmpChar = Serial.read();
  Serial.write(tmpChar);
  tmpChar = tmpChar & 0x0F;
  Serial.write(0x20);
  Serial.println(tmpChar);
}

void cyl1goto() {
  int i = 0;
  getChar();
  if (tmpChar == 0) {
    cyl1zero();
  }
  else {
    for(i=0; i<tmpChar; i++) {
      cyl1bump();
    }
  }
}
