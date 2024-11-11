#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int ballPos = 0;
int ballRow = 1;
int obstaclePos = 15;
int score = 0;

const int greenLED = 8;
const int redLED = 9;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(7, INPUT_PULLUP);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);
}

void loop() {
  lcd.clear();
  
  lcd.setCursor(ballPos, ballRow);
  lcd.print("O");
  
  lcd.setCursor(obstaclePos, 1);
  lcd.print("#");
  
  if (digitalRead(7) == LOW) {
    ballRow = 0;
  } else {
    ballRow = 1;
  }
  
  if (obstaclePos == ballPos && ballRow == 1) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Game Over! Score:");
    lcd.setCursor(0, 1);
    lcd.print(score);
    delay(2000);
    digitalWrite(redLED, HIGH);
    delay(500);
    digitalWrite(redLED, LOW);
    obstaclePos = 15;
    score = 0;
    return;
  }

  obstaclePos--;
  
  if (obstaclePos < 0) {
    obstaclePos = 15;
    score++;
    digitalWrite(greenLED, HIGH);
    delay(200);
    digitalWrite(greenLED, LOW);
  }

  lcd.setCursor(0, 0);
  lcd.print("Score:");
  lcd.setCursor(6, 0);
  lcd.print(score);
  
  delay(200);
}
