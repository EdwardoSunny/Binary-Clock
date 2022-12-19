#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <DS3231.h>
#include <Wire.h>
#define PIN 6

// Tools > Manage Libaries
//Please make sure you have all the above libaries installed (Adafruit circuit playground, DS3231 by Andrew Wickert, DS1307RTC by Paul Stoffregen, and Time by Paul Stoffregen) 
// This is the source code for the binary clock

RTClib myRTC;

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(5, 8, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);

bool century = false;
bool h12Flag;
bool pmFlag;
byte alarmDay, alarmHour, alarmMinute, alarmSecond, alarmBits;
bool alarmDy, alarmH12Flag, alarmPmFlag;

const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) };
  
void setup() {
  Wire.begin();
  matrix.begin();
  matrix.setTextWrap(false);
  // 40
  matrix.setBrightness(10);
  matrix.setTextColor(colors[0]);
  matrix.show();
  Serial.begin(9600);
}

void loop() {
  DateTime now = myRTC.now();
  // put your main code here, to run repeatedly:
  matrix.fillScreen(0);
  Serial.print(now.hour());
  Serial.print("\n");
  setHours(now.hour());
  setMinutes(now.minute());
  setSeconds(now.second());
  matrix.show();
}

void setPixel(int row, int col, int r, int g, int b) {
  // zero based indexing in both column and row
  int pixelValue = row * 8 + col;
  matrix.setPixelColor(pixelValue, r, g, b);
}

void setSeconds(int n) {
  long bin = 0;
  long rem;
  long i = 1;

  while (n!=0) {
    rem = n % 2;
    n/=2;
    bin+=rem*i;
    i*=10;
  }
  if (bin % 10 == 1) {
    setPixel(4, 6, 255, 0, 0); 
  }
  bin = bin / 10;
  if (bin % 10 == 1) {
    setPixel(3, 6, 255, 0, 0); 
  }
  bin = bin / 10;
  if (bin % 10 == 1) {
    setPixel(2, 6, 255, 0, 0); 
  }
  bin = bin / 10;
  if (bin % 10 == 1) {
    setPixel(1, 6, 255, 0, 0); 
  }
  bin = bin / 10;
  if (bin % 10 == 1) {
    setPixel(4, 5, 255, 0, 0); 
  }
  bin = bin / 10;
  if (bin % 10 == 1) {
    setPixel(3, 5, 255, 0, 0); 
  }
}

void setMinutes(int n) {
  long bin = 0;
  long rem;
  long i = 1;

  while (n!=0) {
    rem = n % 2;
    n /= 2;
    bin += rem * i;
    i *= 10;
  }
  if (bin % 10 == 1) {
    setPixel(4, 4, 0, 255, 0); 
  }
  bin = bin / 10;
  if (bin % 10 == 1) {
    setPixel(3, 4, 0, 255, 0); 
  }
  bin = bin / 10;
  if (bin % 10 == 1) {
    setPixel(2, 4, 0, 255, 0); 
  }
  bin = bin / 10;
  if (bin % 10 == 1) {
    setPixel(1, 4, 0, 255, 0); 
  }
  bin = bin / 10;

  if (bin % 10 == 1) {
    setPixel(4, 3, 0, 255, 0); 
  }
  bin = bin / 10;
  if (bin % 10 == 1) {
    setPixel(3, 3, 0, 255, 0); 
  }
}

void setHours(int n) {
  long bin = 0;
  long rem;
  long i = 1;

  while (n!=0) {
    rem = n % 2;
    n /= 2;
    bin += rem * i;
    i *= 10;
  }

  if (bin % 10 == 1) {
    setPixel(4, 2, 0, 0, 255); 
  }
  bin = bin / 10;
  if (bin % 10 == 1) {
    setPixel(3, 2, 0, 0, 255); 
  }
  bin = bin / 10;
  if (bin % 10 == 1) {
    setPixel(2, 2, 0, 0, 255); 
  }
  bin = bin / 10;
  if (bin % 10 == 1) {
    setPixel(1, 2, 0, 0, 255); 
  }
  bin = bin / 10;
  if (bin % 10 == 1) {
    setPixel(4, 1, 0, 0, 255); 
  }
  bin = bin / 10;
  if (bin % 10 == 1) {
    setPixel(3, 1, 0, 0, 255); 
  }
}
