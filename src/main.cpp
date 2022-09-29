/*
  Control MCP4922 dual output voltages with Arduino Uno
  Each DAC has 12-bit range (0-4095)

  @author   Lukas Vasadi
  @date     17 December 2020
  @version  1.0
*/

#include <Arduino.h>
#include <SPI.h>

const int CS = 10;  // chip select pin
const int LDAC = 9; // latch pin

float dacOutA; // output A
float dacOutB; // output B

void writeMCP4922(uint8_t, uint16_t); // function prototype

void setup()
{
  // initialize pins
  pinMode(CS, OUTPUT);
  pinMode(LDAC, OUTPUT);

  digitalWrite(CS, HIGH);
  digitalWrite(LDAC, HIGH);

  // initialize SPI communication
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);

  // initialize serial communication
  Serial.begin(115200);
}

void loop()
{
  writeMCP4922(0, 4095); // set DAC A to 5V
  writeMCP4922(1, 1638); // set DAC B to 2V

  // the latch pin coordinates both channels
  digitalWrite(LDAC, LOW);
  delay(100);
  digitalWrite(LDAC, HIGH);

  // read output from DAC A
  Serial.print("DAC output A: ");
  Serial.println(analogRead(A0));

  // read output from DAC B
  Serial.print("DAC output B: ");
  Serial.print(analogRead(A1));
}

void writeMCP4922(uint8_t dac, uint16_t data)
{
  if (!dac)
    data |= 0x7000; // 0x7000 == 0b0111000000000000
  else
    data |= 0xF000; // 0xF000 == 0b1111000000000000

  SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0));

  digitalWrite(CS, LOW);
  SPI.transfer16(data);
  digitalWrite(CS, HIGH);

  SPI.endTransaction();
}