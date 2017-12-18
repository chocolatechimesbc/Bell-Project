/*********************************************************************************************
      Title: MIDI LED Testing
      Created:          12/17/17
      Author(s):        Bryce Gammon, Martin Yong
      Description:      Recieves MIDI data from serial port from a range of E4(64) -
                        G5(79). Output controls striker and damper in sequence
      Version           1.3.2
      Reference(s)      http://www.instructables.com/id/Send-and-Receive-MIDI-with-Arduino/
                        Created by Amanda Ghassaei, July 2012
                        https://learn.sparkfun.com/tutorials/reed-switch-hookup-guide
                        Created by Jim Lindblom, May 2016

                        This program is free software; you can redistribute it and/or modify
                        it under the terms of the GNU General Public License as published by
                        the Free Software Foundation; either version 3 of the License, or
                        (at your option) any later version.
 *********************************************************************************************/


byte commandByte;
byte noteByte;
byte velocityByte;

int pinMin = 22;
int pinMax = 53;
int dMin = 22;      //lowest damper output pin
int dMax = 37;      //highest damper output pin
int sMin = 38;      //lowest striker output pin
int sMax = 53;      //highest striker output pin



void setup() {
  Serial.begin(115200);

  pinMode(4, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);

  for (int i = pinMin; i <= pinMax; i++)      //declare all of our pinModes
  {
    pinMode(i, OUTPUT);
  }

  for (int i = sMin; i <= sMax; i++)      //initialized all striker pins off
  {
    digitalWrite(i, LOW);
  }
  for (int i = dMin; i <= dMax; i++)      //initialized all damper pins off
  {
    digitalWrite(i, LOW);
  } 
}

void loop() {       //checks for data, delay .1s then turn off LED before checking again
  checkMIDI();
  //checkSwitch();
  delay(100);
}

void checkMIDI()
{ //function call to read incoming MIDI data and write to the corresponding LED
  do
  {
    if (Serial.available())
    {
      commandByte = Serial.read();         //read first byte
      noteByte = Serial.read();            //read next byte
      velocityByte = Serial.read();        //read final byte

      if (velocityByte == 100)     //checks for the note to be on
      {
        if (noteByte == 64) {       
          digitalWrite(22, HIGH);     //lower damper
          delay(100);                 
          digitalWrite(38, HIGH);     //fire and retract striker 
          delay(160);
          digitalWrite(38, LOW);      //damper stays on until note is off
        }
        if (noteByte == 65) {
          digitalWrite(23, HIGH); //F4
          delay(100);
          digitalWrite(39, HIGH);
          delay(160);
          digitalWrite(39, LOW);
        }
        if (noteByte == 66) {
          digitalWrite(24, HIGH); //Gb/F#4
          delay(100);
          digitalWrite(40, HIGH);
          delay(160);
          digitalWrite(40, LOW);
        }
        if (noteByte == 67) {
          digitalWrite(25, HIGH); //G4
          delay(100);
          digitalWrite(41, HIGH);
          delay(160);
          digitalWrite(41, LOW);
        }
        if (noteByte == 68) {
          digitalWrite(26, HIGH); //Ab/G#4
          delay(100);
          digitalWrite(42, HIGH);
          delay(160);
          digitalWrite(42, LOW);
        }
        if (noteByte == 69) {
          digitalWrite(27, HIGH); //A4
          delay(100);
          digitalWrite(43, HIGH);
          delay(160);
          digitalWrite(43, LOW);
        }
        if (noteByte == 70) {
          digitalWrite(28, HIGH); //Bb/A#4
          delay(100);
          digitalWrite(44, HIGH);
          delay(160);
          digitalWrite(44, LOW);
        }
        if (noteByte == 71) {
          digitalWrite(29, HIGH); //B4
          delay(100);
          digitalWrite(45, HIGH);
          delay(160);
          digitalWrite(45, LOW);
        }
        if (noteByte == 72) {
          digitalWrite(30, HIGH); //C5
          delay(100);
          digitalWrite(46, HIGH);
          delay(160);
          digitalWrite(46, LOW);
        }
        if (noteByte == 73) {
          digitalWrite(31, HIGH); //Db/C#5
          delay(100);
          digitalWrite(47, HIGH);
          delay(160);
          digitalWrite(47, LOW);
        }
        if (noteByte == 74) {
          digitalWrite(32, HIGH); //D5
          delay(100);
          digitalWrite(48, HIGH);
          delay(160);
          digitalWrite(48, LOW);
        }
        if (noteByte == 75) {
          digitalWrite(33, HIGH); //Eb/D#5
          delay(100);
          digitalWrite(49, HIGH);
          delay(160);
          digitalWrite(49, LOW);
        }
        if (noteByte == 76) {
          digitalWrite(34, HIGH); //E5
          delay(100);
          digitalWrite(50, HIGH);
          delay(160);
          digitalWrite(50, LOW);
        }
        if (noteByte == 77) {
          digitalWrite(35, HIGH); //F5
          delay(100);
          digitalWrite(51, HIGH);
          delay(160);
          digitalWrite(51, LOW);
        }
        if (noteByte == 78) {
          digitalWrite(36, HIGH); //Gb/F#5
          delay(100);
          digitalWrite(52, HIGH);
          delay(160);
          digitalWrite(52, LOW);
        }
        if (noteByte == 79) {
          digitalWrite(37, HIGH); //G5
          delay(100);
          digitalWrite(53, HIGH);
          delay(160);
          digitalWrite(53, LOW);
        }
      }
      else if (velocityByte == 0)     //turns off damper once note is off
      {
        if (noteByte == 64) {
          digitalWrite(22, LOW); //E4
        }
        if (noteByte == 65) {
          digitalWrite(23, LOW); //F4
        }
        if (noteByte == 66) {
          digitalWrite(24, LOW); //Gb/F#4
        }
        if (noteByte == 67) {
          digitalWrite(25, LOW); //G4
        }
        if (noteByte == 68) {
          digitalWrite(26, LOW); //Ab/G#4
        }
        if (noteByte == 69) {
          digitalWrite(27, LOW); //A4
        }
        if (noteByte == 70) {
          digitalWrite(28, LOW); //Bb/A#4
        }
        if (noteByte == 71) {
          digitalWrite(29, LOW); //B4
        }
        if (noteByte == 72) {
          digitalWrite(30, LOW); //C5
        }
        if (noteByte == 73) {
          digitalWrite(31, LOW); //Db/C#5
        }
        if (noteByte == 74) {
          digitalWrite(32, LOW); //D5
        }
        if (noteByte == 75) {
          digitalWrite(33, LOW); //Eb/D#5
        }
        if (noteByte == 76) {
          digitalWrite(34, LOW); //E5
        }
        if (noteByte == 77) {
          digitalWrite(35, LOW); //F5
        }
        if (noteByte == 78) {
          digitalWrite(36, LOW); //Gb/F#5
        }
        if (noteByte == 79) {
          digitalWrite(37, LOW); //G5
        }
      }
    }
  }
  while (Serial.available() > 2);//when at least three bytes available
}

/*void checkSwitch()      //checks the status of the reed switch.
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
} */
