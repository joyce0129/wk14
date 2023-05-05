/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/
int sensorValue=0;
int ledDimming=0;
int pwmPin=9;
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  Serial.begin(9600);
  pinMode(pwmPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue=analogRead(A0);
  Serial.println(sensorValue);
  delay(1);
  if(sensorValue>550){
    sensorValue=550;
  }
  else if(sensorValue<16){
    sensorValue=16;
  }
  int ledBlink=map(sensorValue, 16, 550, 0, 255);
  analogWrite(9,ledBlink);
}
