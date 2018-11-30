#include <CapacitiveSensor.h>
#define speaker 12
#define button 13

int buttonState = 0;
int lastButtonState = 0;
int toneMode = 0;
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
  pinMode(speaker, OUTPUT);
   // Identify the button pin as input
  pinMode(button, INPUT);
  
  // Arduino start communicate with computer.
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(button); // Our pullup btn, low if not pushed
  // Set the sensitivity of the sensors.
  long total1 =  cs_2_3.capacitiveSensor(30);
  long total2 =  cs_2_4.capacitiveSensor(30);
  long total3 =  cs_2_5.capacitiveSensor(30);
  long total4=   cs_2_6.capacitiveSensor(30);
  long total5 =  cs_2_7.capacitiveSensor(30);
  long total6 =  cs_2_8.capacitiveSensor(30);
  long total7 =  cs_2_9.capacitiveSensor(30);
  Serial.print("\n Button \n");
  Serial.println(buttonState);
  
  Serial.print("\n One \n");
  Serial.print(total1); // print sensor output 1
  Serial.print("\n Two \n");
  Serial.print(total2); // print sensor output 2
  Serial.print("\n Three\n");
  Serial.print(total3); // print sensor output 3
  Serial.print("\n Four \n");
  Serial.print(total4); // print sensor output 1
  Serial.print("\n Five \n");
  Serial.print(total5); // print sensor output 2
  Serial.print("\n Six \n");
  Serial.print(total6); // print sensor output 3
  Serial.print("\n Seveen \n");
  Serial.print(total7); // print sensor output 3

  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      // Change var here
      Serial.println("IN IF");
      if(toneMode == 1)
        toneMode = 0;
      else
        toneMode = 1;
    }
  }
  // If-statements for playing a tone on the piezobuzzer according to the sensors input
  // Green gummybear input
  if (total1 > 60 && toneMode == 0) 
    tone(speaker,523);
  // Pop can input
  if (total2 > 80 && toneMode == 0) 
    tone(speaker,587);
  // Red gummy bear input
  if (total3 > 60 && toneMode == 0) 
    tone(speaker,659);
  // Yellow gummy bear input
  if (total4 > 60 && toneMode == 0)
    tone(speaker,698);
  if (total5 > 60 && toneMode == 0)
    tone(speaker,784);
  // Coin input
  if (total6 > 70 && toneMode == 0)
    tone(speaker,880);
  if (total7 > 60 && toneMode == 0)
    tone(speaker,988);
  
   // When there is no/not enough sensor input turn off the sound
   if (total1<=60  &  total2<=80  &  total3<=60 & total4<=60  &  total5<=60  &  total6<=70 &  total7<=60)
    noTone(speaker);

   lastButtonState = buttonState;
   delay(10); 
}
