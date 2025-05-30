//ultima modificacion 11/06/2024

  // Motor derecha
  int IN2 = 3;
  int IN1 = 2;

  // Motor izquierda
  int IN4 = 4;
  int IN3 = 5;

  // Sensor ultrasónico 1 frente
  const int Trigger1 = 6; // Pin digital 6 para el trigger del sensor
  const int Echo1 = 7;
  long t1;
  long d1;

  //sensor ultrasonico 2 derecha
  const int Trigger2 = 8;
  const int Echo2 = 9;
  long t2;
  long d2;

  //sensor ultrasonico 3 izquierda
  const int Trigger3 = 10;
  const int Echo3 = 11;
  long t3;
  long d3;

  // sensor IR derecha
  int IR_derecha = 12;
  int valor_derecha;

  // sensor IR izquierda
  int IR_izquierdo = 15;
  int valor_izquierdo;

  void adelante()
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    Serial.println("Adelante");
  }

  void atras()
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    Serial.println("Atrás");
  }

  void derecha()
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    Serial.println("Derecha");
  }

  void izquierda()
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    Serial.println("Izquierda");
  }

  void detener()
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    Serial.println("Detener");
  }

  //Sensor soni frente
  void ultra1() {
    digitalWrite(Trigger1, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trigger1, LOW);

    t1 = pulseIn(Echo1, HIGH);
    d1 = t1 / 59;

    //Serial.println(d1);

    if ((d1 <= 50)&& d1>0){
      adelante();
      delay(11);
      Serial.println(d1,"Avanzar");
    }
    else{
      //detener();
    }
  }

  // Sensor soni derecha
  void ultra2(){
    digitalWrite(Trigger2, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trigger2, LOW);

    t2 = pulseIn(Echo2, HIGH);
    d2 = t2 / 59;
    Serial.println(d2);
    
    
    if (d2 <= 50){
      izquierda();
      delay(11);
    }
    else {
      //detener();
    }
  }

  //Sensor soni izquierda  
  void ultra3() {
    digitalWrite(Trigger3, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trigger3, LOW);

    t3 = pulseIn(Echo3, HIGH);
    d3 = t3 / 59;
    
    //Serial.println(d3);

    if ((d3 <= 50)&& d3>0){
      derecha();
      delay(11);
      Serial.println(d3);
    }
    else{
      //detener();
    }
  }


  // si no detecta nada los sensores sonicos, que rote 180 grados
  void giro() {
    digitalWrite(Trigger1, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trigger1, LOW);

    t1 = pulseIn(Echo1, HIGH);
    d1 = t1 / 59;

    digitalWrite(Trigger2, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trigger2, LOW);

    t2 = pulseIn(Echo2, HIGH);
    d2 = t2 / 59;

    digitalWrite(Trigger3, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trigger3, LOW);

    t3 = pulseIn(Echo3, HIGH);
    d3 = t3 / 59;



    Serial.println(d1);
    Serial.println(d2);
    Serial.println(d3);
    if (d1 >= 50 && d2 >= 50 && d3 >= 50){
      derecha();
      delay(15);
    }
  }


  // sensores IR
  void sensor_delanteros(){
    valor_derecha = digitalRead(IR_derecha);
    valor_izquierdo = digitalRead(IR_izquierdo);

    if ((valor_derecha == 0) and (valor_izquierdo == 0)){
      atras();
      // delay(2000); 
      // derecha();
      // delay(2000);
     //detener();
    }
    else if ((valor_derecha == 0) and (valor_izquierdo == 1)){
      izquierda();
      // delay(1000);
    }
    //else if ((valor_izquierdo == 0) and (valor_derecha == 1)){
      //derecha();
      // delay(1000);
    //}
    // Serial.println(valor_derecha);
    // Serial.println(valor_izquierdo);
  }


// Funciones para probar los sensores IR
  void sensorDerecha() {
    valor_derecha = digitalRead(IR_derecha);

    if (valor_derecha == 1) {
      adelante();
    }
    else {
      atras();
    }
  }

  void sensorIzquierda() {
    valor_izquierdo = digitalRead(IR_izquierdo);

    if (valor_izquierdo == 1) {
      adelante();
    }
    else {
      atras();
    }
  }

  void setup() {
    // Motores
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    // Sensor ultrasónico 1
    pinMode(Trigger1, OUTPUT);
    pinMode(Echo1, INPUT);
    digitalWrite(Trigger1, LOW);

    // Sensor ultrasónico 2
    pinMode(Trigger2, OUTPUT);
    pinMode(Echo2, INPUT);
    digitalWrite(Trigger2, LOW);

    // Sensor ultrasónico 3
    pinMode(Trigger3, OUTPUT);
    pinMode(Echo3, INPUT);
    digitalWrite(Trigger3, LOW);

    // Sensor IR delantero
    pinMode(IR_derecha, INPUT);

    // Sensor IR trasero
    pinMode(IR_izquierdo, INPUT);

    Serial.begin(9600);

    // delay de 3 segundos 
    delay(5000);
  }

  void loop(){
    // put your main code here, to run repeatedly:
    //sensor_delanteros();
    ultra1();
    ultra2();
    ultra3();
    //giro();


    // Funciones para probar los sensores IR
     //sensorDerecha();
     //sensorIzquierda();
}