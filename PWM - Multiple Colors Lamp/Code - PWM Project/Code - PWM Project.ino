// Configure constants for the PINS that are being used as the input and output, that way we match each sensor to the color on the RGB LED. We'll use const int for these type of data. G = 9, B = 10, R = 11.
const int greenLEDPin = 9;
const int blueLEDPin = 10;            
const int redLEDPin = 11;            

//This code is for the phototransistors, we have to match each Analog Pin to the gel that we used. 
const int greenSensorPin = A0;            
const int blueSensorPin = A1;
const int redSensorPin = A2;   

//Adding the variables to store the input data of the sensors and the output data that we'll be using to atenuate the LED. 
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
  delay(5);

  Serial.print("Raw Sensor Values \t Red: ");
  Serial.print(redSensorValue); 

  Serial.println("\t Green: ");
  Serial.print(greenSensorValue); 

  Serial.println("\t Blue: ");
  Serial.print(blueSensorValue); 

//Using analogWrite() to execute the PWM
  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;

  Serial.println("Mapped Sensor Values \t Red: ");
  Serial.print(redValue); 

  Serial.println("\t Green: ");
  Serial.print(greenValue); 

  Serial.println("\t Blue: ");
  Serial.print(blueValue); 

  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);


}
