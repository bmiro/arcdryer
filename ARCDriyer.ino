#include <TFT_eSPI.h>
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();

const byte x_rpm_pos = 6;
const byte y_rpm_pos = 40;

const int rpm_pin = 12;
int rpm_raw_value = 0;

void setup(void) {
  tft.init();
  tft.setRotation(1);
  Serial.begin(115200);
}

void loop() {
  tft.fillScreen(TFT_BLACK);
  
  // Set "cursor" at top left corner of display (0,0) and select font 2
  // (cursor will move to next line automatically during printing with 'tft.println'
  //  or stay on the line is there is room for the text with tft.print)
  tft.setCursor(0, 0, 2);
  tft.setTextColor(TFT_WHITE,TFT_BLACK);
  tft.setTextSize(3);
  // We can now plot text on screen using the "print" class
  tft.println("T'estim!");

  int i = 0;
  while(1) {
    tft.setCursor(x_rpm_pos, y_rpm_pos);
    rpm_raw_value = analogRead(rpm_pin);
    tft.println("          ");
    tft.setCursor(x_rpm_pos, y_rpm_pos);
    tft.println(rpm_raw_value);
    Serial.println(rpm_raw_value);
    i++;
    sleep(1);  
  }
}
