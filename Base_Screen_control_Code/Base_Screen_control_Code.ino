#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

// Initialize 0.96" 128x64 I2C OLED (SSD1306 driver)
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
// U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

const int fanPin = 9;    // PWM pin driving the IRLB8720 MOSFET gate
const int potPin = A0;   // Analog pin connected to the potentiometer

void setup() {
  pinMode(fanPin, OUTPUT);
  pinMode(potPin, INPUT);
  u8g2.begin();
}

void loop() {
  // 1. Read the potentiometer (0 to 1023)
  int potValue = analogRead(potPin);
  
  // 2. Inverted mapping: 0 becomes 255 (full speed), 1023 becomes 0 (off)
  int pwmValue = map(potValue, 0, 1023, 255, 0);
  
  // Deadzone: Ensures the fan completely turns off at the lowest setting
  if (pwmValue < 5) {
    pwmValue = 0;
  }
  // Top-end snap: Ensures full 100% power when turned all the way up
  if (pwmValue > 250) {
    pwmValue = 255;
  }

  // 3. Drive the MOSFET on D9
  analogWrite(fanPin, pwmValue);
  
  // 4. Calculate speed percentage (0 to 100%) for display
  int speedPercent = map(pwmValue, 0, 255, 0, 100);
  
  // 5. Update the OLED screen with the 270-degree radial gauge
  updateDisplay(speedPercent);
  
  delay(30); // Short delay for smooth, flicker-free screen updates
}

void updateDisplay(int percent) {
  u8g2.clearBuffer();

  // Center of the 128x64 screen
  int centerX = 64;
  int centerY = 34;
  int outerRadius = 29;
  int innerRadius = 23;

  // 1. Draw the thin dotted outer track (135° bottom-left to 405° bottom-right)
  for (int angle = 135; angle <= 405; angle += 6) {
    float rad = angle * 0.0174533;
    int x = centerX + cos(rad) * outerRadius;
    int y = centerY + sin(rad) * outerRadius;
    u8g2.drawPixel(x, y);
  }

  // 2. Map percentage (0-100%) to the 270° sweep (135° to 405°)
  int targetAngle = map(percent, 0, 100, 135, 405);

  // 3. Fill the solid active ring up to the target angle
  if (percent > 0) {
    for (int angle = 135; angle <= targetAngle; angle += 2) {
      float rad = angle * 0.0174533;
      int x1 = centerX + cos(rad) * innerRadius;
      int y1 = centerY + sin(rad) * innerRadius;
      int x2 = centerX + cos(rad) * outerRadius;
      int y2 = centerY + sin(rad) * outerRadius;
      u8g2.drawLine(x1, y1, x2, y2);
    }
  }

  // 4. Draw the percentage number dead-center inside the ring
  u8g2.setFont(u8g2_font_logisoso16_tr);
  char speedStr[6]; // FIXED: Array of 6 characters to safely hold "100%"
  sprintf(speedStr, "%d%%", percent);
  
  int textWidth = u8g2.getStrWidth(speedStr);
  u8g2.drawStr(centerX - (textWidth / 2), centerY + 7, speedStr);

  // 5. Small "FAN" label tucked into the open bottom gap of the ring
  u8g2.setFont(u8g2_font_5x7_tr);
  u8g2.drawStr(57, 63, "FAN");

  u8g2.sendBuffer();
}
