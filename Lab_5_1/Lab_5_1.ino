
#include "Arduino.h"

#define PHOTODIODE_LIGHT_THRESHOLD 3
#define LIGHT_SENSOR_1 A1

float sensorValue = 0; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(LIGHT_SENSOR_1, INPUT); //Initialize A1 as an input 
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = getPinVoltage(LIGHT_SENSOR_1);
    if (isLight(LIGHT_SENSOR_1)){
      Serial.print("ON: ");
      Serial.print(sensorValue);
      Serial.println(" V");
    } else {
      Serial.print("OFF: ");
      Serial.print(sensorValue);
      Serial.println(" V");
    }


}
// Voltage at which a light is considered to be present

// equations
  // Function that detects if light is present
  bool isLight(int pin) {
/*Do not forget to copy getPinVoltage() 
from your main robot code*/
  float light = getPinVoltage(pin);
  Serial.println(light); // Use this line to test
  return (light > PHOTODIODE_LIGHT_THRESHOLD);
  }
float getPinVoltage(int pin) {
//This function can be used for many different tasks in the labs
//Study this line of code to understand what is going on!!
//What does analogRead(pin) do?
//Why is (float) needed?
//Why divide by 1024?
//Why multiply by 5?
return 5 * (float)analogRead(pin) / 1024;
}





