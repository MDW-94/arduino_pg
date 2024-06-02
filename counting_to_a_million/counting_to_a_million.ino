void setup() {
  Serial.begin(9600);
  Serial.println("Counting to 1,000,000");
}

void loop() {
  for(long i = 0; i < 1000000;i++){
    Serial.println(i);

    if( i == 1000*1000){
      Serial.println("A million has been reached");
    }
  }
}
