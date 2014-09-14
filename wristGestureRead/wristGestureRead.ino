/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int powerpin1 = 12;
int analogpin = 1;

// Variables for gesture recognition
double aveTop;
double aveMid;
double aveBottom;

double* sensorReadings[3] = {new double[3],new double[3],new double[3]};
int sensorReadingsIndex = 0;
boolean reading = false;

double averageValues[3] = {0,0,0};
int readings[3] = {0,0,0};

double alpha = 0.005;

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2,3); // RX, TX

void average(double* firstrow, double* secondrow, double* thirdrow) {
  for (int i=0; i < 3; i++) {
    averageValues[i] = (firstrow[i] + secondrow[i] + thirdrow[i])/3.0;
  }
}

String classifyLightSensor() {
  
}

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(powerpin1, INPUT);
  digitalWrite(powerpin1, HIGH);
  Serial.begin(9600);
  mySerial.begin(115200);
  
  Serial.println("INITIALIZE");
  // initialize the average variables with current values
  aveTop = analogRead(0);
  aveMid = analogRead(1);
  aveBottom = analogRead(2);
}

// the loop routine runs over and over again forever:
void loop() {
  
  Serial.println(analogRead(3));
  
  readings[0] = analogRead(0);
  readings[1] = analogRead(1);
  readings[2] = analogRead(2);
  
  aveTop = alpha*readings[0] + (1-alpha)*aveTop;
  aveMid = alpha*readings[1] + (1-alpha)*aveMid;
  aveBottom = alpha*readings[2] + (1-alpha)*aveBottom;
  
  // If the top or bottom go below 30% of average value, do things
  // Also if reading is true continue doing things
  if (readings[0] < aveTop*0.3 || readings[2] < aveBottom*0.3 || reading == true) {
    for (int i=0; i < 3; i++) {
      sensorReadings[sensorReadingsIndex][i] = readings[i];
    }
    if (sensorReadingsIndex < 2) {
      sensorReadingsIndex++;
    }
    else {
      sensorReadingsIndex = 0;
      
      Serial.println("RECORDED STUFF");
      Serial.print(sensorReadings[0][0]);
      Serial.print(" ");
      Serial.print(sensorReadings[0][1]);
      Serial.print(" ");
      Serial.println(sensorReadings[0][2]);
      Serial.print(sensorReadings[1][0]);
      Serial.print(" ");
      Serial.print(sensorReadings[1][1]);
      Serial.print(" ");
      Serial.println(sensorReadings[1][2]);
      Serial.print(sensorReadings[2][0]);
      Serial.print(" ");
      Serial.print(sensorReadings[2][1]);
      Serial.print(" ");
      Serial.println(sensorReadings[2][2]);
      Serial.println("AVERAGE");
      average(sensorReadings[0], sensorReadings[1], sensorReadings[2]);
      Serial.print(averageValues[2]);
      Serial.print(" ");
      Serial.print(averageValues[1]);
      Serial.print(" ");
      Serial.println(averageValues[0]);
      
    }
    
  }
  
  Serial.print(readings[0]);
  Serial.print(" ");
  Serial.print(readings[1]);
  Serial.print(" ");
  Serial.println(readings[2]);
  
  
}
