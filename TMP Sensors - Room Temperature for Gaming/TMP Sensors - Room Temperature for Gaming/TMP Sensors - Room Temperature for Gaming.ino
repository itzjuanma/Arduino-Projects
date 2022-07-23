  const int sensorPin = A0;
  const float baselineTemp = 20.00;

void setup() {
Serial.begin(9600); //Speed in which the Arduino communicates with the ID.

for(int pinNumber = 2; pinNumber < 6; pinNumber++){ // FOR cycle to go through pins 2 to 4 
  pinMode(pinNumber,OUTPUT);
  digitalWrite(pinNumber, LOW);
}
}

void loop() { //Serial.Print() sends the info from the Arduino to a PC connected to it. If we type "" It will show text, but if we type the name of a variable, it will show the actual value of the variable. 
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  //Finding the real value in Volts of the pin. Remember that the analog pins A0-A5 can return values between 0-1023 which correspond to a range of 0-5 volts.
  float voltage = (sensorVal/1024.0) * 5.0;

  Serial.print("Voltage: ");
  Serial.print(voltage);


  float temperature = (voltage - 0.5) * 100;
  Serial.print(", degrees C: ");
  Serial.println(temperature);

  if(temperature <= baselineTemp+3){ //Temperature below the Base Line Temp constant created before. 
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }
   
   else if(temperature >= baselineTemp+3 && temperature < baselineTemp+5.00){//&& operator means and in a logical meaning. 
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
   }

   else if(temperature >= baselineTemp+5 && temperature < baselineTemp+7){//&& operator means and in a logical meaning. 
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
   }

   else if(temperature > baselineTemp+7){ 
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
   }

    delay(1000);
}
