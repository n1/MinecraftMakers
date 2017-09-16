#include <Adafruit_NeoPixel.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(7, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

  strip.setPixelColor(0, 160, 40, 0);
  strip.setPixelColor(1, 160, 160, 0);
  strip.setPixelColor(2, 160, 40, 0);
  strip.setPixelColor(3, 0, 0, 0);
  strip.setPixelColor(4, 160, 40, 0);
  strip.setPixelColor(5, 160, 40, 0);
  strip.setPixelColor(6, 160, 40, 0);
  strip.show();
  delay(50);


  strip.setPixelColor(0, 80, 20, 0);
  strip.setPixelColor(1, 0, 0, 0);
  strip.setPixelColor(2, 160, 40, 0);
  strip.setPixelColor(3, 80, 20, 0);
  strip.setPixelColor(4, 100, 60, 0);
  strip.setPixelColor(5, 80, 20, 0);
  strip.setPixelColor(6, 160, 160, 0);
  strip.show();
  delay(50);

    strip.setPixelColor(0, 255, 40, 0);
  strip.setPixelColor(1, 80, 0, 0);
  strip.setPixelColor(2, 160, 20, 0);
  strip.setPixelColor(3, 0, 0, 0);
  strip.setPixelColor(4, 160, 160, 0);
  strip.setPixelColor(5, 100, 60, 0);
  strip.setPixelColor(6, 160, 40, 0);
  strip.show();
  delay(50);

    strip.setPixelColor(0, 160, 20, 0);
  strip.setPixelColor(1, 255, 40, 0);
  strip.setPixelColor(2, 160, 80, 0);
  strip.setPixelColor(3, 80, 10, 0);
  strip.setPixelColor(4, 0, 0, 0);
  strip.setPixelColor(5, 160, 20, 0);
  strip.setPixelColor(6, 0, 0, 0);
  strip.show();
  delay(50);

}


