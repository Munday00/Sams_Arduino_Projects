#include <LiquidCrystal.h>
int rs=7, en=8, d4=9, d5=10, d6=11, d7=12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

String ask="Hey I'm a ", ask_="calculator";
String ask1="Type an operand", ask3="Another operand", ask2="Type an operator";
double num1, num2;
String op;
double result;
void setup() {
 lcd.begin(16,2);
 Serial.begin(9600);
}

void loop() {
 lcd.setCursor(0,0);
 lcd.print(ask);
 lcd.setCursor(0,1);
 lcd.print(ask_);
 delay(1000);
 lcd.clear();//note we are clearing several times to ensure we aren't overwriting the lcd.
 lcd.setCursor(0,0);
 lcd.print(ask1);
 while(Serial.available()==0){
 }
 
 num1=Serial.parseInt();
 lcd.clear();
 lcd.setCursor(0,1);
 lcd.print(num1);
 lcd.setCursor(0,0);
 lcd.print(ask2);
  
  
 while(Serial.available()==0){
 
 } 
 op=Serial.readString();
 lcd.clear();
 lcd.setCursor(0,1);
 lcd.print(num1);
 lcd.print(op);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print(ask3);
 lcd.setCursor(0,1);
 lcd.print(num1);
 lcd.print(op);
 delay(500);
 
  while(Serial.available()==0){
  }
    num2=Serial.parseInt();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(num1);
    lcd.print(op);
    lcd.print(num2);
    lcd.print('=');
 
    if(op=="/"){
    result=num1/num2;
    }
    if(op=="-"){
    result=num1-num2;
    }
    if(op=="*"){
    result=num1*num2;
    }
    if(op=="+"){ //must be "" not ''
    result=num1+num2;
    }
    lcd.print(result);
    delay(3000);
    lcd.clear();
    Serial.print(result);
 }
 
 
 
 
