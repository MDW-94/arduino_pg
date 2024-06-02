void setup() {
  Serial.begin(9600);
  Serial.println("Enter a number: ");
}

void loop() {
  if(Serial.available() > 0){
    long input_byte = Serial.parseInt();
    Serial.println(input_byte);
    
    // Calculate its square
    long square = input_byte * input_byte;
    Serial.print("The square of the number is: ");
    Serial.println(square);

    // Calculate its cube
    long cube = input_byte * input_byte * input_byte;
    Serial.print("The cube of the number is: ");
    Serial.println(cube);

    // Use the modula operator to test if the number is even or odd
    if(input_byte % 2 == 0){
      Serial.println("The number is even\r");
    } else {
      Serial.println("The number is odd\r");
    }
  }
}

// Note - ' if(Serial.available() > 0){' CANNOT BE  'if(Serial.available() >= 0){'
// as Arduino seems to sequenctially output 0 after an interval - if it is the later
// the code block keeps running with a specified value of 0
