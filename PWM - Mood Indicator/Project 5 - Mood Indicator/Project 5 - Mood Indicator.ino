  //To use the library for servomotors, first we will need to import it. We use the function #include without ;
#include <Servo.h>

  //Creating the object "Servo", to refer to the servomotor we will need to create an instance from the library into a variable. This is called an object. 
Servo myServo;

  //We need to configure a constant for the pin where potentiometer is connected and the variables to store the value of the analog input and the angle in which we want the servo to move. 

int const potPin = A0;
int potVal;
int angle;

void setup() {
  //We have to tell ARduino on which pin we connected the Servomotor
  myServo.attach(9);

  //We also include a series connection so we can read the values of the potentiometer and see how it maps the angles. 
  Serial.begin(9600);

}

void loop() {
  //To create a useful value for the servomotor from the analog input, the easiest way is to use the map() function. This function converts the numers to a scale. For this case, it will change the values between 0 and 1023 to values between 0 and 179.
  //This function takes 5 arguments: the scalar value (potVal), the minimum input value (0), the maximum input value (1023), the minimum output value (0) and the maximum output value (179). We will store this value in a variable. 
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);

  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print(" , angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(15);
}
