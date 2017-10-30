/********************************************************************************
 *    Title: MIDI LED Testing
 *    Created:          10/19/17
 *    Author(s):        Bryce Gammon, Martin Yong
 *    Description:      Recieves MIDI data from serial port from a range of E3(64) -  
 *                      F#4(78). Output turns on LED
 *    Version           1.0.0
 *    Reference         http://www.instructables.com/id/Send-and-Receive-MIDI-with-Arduino/
 *                      Created by Amanda Ghassaei
 ********************************************************************************/

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
#include <EEPROM.h>       // EEPROM allows us to store/ retrieve MIDI information when the serial port is in use

byte commandByte;
byte noteByte;
byte velocityByte;
//byte count = 0;
byte noteOn = 144;
//byte checker;
int pinMin = 22;      //lowest output pin
int pinMax = 53;      //highest output pin



void setup(){
  Serial.begin(115200);

  for(int i = pinMin; i <= pinMax; i++)       //declare all of our pinModes
  {
    pinMode(i,OUTPUT);
  }
 
  for(int a = pinMin; a <= pinMax; a++)       //initialized all pins off
  {
    digitalWrite(a,LOW);
  }
}

void checkMIDI()
{                   //function call to read incoming MIDI data and write to the corresponding LED
  do
  {
    if (Serial.available())
    {
      commandByte = Serial.read();//read first byte
      noteByte = Serial.read();//read next byte
      velocityByte = Serial.read();//read final byte
      
      /*if(commandByte == 122)  //Check for command to print EEPROM
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
      count++; */
      if (commandByte == noteOn)
      {           
        if (noteByte == 64 && velocityByte > 0){
          digitalWrite(22,HIGH);//E4
        }
        if (noteByte == 65 && velocityByte > 0){
          digitalWrite(23,HIGH);//F4
        }
        if (noteByte == 66 && velocityByte > 0){
          digitalWrite(24,HIGH);//Gb/F#4
        }
        if (noteByte == 67 && velocityByte > 0){
          digitalWrite(25,HIGH);//G4
        }
        if (noteByte == 68 && velocityByte > 0){
          digitalWrite(26,HIGH);//Ab/G#4
        }
        if (noteByte == 69 && velocityByte > 0){
          digitalWrite(27,HIGH);//A4
        }
        if (noteByte == 70 && velocityByte > 0){
          digitalWrite(28,HIGH);//Bb/A#4
        }
        if (noteByte == 71 && velocityByte > 0){
          digitalWrite(29,HIGH);//B4
        }
        if (noteByte == 72 && velocityByte > 0){
          digitalWrite(30,HIGH);//C5
        }
        if (noteByte == 73 && velocityByte > 0){
          digitalWrite(31,HIGH);//Db/C#5
        }
        if (noteByte == 74 && velocityByte > 0){
          digitalWrite(32,HIGH);//D5
        }
        if (noteByte == 75 && velocityByte > 0){
          digitalWrite(33,HIGH);//Eb/D#5
        }
        if (noteByte == 76 && velocityByte > 0){
          digitalWrite(34,HIGH);//E5
        }
        if (noteByte == 77 && velocityByte > 0){
          digitalWrite(35,HIGH);//F5
        }
        if (noteByte == 78 && velocityByte > 0){
          digitalWrite(36,HIGH);//Gb/F#5
        }
        if (noteByte == 79 && velocityByte > 0){
          digitalWrite(37,HIGH);//G5
        }
      }
      //EEPROM.write(1024, count);  //Store count values in EEPROM memory for retrieval when board Resets
    }
  } 
  while (Serial.available() > 2);//when at least three bytes available
}


    

void loop(){
  checkMIDI();
  delay(100);
  digitalWrite(22,LOW);
  digitalWrite(23,LOW);
  digitalWrite(24,LOW);
  digitalWrite(25,LOW);
  digitalWrite(26,LOW);
  digitalWrite(27,LOW);
  digitalWrite(28,LOW);
  digitalWrite(29,LOW);
  digitalWrite(30,LOW);
  digitalWrite(31,LOW);
  digitalWrite(32,LOW);
  digitalWrite(33,LOW);
  digitalWrite(34,LOW);
  digitalWrite(35,LOW);
  digitalWrite(36,LOW);
  digitalWrite(37,LOW);
  
}
