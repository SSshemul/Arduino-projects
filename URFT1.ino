//UltraSonic detection program for URFT 1.0
//Entry date 28.01.2013, Version 1.0
//^^^$$$^^^Shebly Sadik Shemul^^^$$$^^^
//This work is licensed under the Creative Commons Attribution 3.0 Unported License. To view a copy of this license, visit http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
//weblink: https://github.com/SSshemul/Arduino-projects/blob/master/


//▒█▀▀▀█ ▒█▀▀▀█ ▒█▀▀▀█ 
//░▀▀▀▄▄ ░▀▀▀▄▄ ░▀▀▀▄▄ 
//▒█▄▄▄█ ▒█▄▄▄█ ▒█▄▄▄█ production ;)


#include <LiquidCrystal.h>
LiquidCrystal lcd (12, 11, 5, 4, 3, 2);

int URFOutputPin = 9; // TRIG 
int URFInputPin = 10;  // ECHO 
int URFOutputPin1 = 7; // TRIG 
int URFInputPin1 = 6;  // ECHO 

unsigned long distancetym;
unsigned long distancetym1; 
unsigned long cm1;
unsigned long cm2;
unsigned long cm;
unsigned long meter;

void setup(){
  lcd.begin(16, 2);
  pinMode(URFInputPin, INPUT);
  pinMode(URFOutputPin, OUTPUT);
     pinMode(URFInputPin1, INPUT);
  pinMode(URFOutputPin1, OUTPUT);
  
  lcd.print("....URFT 1.0....");
  delay(2000);
  lcd.clear();
  
  lcd.print("Initialising.");
  delay(300);
  lcd.print(".");
  delay(200);
  lcd.print(".");
  delay(100);
  lcd.print(".");
  lcd.clear();
    }
   
 
   
void loop () {
  //distance measurement 
  
  digitalWrite(URFOutputPin, LOW);
  delayMicroseconds(2);
  digitalWrite(URFOutputPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(URFOutputPin, LOW);   
  // the distance is proportional to the time interval
  // between HIGH and LOW
  distancetym = pulseIn(URFInputPin, HIGH); 
  cm1 = distancetym/58;
  lcd.clear();
  lcd.print("Left URF   ");
  lcd.print(cm1);
  delay(1000);
  lcd.clear();
  digitalWrite(URFOutputPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(URFOutputPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(URFOutputPin1, LOW);   
  // the distance is proportional to the time interval
  // between HIGH and LOW
  distancetym1 = pulseIn(URFInputPin1, HIGH);
  cm2 = distancetym1/58;
   lcd.clear();
  lcd.print("Right URF    ");
  lcd.print(cm2);
  delay(1000);
  lcd.clear();
  
  cm = (cm1+cm2+10);
  meter = cm/100;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Range:");
  lcd.setCursor(0,2);
  lcd.print(meter);
  lcd.print("m  or  ");
  lcd.print(cm);
  lcd.print("cm   ");
  
delay(3000);

}
