#include <SPI.h>

uint8_t displayByte = 0b11111111;

void setup() {
  // put your setup code here, to run once:
  SPI.begin();
  SPI.setClockDivider(82);
  
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(5,LOW);
  digitalWrite(6, HIGH);

  SPI.transfer(displayByte);
  
  digitalWrite(5,HIGH);
  delay(100);
  digitalWrite(6, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  delay(100);
  digitalWrite(6, LOW);
  displayByte -= 1;
  digitalWrite(5,LOW);
  digitalWrite(6, HIGH);

  SPI.transfer(displayByte);
  
  digitalWrite(5,HIGH);
  delay(100);
  digitalWrite(6, LOW);
  
  delay(100);
  digitalWrite(6, HIGH);
  
}
