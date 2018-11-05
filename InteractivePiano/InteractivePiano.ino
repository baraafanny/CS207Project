#include <CapacitiveSensor.h>
#define speaker 12

CapacitiveSensor   cs_2_3 = CapacitiveSensor(2,3);        // 10M resistor between pins 2 & 3, pin 2 is sensor pin
CapacitiveSensor   cs_2_4 = CapacitiveSensor(2,4);        // 10M resistor between pins 2 & 4, pin 2 is sensor pin
CapacitiveSensor   cs_2_5 = CapacitiveSensor(2,5);        // 10M resistor between pins 2 & 5, pin 2 is sensor pin
void setup() {
  // Identify the piezobuzzer pin as output
  pinMode(12, OUTPUT);
  cs_2_3.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  
  // Arduino start communicate with computer.
  Serial.begin(9600);
}

void loop() {
  // Set the sensitivity of the sensors.
  long total1 =  cs_2_3.capacitiveSensor(30);
  long total2 =  cs_2_4.capacitiveSensor(30);
  long total3 =  cs_2_5.capacitiveSensor(30);
  
  Serial.print("\n One \n");
  Serial.print(total1); // print sensor output 1
  Serial.print("\n Two \n");
  Serial.print(total2); // print sensor output 2
  Serial.print("\n Three\n");
  Serial.print(total3); // print sensor output 3
  
  // If-statements for playing a tone on the piezobuzzer according to sensor input
  if (total1 > 20) 
    tone(speaker,523);
  if (total2 > 20) 
    tone(speaker,587);
  if (total3 > 20) 
    tone(speaker,659);
  
   // When there is no/not enough sensor input turn off the sound
   if (total1<=20  &  total2<=20  &  total3<=20)
    noTone(speaker);
  
   delay(10); 
}
