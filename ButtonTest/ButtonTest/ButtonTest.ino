void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP); // Set pin 2 for button
  Serial.begin(9600);
 

}
 String button = "Released";


void loop() {
  // put your main code here, to run repeatedly:


  int Fire = digitalRead(2);
  // Serial.println(Fire);
  // delay(1000);
  if (Fire == 0 && button == "Released") { // Use "&&" instead of "and"
    button = "Pressed";
    Serial.println(button);
  } else if (Fire == 1 && button == "Pressed"){
    button = "Released";
    Serial.println(button);
  }



}
