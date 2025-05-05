#include <LiquidCrystal.h>

const int buttonPin = 3;
const int green = 6;
const int red = 2;
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

unsigned long highscore = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  lcd.clear();
  lcd.print("Press to Start");
  lcd.setCursor(0, 1);
  lcd.print("Record:");
  lcd.print(highscore);

  while (digitalRead(buttonPin) == HIGH) {}
  delay(200);

  numberGame();
}

void numberGame() {
  int playerscore = 0;  //player score starts at zero

  while (true) {
    // this part generates a random 7 digit sequence for the player to vaguely remember
    int digit1 = random(0, 10);
    int digit2 = random(0, 10);
    int digit3 = random(0, 10);
    int digit4 = random(0, 10);
    int digit5 = random(0, 10);
    int digit6 = random(0, 10);
    int digit7 = random(0, 10);

    lcd.clear(); //this part displays the random 7 digit sequence for the player to vaguely remember
    lcd.print("Remember:");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print(digit1);
    lcd.print(digit2);
    lcd.print(digit3);
    lcd.print(digit4);
    lcd.print(digit5);
    lcd.print(digit6);
    lcd.print(digit7);
    

    delay(1000);  //gives player a second to remember

    int key = random(0, 10);
    lcd.clear();
    lcd.print("Digit: ");
    lcd.setCursor(0, 1);
    lcd.print(key);

    
      
    }

    // Check if the key was part of the sequence
    bool correct = false;
    if (key == digit1 || key == digit2 || key == digit3 || key == digit4 || key == digit5 || key == digit6 || key == digit7) {
      correct = true; 
      else {

      }
    }

    // Determine if the player was right
    if ((correct && pressed1) || (!correct && pressed2)) {
      playerscore++;
      lcd.clear();
      digitalWrite(green, HIGH);
      delay(2000);
      digitalWrite(green, LOW);
    } else {
      lcd.clear();
      digitalWrite(red, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(3000);
      digitalWrite(red, LOW);
      digitalWrite(buzzer, LOW);

      if (playerscore > highscore) {
        highscore = playerscore;
      }
      break;  //ends the game
    }
  }
}