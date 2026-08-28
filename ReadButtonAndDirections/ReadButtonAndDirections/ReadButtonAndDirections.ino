void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP); // Set pin 2 for button
  pinMode(3, INPUT_PULLUP); // Set pin 3 for Up
  Serial.begin(9600);
 

}
// Set Variables
 String button = "Released";
 bool Up_Bool = false;


void loop() {
  // put your main code here, to run repeatedly:
  // Debounce
  delay(20);
// Button Logic
  int Fire = digitalRead(2);
  // Serial.println(Fire);
  
  if (Fire == 0 && button == "Released") { // Use "&&" instead of "and"
    button = "Pressed";
    Serial.println(button);
  } else if (Fire == 1 && button == "Pressed"){
    button = "Released";
    Serial.println(button);
  }

  // Up Logic
  int Up = digitalRead(3);
  // Serial.println(Fire);
  
  if (Up == 0 && Up_Bool == false) { // Use "&&" instead of "and"
    Up_Bool = true;
    Serial.println("Up-Start");
  } else if (Up == 1 && Up_Bool == true){
    Up_Bool = false;
    Serial.println("Up-Stop");
  }

  

}
