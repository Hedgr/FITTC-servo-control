#include <Servo.h>

// C++ code
//

// board comms out pins
int out1_1=2;
int out1_2=3;
int out2_1=4;
int out2_2=5;

// board comms in pins
int in1=A0;
int in2=A1;

// outputs for the other arduinos to set their speeds with 
//(high/low==forward,low/low==stop,low/high==reverse and board is either 1 or 2) 
int set_speed(int board, int speed) {
  // decides what ports to use based on %board%
  int com1=-1;
  int com2=-1;
  if (board==1) {
    com1=out1_1;
    com2=out1_2;
  }
  else {
    com1=out2_1;
    com2=out2_2;
  }
  if(speed==3) {
    // code for full forward 
    digitalWrite(com1, HIGH);
    digitalWrite(com2,LOW);
    if(board==1) {
      Serial.print("motor 1 started (out1_1 set HIGH, out1_2 set LOW\n");
    }
    else {
      Serial.print("motor 2 started (out2_1 set HIGH, out 2_2 set LOW\n");
    }
  }
  else {
    // code for stopping
    if(speed==2) {
      digitalWrite(com1, LOW);
      digitalWrite(com2, LOW);
      if(board==1) {
        Serial.print("motor 1 stopped (out1_1 set LOW, out1_2 set LOW)\n");
      }
      else {
        Serial.print("motor 2 stopped (out2_1 set LOW, out2_2 set LOW)\n");
      }
    }
    else {
      // code for reverse
      digitalWrite(com1, LOW);
      digitalWrite(com2, HIGH);
      if(board==1) {
        Serial.print("motor 1 reversed (out1_1 set LOW, out1_2 set HIGH)\n");
      }
      else {
        Serial.print("motor 2 reversed (out2_1 set LOW, out2_2 set HIGH)\n");
      }
    }
  }
}

int coupled(int dir) {
  // assuming the motors spin in the right way and if they dont just change out last numbers
  if(dir==1) {
    set_speed(1,3);
    set_speed(2,1);
  }
  else {
    if(dir==0) {
      //dont have to change no matter what (not moving is not moving)
      set_speed(1,2);
      set_speed(2,2);
    }
    else {
      if(dir=-1) {
        set_speed(1, 1);
        set_speed(2, 3);
      }
      else {
        Serial.print("not a valid direction for motor\n");
      }
    } 
  }
  
}

void setup()
{
  Serial.begin(9600);
  Serial.print("\n\n===========================\nserial monitor begun\n");
  pinMode(out1_1, OUTPUT);
  pinMode(out1_2, OUTPUT);
  pinMode(out2_1, OUTPUT);
  pinMode(out2_2, OUTPUT);
}



void loop()
{
  
}
