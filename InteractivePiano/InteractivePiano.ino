#include <CapacitiveSensor.h>
CapacitiveSensor   cs_2_3 = CapacitiveSensor(2,3);        // 10M resistor between pins 2 & 3, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_2_4 = CapacitiveSensor(2,4);        // 10M resistor between pins 2 & 4, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_2_5 = CapacitiveSensor(2,5);        // 10M resistor between pins 2 & 5, pin 2 is sensor pin, add a wire and or foil if desired
void setup() {
  cs_2_3.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  
  // Arduino start communicate with computer.
  Serial.begin(9600);
}

void loop() {
    // Set the sensitivity of the sensors.
    long total1 =  cs_2_3.capacitiveSensor(30);
    long total2 =  cs_2_4.capacitiveSensor(30);
    long total3 =  cs_2_5.capacitiveSensor(30);
  
    Serial.print(total1);                  // print sensor output 1
    Serial.print("\n");
    Serial.print(total2);                  // print sensor output 2
    Serial.print("\n");
    Serial.print(total3);                  // print sensor output 3
    Serial.print("\n");
    delay(1000);
}
