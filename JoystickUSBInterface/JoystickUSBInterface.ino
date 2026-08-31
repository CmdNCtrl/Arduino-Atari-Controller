// Include the Joystick Library
#include <Joystick.h>

// Joystick Library set up
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  1, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP); // Set pin 2 for button
  pinMode(3, INPUT_PULLUP); // Set pin 3 for Up
  pinMode(4, INPUT_PULLUP); // Set pin 4 for Up
  pinMode(5, INPUT_PULLUP); // Set pin 5 for Up
  pinMode(6, INPUT_PULLUP); // Set pin 6 for Up
  Serial.begin(9600);

  // Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(-1, 1);
  Joystick.setYAxisRange(-1, 1); 

}
// Set Variables
 String button = "Released";
 bool Up_Bool = false;
 bool Down_Bool = false;
 bool Left_Bool = false;
 bool Right_Bool = false;


void loop() {
  // put your main code here, to run repeatedly:
  // Debounce
  delay(20);

  //Read Pins
  int Fire = digitalRead(2);
  int Up = digitalRead(3);
  int Down = digitalRead(4);
  int Left = digitalRead(5);
  int Right = digitalRead(6);

  //USB Library Logic
  //Fire
  // Note:  pinMode(2, INPUT_PULLUP); will return "0" when button is pressed.
  // the second arguement is expected to be "1" when pressed
  //by adding the !, it is saying "NOT" and flips the value
  Joystick.setButton(0, !Fire);

  // Right
  if (Right == 0) {
    Joystick.setXAxis(1);
  } else {
    Joystick.setXAxis(0);
  }

	// Left


  //Original Serial Logic

// Button Logic
 
  // Serial.println(Fire);
  
  if (Fire == 0 && button == "Released") { // Use "&&" instead of "and"
    button = "Pressed";
    Serial.println(button);
  } else if (Fire == 1 && button == "Pressed"){
    button = "Released";
    Serial.println(button);
  }

  // Up Logic  
  if (Up == 0 && Up_Bool == false) { // Use "&&" instead of "and"
    Up_Bool = true;
    Serial.println("Up-Start");
  } else if (Up == 1 && Up_Bool == true){
    Up_Bool = false;
    Serial.println("Up-Stop");
  }

  // Down Logic  
  if (Down == 0 && Down_Bool == false) { // Use "&&" instead of "and"
    Down_Bool = true;
    Serial.println("Down-Start");
  } else if (Down == 1 && Down_Bool == true){
    Down_Bool = false;
    Serial.println("Down-Stop");
  }

  // Left Logic  
  if (Left == 0 && Left_Bool == false) { // Use "&&" instead of "and"
    Left_Bool = true;
    Serial.println("Left-Start");
  } else if (Left == 1 && Left_Bool == true){
    Left_Bool = false;
    Serial.println("Left-Stop");
  }

  // Right Logic  
  if (Right == 0 && Right_Bool == false) { // Use "&&" instead of "and"
    Right_Bool = true;
    Serial.println("Right-Start");
  } else if (Right == 1 && Right_Bool == true){
    Right_Bool = false;
    Serial.println("Right-Stop");
  }
  

}
