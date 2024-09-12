#include <Arduino.h>

const int greenLED = 8;
const int yellowLED = 9;
const int redLED = 10;
const int buttonPin = 7;

void setup() {
  // Настройка пинов светодиодов как выходы
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  
  // Настройка кнопки как вход
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Запуск Serial Monitor
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read(); // Читаем команду с консоли
    
    if (command == '1') {
      // Включаем зеленый свет
      digitalWrite(greenLED, HIGH);
      Serial.println("Green LED ON");
    } else if (command == '0') {
      // Выключаем зеленый свет
      digitalWrite(greenLED, LOW);
      Serial.println("Green LED OFF");
    }
  }
  
  // Проверка кнопки пешехода
  if (digitalRead(buttonPin) == LOW) {
    // Выполнение цикла светофора
    digitalWrite(greenLED, HIGH);
    delay(5000); // Зеленый горит 5 секунд
    
    for (int i = 0; i < 3; i++) {
      digitalWrite(greenLED, LOW);
      delay(500); // Выключение на 0.5 секунды
      digitalWrite(greenLED, HIGH);
      delay(500); // Включение на 0.5 секунды
    }
    
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    delay(2000); // Желтый горит 2 секунды
    
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
    delay(5000); // Красный горит 5 секунд
    
    digitalWrite(redLED, LOW); // Цикл завершен, все светодиоды выключены
  }
}
