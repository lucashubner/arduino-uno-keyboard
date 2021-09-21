/* Arduino USB HID Keyboard Demo
 * Random Key/Random Delay
 */
#include <Arduino.h>

uint8_t buf[8] = { 
  0 
 };   /* Keyboard report buffer */


bool state = false;

const int LED_PIN = 4;
const int F1_KEY = 3;


void releaseKey() 
{
 buf[0] = 0;
 buf[2] = 0;
 Serial.write( buf, 8 );
 delay(100);
}

void setup() 
{
  Serial.begin(9600);
  pinMode( LED_PIN, OUTPUT );
  pinMode( F1_KEY, INPUT_PULLUP );
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
}

void loop() {
  if ( digitalRead(F1_KEY) == 0 ){
    while( digitalRead(F1_KEY) == 0 )
      ;
    state = !state;
    digitalWrite(LED_PIN, state);
  }

  if ( state ) {
    buf[2] = 58;
    Serial.write( buf, 8 );
    releaseKey();
  }
}

