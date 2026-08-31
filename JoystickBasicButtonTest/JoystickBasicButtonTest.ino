#include <Joystick.h>

Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID,
  JOYSTICK_TYPE_GAMEPAD,
  1, 0,
  true, true, false,
  false, false, false,
  false, false,
  false, false, false
);

void setup() {
  Joystick.begin();
  Joystick.setXAxisRange(-1, 1);
  Joystick.setYAxisRange(-1, 1);

  delay(1000);

  Joystick.setButton(0, 1);
  delay(1000);
  Joystick.setButton(0, 0);
}

void loop() {
}
