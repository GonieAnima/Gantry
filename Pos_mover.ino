#include <Stepper.h>

int pos_x=0;
int pos_y=0;
int pos_x_new;
int pos_y_new;                
int steps=200;                //pasos por rotación

int outLight=13;
int ans;
int dump;

int endY=2;
int Ylim;
int endX=3;
int Xlim;

Stepper x_stepper(steps, 4, 5, 6, 7);   //eje x
Stepper y_stepper(steps, 8, 9, 10, 11); //eje y

void setup(){
  x_stepper.setSpeed(30); //rpm
  y_stepper.setSpeed(30); //rpm
  pinMode(outLight,OUTPUT);
  pinMode(endY,INPUT);
  pinMode(endX,INPUT);
  Serial.begin(115200);
  Serial.setTimeout(1);
  resetGan();
}

void loop(){
}

void resetGan(){
  Ylim=digitalRead(endY);
  Xlim=digitalRead(endX);
  while (Xlim!=0){
    x_stepper.step(-1); 
    Xlim=digitalRead(endX);
  }
  while (Ylim!=0){
    y_stepper.step(-1); 
    Ylim=digitalRead(endY);
  }
  pos_y=0;
  pos_x=0;
}

void move_poss(){
      if( pos_x <= 0 || pos_x>1600 )
}

//void test(){
//  x_stepper.step(1); 
//  pos_x=pos_x+1;
//  x_stepper.step(1);
//  pos_x=pos_x+1;
//  Serial.println(pos_x);
//}

void blink(){
  digitalWrite(outLight,HIGH);
  delay(200);
  digitalWrite(outLight,LOW);
  delay(200);
}

void mtp_x(){
  delay(20);
}