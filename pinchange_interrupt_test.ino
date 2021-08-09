// Pin Change Interrupt Test Program
// BUTTON_PIN must be pulled up and connected to GND via a tact sw.
//
// The built-in LED is toggled when the tact sw is pushed.

#include <avr/interrupt.h>

#define BUTTON_PIN  2
#define MY_PCINT    PCINT2  // Should be the same to the BUTTON_PIN
#define LED_PIN     1

volatile int sw_prev = HIGH;
volatile int sw_current;

void setup() {
  // put your setup code here, to run once:
  GIMSK |= (1<<PCIE);     // Pin change interrput is enabled
  PCMSK |= (1<<MY_PCINT); // Pin change interrupt of the button pin is enabled

  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

ISR(PCINT0_vect) {
  sw_current = digitalRead(BUTTON_PIN);  
  if ((sw_prev == HIGH) and (sw_current == LOW)) {
    digitalWrite(LED_PIN,!digitalRead(LED_PIN));
  }

  sw_prev = sw_current;
}
