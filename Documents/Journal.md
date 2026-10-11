# 9/30/26

Trying to sort our what programs I did in what order.

| Program Name                | Purpose                                                                       | Folder                  |
| --------------------------- | ----------------------------------------------------------------------------- | ----------------------- |
| ButtonTest.ino              | Detect a button press and print either `Pressed` or `Released` in the console | ButtonTest              |
| ReadButtonAndDirections.ino | Detect button and direction press and release and write it to the console     | ReadButtonAndDirections |
| JoystickUSBInterface.ino    | Final program that incorporates the USB library and the orginal program       | JoystickUSBInterface    |



# 9/29/26

* Got it working on Linux mint but have not figured out how to get it to work on Mac yet
* Seems to be some issue with the Arduino not being properly read by Mac as a controller
* 

# 8/24/26

* Able to make board read when I short the connection, but not via the joystick/break out.

* First checking continuity in the connector itself (OK)
* Next check continuity of the break out D9
* Solved: Issue was the terminal on teh breakout was screwed the wrong way
* Was able to write teh first program to detect fire button press
* Learned a little about "debouncing"