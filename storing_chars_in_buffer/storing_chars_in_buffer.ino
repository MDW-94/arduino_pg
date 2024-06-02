const int BUFFER_SIZE = 20; // Global const int variable to define array size
char buffer[BUFFER_SIZE]; // Global uninitialized array to store characters
int current_index = 0; // variable to track current array index

void setup() {
  Serial.begin(9600);
  Serial.println("Enter text and press ~: ");
}

void loop() {
  if(Serial.available() > 0){
    char character = Serial.read(); // Read the incoming byte
    if(character == '~'){           //See if we should print the contents of buffer
     Serial.println("===== Start of Buffer =====");
      for(int i = 0; i < current_index; i++){ // For loop to print contents of buffer
        Serial.print(buffer[i]); // has to be print() otherwise each character will be on a newline
      }
      Serial.println(" ");
      Serial.println("===== End Buffer =====");
      current_index = 0; // Reset index after completion
    } else {
      if(current_index < BUFFER_SIZE - 1){ //store character if there is room in the buffer
        buffer[current_index] = character; //place character in the array
        current_index++; //advance to next index 
      }
    }
  }
}

// This buffer will overwrite the characters in the buffer each time the input from stdin is taken
// - meaning each time the buffer is printed out the latest input from the user will be displayed:

// Input 1: A, Input 2: newline, Input 3: is made, Input 4: ~
// Outputs:
// 
// A
// newline
// is made
//
// ===== End Buffer =====

// This is because each time you enter an input, the enter key will insert a newline character (carriage return?)
// This will be stored in the buffer as well:

// 11:46:41.939 -> ===== Start of Buffer =====
// 11:46:41.970 -> 
// 11:46:41.970 -> Matthew 1994 
// 11:46:42.002 -> ===== End Buffer =====
// 11:46:49.638 -> ===== Start of Buffer =====
// 11:46:49.669 -> 
// 11:46:49.669 -> Matthew 
// 11:46:49.669 -> 1994 
// 11:46:49.669 -> ===== End Buffer =====


//  Circular Buffer: https://en.wikipedia.org/wiki/Circular_buffer


