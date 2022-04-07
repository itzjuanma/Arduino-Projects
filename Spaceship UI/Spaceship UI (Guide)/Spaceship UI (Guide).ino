int switchState = 0;

void setup() {

  //Assigning the pin numbers and whether they are input or outputs (Input por switches and Output for LED's)
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(2,INPUT);

    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    delay(1000);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    delay(1000);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    delay(1000);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    delay(1000);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(3, HIGH);
    delay(2000);


}

void loop() {

  switchState = digitalRead(2);

 
 // Checking if the switch is pressed, if not, PIN 3 (GREEN LED) will light up and PIN 4 & 5 (RED LEDs) will be off.  
  if(switchState == LOW){

    digitalWrite(3, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }

//ELSE argument, if the switch is pressed which would be HIGH

  else{
    digitalWrite(3, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);


    //Waiting a quarter of a second (time is measured in ms, so 1000/250)
    delay(500);

    //changing the LEDs
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);

    delay(250);

    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);

    delay(250);

    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);

    delay(250);

    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);

    delay(250);
  }
  
}
