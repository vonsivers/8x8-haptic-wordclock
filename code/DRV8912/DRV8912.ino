/*
 * DRV8912 test
 * 
 * wiring: MCU - DRV
 * MISO - pin 7
 * MOSI - pin 5
 * SCLK - pin 20
 * SS - pin 19
 * 
 * on ESP32: SCLK = 18, MISO = 19, MOSI = 23, SS = 5
 */

// the sensor communicates using SPI, so include the library:
#include <SPI.h>

#define VSPI_MISO   MISO
#define VSPI_MOSI   MOSI
#define VSPI_SCLK   SCK
#define VSPI_SS     SS

#define nSLEEP  21

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

// number of rows and columns
// out 1-2 connected to col
// out 3-4 connected to row
const uint8_t nRows = 2;
const uint8_t nCols = 2;

const int tPulse = 200;   // pulse duration in ms


void setup() {

  Serial.begin(115200);

  // start the SPI library:
  SPI.begin(VSPI_SCLK, VSPI_MISO, VSPI_MOSI, VSPI_SS);

  // initalize the pins
  pinMode(VSPI_SS, OUTPUT);
  pinMode(nSLEEP, OUTPUT);
  digitalWrite(nSLEEP, HIGH); // nSLEEP pin needs to be high to enable driver

  // give the sensor time to set up:
  delay(1000);

  // clear all faults
  //writeRegister(CONFIG,0b00000001);
  
}

void loop() {

  // move all taxels one by one to front
  for(int row=0; row<nRows; row++) {
    for(int col=0; col<nCols; col++) {
      moveTX(row, col, 1);
      delay(2000);
    }
  }

  // move all taxels one by one to back
  for(int row=0; row<nRows; row++) {
    for(int col=0; col<nCols; col++) {
      moveTX(row, col, 0);
      delay(2000);
    }
  }

}

//Read from register 
uint16_t readRegister(byte thisRegister) {
  Serial.println("reading register");

  byte inByte = 0;           // incoming byte from the SPI

  uint16_t result = 0;   // result to return

  //Serial.println("register to write to");
  //Serial.print(thisRegister, BIN);
  //Serial.println();
  
  // read command B14 = 1
  byte READ = 0b01000000;
  
  // adress bits are B13 to B8
  thisRegister = thisRegister;

  // now combine the address and the command into one byte
  uint16_t dataToSend = (thisRegister | READ) << 8;

  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE1));

  // take the chip select low to select the device:
  digitalWrite(VSPI_SS, LOW);

  //Serial.println("sending bytes");
  //Serial.println(dataToSend, BIN);

  // send the device the register you want to read:
  result = SPI.transfer16(dataToSend);
  
  // take the chip select high to de-select:
  digitalWrite(VSPI_SS, HIGH);

  SPI.endTransaction();

  delay(100);

  // return the result:
  return (result);
}

//Sends a write command 
void writeRegister(byte thisRegister, byte thisValue) {

  // now combine the register address and the command
  uint16_t dataToSend = (thisRegister << 8) | thisValue;
  //dataToSend = dataToSend | thisValue;

  Serial.println("sending...");
  Serial.println(dataToSend,BIN);

  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE1));
  
  // take the chip select low to select the device:
  digitalWrite(VSPI_SS, LOW);

  SPI.transfer16(dataToSend); // Send data

  // take the chip select high to de-select:
  digitalWrite(VSPI_SS, HIGH);

  SPI.endTransaction();
  delay(100);
}

// move taxel to position
void moveTX(uint8_t row, uint8_t col, bool pos) {

  byte brow = 0;
  byte bcol = 0;
  
  if (pos) {  // if pos=1: row = H, col = L
    brow = 0b10;   // low side bit = 0, high side bit = 1
    bcol = 0b01;
  }
  else {
    bcol = 0b10;
    brow = 0b01;
  }

  // cols are on h-bridges 1-2 (bits 0-3), rows on 3-4 (bits 4-7)
  bcol = bcol << col*2;
  brow = brow << (4+row*2);
  
  byte value = bcol | brow;    // combine bits for row and column
  
  writeRegister(OP_CTRL1,value);  // enable outputs
  delay(tPulse);
  //Serial.println(readRegister(IC_STAT),BIN);
  writeRegister(OP_CTRL1,0b0);  // disable outputs
}
