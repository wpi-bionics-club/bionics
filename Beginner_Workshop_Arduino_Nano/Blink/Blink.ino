/*
This program turns an LED on for 1 second, then turns it off for one second.
If having problems uploading to the board, change your bootloader.

---------- How to change your bootloader ----------
Tools --> Processor --> ATMega 328P (Old Bootloader)
-----------------------------------------------------
*/

// Variable assigning LED to pin 13
#define LED 13

void setup() {
  // put your setup code here, to run once:
  
  pinMode(LED, OUTPUT); // sets LED pin as output

}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(LED, HIGH);     // turn the LED on (HIGH is the voltage level)
  delay(1000);                 // wait for a second
  digitalWrite(LED, LOW);      // turn the LED off by making the voltage LOW
  delay(1000);                 // wait for a second
}



