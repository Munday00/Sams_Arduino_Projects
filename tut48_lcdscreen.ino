#include <LiquidCrystal.h>
int rs=7, en=8, d4=9, d5=10, d6=11, d7=12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
void setup() {
 lcd.begin(16,2); //16 columns 2 rows, opposite way to matrices

}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Hi Nat");
  delay (1000);
  lcd.setCursor(0,1);
  lcd.print("Miss you");
  delay (1000);
  lcd.clear();
delay (1000);
}
