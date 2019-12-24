#define POTI A2

int pins[4]  = {6,5,9,3};
int flame[4] = {0,0,0,0};
int modi = 0;

void setup() {
  pinMode(POTI, INPUT);
  for(int i=0; i<4; ++i) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  flame[3] = flame[2];
  flame[2] = flame[1];
  flame[1] = flame[0];
  flame[0] = random(0, 84);
  modi = analogRead(POTI);
  delay(random(50+(modi/10), 50+modi));
  
  for (int i=0; i<4; ++i) analogWrite(pins[i], flame[i]);
}

