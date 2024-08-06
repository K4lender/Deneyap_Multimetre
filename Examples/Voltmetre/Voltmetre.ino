#include <Deneyap_Multimetre.h>

Multimeter multimetre

#define Vpin A1 /*kullanilacak pin*/

float R1 = 4.609; /*gerilim bolucu direnc degeri*/
float R2 = 0.977; /*gerilimini olcmek istediginiz direnc degeri*/
float Vin = 3.361; /*gerilim bolucu voltajı*/

void setup() {
  Serial.begin(115200);
  pinMode(Vpin, INPUT);
}

void loop() {
  float voltdegeri = readVolt(Vpin, Vin, R1, R2);
  Serial.println("Volt Degeri: " + String(voltdegeri));
  delay(100);
}
