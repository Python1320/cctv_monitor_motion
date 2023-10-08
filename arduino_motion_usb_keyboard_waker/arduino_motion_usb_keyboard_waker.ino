#include "DigiKeyboard.h"
#define MOD_CONTROL_LEFT (1 << 0)
int inPin = 2;
int val = 0;
int prev = 0;
int toggle = 0;
#define MOD_SHIFT_LEFT (1 << 1)
void setup()
{
    pinMode(inPin, INPUT);
    pinMode(1, OUTPUT);
    DigiKeyboard.sendKeyStroke(0);
}

void loop()
{
    val = digitalRead(inPin);
    if (val != prev)
    {
        prev = val;
        toggle = !toggle;
        digitalWrite(1, toggle ? HIGH : LOW);
        DigiKeyboard.sendKeyStroke(0, MOD_SHIFT_LEFT);
    }
    DigiKeyboard.delay(100);
}