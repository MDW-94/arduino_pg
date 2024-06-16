const int LED_PIN = 13;

int tempo;                      //Tempo in BPM
long delay_MS;                  //Delay in milliseconds
boolean blink_status = true;    //true == LED on, false == LED off
int tries;                      //Tracks the number of tries to guess the tempo
int precision = 3;              //Determine accuracy of guess (within +/- 3 BPM)

void newGame(){
  // Reset the nunmber of tries:
  tries = 1;

  // select a random tempo between 30 and 150 BPM:
  tempo = random(30, 150);

  //Calculate the amount of delay:
  //Milliseconds per minute/beats per minute
  unsigned int milliseconds_per_minute = 1000*60;
  delay_MS = milliseconds_per_minute/tempo;

  //Divide by 2 to get half the period:
  delay_MS = delay_MS/2;

  //Print a message:
  Serial.println("Enter the tempo in BPM (e.g. 120): ");
}

void blinkLED(){
  static long last_time = 0;  // Used to track milliseconds between blinks

  // Get the current time in milliseconds
  long current_time = millis();

  // If the current time - last time is greater than the delay time
  if(current_time - last_time >= delay_MS){
    // Toggle blink stats (flase = true or true = false)
    blink_status = !blink_status;
    last_time = current_time; // reset last_time
    updateLED();
  }
}

void updateLED(){
  // Toggle the LED
  if(blink_status == true){
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}

void showCorrectAnswer(){
  Serial.print("Congratulations! You selected the correct tempo in: ");
  Serial.print(tries);
  Serial.println(" tries!");
  Serial.print("The exact tempo is: ");
  Serial.println(tempo);
}


void setup() {
  //Establish 9600 baud serial connection
  Serial.begin(9600);

  //Set up a digital pin as an output:
  pinMode(LED_PIN, OUTPUT);

  //Initialize (seed) the random number generator
  randomSeed(analogRead(0));

  //Set up a new game:
  newGame();
}

void loop() {
  blinkLED();

  //Check Response
  if(Serial.available() > 0){
    //Read the incoming byte
    long input = Serial.parseInt();

    //Check responses:
    if(input > tempo + precision){
      Serial.println("Sorry, your guess is too high. Try again.");
      tries++;
    }
    //See if guess is within the range of the current tempo + precision and
    // current tempo - precision 
    if(input <= tempo + precision && input >= tempo - precision){
      //Correct Answer
      showCorrectAnswer();

      //Start a new game:
      newGame();
    }
  }
}

// Tempo Guessing Game:

// The tempo game sketch blinks an LED at a random tempo and the user
// guesses the tempo by entering numbers in the Serial Monitor window.
// The program provides feedback on each guess and tracks the number of
// of tries it takes to guess the tempo.

// This tempo game will allow you to practice the skill of detecting tempos.
// A variable called 'precision' can be altered so guesses are evaluated with
// more (or less) precision.


// Setup:

// The "prelude" is similar to other sketches - a global constant and several variables are initialized,
// and a Serial connection is established in the setup() function. Two lines of the setup() method are 
// unfamiliar: randomSeed() and newGame().

// randomSeed() is a built-in function that seeds a random number generator with a unique value. Without
// this step, the random number generator would always return the same pattern of numbers. In this case,
// a random value is read from an analog port to seed the generator.

// newGame() is a custom function that is called at the start of each game. It's job is to select a new
// random tempo, reset the variable that corresponds to the number of tries, and calculate the number of
// milliseconds per beat


// Helper Functions:

// Three helper functions - blinkLED(). updateLED(), and showCorrectAnswer() - simplify the logic in the
// main loop. Although this code could have been placed in the main loop, it would make for a long and
// unwieldy function. Breaking the code into smaller chunks of code clarifies the logic and provides an
// opportunity to reuse the code in other sketches.

// The blinkLED() function uses a static variable, last_time, to track the number of milliseconds between
// calls. As mentioned previously, the static key word means that the value of the variable is stored 
// between calls to the function (even though the variable does not have global scope). As you can see
// from the comments in blinkLED(), the function toggles the status of the LED each time
// current_time - last_time is greater than or equal to delay_MS. The following line:

// blink_status = !blink_status;

// is a handy way to toggle between (true/false) variables between states. Another helper function,
// updateLED(), is called each time the state of the LED changes. This function simply turns the LED
// on or off depending on the value of the variable, blink_status.

// A final helper function, showCorrectAnswer(), is caleld whenever the user enters a correct response.
// You might want to add additional feedback such as snarkyc comments when responses exceed a certain
// number of tries.


// Main loop():

// The main loop() function is the heart of the tempo_game program. Its job is to call the blinkLED() method
// and to evaluate user responses. A pseudo-code version might look like this:

// - call blinkLED()
// - Read data from the serial port(if available)
// - Incremenet the tries variable and provide feedback for an incorrect response
// - Call showCorrectAnswer() and newGame() if user enters a correct response


