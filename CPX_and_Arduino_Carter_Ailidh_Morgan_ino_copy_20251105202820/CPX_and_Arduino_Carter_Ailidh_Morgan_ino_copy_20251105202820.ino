#include <Adafruit_CircuitPlayground.h>
int value;

void setup() {
 CircuitPlayground.begin();
Serial.begin(9600);
}


void loop() {
 // Read the X-axis tilt value (roughly -10 to +10)
 float x = CircuitPlayground.motionX();


 // Convert that to a frequency range — adjust to taste!
 int frequency = map(x * 100, -1000, 1000, 200, 2000);
 frequency = constrain(frequency, 200, 2000);


 // Play that tone continuously
 CircuitPlayground.playTone(frequency, 10);  // short tone, repeated quickly


int brightness = map(frequency, 200, 2000, 10, 255);
CircuitPlayground.setBrightness(brightness);
CircuitPlayground.clearPixels();
CircuitPlayground.setPixelColor(0, CircuitPlayground.colorWheel(brightness));
  // Detect if the left or right button is pressed by taking two readings with
  // a small delay inbetween.  If the button changes state (like it was pressed
  // or released) then the two readings will be different.
  bool left_first = CircuitPlayground.leftButton();
  bool right_first = CircuitPlayground.rightButton();
  delay(20);
  bool left_second = CircuitPlayground.leftButton();
  bool right_second = CircuitPlayground.rightButton();
  // Now check if either button was released, i.e. changed from a true (pressed)
  // state to a false (non-pressed) state.
  if ((left_first && !left_second) || (right_first && !right_second)) 
     CircuitPlayground.clearPixels();
    // Now take a color reading (the red, green, blue color components will be
    // returned in the parameters passed in).
    uint8_t red, green, blue;
    CircuitPlayground.senseColor(red, green, blue);
    // Print out the color components.
    Serial.print("Color: red=");
    Serial.print(red, DEC);
    Serial.print(" green=");
    Serial.print(green, DEC);
    Serial.print(" blue=");
    Serial.println(blue, DEC);
    // Gamma correction makes LED brightness appear more linear
    red   = CircuitPlayground.gamma8(red);
    green = CircuitPlayground.gamma8(green);
    blue  = CircuitPlayground.gamma8(blue);
    // Finally set all the pixels to the detected color.
    for (int i=0; i<10; ++i) {
      CircuitPlayground.strip.setPixelColor(i, red, green, blue);
    }
    CircuitPlayground.strip.show();
  }
    // Button was pressed, perform a color sense.
    // First turn off all the pixels to make sure they don't interfere with the
    // reading.

  // put your main code here, to run repeatedly:
//value=analogRead(A3);
//delay(1000);
//if (A3);
// CircuitPlayground.fill(255,0,0);
// CircuitPlayground.fill(0,0,255);
// Serial.println(value);
// //CircuitPlayground.setPixelColor(0, 207, 159, 255);
//  //CircuitPlayground.setPixelColor(1, 127, 0, 255);
// //  CircuitPlayground.setPixelColor(2,  224, 176, 255);
// //  CircuitPlayground.setPixelColor(3,   128, 0, 128);
// //  CircuitPlayground.setPixelColor(4,   203, 195, 227);
// //   CircuitPlayground.setPixelColor(5, 0x77F00FF);
// //  CircuitPlayground.setPixelColor(6, 0x953553);
// //  CircuitPlayground.setPixelColor(7, 0x702963);
// //  CircuitPlayground.setPixelColor(8, 0x953553);
// //  CircuitPlayground.setPixelColor(9, 0x953553);
//   // Read the touch sensor on pin A3. The value will be near zero when not touched
//   // and higher when touched [1, 4].
//   int touchValue = CircuitPlayground.readCap(A3);
  
//   // Set a threshold. You may need to experiment to find the right value
//   int touchThreshold = 50; 

//   if (touchValue > touchThreshold) {
//     // If touched, turn all pixels red
//     CircuitPlayground.setPixelColor(255, 0, 0); // Red
//   } else {
//     // If not touched, turn all pixels blue
//     CircuitPlayground.setPixelColor(0, 0, 255); // Blue
// }