enum {C, Db, D, Eb, E, F, Gb, G, Ab, A, Bb, B}; // enumeration constant list 
//- a list of symbolic names associated with integer values, based on zero-based
//- index values. If we added H at the end of this list it would be assigned 12

void setup() {
  Serial.begin(9600);
  Serial.println("Enter a MIDI note number: ");
}

void loop() {
  if(Serial.available() > 0){
    //Read incoming byte
    int value = Serial.parseInt();

    //Print note information
    printNoteInfo(value, getOctave(value), getNoteName(value));

    //Prompt the user to enter another number: 
    Serial.println("Enter another MIDI note number: ");
  }
}

int getOctave(int midi_note){
  //Calculate the octave of the midi note
  return (midi_note/12) - 1;
}

int getNoteNumber(int midi_note){
  //Calculate the midi note value(0-11)
  return midi_note % 12;
}

char const* getNoteName(int midi_note){
  //Get note number(0-11)
  int note = getNoteNumber(midi_note);

  //use switch statment to determine note name
  //could also be done with a series of if statements
  switch(note){
    case C  : return "C";
    case Db : return "Db";
    case D  : return "D";
    case Eb : return "Eb";
    case E  : return "E";
    case F  : return "F";
    case Gb : return "Gb";
    case G  : return "G";
    case Ab : return "Ab";
    case A  : return "A";
    case Bb : return "Bb";
    case B  : return "B";
    default : return "Unknown";
  }
}

void printNoteInfo(int value, int octave, char const* note_name){
  //Print information about the note:
  Serial.print("Value: ")   ; Serial.println(value);
  Serial.print("Octave: ")  ; Serial.println(octave);
  Serial.print("Note: ")    ; Serial.println(note_name);
  Serial.println("=================================");
}
