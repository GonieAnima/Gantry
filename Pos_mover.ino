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
  x_stepper.setSpeed(100); //rpm
  y_stepper.setSpeed(100); //rpm
  pinMode(outLight,OUTPUT);
  pinMode(endY,INPUT);
  pinMode(endX,INPUT);
  Serial.begin(115200);
  Serial.setTimeout(1);
  resetGan();
}

void loop(){
  receivePositions();
  validatePositions();
  moveToPositions();

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

void receivePositions() {
  while (Serial.available() == 0) {
  
  }
    String input = Serial.readStringUntil('\n');
    int commaIndex = input.indexOf(',');

    if (commaIndex > 0 && input.length() > commaIndex + 1) {                        
      pos_x_new = input.substring(0, commaIndex).toInt();
      pos_y_new = input.substring(commaIndex + 1).toInt();

      // Validate received positions to ensure they are within expected ranges
      if (!isDigit(input.charAt(0)) || !isDigit(input.charAt(commaIndex + 1))) {
        blink();
      }

    } 
    else {
    }
}

void validatePositions() {
  if (pos_x_new >= 0 && pos_x_new <= 1200 && pos_y_new >= 0 && pos_y_new <= 1600) {

    // Add your code to handle valid positions here
  } else {

  }
}

void moveToPositions() {
  int steps_x = pos_x_new - pos_x;
  int steps_y = pos_y_new - pos_y;

  x_stepper.step(steps_x);
  y_stepper.step(steps_y);

  pos_x = pos_x_new;
  pos_y = pos_y_new;

}
