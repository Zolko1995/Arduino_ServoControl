#include<Wire.h> //Wire könyvtár beillesztése az I2C busz használatához
#include<LiquidCrystal_I2C.h> //Az I2C Folyékony kristályos LCD kijelző kezelő könyvtára
LiquidCrystal_I2C lcd(0x27, 16, 2); //Az általunk használt kijelző karakterkészlete 16 karakter és 2 sor
#include<Servo.h> //A szervomotor vezérléséhez szükséges könyvtár beillesztése
Servo servo; //Servo típusú változó mely a szervomotorra mutat

int p; //A pozíciót tartalmazó változó
const int potmeter = A0; //konstans globális integer típusú változó mely a potenciométer vezetőjének pin-jét tárolja
 
void setup()
{
  lcd.init(); //Az LCD kijelző inicializálása
  lcd.backlight(); //Az LCD kijelző háttérvilágításának bekapcsolása
  lcd.clear(); //Az LCD kijelző tartalmának a törlése
  servo.attach(9); //A szervomotor csatlakoztatása a 9-es pinre                           
  servo.write(0); //A szervomotor 0-dik pozícióba állítása
  delay(3000); //Várakozás 3 másodpercig
  lcd.setCursor(0,0); //Kurzor pozicionálás ez esetben 0. karakter a 0. sorban
  lcd.print("-----MOTOR-1----"); //Megadott karakterlánc kiíratása
}

void loop() //ciklus
{
  lcd.setCursor(0,1); //Kurzor pozicionálás ez esetben 0. karakter a 1. sorban
  lcd.print("POZICIO:"); //Megadott karakterlánc kiíratása
  p = analogRead(potmeter); //A potenciométer értékének beolvasása és a p változóban tárolása
  p = map (p, 0, 1023, 0, 180); //A kapott érték intervallumának motorpozícióként értelmezhető értékké alakítása
  lcd.setCursor(9,1); //Kurzor pozicionálás ez esetben 9. karakter a 1. sorban
  lcd.print(p); //A változó értékének kiíratása
  lcd.print(" "); //Üres karakterlánc kiíratása
  servo.write(p); //A szervomotor pozicionálása a változó értékének megfelelően
  lcd.setCursor(13,1); //Kurzor pozicionálás ez esetben 13. karakter a 1. sorban
  lcd.print("FOK"); //Megadott karakterlánc kiíratása
  delay(10); //Várakozás 10 mikroszekundum ideig
}
