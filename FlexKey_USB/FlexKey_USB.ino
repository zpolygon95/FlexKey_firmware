// Based on the example code in the Sparkfun ProMicro hookup guide
// https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide
// Original licence text below:

/* HID KeyBoard Example
by: Jim Lindblom
date: 1/12/2012
license: MIT License - Feel free to use this code for any purpose.
No restrictions. Just keep this license if you go on to use this
code in your future endeavors! Reuse and share. 
*/

#include <Keyboard.h>

int RXLED = 17;  // The RX LED has a defined Arduino pin
int buttonPin = 9;  // Set a button to any pin
int debounce = 0;
int count = 0;
#define THRESHOLD 500
#define ROLLOVER 1000

char hidBuf[256];
int hidIdx = 0;
char cur;

void setup()
{
  pinMode(RXLED, OUTPUT);  // Set RX LED as an output
  pinMode(buttonPin, INPUT);  // Set the button as an input
  digitalWrite(buttonPin, HIGH);  // Pull the button high
  Serial.begin(9600);
  Serial1.begin(9600);
}

void typeString(char *str, int len) {
  for (int i = 0; i < len; i++) Keyboard.write(str[i]);
}

void loop()
{
  delay(1);
  count++;
  if (count == 1) {
    TXLED0;
//    Serial1.print(".");
  }
  else if (count == THRESHOLD) {
    TXLED1;
  }
  else if (count >= ROLLOVER) count = 0;

  while (Serial1.available() > 0) {
    cur = (char) Serial1.read();
    Serial.write(cur);
    if (hidIdx == 0 && cur == '\\') hidBuf[hidIdx++] = cur;
    else if (hidIdx > 0 && hidBuf[hidIdx - 1] == '\\') {
      // Define escape sequences here
      if (cur == '0') {
        // "\0" - End of packet
        typeString(&hidBuf[2], hidIdx - 3);
        hidIdx = 0;
        Serial1.print("OK");
      } else if (cur == '1') {
        // "\1" - Start of packet
        hidBuf[hidIdx++] = cur;
      } else if (cur == '\\') {
        // "\\" - Literal backslash
        // There's already a backslash in the buffer at the correct point. This is a NOP
      } else if (cur == 't') {
        // "\t" - Tab
        hidBuf[hidIdx - 1] = '\t';
      } else if (cur == 'n') {
        // "\n" - New line
        hidBuf[hidIdx - 1] = '\n';
      } else {
        // Unknown Control Character
        hidIdx = 0;
        Serial1.print(cur);
        Serial1.print("?");
      }
    } else if (hidIdx > 0) {
      hidBuf[hidIdx++] = cur;
    } else {
      // Unknown State
      hidIdx = 0;
      Serial1.print("?");
    }
  }
}
