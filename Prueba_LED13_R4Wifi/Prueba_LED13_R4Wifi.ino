const int ledPin = 13;
const int comparador = 100;
void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
    for(int i = 0; i <= comparador; i++){
          digitalWrite(ledPin,LOW);
          delay(1000);
          digitalWrite(ledPin,HIGH);
          delay(1000);

    }

}
