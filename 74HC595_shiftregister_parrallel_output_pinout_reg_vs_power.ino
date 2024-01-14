//Shift register tpic595 vs hc595
//https://www.instructables.com/How-Shift-Registers-Work-74HC595/

/*
//Power/ TPIC6C595:
//Pin connected to ST_CP of TPIC6C595
int latchPin = 8;
//Pin connected to SH_CP of TPIC6C595
int clockPin = 9;
////Pin connected to DS of TPIC6C595
int dataPin = 10;
*/

//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 9;
////Pin connected to DS of 74HC595
int dataPin = 10;

//STANDARD 74HC595:
//byte dataToTransfer = 0b00000001;//== Qa on MSBFIRST, Qh on LSBFIRST

//POWER HC/TPIC6C595:

//byte dataToTransfer = 0b11111111;
byte dataToTransfer = 0b00000001;//== drain0 on MSBFIRST, drain7 on LSBFIRST

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  //ground latchPin and hold low for as long as you are transmitting
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, dataToTransfer);
  //shiftOut(dataPin, clockPin, MSBFIRST, dataToTransfer);
  //return the latch pin high to signal chip that it
  //no longer needs to listen for information
  digitalWrite(latchPin, HIGH);
}

void loop() {
}
