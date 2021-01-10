
//Pin connected to latch pin (RCLK)
const int latchPin = 15;
//Pin connected to clock pin (SRCLK)
const int clockPin = 2;
////Pin connected to Data in (SER IN)
const int dataPin = 4;

const int pulsetime = 2000;             // pulse duration in ms
//const int delaytime = 200;      //delay between pulses of front and back PCB (ms)

void setup() {
  Serial.begin(9600);

  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);

  writeByte(0b00001010);

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
  writeByte(0b00001001);
  delay(pulsetime);
  writeByte(0b00001010);
}

void pushBack() {
  writeByte(0b00000110);
  delay(pulsetime);
  writeByte(0b00001010);
}

// This method sends bits to the shift register:

void writeByte(byte bitsToSend) {

  // turn off the output so the pins don't light up
  // while you're shifting bits:
  digitalWrite(latchPin, LOW);
  
  // shift the bits out
  shiftOut(dataPin, clockPin, MSBFIRST, bitsToSend);

  // turn on the output so the LEDs can light up:
  digitalWrite(latchPin, HIGH);
}

void registerWrite(int whichPin, int whichState) {
  // the bits you want to send
  byte bitsToSend0 = 0;
  // write number as bits
  bitWrite(bitsToSend0, whichPin, whichState);

  // turn off the output so the pins don't light up
  // while you're shifting bits:
  digitalWrite(latchPin, LOW);
  
  // shift the bits out
  shiftOut(dataPin, clockPin, MSBFIRST, bitsToSend0);

  // turn on the output so the LEDs can light up:
  digitalWrite(latchPin, HIGH);
}




  
