/*Receive MIDI and check if note = 60
By Amanda Ghassaei
July 2012
<a href="https://www.instructables.com/id/Send-and-Receive-MIDI-with-Arduino/">

https://www.instructables.com/id/Send-and-Receive-...>

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

*/
#include <EEPROM.h>

byte commandByte;
byte noteByte;
byte velocityByte;
byte count = 0;
byte noteOn = 144;
byte checker;

//light up led at pin 13 when receiving noteON message with note = 60

void setup(){
  Serial.begin(115200);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);
}

void checkMIDI(){
  do{
    if (Serial.available()){
      commandByte = Serial.read();//read first byte
      noteByte = Serial.read();//read next byte
      velocityByte = Serial.read();//read final byte
      if(commandByte == 122)  //Check for command to print EEPROM
      {
        count = EEPROM.read(1024);  //Check EEPROM for # of items to print
        Serial.println("Command");
        for(int j = 0; j < count; j++) //Check Command values
        {  
          checker = EEPROM.read(j);     
          Serial.print(checker, DEC);
          Serial.print(" ");
        }
        Serial.println("Note");  
        for(int j = 200; j < (count + 200); j++) //Check Note values
        {  
          checker = EEPROM.read(j);     
          Serial.print(checker, DEC);
          Serial.print(" ");
        }
        Serial.println("Velocity");
        for(int j = 400; j < (count+400); j++) //Check Velocity Values
          checker = EEPROM.read(j);     
          Serial.print(checker, DEC);
          Serial.print(" ");
        }
        for (int i = 0 ; i < EEPROM.length() ; i++) {  //Clear EEPROM memory space
        EEPROM.write(i, 0);
        count = 0;  //Reset Count to 0
        }
      }
      EEPROM.write(count + 0, commandByte);
      EEPROM.write(count + 200, noteByte);
      EEPROM.write(count + 400, commandByte);
      count++;
      if (commandByte == noteOn){//if note on message
        //check if note == 60 and velocity > 0
        if (noteByte == 60 && velocityByte > 0){
          digitalWrite(13,HIGH);//turn on led
        }
        /*
        if (noteByte == 61 && velocityByte > 0){
          digitalWrite(12,HIGH);//turn on led
        }
        if (noteByte == 62 && velocityByte > 0){
          digitalWrite(10,HIGH);//turn on led
        }
        if (noteByte == 63 && velocityByte > 0){
          digitalWrite(9,HIGH);//turn on led
        }
        if (noteByte == 64 && velocityByte > 0){
          digitalWrite(8,HIGH);//turn on led
        }
        if (noteByte == 65 && velocityByte > 0){
          digitalWrite(7,HIGH);//turn on led
        }
        if (noteByte == 66 && velocityByte > 0){
          digitalWrite(6,HIGH);//turn on led
        }
        if (noteByte == 67 && velocityByte > 0){
          digitalWrite(5,HIGH);//turn on led
        }
        */
      }
      EEPROM.write(1024, count);  //Store count values in EEPROM memory for retrieval when board Resets
    }
  while (Serial.available() > 2);//when at least three bytes available
}
    

void loop(){
  checkMIDI();
  delay(100);
  digitalWrite(13,LOW);//turn led off
  //digitalWrite(12,LOW);
 // digitalWrite(11,LOW);
  //digitalWrite(10,LOW);
  //digitalWrite(9,LOW);
  //digitalWrite(8,LOW);
  //digitalWrite(7,LOW);
 // digitalWrite(6,LOW);
 // digitalWrite(5,LOW);
}
