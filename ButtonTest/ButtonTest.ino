// Set up - This section sets up the program
void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP); // Set pin 2 for button

  // starts serial communication between your Arduino 
  // and your computer at 9600 baud—the communication speed.
  // This is needed so you can print output ot the serial monitor
  Serial.begin(9600);
}
// This variable will be used in the IF statement below
 String button = "Released";

// The bulk of the program is done within the the loop.
// With each loop, it is checking the inputs it is recieving and taking actions
void loop() {
  // put your main code here, to run repeatedly:

  // Establish a variable that holds the value of the fire button in this loop.
  // If the button is pressed, the digitalRead will read "0", otherwise it will read "1"
  int Fire = digitalRead(2);

  // Debug lines:
  // Serial.println(Fire);
  // delay(1000);

  // since this is a loop, if you just print to the console when an input is detected,
  // it will send a constant stream of output to console (one value for each loop)
  // I only wanted to send a value once when the button was pressed and once when it was released

  // This IF confirm that the button is pressed AND that we didn't send Pressed command in the last loop
  if (Fire == 0 && button == "Released") { // Use "&&" instead of "and"

    // When the above condition is met, I set the variable to "Pressed" so that it cant be
    // true the next time the comes around. 
    button = "Pressed";
    Serial.println(button);

    
  } else if (Fire == 1 && button == "Pressed"){
    button = "Released";
    Serial.println(button);
  }

 

}
