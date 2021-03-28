/*
 * Code for 8x8 haptic wordclock
 * by Moritz v. Sivers, March 2021
 * 
 * wiring: MCU - DRV8912
 * MISO - pin 7
 * MOSI - pin 5
 * SCLK - pin 20
 * SS - pin 19
 * 
 * on WEMOS D1 mini (ESP8266): SCLK = D5 (GPIO 14), MISO = D6 (GPIO 12), MOSI = D7 (GPIO 13), CS1 = D8 (GPIO 15), CS2 = D4, CS3 = D3
 */

#include <SPI.h>

// SPI pins
#define MISO    D6
#define MOSI    D7
#define SCLK    D5
#define CS1     D8
#define CS2     D4
#define CS3     D3

// enable pin
#define nSLEEP  D2

//#define DEBUG // activate output to serial

#ifdef DEBUG
#define DEBUG_PRINT(x) Serial.print(x)
#define DEBUG_PRINTF(x, f) Serial.print(x, f)
#define DEBUG_PRINTLN(x) Serial.println(x)
#define DEBUG_PRINTLNF(x, f) Serial.println(x, f)
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTF(x, f)
#define DEBUG_PRINTLN(x)
#define DEBUG_PRINTLNF(x, f)
#endif

/*
 * The SDI input data word is 16 bits long and consists of the following format:
• 1 read or write bit, W (bit B14)
• 6 address bits, A (bits B13 through B8)
• 8 data bits, D (bits B7 through B0)
The SDO output data word is 16 bits long and the first 8 bits makes up the IC status register. The report word is
the content of the register being accessed.
For a write command (W0 = 0), the response word on the SDO pin is the data currently in the register being
written to.
For a read command (W0 = 1), the response word is the data currently in the register being read.
 */
 
// register addresses:
const int IC_STAT = 0x00;       // status
const int OLD_STAT1 = 0x04;      // open load detect H-bridges 1..4
const int CONFIG = 0x07;        // configuration 
const int OP_CTRL1 = 0x08;       // enable/disable (default) H-bridges 1..4
const int OP_CTRL2 = 0x09;       // enable/disable (default) H-bridges 5..8
const int OP_CTRL3 = 0x0A;       // enable/disable (default) H-bridges 9..12
const int PWM_CTRL1 = 0x0B;      // PWM or continous (default) operation, H-bridges 1..8
const int PWM_CTRL2 = 0x0C;      // PWM or continous (default), H-bridges 9..12, enable/disable PWM generator 1..4
const int PWM_FREQ_CTRL = 0x12;   // frequency of PWM Generators 1..4
const int PWM_DUTY_CH1 = 0x13;    // duty cycle of PWM Ch 1, 0..255
const int OLD_CTRL1 = 0x19;       // enable disable OLD on H-bridges 1..8
const int OLD_CTRL2 = 0x1A;       // enable disable OLD on H-bridges 9..12 (bit 0..3)
const int OLD_CTRL3 = 0x1B;       // set OCP deglitch time (bit 5..7)

// number of rows and columns
const uint8_t nRows = 8;
const uint8_t nCols = 8;

const int tPulse = 100;   // pulse duration in ms

const int tDelay = 0; // delay between driving pixels in ms

const int duty = 210;  // PWM duty cycle 0..255

bool pushpull = false; // push and pull taxels simultaneously

bool polarity = 1; // polarity of magnets

bool alternatePol = false; // alternating polarity

bool PWM = false; // operate h-bridges in PWM mode

bool currentState[8][8] = {0}; // current state of all letters 0=back, 1=front

// 64-bit "mask" for each pixel in the matrix- is it on or off?
uint64_t mask;

// define masks for each word. we add them with "bitwise or" to generate a mask for the entire "phrase".
#define MFIVE    mask |= 0xF00000000000        // these are in hexadecimal
#define MTEN     mask |= 0x5800000000000000
#define AQUARTER mask |= 0x80FE000000000000
#define TWENTY   mask |= 0x7E00000000000000
#define HALF     mask |= 0xF0000000000
#define PAST     mask |= 0x7800000000
#define TO       mask |= 0xC00000000
#define ONE      mask |= 0x43
#define TWO      mask |= 0xC040
#define THREE    mask |= 0x1F0000
#define FOUR     mask |= 0xF0
#define FIVE     mask |= 0xF0000000
#define SIX      mask |= 0xE00000
#define SEVEN    mask |= 0x800F00
#define EIGHT    mask |= 0x1F000000
#define NINE     mask |= 0xF
#define TEN      mask |= 0x1010100
#define ELEVEN   mask |= 0x3F00
#define TWELVE   mask |= 0xF600
#define ANDYDORO mask |= 0x8901008700000000

#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char *ssid     = "your ssid";
const char *password = "your password";

const long utcOffsetInSeconds = 3600; // change to your timezone

uint8_t lastMinute;

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);


void setup() {

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    DEBUG_PRINT ( "." );
  }

  timeClient.begin();

  // start the SPI library:
  SPI.begin();
  
  // initalize the pins
  pinMode(nSLEEP, OUTPUT);
  pinMode(CS1, OUTPUT);
  pinMode(CS2, OUTPUT);
  pinMode(CS3, OUTPUT);
  
  digitalWrite(CS1, HIGH);
  digitalWrite(CS2, HIGH);
  digitalWrite(CS3, HIGH);
  digitalWrite(nSLEEP, HIGH); // nSLEEP pin needs to be high to enable driver

  // give the sensor time to set up:
  delay(2000);

  DEBUG_PRINTLN("configuring device");
  for(int device=0; device<3; device++) {
    writeRegister(device,OLD_CTRL1,0b11111111); // disable open load detection on out 1-8
    writeRegister(device,OLD_CTRL2,0b01001111); // disable open load detection on out 9-12, h-bridges active after OLD
    if(PWM) {                                         // set h-bridges to PWM operation
      writeRegister(device,PWM_CTRL1,0b11111111);
      writeRegister(device,PWM_CTRL2,0b00001111);
      writeRegister(device,PWM_FREQ_CTRL,0b11111111); // set PWM frequency to 2 kHz
      writeRegister(device,PWM_DUTY_CH1,duty);        // set PWM Ch1 duty cycle (all h-bridges are mapped to Ch1 by default)
    }
    //writeRegister(device,OLD_CTRL2,0b01011111); // disable open load detection on out 9-12, h-bridges active after OLD, enable parallel mode OCP slow turn off slew
    //writeRegister(device,OLD_CTRL3,0b10000000); // set OCP deglitch time to max
  }
  
  DEBUG_PRINTLN("reading DRV8912 status");
  readRegister(0,IC_STAT);
  readRegister(1,IC_STAT);
  readRegister(2,IC_STAT);
  DEBUG_PRINTLN("---------start-------");

  //resetAllLetters();
  testDisplay();
  //delay(2000);
  //testClock();
  getNTPTime();
  displayTime();
  lastMinute = timeClient.getMinutes();
    
}

void loop() {

  getNTPTime();
  
  // update display every 5 minutes
  if(timeClient.getMinutes() % 5 == 0 && timeClient.getMinutes()!=lastMinute) {
    resetLetters(1);
    displayTime();
    lastMinute = timeClient.getMinutes();
  }

}

// test clock
//
void testClock() {

  resetLetters(1);
  AQUARTER;
  PAST;
  ELEVEN;
  applyMask();
  mask=0;
  delay(5000);

  resetLetters(1);
  TWENTY;
  PAST;
  ELEVEN;
  applyMask();
  mask=0;
  
}

// get time from NTP client
//
void getNTPTime() {
  timeClient.update();

  DEBUG_PRINT(daysOfTheWeek[timeClient.getDay()]);
  DEBUG_PRINT(", ");
  DEBUG_PRINT(timeClient.getHours());
  DEBUG_PRINT(":");
  DEBUG_PRINT(timeClient.getMinutes());
  DEBUG_PRINT(":");
  DEBUG_PRINTLN(timeClient.getSeconds());

  delay(1000);
}

// function to generate the right "phrase" based on the time
//
void displayTime(void) {

  // time we display the appropriate timeClient.getMinutes() counter
  if ((timeClient.getMinutes() > 4) && (timeClient.getMinutes() < 10)) {
    MFIVE;
    DEBUG_PRINT("five");
  }
  if ((timeClient.getMinutes() > 9) && (timeClient.getMinutes() < 15)) {
    MTEN;
    DEBUG_PRINT("ten");
  }
  if ((timeClient.getMinutes() > 14) && (timeClient.getMinutes() < 20)) {
    AQUARTER;
    DEBUG_PRINT("a quarter");
  }
  if ((timeClient.getMinutes() > 19) && (timeClient.getMinutes() < 25)) {
    TWENTY;
    DEBUG_PRINT("twenty");
  }
  if ((timeClient.getMinutes() > 24) && (timeClient.getMinutes() < 30)) {
    TWENTY;
    MFIVE;
    DEBUG_PRINT("twenty five");
  }
  if ((timeClient.getMinutes() > 29) && (timeClient.getMinutes() < 35)) {
    HALF;
    DEBUG_PRINT("half");
  }
  if ((timeClient.getMinutes() > 34) && (timeClient.getMinutes() < 40)) {
    TWENTY;
    MFIVE;
    DEBUG_PRINT("twenty five");
  }
  if ((timeClient.getMinutes() > 39) && (timeClient.getMinutes() < 45)) {
    TWENTY;
    DEBUG_PRINT("twenty");
  }
  if ((timeClient.getMinutes() > 44) && (timeClient.getMinutes() < 50)) {
    AQUARTER;
    DEBUG_PRINT("a quarter");
  }
  if ((timeClient.getMinutes() > 49) && (timeClient.getMinutes() < 55)) {
    MTEN;
    DEBUG_PRINT("ten");
  }
  if (timeClient.getMinutes() > 54) {
    MFIVE;
    DEBUG_PRINT("five");
  }

  if ((timeClient.getMinutes() < 5))
  {
    switch (timeClient.getHours()) {
      case 1:
      case 13:
        ONE;
        break;
      case 2:
      case 14:
        TWO;
        break;
      case 3:
      case 15:
        THREE;
        break;
      case 4:
      case 16:
        FOUR;
        break;
      case 5:
      case 17:
        FIVE;
        break;
      case 6:
      case 18:
        SIX;
        break;
      case 7:
      case 19:
        SEVEN;
        break;
      case 8:
      case 20:
        EIGHT;
        break;
      case 9:
      case 21:
        NINE;
        break;
      case 10:
      case 22:
        TEN;
        break;
      case 11:
      case 23:
        ELEVEN;
        break;
      case 0:
      case 12:
        TWELVE;
        break;
    }

  }
  else if ((timeClient.getMinutes() < 35) && (timeClient.getMinutes() > 4))
  {
    PAST;
    DEBUG_PRINT(" past ");
    switch (timeClient.getHours()) {
      case 1:
      case 13:
        ONE;
        break;
      case 2:
      case 14:
        TWO;
        break;
      case 3:
      case 15:
        THREE;
        break;
      case 4:
      case 16:
        FOUR;
        break;
      case 5:
      case 17:
        FIVE;
        break;
      case 6:
      case 18:
        SIX;
        break;
      case 7:
      case 19:
        SEVEN;
        break;
      case 8:
      case 20:
        EIGHT;
        break;
      case 9:
      case 21:
        NINE;
        break;
      case 10:
      case 22:
        TEN;
        break;
      case 11:
      case 23:
        ELEVEN;
        break;
      case 0:
      case 12:
        TWELVE;
        break;
    }
  }
  else
  {
    // if we are greater than 34 minutes past the hour then display
    // the next hour, as we will be displaying a 'to' sign
    TO;
    DEBUG_PRINT(" to ");
    switch (timeClient.getHours()) {
      case 1:
      case 13:
        TWO;
        break;
      case 14:
      case 2:
        THREE;
        break;
      case 15:
      case 3:
        FOUR;
        break;
      case 4:
      case 16:
        FIVE;
        break;
      case 5:
      case 17:
        SIX;
        break;
      case 6:
      case 18:
        SEVEN;
        break;
      case 7:
      case 19:
        EIGHT;
        break;
      case 8:
      case 20:
        NINE;
        break;
      case 9:
      case 21:
        TEN;
        break;
      case 10:
      case 22:
        ELEVEN;
        break;
      case 11:
      case 23:
        TWELVE;
        break;
      case 0:
      case 12:
        ONE;
        break;
    }
  }
  applyMask(); // apply phrase mask to colorshift function

}

// show colorshift through the phrase mask. for each NeoPixel either show a color or show nothing!
void applyMask() {

  for (byte i = 0; i < 64; i++) {
    boolean masker = bitRead(mask, 63 - i); // bitread is backwards because bitRead reads rightmost digits first. could have defined the word masks differently
    uint8_t row = i / 8;
    uint8_t col = i % 8;
    switch (masker) {
      case 0:
        break;
      case 1:
        setCoilBack(row, col, polarity);
        break;
    }
    delay(tDelay);
  }

  // reset mask for next time
  mask = 0;
}

// move all letters to back
// effect=0: left to right, top to bottom
// effect=1: right to left, bottom to top
void resetLetters(uint8_t effect) {
   switch (effect) {
      case 0:
        for(int row=0; row<nRows; row++) {
          for(int col=0; col<nCols; col++) {
            if(currentState[row][col]) {
              setCoilFront(row, col, polarity);
            }
          }
        }
        break;
      case 1:
        for(int row=nRows-1; row>=0; row--) {
          for(int col=nCols-1; col>=0; col--) {
            if(currentState[row][col]) {
              setCoilFront(row, col, polarity);
            }
          }
        }
        break;
    }
}

void showSymbol(const bool symbol[8][8]) {
  for(int row=0; row<nRows; ++row) {
    for(int col=0; col<nCols; col++) {
      if(alternatePol) {
        polarity = (col+row) % 2;    // magnets have alternating polarity
      }
      if(pgm_read_byte(&symbol[row][col]) && !currentState[row][col]) {
        setCoilBack(row, col, polarity);
        delay(tDelay);  
      }
      else if(!pgm_read_byte(&symbol[row][col]) && currentState[row][col]) {
        setCoilFront(row, col, polarity);
        delay(tDelay);
      }
    }
  }
}

// set all letter to back
void resetAllLetters() {
  // push all taxels one by one from front to back
  for(int row=0; row<nRows; row++) {
    for(int col=0; col<nCols; col++) {
        setCoilFront(row, col, polarity);
        delay(tDelay);
    }
  }  
}


// test all taxels
void testDisplay() {
  // push all taxels one by one from back to front
  for(int row=0; row<nRows; row++) {
    for(int col=0; col<nCols; col++) {
      if(alternatePol) {
        polarity = (col+row) % 2;    // magnets have alternating polarity
      }      
      if(pushpull) {
        setCoilBackFront(row, col, polarity, !polarity);
        delay(tDelay);
      }
      else {
        setCoilBack(row, col, polarity);
        delay(tDelay);
      }
    }
  }
  delay(2000);

  // push all taxels one by one from front to back
  for(int row=0; row<nRows; row++) {
    for(int col=0; col<nCols; col++) {
      if(alternatePol) {
        polarity = (col+row) % 2;    // magnets have alternating polarity
      }
      if(pushpull) {
        setCoilBackFront(row, col, !polarity, polarity);
        delay(tDelay);
      }
      else {
        setCoilFront(row, col, polarity);
        delay(tDelay);
      }
    }
  }
  delay(2000);
}

// test all taxels
void testDisplay2() {
  // push all taxels one by one from back to front then immediately to back again
  for(int row=0; row<nRows; row++) {
    for(int col=0; col<nCols; col++) {
      if(alternatePol) {
        polarity = (col+row) % 2;    // magnets have alternating polarity
      }
      if(pushpull) {
        setCoilBackFront(row, col, polarity, !polarity);
        delay(tDelay);
        setCoilBackFront(row, col, !polarity, polarity);
        delay(tDelay);
      }
      else {
        setCoilBack(row, col, polarity);
        delay(tDelay);
        setCoilFront(row, col, polarity);
        delay(tDelay);
      }
    }
  }
}


// activate coils of front PCB
// row 0..7 -> device 0, out 1..8
// col 0..3 -> device 0, out 9..12
// col 4..7 -> device 1, out 1..4  
void setCoilFront(uint8_t row, uint8_t col, bool polarity) {
  DEBUG_PRINT("setting front coil: ");
  DEBUG_PRINT(row); DEBUG_PRINT(", "); DEBUG_PRINT(col); DEBUG_PRINT(" polarity: "); DEBUG_PRINTLN(polarity);
  
  uint8_t deviceRow;
  uint8_t deviceCol;
  
  byte brow;
  byte bcol;

  int regRow;
  int regCol;
  
  if (polarity) {  // if pol=1: row = H, col = L
    brow = 0b10;   // low side bit = 0, high side bit = 1
    bcol = 0b01;
  }
  else {          // if pol=0: row = L, col = H
    bcol = 0b10;
    brow = 0b01;
  }

  if(row<4) {                   // row 0..3 -> device 0, h-bridges 1..4 -> OP_CTRL1 bits 0..7
    deviceRow = 0;
    regRow = OP_CTRL1;
    brow = brow << (row*2);
  }
  else {                        // row 4..7 -> device 0, h-bridges 5..8 -> OP_CTRL2 bits 0..7
    deviceRow = 0;
    regRow = OP_CTRL2;
    brow = brow << ((row-4)*2);
  }

  if(col<4) {                   // col 0..3 -> device 0, h-bridges 9..12 -> OP_CTRL3 bits 0..7
    deviceCol = 0;
    regCol = OP_CTRL3;
    bcol = bcol << (col*2);
  }
  else {                        // col 4..7 -> device 1, h-bridges 1..4 -> OP_CTRL1 bits 0..7
    deviceCol = 1;
    regCol = OP_CTRL1;
    bcol = bcol << ((col-4)*2);
  }

  // enable outputs
  writeRegister(deviceRow, regRow, brow);  
  writeRegister(deviceCol, regCol, bcol);  
  delay(tPulse);
  // disable outputs
  writeRegister(deviceRow, regRow, 0);  
  writeRegister(deviceCol, regCol, 0);

  // change state variable
  currentState[row][col] = 0;
}


// activate coils of back PCB
// row 0..7 -> device 1, out 5..12
// col 0..7 -> device 2, out 1..8
void setCoilBack(uint8_t row, uint8_t col, bool polarity) {
  DEBUG_PRINT("setting back coil: ");
  DEBUG_PRINT(row); DEBUG_PRINT(", "); DEBUG_PRINT(col); DEBUG_PRINT(" polarity: "); DEBUG_PRINTLN(polarity);
  
  uint8_t deviceRow;
  uint8_t deviceCol;

  byte brow;
  byte bcol;

  int regRow;
  int regCol; 
  
  if (polarity) {  // if pol=1: row = H, col = L
    brow = 0b10;   // low side bit = 0, high side bit = 1
    bcol = 0b01;
  }
  else {          // if pol=0: row = L, col = H
    bcol = 0b10;
    brow = 0b01;
  }

  if(row<4) {                   // row 0..3 -> device 1, h-bridges 5..8 -> OP_CTRL2 bits 0..7
    deviceRow = 1;
    regRow = OP_CTRL2;
    brow = brow << (row*2);
  }
  else {                        // row 4..7 -> device 1, h-bridges 9..12 -> OP_CTRL3 bits 0..7
    deviceRow = 1;
    regRow = OP_CTRL3;
    brow = brow << ((row-4)*2);
  }

  if(col<4) {                   // col 0..3 -> device 2, h-bridges 1..4 -> OP_CTRL1 bits 0..7
    deviceCol = 2;
    regCol = OP_CTRL1;
    bcol = bcol << (col*2);
  }
  else {                        // col 4..7 -> device 2, h-bridges 5..8 -> OP_CTRL2 bits 0..7
    deviceCol = 2;
    regCol = OP_CTRL2;
    bcol = bcol << ((col-4)*2);
  }

  // enable outputs
  writeRegister(deviceRow, regRow, brow);  
  writeRegister(deviceCol, regCol, bcol);  
  delay(tPulse);
  // disable outputs
  writeRegister(deviceRow, regRow, 0);  
  writeRegister(deviceCol, regCol, 0);

  // change state variable
  currentState[row][col] = 1;
}


// activate coils of front and back PCB simultaneously
void setCoilBackFront(uint8_t row, uint8_t col, bool polarity_back, bool polarity_front) {
  DEBUG_PRINT("setting row, col: ");
  DEBUG_PRINT(row); DEBUG_PRINT(", "); DEBUG_PRINTLN(col); 

  uint8_t deviceRow_back;
  uint8_t deviceCol_back;
  uint8_t deviceRow_front;
  uint8_t deviceCol_front;
  
  byte brow_back;
  byte bcol_back;
  byte brow_front;
  byte bcol_front;

  int regRow_back;
  int regCol_back;
  int regRow_front;
  int regCol_front; 
  
  if (polarity_back) {  // if pol=1: row = H, col = L
    brow_back = 0b10;   // low side bit = 0, high side bit = 1
    bcol_back = 0b01;
  }
  else {          // if pol=0: row = L, col = H
    bcol_back = 0b10;
    brow_back = 0b01;
  }
  if (polarity_front) {  // if pol=1: row = H, col = L
    brow_front = 0b10;   // low side bit = 0, high side bit = 1
    bcol_front = 0b01;
  }
  else {          // if pol=0: row = L, col = H
    bcol_front = 0b10;
    brow_front = 0b01;
  }

  // back PCB
 if(row<4) {                   // row 0..3 -> device 1, h-bridges 5..8 -> OP_CTRL2 bits 0..7
    deviceRow_back = 1;
    regRow_back = OP_CTRL2;
    brow_back = brow_back << (row*2);
  }
  else {                        // row 4..7 -> device 1, h-bridges 9..12 -> OP_CTRL3 bits 0..7
    deviceRow_back = 1;
    regRow_back = OP_CTRL3;
    brow_back = brow_back << ((row-4)*2);
  }

  if(col<4) {                   // col 0..3 -> device 2, h-bridges 1..4 -> OP_CTRL1 bits 0..7
    deviceCol_back = 2;
    regCol_back = OP_CTRL1;
    bcol_back = bcol_back << (col*2);
  }
  else {                        // col 4..7 -> device 2, h-bridges 5..8 -> OP_CTRL2 bits 0..7
    deviceCol_back = 2;
    regCol_back = OP_CTRL2;
    bcol_back = bcol_back << ((col-4)*2);
  }

  // front PCB
  if(row<4) {                   // row 0..3 -> device 0, h-bridges 1..4 -> OP_CTRL1 bits 0..7
    deviceRow_front = 0;
    regRow_front = OP_CTRL1;
    brow_front = brow_front << (row*2);
  }
  else {                        // row 4..7 -> device 0, h-bridges 5..8 -> OP_CTRL2 bits 0..7
    deviceRow_front = 0;
    regRow_front = OP_CTRL2;
    brow_front = brow_front << ((row-4)*2);
  }

  if(col<4) {                   // col 0..3 -> device 0, h-bridges 9..12 -> OP_CTRL3 bits 0..7
    deviceCol_front = 0;
    regCol_front = OP_CTRL3;
    bcol_front = bcol_front << (col*2);
  }
  else {                        // col 4..7 -> device 1, h-bridges 1..4 -> OP_CTRL1 bits 0..7
    deviceCol_front = 1;
    regCol_front = OP_CTRL1;
    bcol_front = bcol_front << ((col-4)*2);
  }

  writeRegister(deviceRow_front,regRow_front,brow_front);  // enable outputs
  writeRegister(deviceCol_front,regCol_front,bcol_front);  // enable
  writeRegister(deviceRow_back,regRow_back,brow_back);  // enable outputs
  writeRegister(deviceCol_back,regCol_back,bcol_back);  // enable outputs
  delay(tPulse);
  writeRegister(deviceRow_front,regRow_front,0);  // disable outputs
  writeRegister(deviceCol_front,regCol_front,0);  // disable outputs
  writeRegister(deviceRow_back,regRow_back,0);  // disable outputs
  writeRegister(deviceCol_back,regCol_back,0);  // disable outputs
}

// Read from register 
uint16_t readRegister(uint8_t device, byte thisRegister) {
  DEBUG_PRINTLN("reading register...");

  byte inByte = 0;           // incoming byte from the SPI

  uint16_t result = 0;   // result to return
  
  // read command B14 = 1
  byte READ = 0b01000000;
  
  // adress bits are B13 to B8
  thisRegister = thisRegister;

  // now combine the address and the command into one byte
  uint16_t dataToSend = (thisRegister | READ) << 8;

  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE1));

  // take the chip select low to select the device:
  switch(device) {
    case 0: digitalWrite(CS1, LOW); break;
    case 1: digitalWrite(CS2, LOW); break;
    case 2: digitalWrite(CS3, LOW); break;
  }

  DEBUG_PRINT("device "); DEBUG_PRINTLN(device);
  DEBUG_PRINTLN("sending "); DEBUG_PRINTLNF(dataToSend, BIN);

  // send the device the register you want to read:
  result = SPI.transfer16(dataToSend);
  
  // take the chip select high to de-select:
  switch(device) {
    case 0: digitalWrite(CS1, HIGH); break;
    case 1: digitalWrite(CS2, HIGH); break;
    case 2: digitalWrite(CS3, HIGH); break;
  }

  SPI.endTransaction();

  delay(1);

  // return the result:
  DEBUG_PRINTLN("reply "); DEBUG_PRINTLNF(result,BIN);
  return (result);
}

//Sends a write command 
void writeRegister(uint8_t device, byte thisRegister, byte thisValue) {
  DEBUG_PRINTLN("writing register...");

  uint16_t result = 0;
  
  // now combine the register address and the command
  uint16_t dataToSend = (thisRegister << 8) | thisValue;

  DEBUG_PRINT("device "); DEBUG_PRINTLN(device);
  DEBUG_PRINT("sending "); DEBUG_PRINTLNF(dataToSend,BIN);

  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE1));
  
  // take the chip select low to select the device:
  switch(device) {
    case 0: digitalWrite(CS1, LOW); break;
    case 1: digitalWrite(CS2, LOW); break;
    case 2: digitalWrite(CS3, LOW); break;
  }

  result = SPI.transfer16(dataToSend); // Send data

  // take the chip select high to de-select:
  switch(device) {
    case 0: digitalWrite(CS1, HIGH); break;
    case 1: digitalWrite(CS2, HIGH); break;
    case 2: digitalWrite(CS3, HIGH); break;
  }

  SPI.endTransaction();
  delay(1);

  DEBUG_PRINT("reply "); DEBUG_PRINTLNF(result,BIN);

  // check for fault conditions
  byte fault = result >> 8;
  if(fault&0b10) {
    DEBUG_PRINTLN("FAULT: Overvoltage detected!");
  }
  if(fault&0b100) {
    DEBUG_PRINTLN("FAULT: Undervoltage detected!");
  }
  if(fault&0b1000) {
    DEBUG_PRINTLN("FAULT: Overcurrent detected!");
  }
  if(fault&0b10000) {
    DEBUG_PRINTLN("FAULT: Open load detected!");
  }
  if(fault&0b100000) {
    DEBUG_PRINTLN("FAULT: Overtemperature detected!");
  }
      
}
