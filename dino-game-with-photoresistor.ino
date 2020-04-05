#include <Servo.h>
const int pResistor = A0; // Photoresistor at Arduino analog pin A0
Servo myservo;

//Variables
int value;          // Store value from photoresistor (0-1023)

void setup() {
  Serial.begin(9600);
  Serial.println("Startup!");
  pinMode(LED_BUILTIN, OUTPUT);  
  pinMode(pResistor, INPUT);
  myservo.attach(9); 
  delay(100);
  jump();
}

void loop() {
  value = analogRead(pResistor);
  act(value);
}


void act(int value)
{
  if (value < 217) {
    jump();
    digitalWrite(LED_BUILTIN, HIGH);  //Turn led off
  }
  else {
    //Serial.println(value);
    digitalWrite(LED_BUILTIN, LOW); //Turn led on
  }

  delay(20);
}

void jump() {
  myservo.write(90);              
  delay(80);                       
  myservo.write(115); 
  delay(80);
  myservo.write(90);
}



