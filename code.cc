#include <LiquidCrystal.h>

const int IN1 = 6;
const int IN2 = 5;
const int IN3 = 3;
const int IN4 = 9;

const int CZUJNIK_PRZESZKOD = 2; 
const int CZUJNIK_LINII = 4;     

LiquidCrystal lcd(12, 11, 10, 8, 7, 13);

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(CZUJNIK_PRZESZKOD, INPUT);
  pinMode(CZUJNIK_LINII, INPUT);

  lcd.begin(16, 2);
  
  lcd.setCursor(0, 0);
  lcd.print("  ROZPOCZYNAMY  ");
  lcd.setCursor(0, 1);
  lcd.print("    PRZEJAZD    ");
  delay(1000);
  lcd.clear();
}

void loop() {
  int przeszkoda = digitalRead(CZUJNIK_PRZESZKOD);
  int linia = digitalRead(CZUJNIK_LINII);

  if (przeszkoda == LOW) { 
    stoj();
    lcd.setCursor(0, 0);
    lcd.print("STOP!           ");
    lcd.setCursor(0, 1);
    lcd.print("BLOKADA Z PRZODU");
  } 
  else if (linia == LOW) {
    stoj();
    lcd.setCursor(0, 0);
    lcd.print("STOP! COS       "); 
    lcd.setCursor(0, 1);
    lcd.print("CZARNEGO POD NAMI");
  }
  else {
    jedz_do_przodu();
    lcd.setCursor(0, 0);
    lcd.print("JAZDA!          "); 
    lcd.setCursor(0, 1);
    lcd.print("#JADYMY         ");
  }

  delay(60);
}

void jedz_do_przodu() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stoj() {
  digitalWrite(IN1, LOW);  
  digitalWrite(IN2, LOW); 
  digitalWrite(IN3, LOW);  
  digitalWrite(IN4, LOW); 
}
