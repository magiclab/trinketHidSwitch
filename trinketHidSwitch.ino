#include <HIDSerial.h>

HIDSerial serial;
bool bState = false;
bool bPingLight = false;
int nFrames = 0;
const int maxFrames = 20000;
int pinLed = 1;
int pinPower = 2;
unsigned char buffer[1];

void setup() {
  bState = false;
  bPingLight = false;
  nFrames = 0;
  pinMode(pinPower, OUTPUT);
  digitalWrite(pinPower, HIGH);
  serial.begin();
}

void loop() {
  if(bPingLight){
    nFrames++;
    if(nFrames>maxFrames){
      bPingLight=false;
      nFrames = 0;
      if(bState==false){
        digitalWrite(pinLed, LOW);
      }
      serial.write('r');
      serial.poll();
      return;
    }
  }
  
  if(serial.available()) {
    int size = serial.read(buffer);
    if (size>0) {
      if(buffer[0]=='0'){
        bState = false;
        digitalWrite(pinLed, LOW);
        digitalWrite(pinPower, HIGH);
        serial.write('0');
      }else if(buffer[0]=='1'){
        bState = true;
        digitalWrite(pinLed, HIGH);
        digitalWrite(pinPower, LOW);
        serial.write('1');
      }else{
        if(bPingLight==false){
          bPingLight = true;
          nFrames = 0;
          digitalWrite(pinLed,HIGH);
          serial.write('p');
        }
      }
    }
  }
  serial.poll();
}

