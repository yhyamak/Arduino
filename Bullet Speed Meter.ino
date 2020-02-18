 long time1= 0;
 long time2=1;
 long t=100000;
  long a;
  int s=0;
  long dis=100;
const byte in1 = 4;
const byte in2 = 23;
const byte out1 = 13;
const byte out2 = 12;
String msgVal="1";
#include <WiFi.h>
char * ssid = (char*) malloc(40);
const char* password = "123456789";

void setup() {
    pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  digitalWrite(out1, HIGH);
  digitalWrite(out2, HIGH);
  Serial.begin(115200);
  pinMode(in1, INPUT_PULLUP);
    pinMode(in2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(in1), t1, FALLING );
  attachInterrupt(digitalPinToInterrupt(in2), t2, FALLING );
 
}

void loop() {
Serial.println(digitalRead(in1));
Serial.println(digitalRead(in2));
Serial.println("---------");
if (s==1){
msgVal=String(a);
  ssid = (char*) malloc(msgVal.length()+2); 
 msgVal.toCharArray(ssid, msgVal.length()+2);
WiFi.softAP(ssid, password);
s=0;
}
else {
}
delay (2000);

}


void t1() { 
 time1 = micros() ;
 detachInterrupt(digitalPinToInterrupt(in1)); 
}



void t2() { 
 time2 = micros() ;
 t= time2 - time1;

 if (t==0){
  a= 0;
 }
 else {
   detachInterrupt(digitalPinToInterrupt(in2));
  a=dis*10000/t;
   Serial.println(time2);
    Serial.println(time1);
   Serial.println("time is  :"+ String(t) + " microsecond");
 
 Serial.println("speed is :" + String(a)+" M/S");
s=1;
 }
 }


 
