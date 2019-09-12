#include "US_100.h"
//use UART to read tempeature
//   US-100 ARDUINO
//Pin  TX     TX(P1)
//Pin  Rx     Rx(P0)
US100 mysonic1(100);
void setup() {
Serial.begin(9600);
}

void loop() {
Serial.println(mysonic1.get_Temperature());
}
