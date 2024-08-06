#include <Deneyap_Multimetre.h>

Multimeter multimetre

#define Vpin A1 /*kullanilacak pin*/

float R1 = 1000 /*--1K ohm -- gerilim bolucu direnc degeri*/;
float Vin = 3.36 /*devreye verilen volt degeri*/;

void setup() {
  Serial.begin(115200);
  pinMode(Vpin, INPUT);
}

void loop() {
  float direncdegeri = readOhm(Vpin, Vin, R1);
  Serial.println("Direnc Degeri: " + String(direncdegeri));
  delay(100);
}
