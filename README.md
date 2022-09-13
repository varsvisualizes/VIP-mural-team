# VIP-mural-team

This code is intended for use by the NYU VIP Designing for Creative Physical Computing team. Altogether the code will be used as part of an interactive mural installation. You can make the mural light up and play sound by touching the metal flowers. 

Use the following link to follow the blog record of our mural! https://wp.nyu.edu/creativephyscomp/category/arduiknow/

![VIP-Mural-Sept2022](https://user-images.githubusercontent.com/47091936/190029610-b8bfeef7-3a47-4a2e-80d0-27eba6d0a745.jpg)

# Musical Building

https://user-images.githubusercontent.com/47091936/155765102-84180c1e-27b5-4fd9-a02a-19f4647561f0.mov

This was made out of packaging scraps. You will need:

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

First, cut the windows out of the building using the craft knife. Cut 5 windows, approx 1" x 1" each. The pattern used in this example was two on the right side, two on the left side, and 1 on the right side - or, create your own window pattern. 

Next, hot glued the two cardboard supports to the face of the building. Lay the glue along the one lengthwise edge of each support piece, and glue them as close to the edge of the face of the building as possible. The end result will allow the building to house the breadboard. 

After that, place the tissue paper behind the face of the building, between the two supports, and tape it to the inside of the cardboard. This will diffuse the light from the LED.

Now you're ready to program the Arduino! Reference the Fritzing image pics in the repo for the breadboard set-up, and upload the code labeled BuildingLights_PiezoMusic.ino. This code also activates particular tones when the flowers are touched. 

NOTE: I didn't include the blue LED in the instructions because it's just a power LED; once you're confident that your system is powered, you can take it out so all the attention is on the RGB LED. 
