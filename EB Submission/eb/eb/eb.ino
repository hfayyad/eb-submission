#include <LiquidCrystal.h>
#include <Servo.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo myservo;

const int ledPin = LED_BUILTIN; // the number of the LED pin
int ledState = LOW;             // ledState used to set the LED
unsigned long previousMillis = 0;
const long interval = 1000; // interval at which to blink (milliseconds)

void setup() {
  myservo.attach(9);    // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);   // 9600 bps
  lcd.begin(16, 2);     // set up the LCD's number of columns and rows
  pinMode(ledPin, OUTPUT); // set the digital pin as output
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
    analogWrite(9, 177);
    myservo.write(270);
    delay(1650);
    myservo.write(0);
    delay(1650);
    uint16_t val;
    double dat;
    val = analogRead(A0);          // Connect LM35 on Analog 0
    dat = (double)val * (5 / 10.24);
    lcd.clear();                   // Clear the LCD
    Serial.print("Temperature: ");    // Display the temperature label
    Serial.println(dat);                // Display the temperature value with new line
    Serial.print(" Celsius");
    delay(500);
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    lcd.print(millis() / 1000);
  }
}

