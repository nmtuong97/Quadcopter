
#include <SoftwareSerial.h>
SoftwareSerial mySerial(6,5); // RX, TX

int motor1 = 3;
int motor2 = 9;
int motor3 = 10;
int motor4 = 11;
char state;
int speeds1=0;
int speeds2=0;
int speeds3=0;
int speeds4=0;
int speeds;
void setup() {
 mySerial.begin(9600);
 Serial.begin(9600);
// Serial.println("Hello Quadcopter");
 pinMode(motor1,OUTPUT);
 pinMode(motor2,OUTPUT);
 pinMode(motor3,OUTPUT);
 pinMode(motor4,OUTPUT);
 //Serial.println("ok");
}

void loop() {
  if(mySerial.available()){
  state = mySerial.read();
 }

  
 if (state == '1' && speeds1 <=245){//tang toc motor1
    speeds1 = speeds1+5;
    state =0;
    delay(5);
    }else
    if (state == '2'&& speeds2 <=245){//tang toc moto2
    speeds2 = speeds2+5;
    state =0;
    delay(5);
    }else
    if (state == '3'&& speeds3 <=245){//tang toc motor3
      speeds3 = speeds3+5;
      state =0;
      delay(5);
    }else
    if (state == '4'&& speeds4 <=245){  //tang toc motor4
      speeds4 = speeds4+5;
      state =0;
      delay(5);
    }else
    if (state == '5'){//tang toc 4 motor
      speeds1 =speeds1+5;
      speeds2 =speeds2+5;
      speeds3 =speeds3+5;
      speeds4 =speeds4+5;
      state =0;
      delay(5);
    }else
    if (state == '6'){//tat 4 motor
      speeds1 =0;
      speeds2 =0;
      speeds3 =0;
      speeds4 =0;
      state =0;
      delay(5);
    }/*else
    if (state == '7'){//tien
      speeds1 =speeds1 + 10;
      speeds2 =speeds2 + 10;
      speeds3 =speeds3;
      speeds4 =speeds4;
      state =0;
      delay(5);
    }else
    if (state == '8'){//lui
      speeds3 =speeds3 + 10;
      speeds4 =speeds4 + 10;
      speeds1 =speeds1;
      speeds2 =speeds2;
      state =0;
      delay(5);
    }else
    if (state == '9'){//trai
      speeds1 =speeds1 + 10;
      speeds4 =speeds4 + 10;
      speeds3 =speeds3;
      speeds2 =speeds2;
      state =0;
      delay(5);
    }else
    if (state == '10'){//phai
      speeds3 =speeds1 + 10;
      speeds2 =speeds2 + 10;
      speeds1 =speeds1;
      speeds4 =speeds4;
      state =0;
      delay(5);
    }*/else
    if (state == '7'&& speeds1 >= 5){//giam motor 1
      speeds1 = speeds1-5;
      state =0;
      delay(5);
    }else
    if (state == '8' && speeds2 >= 5){//giam motor 2
      speeds2 = speeds2-5;
      state =0;
      delay(5);
    }else
    if (state == '9' && speeds3 >= 5){//giam motor 3
      speeds3 = speeds3-5;
      state =0;
      delay(5);
    }else
    if (state == '0' && speeds4 >= 5){//giam motor 4
      speeds4 = speeds4-5;
      state =0;
      delay(5);
    }
    analogWrite(motor1,speeds1);
    analogWrite(motor2,speeds2);
    analogWrite(motor3,speeds3);
    analogWrite(motor4,speeds4); 
}
