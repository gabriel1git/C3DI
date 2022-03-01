#include <LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"#include <SPI.h>
#include <SD.h>
  
  int in=0;
  int in2=0;
  int w=0;
  int x=0;
  int y=0;
  int z=0;
  int ww=0;
  int xx=0;
  int yy=0;
  int zz=0;
  int f=0;
  int ff=0;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
File myFile;
RTC_DS3231 rtc;
  #define a 8
  #define b 9
  
void setup() {
  Serial.begin(9600);  
  myFile = SD.open("test.txt", FILE_WRITE);
    Serial.println("RELATÓRIO DE ACESSO A BILIOTECA CENTRAL, FURG ");
    myFile.println("RELATÓRIO DE ACESSO A BILIOTECA CENTRAL, FURG ");
  Wire.begin();
  pinMode(a, INPUT);
  pinMode(b, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("BIBLIOTECA FURG");
/////////////////////////////////////////////////////////////
///////////////////////HORA E DATA///////////////////////////
/////////////////////////////////////////////////////////////
    DateTime now = rtc.now();
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
  delay(3000);
/////////////////////////////////////////////////////////////////
//////////////////////REGISTRO DO CARD///////////////////////////
/////////////////////////////////////////////////////////////////
    Serial.print("CONDIÇÃO");
    Serial.print("          ");
    myFile.print("CONDIÇÃO");
    myFile.print("          ");
    Serial.print("HORA");
    Serial.print("            ");
    myFile.print("HORA");
    myFile.print("            ");
    Serial.println("DATA");
    myFile.println("DATA");
}

void loop() {
/////////////////////////////////////////////////////////////
///////////////////////HORA E DATA///////////////////////////
/////////////////////////////////////////////////////////////
    DateTime now = rtc.now();
/////////////////////////////////////////////////////////////////
//////////////////////////CONTADOR///////////////////////////////
/////////////////////////////////////////////////////////////////
  lcd.setCursor(0, 0);
  lcd.print("ACESSARAM:");
  lcd.setCursor(0, 1);
  lcd.print("ACESSANDO: ");
  lcd.setCursor(11, 0);
  lcd.print(in);
  lcd.setCursor(11, 1);
  lcd.print(in2);
  delay(50);
  lcd.clear();
  if(digitalRead(a) == HIGH && x==0){   
  x=1;
  y=1;
  yy=1;
  f=0;
  }
  if(digitalRead(b) == HIGH && y==1){
  w=1;
  y=0;
  f=0;
  }
  if(digitalRead(b) == LOW && w==1){
  z=1;
  w=0;
  yy=0;
  }  
  if(z==1){    
  in++;
  in2++;
  z=0;
  x=0;
  y=0;
  f=0;
    myFile.print("    1    ");
    myFile.print("        ");
    myFile.print(now.hour(), DEC);
    myFile.print(':');
    myFile.print(now.minute(), DEC);
    myFile.print(':');
    myFile.print(now.second(), DEC);
    myFile.print("        ");
    myFile.print(now.year(), DEC);
    myFile.print('/');
    myFile.print(now.month(), DEC);
    myFile.print('/');
    myFile.println(now.day(), DEC);

    Serial.print("    1    ");
    Serial.print("        ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.print("        ");
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.println(now.day(), DEC);
  }
  if(digitalRead(b) == HIGH && yy==0){    
  x=1;
  xx=1;
  yy=1;
  f=0;
  }
  if(digitalRead(a) == HIGH && xx==1){
  ww=1;
  xx=0;
  f=0;
  }
  if(digitalRead(a) == LOW && ww==1){
  zz=1;
  ww=0;
  x=0;
  }  
  if(zz==1){    
  in--;
  zz=0;
  xx=0;
  yy=0;
  y=0;
  f=0;
    myFile.print("    0    ");
    myFile.print("        ");
    myFile.print(now.hour(), DEC);
    myFile.print(':');
    myFile.print(now.minute(), DEC);
    myFile.print(':');
    myFile.print(now.second(), DEC);
    myFile.print("        ");
    myFile.print(now.year(), DEC);
    myFile.print('/');
    myFile.print(now.month(), DEC);
    myFile.print('/');
    myFile.println(now.day(), DEC);

    Serial.print("    0    ");
    Serial.print("        ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.print("        ");
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.println(now.day(), DEC);
  }
  if(digitalRead(b)==HIGH){
  ff=1;
  }
  if(digitalRead(b)==LOW && ff==1){
    f++;
    ff=0;
  }
  if(f>=4){
    f=0;
    myFile.close();
    Serial.println("Pasta fechada");
  }
}
