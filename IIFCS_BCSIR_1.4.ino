//Automated Irrigation & Ferzilizer program for IIFCS

//Entry date 26.12.2012, Version 1.3

//^^^$$$^^^Shebly Sadik Shemul^^^$$$^^^

//This work is licensed under the Creative Commons Attribution 3.0 Unported License. To view a copy of this license, visit http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
//weblink: https://github.com/SSshemul/Arduino-projects/blob/master/IIFCS_BCSIR.ino


//▒█▀▀▀█ ▒█▀▀▀█ ▒█▀▀▀█ 
//░▀▀▀▄▄ ░▀▀▀▄▄ ░▀▀▀▄▄ 
//▒█▄▄▄█ ▒█▄▄▄█ ▒█▄▄▄█ production ;)


// TEST ONLY FOR BCSIR Science Fair...
//delay time shorten
//TIME change, mash = hour, tarikh = minute, ghonta = second. 

#include <Wire.h>
#include "RTClib.h"

long mash;
long tarikh;
long ghonta;
long minut;

int humidity = 0;
int lowestrh = 0;

 

int waterlow = 4;//water level indicator (red)
int waterlevel1 = 5;//yellow indicators
int waterlevel2 = 6;
int waterlevel3 = 7;
int waterlevel4 = 8;


int motorRelay = 9;//water relay er jonno
int fRelay = 10;//fertilizer relay er jonno
int powerled = 3;//power on LED
int criticalled = 2;

RTC_DS1307 RTC;

void setup () {
  pinMode(waterlow, OUTPUT);
  pinMode(waterlevel1, OUTPUT);
  pinMode(waterlevel2, OUTPUT);
  pinMode(waterlevel3, OUTPUT);
  pinMode(waterlevel4, OUTPUT);

  pinMode(motorRelay, OUTPUT);

  pinMode(powerled, OUTPUT);
  pinMode(criticalled, OUTPUT);


  digitalWrite(powerled, HIGH);//power LED on holo
  digitalWrite(criticalled, LOW);
  digitalWrite(waterlow, LOW);//water level akhn turned off
  digitalWrite(waterlevel1, LOW);
  digitalWrite(waterlevel2, LOW);
  digitalWrite(waterlevel3, LOW);
  digitalWrite(waterlevel4, LOW);

  Serial.begin(57600);
  Wire.begin();
  RTC.begin();



}

void loop(){
  noInterrupts();

  humidity = analogRead(A0); //ADC theke in 
  lowestrh = analogRead(A1);
  
  if (humidity <= lowestrh){            // jodi water level lowest hoe jay
  digitalWrite(waterlevel1, LOW);
  digitalWrite(waterlevel2, LOW);
  digitalWrite(waterlevel3, LOW);
  digitalWrite(waterlevel4, LOW);
  
  digitalWrite(waterlow, HIGH);
  digitalWrite(criticalled, HIGH);
  delay(1000);
  digitalWrite(criticalled, LOW);
  delay(1000);
  digitalWrite(criticalled, HIGH);
  delay(1000);
  digitalWrite(criticalled, LOW);
  delay(1000);
}

if (humidity <= (lowestrh+100)){            // jodi water level low hoe jay
  digitalWrite(waterlevel1, HIGH);
  digitalWrite(waterlevel2, HIGH);
  digitalWrite(waterlevel3, LOW);
  digitalWrite(waterlevel4, LOW);

  delay(2000);
}

if (humidity <= (lowestrh+200)){            // jodi water level low hoe jay
  digitalWrite(waterlevel1, HIGH);
  digitalWrite(waterlevel2, HIGH);
  digitalWrite(waterlevel3, HIGH);
  digitalWrite(waterlevel4, LOW);
  
  
}

if (humidity <= (lowestrh+500)){            // jodi water level full hoe jay
  digitalWrite(waterlevel1, HIGH);
  digitalWrite(waterlevel2, HIGH);
  digitalWrite(waterlevel3, HIGH);
  digitalWrite(waterlevel4, HIGH);
  
}


  interrupts();

  DateTime now = RTC.now();

  Serial.print(now.day());
  Serial.print('/');
  Serial.print(now.month());
  Serial.print('/');
  Serial.print(now.year());
  Serial.print(' ');


  Serial.print(now.hour());
  Serial.print(':');
  Serial.print(now.minute());
  Serial.print(':');
  Serial.print(now.second());
  Serial.println();
  
  int starttarikh = now.minute();
  int startmash = now.hour();
  
///////////////////////////////////////
  mash = now.hour();                  //
  tarikh = now.minute();//BCSIR TEST  //
  ghonta = now.second();              //
///////////////////////////////////////  


  
  
///////////////////////////////////////////////////
  if (mash == startmash && tarikh == starttarikh  )
  {
    executeday1();
  }

  if (mash == startmash && tarikh == (starttarikh+1)  )
  {
    executeday2();
  }

  if (mash == startmash && tarikh == (starttarikh+2)  )
  {
    executeday3();
  }

  if (mash == startmash && tarikh == (starttarikh+3) )
  {
    executeday4();
  }

  if (mash == startmash && tarikh == (starttarikh+4) )
  {
    executeday5();
  }

  if (mash == startmash && tarikh == (starttarikh+5) )
  {
    executeday6();
  }

  if (mash == startmash && tarikh == (starttarikh+6) )
  {
    executeday7();
  }

  if (mash == startmash && tarikh == (starttarikh+7) )
  {
    executeday8();
  }

  if (mash == startmash && tarikh == (starttarikh+8) )
  {
    executeday9();
  }
  if (mash == startmash && tarikh == (starttarikh+9) )
  {
    executeday10();
  }
  if (mash == startmash && tarikh == (starttarikh+10) )
  {
    executeday11();
  }
  if (mash == startmash && tarikh == (starttarikh+11) )
  {
    executeday12();
  }
  if (mash == startmash && tarikh == (starttarikh+12) )
  {
    executeday13();
  }
  if (mash == startmash && tarikh == (starttarikh+13) )
  {
    executeday14();
  }
  if (mash == startmash && tarikh == (starttarikh+14) )
  {
    executeday15();
  }

  if (mash == startmash && tarikh == (starttarikh+15) )
  {
    executeday16();
  }
  if (mash == startmash && tarikh == (starttarikh+16) )
  {
    executeday17();
  }
  if (mash == startmash && tarikh == (starttarikh+17) )
  {
    executeday18();
  }
  if (mash == startmash && tarikh == (starttarikh+18) )
  {
    executeday19();
  }
  if (mash == startmash && tarikh == (starttarikh+19) )
  {
    executeday20();
  }
  
  ////////////////////////////////////////////////
 

 
}
//////////////////////////////////////////////////
int executeday1(){
  
  if (ghonta == 6 ){
    

    digitalWrite(motorRelay, HIGH);
    delay(10000); //10min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
  }

  if (ghonta == 11 && humidity <= lowestrh) {

    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);

  }

  if (ghonta == 16 && humidity <= lowestrh ) {
    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
  }

  if (ghonta == 20){
    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
  }

}
//////////////////////////////////////////////////
int executeday2(){
  Serial.println("day2");
  if (ghonta == 6 ){

    digitalWrite(motorRelay, HIGH);
    delay(6000); //10min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
  }

  if (ghonta == 11 && humidity <= lowestrh) {

    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);

  }

  if (ghonta == 16 && humidity <= lowestrh ) {
    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
  }

  if (ghonta == 20){
    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
  }

}

//////////////////////////////////////////////////
int executeday3(){
  if (ghonta == 6 && humidity <= lowestrh ){

    digitalWrite(motorRelay, HIGH);
    delay(6000); //10min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
  }

  if (ghonta == 11 && humidity <= lowestrh) {

    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);

  }

  if (ghonta == 16 && humidity <= lowestrh ) {
    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
  }

  if (ghonta == 20 && humidity <= lowestrh){
    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
  }

}

//////////////////////////////////////////////////
int executeday4(){
  if (ghonta == 6 && humidity <= lowestrh ){

    digitalWrite(motorRelay, HIGH);
    delay(6000); //10min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
  }

  if (ghonta == 11 && humidity <= lowestrh) {

    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);

  }

  if (ghonta == 16 && humidity <= lowestrh ) {
    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
  }

  if (ghonta == 20 && humidity <= lowestrh){
    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
  }

}

//////////////////////////////////////////////////
int executeday5(){
  if (ghonta == 6 && humidity <= lowestrh ){


    digitalWrite(motorRelay, HIGH);
    delay(6000); //10min er jonno motor on
    digitalWrite(fRelay, HIGH);
    delay(6000);//2min er jonno fvalve on
    digitalWrite(fRelay, LOW);



    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);

  }

  if (ghonta == 11 && humidity <= lowestrh) {

    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);

  }

  if (ghonta == 16 && humidity <= lowestrh ) {
    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 20 && humidity <= lowestrh){
    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

}

//////////////////////////////////////////////////
int executeday6(){
  if (ghonta == 6 && humidity <= lowestrh ){

    digitalWrite(motorRelay, HIGH);
    delay(6000); //10min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 11 && humidity <= lowestrh) {

    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);

  }

  if (ghonta == 16 && humidity <= lowestrh ) {
    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 20 && humidity <= lowestrh){
    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }
}

//////////////////////////////////////////////////
int executeday7(){
  if (ghonta == 6 && humidity <= lowestrh ){

    digitalWrite(motorRelay, HIGH);
    delay(6000); //10min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 11 && humidity <= lowestrh) {


    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);

  }

  if (ghonta == 16 && humidity <= lowestrh ) {
    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 20 && humidity <= lowestrh){
    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }



}

//////////////////////////////////////////////////
int executeday8(){
  if (ghonta == 6 && humidity <= lowestrh ){

    digitalWrite(motorRelay, HIGH);
    delay(6000); //10min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 11 && humidity <= lowestrh) {


    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 16 && humidity <= lowestrh ) {
    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 20 && humidity <= lowestrh){
    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }



}
//////////////////////////////////////////////////
int executeday9(){
  if (ghonta == 6 && humidity <= lowestrh ){

    digitalWrite(motorRelay, HIGH);
    delay(6000); //10min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 11 && humidity <= lowestrh) {


    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);

  }

  if (ghonta == 16 && humidity <= lowestrh ) {
    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 20 && humidity <= lowestrh){
    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }



}

//////////////////////////////////////////////////
int executeday10(){
  if (ghonta == 6 && humidity <= lowestrh ){

    digitalWrite(motorRelay, HIGH);
    delay(6000); //10min er jonno motor on
    digitalWrite(fRelay, HIGH);
    delay(6000);
    digitalWrite(fRelay, LOW);
    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 11 && humidity <= lowestrh) {


    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);

  }

  if (ghonta == 16 && humidity <= lowestrh ) {
    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 20 && humidity <= lowestrh){
    digitalWrite(motorRelay, HIGH);
    delay(3000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }



}

//////////////////////////////////////////////////
int executeday11(){
  if (ghonta == 6 && humidity <= lowestrh ){

    digitalWrite(motorRelay, HIGH);
    delay(6000); //10min er jonno motor on

    digitalWrite(fRelay, HIGH);
    delay(6000);
    digitalWrite(fRelay, LOW);

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 11 && humidity <= lowestrh) {


    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);

  }

  if (ghonta == 16 && humidity <= lowestrh ) {
    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 20 && humidity <= lowestrh){
    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }



}

//////////////////////////////////////////////////
int executeday12(){
  if (ghonta == 6 && humidity <= lowestrh ){

    digitalWrite(motorRelay, HIGH);
    delay(600000); //10min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 11 && humidity <= lowestrh) {


    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);

  }

  if (ghonta == 16 && humidity <= lowestrh ) {
    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 20 && humidity <= lowestrh){
    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }



}

//////////////////////////////////////////////////
int executeday13(){
  if (ghonta == 6 && humidity <= lowestrh ){

    digitalWrite(motorRelay, HIGH);
    delay(600000); //10min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 11 && humidity <= lowestrh) {


    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);

  }

  if (ghonta == 16 && humidity <= lowestrh ) {
    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 20 && humidity <= lowestrh){
    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }



}

//////////////////////////////////////////////////
int executeday14(){
  if (ghonta == 6 && humidity <= lowestrh ){

    digitalWrite(motorRelay, HIGH);
    delay(600000); //10min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 11 && humidity <= lowestrh) {


    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);

  }

  if (ghonta == 16 && humidity <= lowestrh ) {
    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 20 && humidity <= lowestrh){
    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }



}

//////////////////////////////////////////////////
int executeday15(){
  if (ghonta == 6 && humidity <= lowestrh ){

    digitalWrite(motorRelay, HIGH);
    delay(600000); //10min er jonno motor on
    digitalWrite(fRelay, HIGH);
    delay(2*60000);
    digitalWrite(fRelay, LOW);
    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 11 && humidity <= lowestrh) {


    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);

  }

  if (ghonta == 16 && humidity <= lowestrh ) {
    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 20 && humidity <= lowestrh){
    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }



}

//////////////////////////////////////////////////
int executeday16(){
  if (ghonta == 6 && humidity <= lowestrh ){

    digitalWrite(motorRelay, HIGH);
    delay(600000); //10min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 11 && humidity <= lowestrh) {


    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);

  }

  if (ghonta == 16 && humidity <= lowestrh ) {
    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 20 && humidity <= lowestrh){
    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }



}

//////////////////////////////////////////////////
int executeday17(){
  if (ghonta == 6 && humidity <= lowestrh ){

    digitalWrite(motorRelay, HIGH);
    delay(600000); //10min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 11 && humidity <= lowestrh) {


    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);

  }

  if (ghonta == 16 && humidity <= lowestrh ) {
    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 20 && humidity <= lowestrh){
    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }



}

//////////////////////////////////////////////////
int executeday18(){
  if (ghonta == 6 && humidity <= lowestrh ){

    digitalWrite(motorRelay, HIGH);
    delay(600000); //10min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 11 && humidity <= lowestrh) {


    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);

  }

  if (ghonta == 16 && humidity <= lowestrh ) {
    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 20 && humidity <= lowestrh){
    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }



}

//////////////////////////////////////////////////
int executeday19(){
  if (ghonta == 6 && humidity <= lowestrh ){

    digitalWrite(motorRelay, HIGH);
    delay(600000); //10min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 11 && humidity <= lowestrh) {


    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);

  }

  if (ghonta == 16 && humidity <= lowestrh ) {
    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 20 && humidity <= lowestrh){
    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

}

//////////////////////////////////////////////////
int executeday20(){
  if (ghonta == 6 && humidity <= lowestrh ){

    digitalWrite(motorRelay, HIGH);
    delay(600000); //10min er jonno motor on
    digitalWrite(fRelay, HIGH);
    delay(2*60000);
    digitalWrite(fRelay, LOW);
    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 11 && humidity <= lowestrh) {


    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);

  }

  if (ghonta == 16 && humidity <= lowestrh ) {
    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }

  if (ghonta == 20 && humidity <= lowestrh){
    digitalWrite(motorRelay, HIGH);
    delay(300000); //5min er jonno motor on

    digitalWrite(powerled, LOW);
    delay(2000);
    digitalWrite(powerled, HIGH);
    digitalWrite(motorRelay, LOW);
  }



}

//////////////////////////////////////////////////












