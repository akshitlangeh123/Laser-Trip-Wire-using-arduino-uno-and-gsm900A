#include<SoftwareSerial.h>
SoftwareSerial SIM900A(2,3);
int led = 13;
int sensor = A0;
int laser = 12;
int buzzer = 8;
void setup(){
SIM900A.begin(9600);
Serial.begin(9600);
pinMode(led, OUTPUT);
pinMode(laser, OUTPUT);
pinMode(sensor, INPUT);
pinMode(buzzer,OUTPUT);
}
void loop(){
digitalWrite(laser, HIGH);
delay(200);
int sensorReading = analogRead(sensor);
Serial.println(sensorReading);
if(sensorReading <900){
if(Serial.available()>0){
SendAlert();
}
digitalWrite(led, HIGH);
tone(buzzer, 1000);
delay(1000);
tone(buzzer, 1500);
delay(1000);
noTone(buzzer);
}
else{
digitalWrite(led,LOW);
}
}
void SendAlert(){
Serial.println("in");
SIM900A.println("AT+CMFG=1");
delay(1000);
Serial.println("senders");
SIM900A.println("AT+CMGS=\"+919770800886\"\r");
delay(1000);
Serial.println("sending");
SIM900A.println("Intruder Alert!");
delay(100);
SIM900A.println((char)26);
}