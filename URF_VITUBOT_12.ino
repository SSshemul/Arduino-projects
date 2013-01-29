//UltraSonic detection program for VITUBOT 1.0

//Entry date 17.10.2013, Version 1.2

//^^^$$$^^^Shebly Sadik Shemul^^^$$$^^^

//This work is licensed under the Creative Commons Attribution 3.0 Unported License. To view a copy of this license, visit http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
//weblink: https://github.com/SSshemul/


//▒█▀▀▀█ ▒█▀▀▀█ ▒█▀▀▀█ 
//░▀▀▀▄▄ ░▀▀▀▄▄ ░▀▀▀▄▄ 
//▒█▄▄▄█ ▒█▄▄▄█ ▒█▄▄▄█ production ;)

int URFOutputPin = 11; // TRIG (orange wire)
int URFInputPin = 12;  // ECHO (white wire)

long distancetym;//variable 
long cm;
long meter;
int ondelayTime = 5;

//pins as output - 2,3,4,7,8>>4,5,6,13,14 for CHIP
int onPin = 4;
int lPin = 5;
int rPin = 6;

int spdPin = 7;
int brkPin = 8;

int delayledPin = 2;
int cautionledPin = 3;
int caution2ledPin = 9;
int cautionbuzzerPin = 10;

int startswitch = 6;


void setup(){
  pinMode(delayledPin, OUTPUT);
  pinMode(onPin, OUTPUT);
  pinMode(brkPin, OUTPUT);
  pinMode(spdPin, OUTPUT);
  pinMode(lPin, OUTPUT);
  pinMode(rPin, OUTPUT);
  
  pinMode(URFInputPin, INPUT);
  pinMode(URFOutputPin, OUTPUT);
  pinMode(startswitch, INPUT);
  
 
  digitalWrite(onPin, HIGH);//starting motorpower on,brake on
  digitalWrite(brkPin, HIGH);
  digitalWrite(spdPin, LOW);
  digitalWrite(lPin, LOW);
  digitalWrite(rPin, LOW);
 
 
     
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
  cm = distancetym/58;

delay(100);

if( cm > 300){
  highpace();
}

if( 150 < cm <300){
 normalpace();
}

if(50 < cm <150 ){
  lowpace();
}
if( 0 < cm < 30){
  hardbrake();
}
  if ( cm == 0){
    error();
  }
}


int highpace(){
  digitalWrite(cautionledPin, LOW);
  digitalWrite(caution2ledPin, LOW);
  digitalWrite(brkPin, LOW);
  digitalWrite(spdPin, HIGH);
  
}

int normalpace(){
  digitalWrite(cautionledPin, LOW);
  digitalWrite(caution2ledPin, LOW);
  digitalWrite(brkPin, LOW);
  digitalWrite(spdPin, HIGH);
  digitalWrite(spdPin, LOW);
}
int lowpace(){
  digitalWrite(cautionledPin, HIGH);
  digitalWrite(brkPin, LOW);
  digitalWrite(brkPin, HIGH);
  digitalWrite(brkPin, LOW);
}
int hardbrake(){
 digitalWrite(cautionledPin, HIGH);
 digitalWrite(caution2ledPin, HIGH);
 digitalWrite(cautionbuzzerPin, HIGH);
  digitalWrite(rPin, HIGH);
  
  digitalWrite(brkPin, HIGH);
  digitalWrite(rPin, LOW);
}

int error(){
  digitalWrite(cautionledPin, HIGH);
 digitalWrite(caution2ledPin, HIGH);
 delay(500);
 digitalWrite(cautionledPin, LOW);
  digitalWrite(caution2ledPin, LOW);
 delay(500);
 digitalWrite(cautionledPin, HIGH);
 digitalWrite(caution2ledPin, HIGH);
 delay(500);
 digitalWrite(cautionledPin, LOW);
  digitalWrite(caution2ledPin, LOW);
}
  
