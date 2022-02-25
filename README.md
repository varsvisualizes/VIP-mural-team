# VIP-mural-team

This code is intended for use by the NYU VIP Designing for Creative Physical Computing team. Altogether the code will be used as part of an interactive mural installation. 

So far I have put together:

- Buildings that light up and play music upon being triggered by rock-shaped knobs
- A seed dispenser that dispenses seed-filled confetti upon being triggered by rock-shaped knobs
- Potentiometers that are covered in paper to appear like rocks

Use the following link to follow the blog record of our mural! https://wp.nyu.edu/creativephyscomp/category/arduiknow/

# Rock Potentiometers

![Rock Back](https://user-images.githubusercontent.com/47091936/155765830-ed309e3a-37f4-4175-8aad-912dcc22c998.jpg)

The rock potentiometer is simple to build. You'll need:

- An Arduino UNO
- 1 10k potentiometer
- A breadboard and jumper wires
- 1 paper you can crumple up (I used some leftover package lining)
- Tape
- Hot glue

I crumpled the paper into roughly a rock shape, using tape to wrap it together and keep it from sprawling out. Once the "rock" was made, I poked a hole large enough to fit the top of the poteniometer, and I hot glued the potentiometer top to the inside of the hole in the rock. 

I would recommend soldering wires to the potentiometer the rock can be distanced from the breadboard. There's no special code for the potentiometer - I just used the Knob example already build into the Arduino IDE. 

Ideally there would be 3 rocks in the mural, so 3 rock potentiometers. The rocks would control a few things in the mural: They'll make some bees sway, they'll change the music and color of the buildings, and they can activate the seed dispenser. 

More pics can be seen in the Rock Potentiometer images file in the repo! 

# Musical Building

https://user-images.githubusercontent.com/47091936/155765102-84180c1e-27b5-4fd9-a02a-19f4647561f0.mov

This was also made out of packaging scraps. You will need:

- An Arduino UNO
- A piezo buzzer
- An RGB LED
- 3 560 Ohm resistors
- 3 potentiometers
- Breadboard(s) and jumper cables
- 1 12.5" x 8.5" cardboard (the face of the building)
- 2 6" x 1.25" cardboards (the support rails of the building)
- Tissue paper / clear cellophane
- A craft knife / scissors
- Hot glue
- Tape

First, I cut the windows out of the building using the craft knife. I cut 5 windows, approx 1" x 1" each. The pattern I used in this example was two on the right side, two on the left side, and 1 on the right side, but you can cut however you'd like to create your own window pattern. 

Next, I hot glued the two cardboard supports to the face of the building. I laid the glue along the one lengthwise edge of each support piece, and glued them as close to the edge of the face of the building as I could. The end result will allow the building to house the breadboard. 

After that, I placed the tissue paper behind the face of the building, between the two supports, and I taped it to the inside of the cardboard. This will diffuse the light from the LED.

Now you're ready to program the Arduino! Reference the Fritzing image pics in the repo for the breadboard set-up, and upload the code labeled BuildingLights_PiezoMusic.ino.

NOTE: I didn't include the blue LED in the instructions because it's just a power LED; once you're confident that your system is powered, you can take it out so all the attention is on the RGB LED. 

# Seed Dispenser

https://user-images.githubusercontent.com/47091936/155765277-57615a12-add1-4221-a758-5ff49b87a217.MOV

The idea for the seed dispenser is that once you've rotated all 3 rock potentiometers, the dispenser pops out a few confetti pieces full of native seeds for you to grow in your home or garden. A little Easter egg for interacting with the mural. 

The instructable detailing the construction of the seed dispenser is in the repo files! 

There's no particular code for this file either - I again just used the Knob example file. 





