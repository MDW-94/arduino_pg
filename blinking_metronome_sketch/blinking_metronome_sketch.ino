const int LED_PIN = 13;
unsigned int delay_per_beat = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT); // set the digital pin as the output
  
  // Calculate the amount of delay:
  // milliseconds per minute/beats per minute
  // milliseconds_per_minute and beats_per_minute have local scope
  unsigned int milliseconds_per_minute = 1000*60;
  unsigned int beats_per_minute = 60;
  
  // divide by 2 to get half the period
  delay_per_beat = milliseconds_per_minute/beats_per_minute/2;
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // Turn LED on
  delay(delay_per_beat);        // Delay = 1/2 period
  digitalWrite(LED_PIN, LOW);   // Turn LED off
  delay(delay_per_beat);        // Delay for the other 1/2 period
}
