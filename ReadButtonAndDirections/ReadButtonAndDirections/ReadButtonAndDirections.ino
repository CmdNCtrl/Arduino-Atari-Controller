void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP); // Set pin 2 for button
  pinMode(3, INPUT_PULLUP); // Set pin 3 for Up
  pinMode(4, INPUT_PULLUP); // Set pin 4 for Up
  pinMode(5, INPUT_PULLUP); // Set pin 5 for Up
  pinMode(6, INPUT_PULLUP); // Set pin 6 for Up
  Serial.begin(9600);
 

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
