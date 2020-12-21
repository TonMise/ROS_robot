#include <VNH3SP30.h>
VNH3SP30 Motor1;    
VNH3SP30 Motor2;
VNH3SP30 Motor3;    
VNH3SP30 Motor4;
#define M1_PWM 7  
#define M1_INA 6   
#define M1_INB 5
#define M2_PWM 4  
#define M2_INA 3   
#define M2_INB 2  
#define M3_PWM 13 
#define M3_INA 12 
#define M3_INB 11   
#define M4_PWM 8   
#define M4_INA 9    
#define M4_INB 10
int ch1 = 23;
int ch2 = 25;
int ch3 = 27;
int ch4 = 29;
float S1;
float S2;
float S3;
float S4;
float thd = 0.01;
int Min = 993;
int Cent = 1500;
int Max = 2007; 

void setup() {
  Motor1.begin(M1_PWM, M1_INA, M1_INB, -1, -1); 
  Motor2.begin(M2_PWM, M2_INA, M2_INB, -1, -1); 
  Motor3.begin(M3_PWM, M3_INA, M3_INB, -1, -1); 
  Motor4.begin(M4_PWM, M4_INA, M4_INB, -1, -1); 
int ch1 = 23;
int ch2 = 25;
int ch3 = 27;
int ch4 = 29;

  Motor1.setSpeed(0);
  Motor2.setSpeed(0);
  Motor3.setSpeed(0);
  Motor4.setSpeed(0);
  Serial.begin(115200);
}

void loop() {
  m1();
  m2();
  m3();
  m4();
  }
void m1(){
  float CH1;
  CH1 = pulseIn(ch1, HIGH);
  if (CH1<Max && CH1>Min){
    if (CH1<(Cent*(1+thd)) && CH1>(Cent*(1-thd))){
      S1 = 0;
      Motor1.setSpeed(S1);
      Serial.print("Zero");
      Serial.print("|");
      }
    else{
      S1 = map(pulseIn(ch1, HIGH), Min, Max, -400, 400);
      Motor1.setSpeed(S1);
      Serial.print(S1);
      Serial.print("|"); 
    } 
    }
   else{
      S1 = 0;
      Motor1.setSpeed(S1);
      Serial.print("No Signal");
      Serial.print("|");
   } 
  }
void m2(){
  float CH2;
  CH2 = pulseIn(ch2, HIGH);
  if (CH2<Max && CH2>Min){
    if (CH2<(Cent*(1+thd)) && CH2>(Cent*(1-thd))){
      S2 = 0;
      Motor2.setSpeed(S2);
      Serial.print("Zero");
      Serial.print("|");
      }
    else{
      S2 = map(pulseIn(ch2, HIGH), Min, Max, -400, 400);
      Motor2.setSpeed(S2);
      Serial.print(S2);
      Serial.print("|"); 
    } 
    }
   else{
      S2 = 0;
      Motor2.setSpeed(S2);
      Serial.print("No Signal");
      Serial.print("|");
   } 
  }
void m3(){
  float CH3;
  CH3 = pulseIn(ch3, HIGH);
  if (CH3<Max && CH3>Min){
    if (CH3<(Cent*(1+thd)) && CH3>(Cent*(1-thd))){
      S3 = 0;
      Motor3.setSpeed(S3);
      Serial.print("Zero");
      Serial.print("|");
      }
    else{
      S3 = map(pulseIn(ch3, HIGH), Min, Max, -400, 400);
      Motor3.setSpeed(S3);
      Serial.print(S3);
      Serial.print("|"); 
    } 
    }
   else{
      S3 = 0;
      Motor3.setSpeed(S3);
      Serial.print("No Signal");
      Serial.print("|");
   } 
  }

void m4(){
  float CH4;
  CH4 = pulseIn(ch4, HIGH);
  if (CH4<Max && CH4>Min){
    if (CH4<(Cent*(1+thd)) && CH4>(Cent*(1-thd))){
      S4 = 0;
      Motor4.setSpeed(S4);
      Serial.print("Zero");
      Serial.print("|");
      Serial.println();
      }
    else{
      S4 = map(pulseIn(ch4, HIGH), Min, Max, -400, 400);
      Motor4.setSpeed(S4);
      Serial.print(S4);
      Serial.print("|"); 
      Serial.println();
    } 
    }
   else{
      S4 = 0;
      Motor4.setSpeed(S4);
      Serial.print("No Signal");
      Serial.print("|");
      Serial.println();
   } 
  }
