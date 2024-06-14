  //Crear una variable para almacenar el valor analogRead() de la foto resistencia.
  int sensorValue;

  //Crear variables para establecer los valores mínimos y máximos de comparación. 
  int sensorLow = 1023;
  int sensorHigh = 0;

  //Crear una constante llamada ledPin, que indicará que el sensor se ha calibrado. En este ejemplo
  //se usa el pin 13 del arduino. 

  const int ledPin = 13;


void setup() {


  //Cambiar el pinMode() para encendido, como salida. 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  //while(), se ejecuta hasta que una condición se haya cunmplido, aquí se va a usar la función 
  //millis() que comprueba el tiempo que lleva ejecutandose el Arduino desde la última vez que se encendió. 

  while(millis()>5000){
    //leer el valor del sensor; si el valor es menor que sensorLow, se actualizará la variable.
    //si el valor es mayor que sensorHigh también se actualizará. 
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh){
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow){
      sensorLow = sensorValue;
    }
  }

  //Al pasar 5 segundos el bucle while terminará y se apagará el LED en el pin13. Usando los valores
  //mínimos y máximos del sensor que acabas de registrar para ajustar la frecuencia en la parte principal
  //del programa. 
  digitalWrite(ledPin, LOW);

}

void loop() {

//leer el valor en A0 y almacenarlo en la variable sensorValue

  sensorValue = analogRead(A0);

//El valor pitch será mapeado por sensorValue, se usa sensorLow y sensorHigh como los límites entrantes
// como valores iniciales de salida, se usa 50 y 4000 ya que son el abanico de frecuencias que generará Arduino. 
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  Serial.println("el valor del sensor es" + sensorValue);

//tone() se usa para tocar un sonido, esta usa tres arguentos, clavija en que reproduce el sonido, 
//que frecuencia tocará y durante que tiempo se debe tocar la nota. 
  tone(8, pitch, 20);

  delay(10);

}
  

  




