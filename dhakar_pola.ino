/* Sonar Distance Measurement Code by MASLab
                   www.maslab.org            */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 9;                // Pin that the Trig pin is attached to
const int echoPin = 10;               // Pin that the Potentiometer is attached to
long duration;                        // Variable to store the duration
int distance;                         // Variable to store the distance

void setup() {                        // The setup function runs once when you press reset/power the board
  pinMode(trigPin, OUTPUT);           // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);            // Sets the echoPin as an Input
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {                         // The loop routine runs over and over again forever
  lcd.clear();
  lcd.setCursor(0, 0);
  digitalWrite(trigPin, LOW);         // Pull the trig pin to low
  delayMicroseconds(2);               // Wait for 2 microseconds
  digitalWrite(trigPin, HIGH);        // Set the trig pin to high
  delayMicroseconds(10);              // Waits for 10 microseconds
  digitalWrite(trigPin, LOW);         // Pulls the trig pin to low again
  duration = pulseIn(echoPin, HIGH);  // Measures the duration using pulseIn function
  distance = duration * 0.034 / 2;    // Convert duration to distance
  Serial.print("Distance: ");         // Serial print
  Serial.println(distance);// Serial prints distance
  if(distance<15){
    lcd.print("Come Closer,babe.You are 15 cm far");
    delay(1000);
  }
   else
  { 
    lcd.print("Hi babe");
    delay(1000);
  }
  
  
}
