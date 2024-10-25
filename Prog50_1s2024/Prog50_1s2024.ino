/*
   Código demonstrativo para a aula de Sistemas Embarcados,
   Curso de Ciência da Computação e Engenharia da Computação
   EEP.
*/
#include "RTClib.h"

RTC_DS1307 rtc;

void setup() {

  Serial.begin(9600);

  rtc.begin();

}

void loop() {

  DateTime agora = rtc.now();

  Serial.print("Data: ");
  Serial.print(agora.day(), DEC);
  Serial.print("/");
  Serial.print(agora.month(), DEC);
  Serial.print("/");
  Serial.print(agora.year(), DEC);
  Serial.print(" e ");
  Serial.print("Hora: ");
  Serial.print(agora.hour(), DEC);
  Serial.print(":");
  Serial.print(agora.minute(), DEC);
  Serial.print(":");
  Serial.print(agora.second(), DEC);
  Serial.println();

  Serial.print("Data (unixtime) desde 01/01/1970 = ");
  Serial.print(agora.unixtime());
  Serial.print(" segundos ou ");
  Serial.print(agora.unixtime() / 86400L);
  Serial.println(" dias");

  Serial.println();

  delay(3000);

}