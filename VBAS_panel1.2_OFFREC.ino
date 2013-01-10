
//UltraSonic detection program for VBAS 1.0

//Entry date 7.1.2013, Version 1.2

//^^^$$$^^^Shebly Sadik Shemul^^^$$$^^^

//This work is licensed under the Creative Commons Attribution 3.0 Unported License. To view a copy of this license, visit http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
//weblink: https://github.com/SSshemul/Arduino-projects/blob/master/IIFCS_BCSIR.ino


//▒█▀▀▀█ ▒█▀▀▀█ ▒█▀▀▀█ 
//░▀▀▀▄▄ ░▀▀▀▄▄ ░▀▀▀▄▄ 
//▒█▄▄▄█ ▒█▄▄▄█ ▒█▄▄▄█ production ;)


#include <LiquidCrystal.h>

int dypOutputPin = 9; // TRIG 
int dypInputPin = 10;  // ECHO 

long distance = 0;
long cm = 0;
long meter = 0;

LiquidCrystal lcd (12, 11, 5, 4, 3, 2);

int warningled =6;
int vpin1 = 7;
int vpin2 = 8;


void setup(){


  lcd.begin(16, 2);
  pinMode(vpin1, OUTPUT);
  pinMode(vpin2, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  
  pinMode(warningled, OUTPUT);
  pinMode(dypOutputPin, OUTPUT);
  pinMode(dypInputPin,INPUT);
  lcd.print("....VBAS 1.0....");
  delay(2000);
  lcd.clear();
  lcd.print("By SSS & RAA ;)");
  delay(2000);
  lcd.clear();
  lcd.print("Initialising.");
  delay(1000);
  lcd.print(".");
  delay(1000);
  lcd.print(".");
  delay(1000);
  lcd.print(".");

  lcd.clear();


}
void loop()
{
  
  // The DYP-ME007 pings on the low-high flank...
  digitalWrite(dypOutputPin, LOW);
  delayMicroseconds(2);
  digitalWrite(dypOutputPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(dypOutputPin, LOW);   
  // the distance is proportional to the time interval
  // between HIGH and LOW
  distance = pulseIn(dypInputPin, HIGH); 
  cm = distance/58;
  meter = cm/100;  
delay(1000);
  lcd.setCursor(0,0);
  lcd.print("Range detected:");
  lcd.setCursor(0,2);
  lcd.print(meter);
  lcd.print("m  or  ");
  lcd.print(cm);
  lcd.print("cm   ");
  lcd.println();
  

  if(cm > 15 && cm < 50){
    delay(500);
    if( cm > 30 && cm < 40){
      
      digitalWrite(vpin1, HIGH);
        digitalWrite(vpin2, HIGH);
        
        lcd.clear();
        lcd.print("....Warning....");
        lcd.setCursor(0,2);
        lcd.println("Collision Imminent");
        delay(1000);
        
        digitalWrite(vpin1, LOW);
        digitalWrite(vpin2, LOW);
    }
  }
  if (cm > 1 && cm < 15){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("allah r nam neo :P");
    lcd.setCursor(0,2);
    lcd.println("dhakka laglo :O :O  ");
    digitalWrite(vpin1, HIGH);
    digitalWrite(vpin2, HIGH);
    digitalWrite(warningled, HIGH);
    delay(800);
    digitalWrite(vpin1, LOW);
    digitalWrite(vpin2, LOW);
    digitalWrite(warningled, LOW);
    delay(800);
    digitalWrite(vpin1, HIGH);
    digitalWrite(vpin2, HIGH);
    digitalWrite(warningled, HIGH);
    delay(800);
    digitalWrite(vpin1, LOW);
    digitalWrite(vpin2, LOW);
    digitalWrite(warningled, LOW);
    delay(800);

  }
  
  if (cm > 0 && cm < 15 ){            
  digitalWrite(A1, HIGH);
  digitalWrite(A5, HIGH);
  digitalWrite(A4, HIGH);
  digitalWrite(A3, HIGH);
  delay(500);
  }
  if (cm > 16 && cm < 25 ){            
  digitalWrite(A1, LOW);
  digitalWrite(A5, HIGH);
  digitalWrite(A4, HIGH);
  digitalWrite(A3, HIGH);
  delay(500);
}
if (cm > 26 && cm < 30 ){            
  digitalWrite(A1, LOW);
  digitalWrite(A5, LOW);
  digitalWrite(A4, HIGH);
  digitalWrite(A3, HIGH);
  delay(500);
  
  
}
if (cm > 31 && cm < 800 ){            
  digitalWrite(A1, LOW);
  digitalWrite(A5, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A3, HIGH);
  delay(500);
  
  
}

if (cm == 0 ){            
  digitalWrite(A1, LOW);
  digitalWrite(A5, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A3, LOW);
  delay(500);
  
  
}


}



