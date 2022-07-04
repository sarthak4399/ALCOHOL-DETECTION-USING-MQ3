#include <LiquidCrystal.h>
LiquidCrystal lcd(5, 6, 8, 9, 10, 11);

int redled = 2;
int greenled = 3;
int buzzer = 4;
int sensor = A0;
int sensorThresh = 400; // THRESHOLD VALUE FOR ALCOHOL DETETCTION
int speed = 7;

void setup()
{
    pinMode(redled, OUTPUT);
    pinMode(greenled, OUTPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(sensor, INPUT);
    pinMode(speed, OUTPUT);
    Serial.begin(9600);
    lcd.begin(16, 2);
}

void loop()
{
    int analogValue = analogRead(sensor); // VALUE READ BY MQ3
    Serial.print(analogValue);
    if (analogValue > sensorThresh) // CONDITION FOR DRUNK DRIVER
    {
        digitalWrite(redled, HIGH);
        digitalWrite(greenled, LOW);
        // PLAY THE BUZZER WITH FREQUENCY OF 1000 Hz FOR 3 SECONDS
        tone(buzzer, 1000, 8000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("ALCOHOL DETECTED!!");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("DANGER!!");
        delay(500);
        lcd.setCursor(0, 1);
        lcd.print("ENGINE STOPED!! ");
        delay(1000);
        lcd.clear();
        digitalWrite(speed, LOW);
        lcd.setCursor(0, 0);
        lcd.print("STOP DRINKING!! ");
        delay(5000);
    }
    else // IF DRIVER IS NOT DRUNK
    {
        digitalWrite(greenled, HIGH);
        digitalWrite(redled, LOW);
        digitalWrite(speed, HIGH);
        noTone(buzzer);
        lcd.clear();
        lcd.setCursor(3, 0);
        lcd.print("SAFE TO DRIVE");
        lcd.setCursor(0, 1);
        lcd.print("SAFE JOURNEY");
        delay(1000);
    }
}
