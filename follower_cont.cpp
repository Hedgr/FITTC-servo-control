#include <Servo.h>

// C++ code
//

int in0 = A0;
int in1 = A1;

Servo srv;
int s_pin=13;

void setup()
{
  Serial.begin(9600);
  Serial.print("\n\n==============================\nserial began\n");  
  srv.attach(s_pin);
  pinMode(in0,INPUT);
  pinMode(in1,INPUT);
  pinMode(s_pin,OUTPUT);
}

void loop()
{
  if((digitalRead(in0)==HIGH)&&(digitalRead(in1)==LOW)) {
    srv.write(180);
  }
  else {
    if((digitalRead(in0)==LOW)&&(digitalRead(in1)==LOW)) {
      srv.write(90);
    }
    else {
      if ((digitalRead(in0)==LOW)&&(digitalRead(in1)==HIGH)) {
        srv.write(0);
      }
    }
  }
}
