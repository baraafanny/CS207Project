#include <CapacitiveSensor.h>
#define speaker 12

// Defining the send and receive pins for the different capacitive sensors. Pin 2 is the sensor pin. 
CapacitiveSensor   cs_2_3 = CapacitiveSensor(2,3);        // 10M resistor between pins 2 & 3
CapacitiveSensor   cs_2_4 = CapacitiveSensor(2,4);        // 10M resistor between pins 2 & 4
CapacitiveSensor   cs_2_5 = CapacitiveSensor(2,5);        // 10M resistor between pins 2 & 5
CapacitiveSensor   cs_2_6 = CapacitiveSensor(2,6);        // 10M resistor between pins 2 & 6
CapacitiveSensor   cs_2_7 = CapacitiveSensor(2,7);        // 10M resistor between pins 2 & 7
CapacitiveSensor   cs_2_8 = CapacitiveSensor(2,8);        // 10M resistor between pins 2 & 8
CapacitiveSensor   cs_2_9 = CapacitiveSensor(2,9);        // 10M resistor between pins 2 & 9
void setup() {
  // Identify the piezobuzzer pin as output
  pinMode(12, OUTPUT);
  
  // Arduino start communicate with computer.
  Serial.begin(9600);
}

void loop() {
  // Set the sensitivity of the sensors.
  long total1 =  cs_2_3.capacitiveSensor(30);
  long total2 =  cs_2_4.capacitiveSensor(30);
  long total3 =  cs_2_5.capacitiveSensor(30);
  long total4=   cs_2_6.capacitiveSensor(30);
  long total5 =  cs_2_7.capacitiveSensor(30);
  long total6 =  cs_2_8.capacitiveSensor(30);
  long total7 =  cs_2_9.capacitiveSensor(30);
  
  Serial.print("\n One \n");
  //Serial.print(total1); // print sensor output 1
  Serial.print("\n Two \n");
  Serial.print(total2); // print sensor output 2
  Serial.print("\n Three\n");
  //Serial.print(total3); // print sensor output 3
  Serial.print("\n Four \n");
  //Serial.print(total4); // print sensor output 1
  Serial.print("\n Five \n");
  //Serial.print(total5); // print sensor output 2
  Serial.print("\n Six \n");
  //Serial.print(total6); // print sensor output 3
  Serial.print("\n Seveen \n");
  //Serial.print(total7); // print sensor output 3
  
  
  // If-statements for playing a tone on the piezobuzzer according to the sensors input
  if (total1 > 20) 
    tone(speaker,523);
  if (total2 > 50) 
    tone(speaker,587);
  if (total3 > 20) 
    tone(speaker,659);
  if (total4 > 20)
    tone(speaker,698);
  if (total5 > 20)
    tone(speaker,784);
  if (total6 > 20)
    tone(speaker,880);
  if (total7 > 20)
    tone(speaker,988);
  
   // When there is no/not enough sensor input turn off the sound
   if (total1<=150  &  total2<=150  &  total3<=150 & total4<=150  &  total5<=150  &  total6<=150 &  total7<=150)
    noTone(speaker);
  
   delay(10); 
}
