// Where traditional strings are the best choice when you want to keep your program lean
// and mean, a String class is available to handle many of the tricky details working with
// characters arrays. The String class makes it possible to concatenate or add strings together,
// convert numbers to strings, trim whitespace, convert to upper or lower case, and a number
// of other useful functions you can read about at http://arduino.cc/en/Reference/StringObject

//To use the String class, simply create an instance of the calss and assign it to a string literal
// or call one of its member functions as shown:

// String Demonstration 1:

void setup() {
  Serial.begin(9600);

  // Create Two Strings:
  String aString = "This is a string. "; //tab space here
  String bString = " This is another string.";

  // Combine the strings into a new string
  String cString = aString + bString;
  Serial.println(cString);

  // Change all characters to upper case
  cString.toUpperCase();
  Serial.println(cString);

  // Get a substring from first element (0) through fourth element
  String subString = cString.substring(0,4);
  Serial.println(subString);
}

void loop() {
  // put your main code here, to run repeatedly:

}

//  Tip: Be sure to check out the Standard Template Library ig you ever program on full-fledged computers.
//  The STL provides helpful container classes and a string class that is powerful and easy to use


//  ======= Previous Chapter:


// The Ugly Turth: Working With Text in C:

// Although we have utilized text in several examples in this chapter, I have purposefully
// avoided a discussion of the details. Text (usually referred to as strings or character arrays 
// C programmers) is an important topic when writing software for computers, but less so
// when dealing with the memory constraints of a microcontroller. For that reason, I will limit
// the discussion to the basics:

// String Literals:
// Most of the programs in this book (Arduino For Musicians) utilize a type of string known as a
// 'string literal'. You have already seen a number of examples. A string literal is "an array of
// type char". Characters or "chars" are similiar to bytes but are typically used when working with
// text strings. Moving back to the "Hello World!" application, the text in quotes is an example of
// a string literal

// Serial.println("Hello World!");

// Character Arrays:
// The length of strings can also be variable, in which case they are handled just like other arrays.
// In this case, the array contains a list of characters instead of numbers.

// char text[] = "Hello, World!";
// char letter=text[1]; //letter equals e--the 2nd index

// However, there is one subtle difference between variables arrays of characters and integers
// In the preceeding example, a "hidden" element is appended to the end of the array.
// The hidden element is a null value ('\0') that is used to indicate the end or the string.
// This will be handled behind the scenes in the code in this book, but it is something to be
// aware of should you find yourself manipulating strings as part of an Arduino sketch.

// Also note the following statements are functionally equivalent. The second example uses a pointer
// to indiciate the first element in an array. Pointers are really useful in programming,
// but they will not necessarily be useful in the projects in this portion of the book.

// char text[]="Hello, world!";
// char *text2="Hello, world!";


