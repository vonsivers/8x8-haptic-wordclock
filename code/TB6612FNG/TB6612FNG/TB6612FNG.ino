
// Pins for all inputs, keep in mind the PWM defines must be on PWM pins
#define PWMA 2
#define AIN2 3
#define AIN1 4
#define STBY 5
#define BIN1 6
#define BIN2 7
#define PWMB 8

const int pulsetime = 200;             // pulse duration in ms
//const int delaytime = 200;      //delay between pulses of front and back PCB (ms)

void setup() {
  Serial.begin(9600);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(STBY, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  digitalWrite(STBY, LOW);

  // wait some time
  delay(1000);

}

void loop() {

  moveTX1(0);
  //moveTX(0,0);
  delay(1000);
  moveTX1(1);
  //moveTX(1,0);
  delay(1000);
  
}

// move taxel 
// tx: taxel number (0, 1)
// pos: position (0, 1)
void moveTX(int tx, int pos) {
  if(tx==0) {
    if(pos==0) {
      digitalWrite(STBY, HIGH);
      digitalWrite(AIN1, HIGH);
      digitalWrite(AIN2, LOW);
      digitalWrite(PWMA, HIGH);
      delay(pulsetime);
      digitalWrite(STBY, LOW);
      digitalWrite(AIN1, LOW);
      digitalWrite(PWMA, LOW);
    }
    else {
      digitalWrite(STBY, HIGH);
      digitalWrite(AIN1, LOW);
      digitalWrite(AIN2, HIGH);
      digitalWrite(PWMA, HIGH);
      delay(pulsetime);
      digitalWrite(STBY, LOW);
      digitalWrite(AIN2, LOW);
      digitalWrite(PWMA, LOW);
    }
  }
   else{
    if(pos==0) {
      digitalWrite(STBY, HIGH);
      digitalWrite(BIN1, HIGH);
      digitalWrite(BIN2, LOW);
      digitalWrite(PWMB, HIGH);
      delay(pulsetime);
      digitalWrite(STBY, LOW);
      digitalWrite(BIN1, LOW);
      digitalWrite(PWMB, LOW);
    }
    else {
      digitalWrite(STBY, HIGH);
      digitalWrite(BIN1, LOW);
      digitalWrite(BIN2, HIGH);
      digitalWrite(PWMB, HIGH);
      delay(pulsetime);
      digitalWrite(STBY, LOW);
      digitalWrite(BIN2, LOW);
      digitalWrite(PWMB, LOW);
    }
   }
    
}

void moveTX1(int pos) {
  if(pos==0) {
    digitalWrite(STBY, HIGH);
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    digitalWrite(PWMA, HIGH);
    //delay(delaytime);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    digitalWrite(PWMB, HIGH);
    delay(pulsetime);
    digitalWrite(STBY, LOW);
    digitalWrite(AIN1, LOW);
    digitalWrite(BIN1, LOW);
    digitalWrite(PWMA, LOW);
    digitalWrite(PWMB, LOW);
  }
  else {
    digitalWrite(STBY, HIGH);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    digitalWrite(PWMB, HIGH);
    //delay(delaytime);
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    digitalWrite(PWMA, HIGH);    
    delay(pulsetime);
    digitalWrite(STBY, LOW);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN2, LOW);
    digitalWrite(PWMA, LOW);
    digitalWrite(PWMB, LOW);
  }
}
  
