#include <HIDSerial.h>

HIDSerial serial;
bool bState = false;
int pinPower = 1;
unsigned char buffer[1];

void setup() {
  bState = false;
  pinMode(pinPower, OUTPUT);
  digitalWrite(pinPower, LOW);
  serial.begin();
}

void loop() {
  if(serial.available()) {
    int size = serial.read(buffer);
    if (size>0) {
      if(buffer[0]=='0'){
        bState = false;
        digitalWrite(pinPower, LOW);
        serial.write('0');
      }else if(buffer[0]=='1'){
        bState = true;
        digitalWrite(pinPower, HIGH);
        serial.write('1');
      }
    }
  }
  serial.poll();
}

