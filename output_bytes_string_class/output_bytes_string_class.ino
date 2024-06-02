int count = 0;

void setup() {
  // Establish 9600 baud serial connection
  Serial.begin(9600);
}

void loop() {
  // Read the serial port and output incoming data...
  // Based on an example from stackoverflow.com

  // The String variable msg acts like a buffer to store characters
  String msg;

  if(Serial.available() > 0){ // if the serial input is available: this is a catchment to prevet errors
    while(Serial.available() > 0){
      msg += char(Serial.read());
      delay(3);
    }
    Serial.println(msg); // Print the message

    int length = msg.length(); // Print the message length
    String new_message = "The string is " + String(length) + " characters long.";
    Serial.println(new_message);
  }

}

// This sketch is good for handling text commands to the Arduino
