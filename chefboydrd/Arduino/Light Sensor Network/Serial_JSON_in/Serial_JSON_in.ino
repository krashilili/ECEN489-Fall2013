#include <json_arduino.h>



/*
Title: Arduino Light Sensor
Author: John Boyd
Notes:

*/

// ---------------------
// CONTROL PARAMETERS
// ---------------------
int ledPin = 13;    // select the input pin for the potentiometer

// ---------------------
// VARIABLE DECLARATIONS
// ---------------------
  token_list_t* LIST = create_token_list(1);  // List of JSON tokens
  char json_string[256];
  int lightLevel = 0;
  String LEDstate = "LOLOLOL";
  boolean OnOff = LOW;

// ---------------------
// FUNCTION DECLARATIONS
// ---------------------
  String getInput();

// ---------------------
// DEVICE INITIALIZATION
// ---------------------
  void setup() {
  // Initialize serial port
  Serial.begin(9600);
  
  // Set ledPin as output
  pinMode(ledPin, OUTPUT);
}


// ---------------------
// MAIN LOOP
// ---------------------
void loop() {
  
  strcpy(json_string, getInput("").c_str());
  json_to_token_list(json_string, LIST);
  //lightLevel = atoi(json_get_value(LIST, "lightLevel"));
  //strcpy(LEDstate, json_get_value(LIST, "LEDstate"));
  /*
  if(LEDstate == "ON")
    OnOff = HIGH;
  else if(LEDstate == "OFF")
    OnOff = LOW;
  */
  
  //digitalWrite(ledPin, LOW);
  Serial.println(json_string);
  Serial.println(json_get_value(LIST, "lightLevel"));
  
  //release_token_list(LIST);
  delay(1000);
}


// ---------------------
// FUNCTION DEFINITIONS
// ---------------------
String getInput(String prompt)
{
  char readChar = ' ';
  String Input = "";
  
  if(prompt != "")
  {
    Serial.print(prompt);
  }
  
  while (!Serial.available());  // Holds the program while waiting for input
  
  while (readChar != '\n') 
  {
    if(Serial.available())
    {
      readChar = (char)Serial.read();
      if(readChar != '\n')
      {
        Input += readChar;      
      }
      else break;
    }
  }
  
  return Input;  
}
