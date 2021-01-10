
// Pins for all inputs, keep in mind the PWM defines must be on PWM pins
#define NCH1 2
#define PCH1 3
#define NCH2 4
#define PCH2 5

const int pulsetime = 200;             // pulse duration in ms
//const int delaytime = 200;      //delay between pulses of front and back PCB (ms)

void setup() {
  Serial.begin(9600);

  pinMode(NCH1, OUTPUT);
  pinMode(PCH1, OUTPUT);
  pinMode(NCH2, OUTPUT);
  pinMode(PCH2, OUTPUT);

  digitalWrite(NCH1, LOW);
  digitalWrite(PCH1, HIGH);
  digitalWrite(NCH2, LOW);
  digitalWrite(PCH2, HIGH);

  // wait some time
  delay(1000);

}

void loop() {
  
  pushFW();
  delay(1000);
  pushBack();
  delay(1000);
  
}

void pushFW() {
  digitalWrite(PCH1, LOW);
  digitalWrite(NCH1, HIGH);
  delay(pulsetime);
  digitalWrite(NCH1, LOW);
  digitalWrite(PCH1, HIGH);
}

void pushBack() {
  digitalWrite(PCH2, LOW);
  digitalWrite(NCH2, HIGH);
  delay(pulsetime);
  digitalWrite(NCH2, LOW);
  digitalWrite(PCH2, HIGH);
}




  
