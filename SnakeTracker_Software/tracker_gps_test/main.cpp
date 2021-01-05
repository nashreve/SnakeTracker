#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GPS_PWR 15
#define GPS_ON 16
#define LORA_SWITCH_PWR 17

void setup() {
  Serial.begin(4800);
  delay(1);
  Serial.println("\nMicrochip ATSAMR34 Xplained Pro 2019 Georgi Angelov");
  pinMode(LED, OUTPUT);
  pinMode(GPS_PWR, OUTPUT);
  pinMode(GPS_ON, OUTPUT);
  pinMode(LORA_SWITCH_PWR, OUTPUT);
  Serial.println("SETUP");
  //char cold_start[29] = "$PSRF101,0,0,0,0,0,0,12,4*10";
  //Serial.write(cold_start);
}

void powerGPSOn(){
  digitalWrite(GPS_PWR, 0);
  digitalWrite(GPS_ON, 0);
  void sendColdStartMessage();
}

void sendColdStartMessage(){
  // unsure if required, gps appears to enter cold start by default
}

bool isPosData(const char *str)
{
    const char *posCode = "$GNGGA";
    size_t lenpre = strlen(posCode),
           lenstr = strlen(str);
    return lenstr < lenpre ? false : memcmp(posCode, str, lenpre) == 0;
}

void getPosition(char *posDataStr){
  bool positionAcquired = false;
  String incomingSentence;
  posDataStr = "";
  char *copyChar = "a";
  int i = 0;
  ulong startTime = millis();
  ulong currTime;
  digitalWrite(LED, 0);
  while(!positionAcquired){
    currTime = millis();
    if(currTime - startTime > 1000){
      positionAcquired = true;
      posDataStr = "Failed: Timeout";
    }
    if(Serial.available() > 0){
      incomingSentence = Serial.readStringUntil(0x0D);
      Serial.print(incomingSentence);
      if(isPosData(incomingSentence.c_str())){
        // scan forward to time stamp
        while(incomingSentence[i++] != ','){}
        // do we need to save the timestamp or can we get it from clock?
        // scan forward to latitude
        while(incomingSentence[i++] != ','){}
        // get latitude
        while(incomingSentence[i] != ','){
          copyChar[0] = incomingSentence[i];
          strcat(posDataStr, copyChar);
          i++;
        }
        i++;
        // get N/S indicator
        while(incomingSentence[i] != ','){
          copyChar[0] = incomingSentence[i];
          strcat(posDataStr, copyChar);
          i++;
        }
        i++;
        // get longitude
        while(incomingSentence[i] != ','){
          copyChar[0] = incomingSentence[i];
          strcat(posDataStr, copyChar);
          i++;
        }
        i++;
        // get E/W inducator
        while(incomingSentence[i] != ','){
          copyChar[0] = incomingSentence[i];
          strcat(posDataStr, copyChar);
          i++;
        }
      }
    }
  }
}

void powerGPSOff(){
  digitalWrite(GPS_ON, 1);
  digitalWrite(GPS_PWR, 1);
}

void loop() {
  char *posDataStr;
  //powerGPSOn();
  //sendColdStartMessage();
  getPosition(posDataStr);
  // DEBUG: print posDataStr
  Serial.println(posDataStr);
  //powerGPSOff();
  // LoRa stuff goes here
  digitalWrite(LED, 1);
  delay(1000);
}