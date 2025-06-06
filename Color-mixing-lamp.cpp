const int greenLEDPin = 9; 
const int redLEDPin = 11; 
const int blueLEDPin = 10; 

const int redSensorPin = A0; 
const int greenSensorPin = A1; 
const int blueSensorPin = A2; 

int redValue = 0; 
int greenValue = 0; 
int blueValue = 0; 

int redSensorValue = 0; 
int greenSensorValue = 0; 
int blueSensorValue = 0; 

void setup() { 
  Serial.begin(9600); 
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop() {
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);

  Serial.print("Raw Sensor Values \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\t Green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue: ");
  Serial.println(blueSensorValue);
  
  redValue = redSensorValue / 4; 
  greenValue = greenSensorValue / 4;
  blueValue = blueSensorValue / 4;

  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(redValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.println(blueValue); 

  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);

  delay(100); // Small delay for stability
}