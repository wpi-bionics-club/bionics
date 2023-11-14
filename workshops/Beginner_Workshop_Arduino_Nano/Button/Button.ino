/*
This program is for handling input from a button
and turning that into output. This project used
an arduino nano, but can use any other arduino board.

If you are running into errors with uploading from your computer
Please change the bootloader to the old bootloader.

---------- How to change your bootloader ----------
Tools --> Processor --> ATMega 328P (Old Bootloader)
-----------------------------------------------------
*/

// variable definitions
#define BUTTON 2
#define PIN1 5
#define PIN2 6
#define PIN3 7
int clicks = 0;

void setup() {
  // put your setup code here, to run once:

/*
  sets BUTTON pin with internal pull up resistor.
  this inverts the output. So when reading from this
  pin, the default value is 1 (HIGH) when the button
  is not pressed.

  So when the button is not pressed digitalRead() will
  return 1, and when the button is pressed, the button
  will return 0.
*/
  pinMode(BUTTON, INPUT_PULLUP); 
  pinMode(PIN1, OUTPUT); // Pin 5 as output
  pinMode(PIN2, OUTPUT); // Pin 6 as output
  pinMode(PIN3, OUTPUT); // Pin 7 as output

// you must set the LEDs off at the beginning of your program.
  digitalWrite(PIN1, LOW);
  digitalWrite(PIN2, LOW);
  digitalWrite(PIN3, LOW);
}



void loop() {
  // put your main code here, to run repeatedly:
  
  int val = digitalRead(BUTTON); // reads from button pin. val = 0, if pressed

// when each button is pressed turn off all the LEDs and increment clicks
  if (val == LOW){
    clicks++;
    digitalWrite(PIN1, LOW);
    digitalWrite(PIN2, LOW);
    digitalWrite(PIN3, LOW);
  }

/** this allows for circular indexing. this means that the
 variable toSwitch will only contain values: 0, 1, 2, or 3

 This is done using the modulo operator which returns the remainder
 a number when divided by that number. 

 For example: 15 % 3 = 0

 when you divide 15 by 3, there is no remainder. 
 
 so 0 % 3 = 0; when 0 is divided by 3, there is no remainder.
    1 % 3 = 1; when 1 is divided by 3, the answer is 0 remainder 1.
    2 % 3 = 2; when 2 is divided by 3, the answer is 0 remainder 2.
    3 % 3 = 0; see the pattern? 3 divided by 3 has no remainder!
    4 % 3 = 1; and the cycle continues. 

    so modulo just returns the remainder of a division.
 **/

int toSwitch = clicks % 4;
  
  /*
  A switch case is equivalent to a bunch of if statements. 
  However, they are best used when you know the finite
  values a variable can have. 

  A switch case is commonly preferred because it is 
  syntactically cleaner and allows for easy readability. 
  */

  switch(toSwitch) {
    // when the button has been pressed once, turn on the first LED.
  
    case 1:
    digitalWrite(PIN1, HIGH);
    break;

    // when the button has been pressed once, turn on the first LED.
    case 2: 
    digitalWrite(PIN2, HIGH);
    break;
    
    // when the button has been pressed once, turn on the first LED.
    case 3:
    digitalWrite(PIN3, HIGH);
    break;
  }

  
}

