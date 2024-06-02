void setup() {
  Serial.begin(9600);
  for(int c = 0; c < 10; c++){
    printMessage("Calling printMessage()");
  }
}

void loop() {
  // Nothing to do here
}

void printMessage(char* message){
  static int number_of_calls = 0;
  number_of_calls++; // increase each time the function is called
  Serial.println(message); // print the number of times the function has been called
  Serial.print("printMessage() has been called ");
  Serial.print(number_of_calls);
  Serial.println(" times.");
}

// The 'static' keyword can be used to force the compiler to extend the life
// of local C function level variables. This is different to 'global scope'
// - such variables retian their values between function calls.
// In this example, teh static local variable number_of_calls tracks the
// umber of times the printMessage() function has been called.
