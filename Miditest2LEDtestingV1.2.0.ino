/*********************************************************************************************
 *    Title: MIDI LED Testing
 *    Created:          10/19/17
 *    Author(s):        Bryce Gammon, Martin Yong
 *    Description:      Recieves MIDI data from serial port from a range of E4(64) -  
 *                      G5(79). Output turns on LED
 *    Version           1.2.0
 *    Reference(s)      http://www.instructables.com/id/Send-and-Receive-MIDI-with-Arduino/
 *                      Created by Amanda Ghassaei, July 2012
 *                      https://learn.sparkfun.com/tutorials/reed-switch-hookup-guide
 *                      Created by Jim Lindblom, May 2016
 *                      
 *                      This program is free software; you can redistribute it and/or modify
 *                      it under the terms of the GNU General Public License as published by
 *                      the Free Software Foundation; either version 3 of the License, or
 *                      (at your option) any later version.
 *********************************************************************************************/

#include <EEPROM.h>       // EEPROM allows us to store/ retrieve MIDI information when the serial port is in use

byte commandByte;
byte noteByte;
byte velocityByte;
//byte count = 0;
//byte noteOn = 144;
//byte noteOff = 128;
//byte checker;
int pinMin = 22;    
int pinMax = 53;
int sMin = 22;      //lowest striker output pin
int sMax = 37;      //highest striker output pin
int dMin = 38;      //lowest damper output pin
int dMax = 53;      //highest damper output pin
int clockcount = 0;


void setup(){
  Serial.begin(115200);

  pinMode(4,INPUT_PULLUP);
  pinMode(13, OUTPUT);

  for(int i = pinMin; i <= pinMax; i++)       //declare all of our pinModes
  {
    pinMode(i,OUTPUT);
  }
 
  for(int i = sMin; i <= sMax; i++)       //initialized all striker pins off
  {
    digitalWrite(i,LOW);
  }
  digitalWrite(38, HIGH);
  /*for(int i = dMin; i <= dMax; i++)       //initialized all damper pins on
  {
    digitalWrite(i,HIGH);
  } */
}

void loop(){        //checks for data, delay .1s then turn off LED before checking again
  checkMIDI();
  checkSwitch();
  delay(100);
  //offLED();
  
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
 
      if (velocityByte == 100)     //turns on LED
      {           
        if (noteByte == 64){
          digitalWrite(22,HIGH);//E4
        }
        if (noteByte == 65){
          digitalWrite(23,HIGH);//F4
        }
        if (noteByte == 66){
          digitalWrite(24,HIGH);//Gb/F#4
        }
        if (noteByte == 67){
          digitalWrite(25,HIGH);//G4
        }
        if (noteByte == 68){
          digitalWrite(26,HIGH);//Ab/G#4
        }
        if (noteByte == 69){
          digitalWrite(27,HIGH);//A4
        }
        if (noteByte == 70){
          digitalWrite(28,HIGH);//Bb/A#4
        }
        if (noteByte == 71){
          digitalWrite(29,HIGH);//B4
        }
        if (noteByte == 72){
          digitalWrite(30,HIGH);//C5
        }
        if (noteByte == 73){
          digitalWrite(31,HIGH);//Db/C#5
        }
        if (noteByte == 74){
          digitalWrite(32,HIGH);//D5
        }
        if (noteByte == 75){
          digitalWrite(33,HIGH);//Eb/D#5
        }
        if (noteByte == 76){
          digitalWrite(34,HIGH);//E5
        }
        if (noteByte == 77){
          digitalWrite(35,HIGH);//F5
        }
        if (noteByte == 78){
          digitalWrite(36,HIGH);//Gb/F#5
        }
        if (noteByte == 79){
          digitalWrite(37,HIGH);//G5
        }
      }
    else if (velocityByte == 0)     //turns off LED
      {           
        if (noteByte == 64){
          digitalWrite(22,LOW);//E4
        }
        if (noteByte == 65){
          digitalWrite(23,LOW);//F4
        }
        if (noteByte == 66){
          digitalWrite(24,LOW);//Gb/F#4
        }
        if (noteByte == 67){
          digitalWrite(25,LOW);//G4
        }
        if (noteByte == 68){
          digitalWrite(26,LOW);//Ab/G#4
        }
        if (noteByte == 69){
          digitalWrite(27,LOW);//A4
        }
        if (noteByte == 70){
          digitalWrite(28,LOW);//Bb/A#4
        }
        if (noteByte == 71){
          digitalWrite(29,LOW);//B4
        }
        if (noteByte == 72){
          digitalWrite(30,LOW);//C5
        }
        if (noteByte == 73){
          digitalWrite(31,LOW);//Db/C#5
        }
        if (noteByte == 74){
          digitalWrite(32,LOW);//D5
        }
        if (noteByte == 75){
          digitalWrite(33,LOW);//Eb/D#5
        }
        if (noteByte == 76){
          digitalWrite(34,LOW);//E5
        }
        if (noteByte == 77){
          digitalWrite(35,LOW);//F5
        }
        if (noteByte == 78){
          digitalWrite(36,LOW);//Gb/F#5
        }
        if (noteByte == 79){
          digitalWrite(37,LOW);//G5
        }
      }
    }
  } 
  while (Serial.available() > 2);//when at least three bytes available
}

void checkSwitch()      //checks the status of the reed switch.
{
  int l = digitalRead(4); // Read the state of the switch
  //Serial.println(l);
  //delay(100);
  if (l == LOW) // If the pin reads low, the switch is closed.
  {
    //Serial.println("Switch closed");
    digitalWrite(13, HIGH); // Turn the LED on
  }
  else
  {
    digitalWrite(13, LOW); // Turn the LED off
  }
}


void offLED()         // turns off LEDS for each pin
{
  for(int i = sMin; i <= sMax; i++)       //initialized all pins off
  {
    digitalWrite(i,LOW);
  }
  digitalWrite(38,HIGH);
  
}
