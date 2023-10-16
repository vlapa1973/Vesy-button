/*
    Программа эмуляции весов
    MIDL (13 байт)
*/

#include <Arduino.h>

const uint8_t BTN1 = 12; // PIN переключение веса
const uint8_t BTN3 = 6;  // сброс весов (съезд автомобиля)
const uint8_t LED = 13;
uint16_t text[] = {0, 690, 1540, 20000, 37850};
uint8_t i = 0;

void work()
{
  Serial.print("ww0");

  if (text[i] < 10000)
  {
    Serial.print('0');
    if (text[i] < 1000)
    {
      Serial.print('0');
      if (text[i] < 100)
      {
        Serial.print('0');
        if (text[i] < 10)
        {
          Serial.print('0');
        }
      }
    }
  }

  Serial.print(text[i]);
  Serial.println(" kg");
}

void setup()
{
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN3, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
  digitalWrite(8, LOW);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop()
{

  if (!digitalRead(BTN1))
  {
    i++;
    digitalWrite(LED, LOW);
    if (i == sizeof(text) / 2)
      i = 0;
  }

  if (!digitalRead(BTN3))
  {
    i = 0;
  }

  digitalWrite(LED, HIGH);
  work();
  delay(500);
}
