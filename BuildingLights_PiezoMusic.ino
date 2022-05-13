/*
  This code will:

   - show proposed building illumination colors
   - play music on the piezo buzzer based on a timer
   - play a particular note when a flower is pressed

   When the flowers are not interacted with, the buildings will play music patterns and display colors based on a timer.
   If the flowers are being touched, this will override the building timer and just play the note corresponding to the flower.

   These are the notes used for the music when the buildings are running on a timer:

   NOTE_D6 1175
   NOTE_F 1480
   NOTE_A 1760
   NOTE_B 1976
   NOTE_D7 2349

   6 May 2022
   Sarva Kompella
   Sophie Lowen
   Carmen Vargas
*/

#include <ADCTouch.h>
#include "pitches.h"

// initialize pins

// RGB LED 1
int redPin1 = 7;
int greenPin1 = 8;
int bluePin1 = 9;

// RGB LED 2
int redPin2 = 10;
int greenPin2 = 11;
int bluePin2 = 12;

// piezo buzzer
int speakerPin = 5;

// timer
unsigned long startTime;
unsigned long currentTime;

// set intervals to trigger different light / music patterns
int intervalLength = 500;
int interval1 = (intervalLength * 5);
int interval2 = (intervalLength * 10);
int interval3 = (intervalLength * 15);
int interval4 = (intervalLength * 20);
int interval5 = (intervalLength * 25);
int interval6 = (intervalLength * 30);
int interval7 = (intervalLength * 35);
int interval8 = (intervalLength * 43);

// references values to remove offset for the flower sensors
int ref0;
int ref1;
int ref2;
// int ref3;


void setup() {

  // start the timer
  startTime = millis();

  // establish the pins
  pinMode(redPin1, OUTPUT);
  pinMode(greenPin1, OUTPUT);
  pinMode(bluePin1, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(bluePin2, OUTPUT);
  pinMode(speakerPin, OUTPUT);

  // reference values for the flowers
  ref0 = ADCTouch.read(A0, 500);
  ref1 = ADCTouch.read(A1, 500);
  ref2 = ADCTouch.read(A2, 500);
  //  ref3 = ADCTouch.read(A4, 500);

  Serial.begin(9600);
}

void loop() {

  // get the touch readings for each capacitor
  int value0 = ADCTouch.read(A0);
  int value1 = ADCTouch.read(A1);
  int value2 = ADCTouch.read(A2);
  // int value3 = ADCTouch.read(A4);

  // remove the offset
  value0 -= ref0;
  value1 -= ref1;
  value2 -= ref2;
  //  value3 -= ref3;

  // use  value of capacitor as a boolean
  int buttonState1 = (value0 > 40) ;
  int buttonState2 = (value1 > 40) ;
  int buttonState3 = (value2 > 40) ;
  // int buttonState4 = (value3 > 40) ;

  // get the current time
  currentTime = millis();

  if (buttonState1 == 1) {

    //flower #1
    Serial.println("pressed 1");
    //iterate over notes of melody
    tone(speakerPin, NOTE_E6);

    // purple pulse pattern - LED 1
    for (int j = 0; j < 3; j++) {
      for (int i = 0; i < 100; i += 10) {
        analogWrite(redPin1, i);
        analogWrite(bluePin1, i);
        digitalWrite(greenPin1, HIGH);
        delay(20);
      }
      for (int i = 100; i > 0; i -= 10) {
        analogWrite(redPin1, i);
        analogWrite(bluePin1, i);
        digitalWrite(greenPin1, HIGH);
        delay(20);
      }
    }

    // turn off LED 2
    digitalWrite(redPin2, HIGH);
    digitalWrite(greenPin2, HIGH);
    digitalWrite(bluePin2, HIGH);

  }
  else if (buttonState2 == 1) {
    //flower #2
    tone(speakerPin, NOTE_G5);
    Serial.println("pressed 2");


    // cyan / green alternating pattern - LED 2
    for (int j = 0; j < 3; j++) {
      for (int i = 0; i < 255; i += 10) {
        analogWrite(greenPin2, (i * 0.5));
        analogWrite(bluePin2, i);
        digitalWrite(redPin2, HIGH);
        delay(20);
      }
      for (int i = 255; i > 0; i -= 10) {
        analogWrite(bluePin2, i);
        digitalWrite(greenPin2, LOW);
        digitalWrite(redPin2, HIGH);
        delay(20);
      }

    // turn off LED 1
    digitalWrite(redPin1, HIGH);
    digitalWrite(greenPin1, HIGH);
    digitalWrite(bluePin1, HIGH);

    }

  }
  else if (buttonState3 == 1) {
    //flower #3
    tone(speakerPin, NOTE_D7);
    Serial.println("pressed 3");

    // bouncing white light between buildings

    digitalWrite(redPin1, HIGH);
    digitalWrite(greenPin1, HIGH);
    digitalWrite(bluePin1, HIGH);

    digitalWrite(redPin2, LOW);
    digitalWrite(greenPin2, LOW);
    digitalWrite(bluePin2, LOW);

    delay(150);

    digitalWrite(redPin2, HIGH);
    digitalWrite(greenPin2, HIGH);
    digitalWrite(bluePin2, HIGH);

    digitalWrite(redPin1, LOW);
    digitalWrite(greenPin1, LOW);
    digitalWrite(bluePin1, LOW);

    delay(150);

  }
  //  else if (buttonState4 == 1) {
  //    //flower #4
  //    tone(speakerPin, NOTE_B6);
  //    Serial.println("pressed");
  //  }
  // if no flowers are pressed, launch the building display & music timer
  else if (buttonState1 != 1 && buttonState2 != 1 && buttonState3 != 1) {
    if (currentTime - startTime >= interval1 && currentTime - startTime < interval2) {

      Serial.println("Playing interval 1");

      digitalWrite(redPin1, LOW);
      digitalWrite(greenPin1, HIGH);
      digitalWrite(bluePin1, HIGH);

      digitalWrite(redPin2, LOW);
      digitalWrite(greenPin2, HIGH);
      digitalWrite(bluePin2, HIGH);

      tone(speakerPin, 1175, (1000 / 4));
      delay((1000 / 4) * 1.30);
      tone(speakerPin, 1760, (1000 / 4));
      delay((1000 / 4) * 1.30);
      tone(speakerPin, 2349, (1000 / 4));
      delay((1000 / 4) * 1.30);
    }
    else if (currentTime - startTime >= interval2 && currentTime - startTime < interval3) {

      Serial.println("Playing interval 2");

      digitalWrite(redPin1, HIGH);
      digitalWrite(greenPin1, LOW);
      digitalWrite(bluePin1, HIGH);

      digitalWrite(redPin2, HIGH);
      digitalWrite(greenPin2, LOW);
      digitalWrite(bluePin2, HIGH);

      tone(speakerPin, 1480, (1000 / 4));
      delay((1000 / 4) * 1.30);
      tone(speakerPin, 1760, (1000 / 4));
      delay((1000 / 4) * 1.30);
      tone(speakerPin, 1976, (1000 / 4));
      delay((1000 / 4) * 1.30);

    }
    else if (currentTime - startTime >= interval3 && currentTime - startTime < interval4) {

      Serial.println("Playing interval 3");

      digitalWrite(redPin1, HIGH);
      digitalWrite(greenPin1, HIGH);
      digitalWrite(bluePin1, LOW);

      digitalWrite(redPin2, HIGH);
      digitalWrite(greenPin2, HIGH);
      digitalWrite(bluePin2, LOW);

      tone(speakerPin, 1175, (1000 / 4));
      delay((1000 / 4) * 1.30);
      tone(speakerPin, 1480, (1000 / 4));
      delay((1000 / 4) * 1.30);
      tone(speakerPin, 2349, (1000 / 4));
      delay((1000 / 4) * 1.30);
    }
    else if (currentTime - startTime >= interval4 && currentTime - startTime < interval5) {

      Serial.println("Playing interval 4");

      digitalWrite(redPin1, LOW);
      digitalWrite(greenPin1, LOW);
      digitalWrite(bluePin1, HIGH);

      digitalWrite(redPin2, LOW);
      digitalWrite(greenPin2, LOW);
      digitalWrite(bluePin2, HIGH);

      tone(speakerPin, 1976, (1000 / 4));
      delay((1000 / 4) * 1.30);
      tone(speakerPin, 1760, (1000 / 4));
      delay((1000 / 4) * 1.30);
      tone(speakerPin, 1480, (1000 / 4));
      delay((1000 / 4) * 1.30);
    }
    else if (currentTime - startTime >= interval5 && currentTime - startTime < interval6) {

      Serial.println("Playing interval 5");

      digitalWrite(redPin1, LOW);
      digitalWrite(greenPin1, HIGH);
      digitalWrite(bluePin1, LOW);

      digitalWrite(redPin2, LOW);
      digitalWrite(greenPin2, HIGH);
      digitalWrite(bluePin2, LOW);

      tone(speakerPin, 2349, (1000 / 4));
      delay((1000 / 4) * 1.30);
      tone(speakerPin, 1760, (1000 / 4));
      delay((1000 / 4) * 1.30);
      tone(speakerPin, 1175, (1000 / 4));
      delay((1000 / 4) * 1.30);
    }
    else if (currentTime - startTime >= interval6 && currentTime - startTime < interval7) {

      Serial.println("Playing interval 6");

      digitalWrite(redPin1, HIGH);
      digitalWrite(greenPin1, LOW);
      digitalWrite(bluePin1, LOW);

      digitalWrite(redPin2, HIGH);
      digitalWrite(greenPin2, LOW);
      digitalWrite(bluePin2, LOW);


      tone(speakerPin, 1175, (1000 / 4));
      delay((1000 / 4) * 1.30);
      tone(speakerPin, 1760, (1000 / 4));
      delay((1000 / 4) * 1.30);
      tone(speakerPin, 1480, (1000 / 4));
      delay((1000 / 4) * 1.30);
    }
    else if (currentTime - startTime >= interval7 && currentTime - startTime < interval8) {

      Serial.println("Playing interval 7");

      digitalWrite(redPin1, LOW);
      digitalWrite(greenPin1, LOW);
      digitalWrite(bluePin1, LOW);

      digitalWrite(redPin2, LOW);
      digitalWrite(greenPin2, LOW);
      digitalWrite(bluePin2, LOW);

      tone(speakerPin, 1175, (1000 / 4));
      delay((1000 / 4) * 1.30);
      tone(speakerPin, 1480, (1000 / 4));
      delay((1000 / 4) * 1.30);
      tone(speakerPin, 1760, (1000 / 4));
      delay((1000 / 4) * 1.30);
      tone(speakerPin, 2349, (1000 / 4));
      delay((1000 / 4) * 1.30);
      tone(speakerPin, 1760, (1000 / 4));
      delay((1000 / 4) * 1.30);
      tone(speakerPin, 1480, (1000 / 4));
      delay((1000 / 4) * 1.30);

    }
    else if (currentTime - startTime >= interval8) {

      Serial.println("Resetting intervals");

      startTime = millis();

    }
  }
}
