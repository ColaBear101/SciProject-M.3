#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

int mxval = 50; //** กรอกจำนวนสูงสุดของเหรียญที่มี **\\

int tbath; //สิบบาท
int fbath; //ห้าบาท
int obath; //หนึ่งบาท

void setup()
{
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();

}
void loop() {
  //1 Bath: 0   //
  //            //
  lcd.setCursor(0, 0);
  lcd.print(" 1  Baht:");
  lcd.setCursor(10, 0);
  lcd.print(obath);
  delay (100);
  fbath += random(0, 5);
  custombreak();
  
  //1 Bath: 0   //
  //5 Bath: 0   //
  lcd.setCursor(0, 1);
  lcd.print(" 5  Baht:");
  lcd.setCursor(10, 1);
  lcd.print(fbath);
  delay (2000);
  obath += random(0, 5);
  custombreak();
  
  //5 Bath: 0   //
  //5 Bath: 0   //
  lcd.setCursor(0, 0);
  lcd.print(" 5  Baht:");
  lcd.setCursor(10, 0);
  lcd.print(fbath);
  delay (100);
  fbath += random(0, 5);
  custombreak();
  
  //5 Bath: 0   //
  //10 Bath: 0   //
  lcd.setCursor(0, 1);
  lcd.print("10  Baht:");
  lcd.setCursor(10, 1);
  lcd.print(tbath);
  delay (2000);
  tbath += random(0, 5);
  custombreak();
  
  //10 Bath: 0   //
  //10 Bath: 0   //
  lcd.setCursor(0, 0);
  lcd.print("10  Baht:");
  lcd.setCursor(10, 0);
  lcd.print(tbath);
  delay (100);
  obath += random(0, 5);
  custombreak();
  
  //10 Bath: 0   //
  //1 Bath: 0   //
  lcd.setCursor(0, 1);
  lcd.print(" 1  Baht:");
  lcd.setCursor(10, 1);
  lcd.print(obath);
  delay (2000);
  tbath += random(0, 5);
  custombreak();
}

void custombreak()
{
    if (obath + fbath + tbath > mxval)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("1B=");
    lcd.setCursor(4, 0);
    lcd.print(obath);
    lcd.setCursor(0, 1);
    lcd.print("5B=");
    lcd.setCursor(4, 1);
    lcd.print(fbath);
    lcd.setCursor(8, 0);
    lcd.print("10B=");
    lcd.setCursor(12, 0);
    lcd.print(tbath);
    exit(0);
  }
  }
