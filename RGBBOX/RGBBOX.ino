// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN            2
#define NUMPIXELS      9
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500;
String data;
void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  Serial.begin(9600);
  pixels.begin();
  pixels.clear(); // T
}

void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  if (Serial.available() > 0) {
    receive();
    if (data == "q") {
      pixels.clear(); // T
      for (int i = 0; i < NUMPIXELS; i++) {

        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(255, 255, 255)); // Moderately bright green color.

        pixels.show(); // This sends the updated pixel color to the hardware.

        delay(delayval); // Delay for a period of time (in milliseconds).
      }
    }
    if (data == "s") {
      pixels.clear(); // T
       for (int i = 0; i < NUMPIXELS; i++) {

        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Moderately bright green color.

        pixels.show(); // This sends the updated pixel color to the hardware.

        delay(10); // Delay for a period of time (in milliseconds).
      }
    }
     if (data == "a") {
      pixels.clear(); // T
      for (int i = 0; i < NUMPIXELS; i++) {

        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(0, 255, 0)); // Moderately bright green color.

        pixels.show(); // This sends the updated pixel color to the hardware.

        delay(10); // Delay for a period of time (in milliseconds).
      }
    }
     if (data == "w") {
      pixels.clear(); // T
      for (int i = 0; i < NUMPIXELS; i++) {

        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(0, 0, 255)); // Moderately bright green color.

        pixels.show(); // This sends the updated pixel color to the hardware.

        delay(delayval); // Delay for a period of time (in milliseconds).
      }
    }
  if (data == "d") {
      pixels.clear(); // T
      for (int i = 0; i < NUMPIXELS; i++) {

        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(255, 0, 0)); // Moderately bright green color.

        pixels.show(); // This sends the updated pixel color to the hardware.

        delay(10); // Delay for a period of time (in milliseconds).
      }
    }
     if (data == "x") {
      pixels.clear(); // T
      for (int i = 0; i < NUMPIXELS; i++) {
        int r = random(0,255);
        int g = random(0,255);
        int b = random(0,255);

        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(r, g, b)); // Moderately bright green color.

        pixels.show(); // This sends the updated pixel color to the hardware.

        delay(delayval); // Delay for a period of time (in milliseconds).
      }
    }

  }
}
void receive() {
  data = "";
  while (Serial.available() > 0) {
    data = data + char(Serial.read());
    delay(2);
  }
  Serial.print("data:" + data);
}
