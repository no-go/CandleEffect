// I use 8 LEDs with GND connected to ...

int pins[8]    = {A3,A2,A1,A0,  13,12,11,10};
//int pins[8]  = {10,11,12,13,  A0,A1,A2,A3};

// ... and their + connected to a 68 Ohm resistor (and that connected to 3.3V)

int flame[8] = {0,0,0,0,0,0,0,0}; // stores the LED blackout delay

void setup() {
  for(int i=0; i<8; ++i) {
    pinMode(pins[i], OUTPUT);
  }
}

int i=0;
void loop() {
  // floating the delay to through to LEDs
  flame[7] = flame[6];
  flame[6] = flame[5];
  flame[5] = flame[4];
  flame[4] = flame[3];
  flame[3] = flame[2];
  flame[2] = flame[1];
  flame[1] = flame[0];
  flame[0] = random(1, 25);
  
  digitalWrite(pins[i], HIGH);  // = OFF
  delay(flame[i]);
  digitalWrite(pins[i], LOW);   // = ON
  delay(flame[i]);

  i = (i+1)%8;
}

