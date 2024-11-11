# Arduino LCD Jumping Game

An interactive Arduino-based game using an LCD display and LEDs to create a simple jumping game. A ball character jumps over obstacles controlled by a button press. LEDs indicate successful jumps or collisions, and the LCD shows real-time score updates.

## Features

- **LCD Display**: Shows the ball, obstacles, and score.
- **Green LED**: Lights up briefly when the player successfully avoids an obstacle.
- **Red LED**: Lights up upon collision, signaling game over, and the score resets.
- **Button Control**: Pressing the button moves the ball character up to avoid obstacles.

## Components

- 1 x Arduino Uno
- 1 x LCD Display (16x2)
- 1 x Button
- 1 x Green LED
- 1 x Red LED
- Resistors for LEDs
- Jumper wires and breadboard

## Circuit Setup

1. **LCD Display**: Connect to the Arduino with pins 12, 11, 5, 4, 3, and 2 for data lines.
2. **Button**: Connect one terminal to pin 7 and the other to GND, with a pull-up resistor.
3. **Green LED**: Connect the anode to pin 8 with a resistor, and the cathode to GND.
4. **Red LED**: Connect the anode to pin 9 with a resistor, and the cathode to GND.

## Code

Upload the following code to your Arduino:

```cpp
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
```
