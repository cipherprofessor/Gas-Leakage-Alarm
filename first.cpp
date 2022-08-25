#include <Stepper.h>
#include <LiquidCrystal.h>

const int stepsPerRevolution = 90;
// change this to fit the number of steps per revolution
// for your motor
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
   // set the speed at 60 rpm:
   myStepper.setSpeed(5);
   // initialize the serial port:
   Serial.begin(9600);
}

void loop() {
   // step one revolution in one direction:
   Serial.println("clockwise");
   myStepper.step(stepsPerRevolution);
   delay(500);
   // step one revolution in the other direction:
   Serial.println("counterclockwise");
   myStepper.step(-stepsPerRevolution);
   delay(500);
}

LiquidCrystal lcd( 2,3, 4, 5, 6, 7);

#include <Stepper.h>

const int stepsPerRevolution = 90;

Stepper myStepper(stepsPerRevolution, 1, 10, 11, 12);

#define lpg_sensor 18

#define buzzer 13


void setup() 

{

  pinMode(lpg_sensor, INPUT);

  pinMode(buzzer, OUTPUT);
  
  myStepper.setSpeed(5);
  
  Serial.begin(9600);

  lcd.begin(16, 2);

  lcd.print("LPG Gas Detector");

  lcd.setCursor(0,1);

  lcd.print("Circuit Digest");

  delay(2000);

}


void loop() 

{

  if(digitalRead(lpg_sensor))

  {

    digitalWrite(buzzer, HIGH);

    Serial.println("clockwise");
    
    myStepper.step(stepsPerRevolution);
   
    delay(500);

    Serial.println("counterclockwise");
    
    myStepper.step(-stepsPerRevolution);
    
    delay(500);

    lcd.clear();

    lcd.print("LPG Gas Leakage");

    lcd.setCursor(0, 1);

    lcd.print("     Alert     ");

    delay(400);

    digitalWrite(buzzer, LOW);

    delay(500);

  }

  

  else 

  {

    digitalWrite(buzzer, LOW);

    lcd.clear();

    lcd.print("  No LPG Gas ");

    lcd.setCursor(0,1);

    lcd.print("   Leakage   ");

    delay(1000);

  }

}