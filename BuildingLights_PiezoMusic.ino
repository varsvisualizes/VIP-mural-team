/*
   This code will:

   - show proposed building illumination colors
   - play music on the piezo buzzer corresponding to the potentiometers turned

   This will demo some Easter egg ideas and get the buildings glowing.

   These are the notes used for the music:

   NOTE_D6 1175
   NOTE_F 1480
   NOTE_A 1760
   NOTE_B 1976
   NOTE_D7 2349

   10 Dec 2021
   Carmen Vargas
*/

// initialize pins

// RGB LED
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

// piezo buzzer
int speakerPin = 5;

// 'stone' potentiometer
int potPin1 = A0;

// trimpot 1
int potPin2 = A1;

// trimpot 2
int potPin3 = A2;

// define potentiometer values
int potVal1 = 0;
int potVal2 = 0;
int potVal3 = 0;

// define threshold for potentiometer to trip music
int threshold = 500;

void setup() {

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(speakerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // get the values for the potentiometers
  potVal1 = analogRead(potPin1);
  potVal2 = analogRead(potPin2);
  potVal3 = analogRead(potPin3);

  Serial.print("PotVal1 = ");
  Serial.print(potVal1);
  Serial.print('\t');
  Serial.print("PotVal2 = ");
  Serial.print(potVal2);
  Serial.print('\t');
  Serial.print("PotVal3 = ");
  Serial.println(potVal3);

  if (potVal1 > threshold && potVal2 < threshold && potVal3 < threshold) {

    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);

    tone(speakerPin, 1175, (1000 / 4));
    delay((1000 / 4) * 1.30);
    tone(speakerPin, 1760, (1000 / 4));
    delay((1000 / 4) * 1.30);
    tone(speakerPin, 2349, (1000 / 4));
    delay((1000 / 4) * 1.30);
  }
  else if (potVal1 < threshold && potVal2 > threshold && potVal3 < threshold) {

    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);

    tone(speakerPin, 1480, (1000 / 4));
    delay((1000 / 4) * 1.30);
    tone(speakerPin, 1760, (1000 / 4));
    delay((1000 / 4) * 1.30);
    tone(speakerPin, 1976, (1000 / 4));
    delay((1000 / 4) * 1.30);

  }
  else if (potVal1 < threshold && potVal2 < threshold && potVal3 > threshold) {

    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);

    tone(speakerPin, 1175, (1000 / 4));
    delay((1000 / 4) * 1.30);
    tone(speakerPin, 1480, (1000 / 4));
    delay((1000 / 4) * 1.30);
    tone(speakerPin, 2349, (1000 / 4));
    delay((1000 / 4) * 1.30);
  }
  else if (potVal1 > threshold && potVal2 > threshold && potVal3 < threshold) {

    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);

    tone(speakerPin, 1976, (1000 / 4));
    delay((1000 / 4) * 1.30);
    tone(speakerPin, 1760, (1000 / 4));
    delay((1000 / 4) * 1.30);
    tone(speakerPin, 1480, (1000 / 4));
    delay((1000 / 4) * 1.30);
  }
  else if (potVal1 > threshold && potVal2 < threshold && potVal3 > threshold) {

    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);

    tone(speakerPin, 2349, (1000 / 4));
    delay((1000 / 4) * 1.30);
    tone(speakerPin, 1760, (1000 / 4));
    delay((1000 / 4) * 1.30);
    tone(speakerPin, 1175, (1000 / 4));
    delay((1000 / 4) * 1.30);
  }
  else if (potVal1 < threshold && potVal2 > threshold && potVal3 > threshold) {

    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);

    tone(speakerPin, 1175, (1000 / 4));
    delay((1000 / 4) * 1.30);
    tone(speakerPin, 1760, (1000 / 4));
    delay((1000 / 4) * 1.30);
    tone(speakerPin, 1480, (1000 / 4));
    delay((1000 / 4) * 1.30);
  }
  else if (potVal1 > threshold && potVal2 > threshold && potVal3 > threshold) {

    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);

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
  else {
    
    noTone(speakerPin);

    // Off
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
  }

}
