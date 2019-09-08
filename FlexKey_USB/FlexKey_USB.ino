/* HID KeyBoard Example
by: Jim Lindblom
date: 1/12/2012
license: MIT License - Feel free to use this code for any purpose.
No restrictions. Just keep this license if you go on to use this
code in your future endeavors! Reuse and share. 

This is very simplistic code that allows you to send a 'z' with
a momentary pushbutton. 
*/

#include <Keyboard.h>

int RXLED = 17;  // The RX LED has a defined Arduino pin
int buttonPin = 9;  // Set a button to any pin
int debounce = 0;
int count = 0;
#define THRESHOLD 500
#define ROLLOVER 1000

char *toType = "Hello, world!\n";

void setup()
{
  pinMode(RXLED, OUTPUT);  // Set RX LED as an output
  pinMode(buttonPin, INPUT);  // Set the button as an input
  digitalWrite(buttonPin, HIGH);  // Pull the button high
}

void typeString(char *str, int len) {
  for (int i = 0; i < len; i++) Keyboard.write(str[i]);
}

void loop()
{
  delay(1);
  count++;
  if (count == 1) TXLED0;
  else if (count == THRESHOLD) TXLED1;
  else if (count >= ROLLOVER) count = 0;

  if (digitalRead(buttonPin) == 0 && debounce == 0)  debounce = 1;
  if (debounce == 1)
  {
    digitalWrite(RXLED, LOW);   // set the RX LED ON
    typeString(toType, strlen(toType));
    debounce++;
  }
  else if (debounce > 0 && debounce < THRESHOLD) debounce++;
  else if (debounce >= THRESHOLD) {
    debounce = 0;
    digitalWrite(RXLED, HIGH);   // set the RX LED OFF    
  }
}
