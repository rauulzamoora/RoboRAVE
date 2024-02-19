//Juanito Belicón RoboRAVE version

//Infrarrojos
 int sensor1 = 8; //const
 int sensor2 = 9; //const
//Ultrasonico
 int triggerPin = 6; //const
 int echoPin = 7; //const
//Motores
 int motor1A = 2;  //const
 int motor1B = 3;  //const
 int motor2A = 4;  //const
 int motor2B = 5;  //const
//Valores
 int valorSensor1;
 int valorSensor2;
 float distancia, duracion, valor;

void setup() {
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  delay(3000);
}

void loop() {
  //Leer valores de los infrarrojos
    valorSensor1 = digitalRead(sensor1);
    valorSensor2 = digitalRead(sensor2);
    distancia = medirDistancia();
    Serial.print(distancia);
    Serial.println("cm");
    Serial.print(valorSensor1);
    Serial.println("derecha");
    Serial.print(valorSensor2);
    Serial.println("izquierda");
    
    if (distancia <= 60){
    //interrupts();
      //stop();
      ataca();
    }
    else if(valorSensor1==0 && valorSensor2==1){
      girarDerecha();
    }
    else if(valorSensor2==0 && valorSensor1==1){
      girarIzquierda();
    }
    else{
      avanza();
    }
  }
    
void detenerMotores(){
  digitalWrite(motor1A,LOW);
  digitalWrite(motor1B,LOW);
  digitalWrite(motor2A,LOW);
  digitalWrite(motor2B,LOW);
}

void rutina(){
      avanza();
      if (distancia>60){delay(500); medirDistancia();}
      buscar2();
      if (distancia>60){delay(1000); medirDistancia();}
      buscar1();
      if (distancia>60){delay(1000); medirDistancia();}
}

void stop(){
  interrupts();
}

void avanza(){
  digitalWrite(motor1A,HIGH);
  digitalWrite(motor1B,LOW);
  digitalWrite(motor2A,HIGH);
  digitalWrite(motor2B,LOW);
}

void buscar1(){
  digitalWrite(motor1A,HIGH);
  digitalWrite(motor1B,LOW);
  digitalWrite(motor2A,LOW);
  digitalWrite(motor2B,HIGH);
}

void buscar2(){
  digitalWrite(motor1A,LOW);
  digitalWrite(motor1B,HIGH);
  digitalWrite(motor2A,HIGH);
  digitalWrite(motor2B,LOW);
}

void girarDerecha(){
  digitalWrite(motor1A,LOW);
  digitalWrite(motor1B,HIGH);
  digitalWrite(motor2A,HIGH);
  digitalWrite(motor2B,LOW);
  delay(800);
}

void girarIzquierda(){
  digitalWrite(motor1A,HIGH);
  digitalWrite(motor1B,LOW);
  digitalWrite(motor2A,LOW);
  digitalWrite(motor2B,HIGH);
  delay(800);
}

float medirDistancia(){
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  float duracion = pulseIn(echoPin, HIGH);
  float distancia = (duracion/59);
 return distancia;
  
}

void ataca(){
  digitalWrite(motor1A,HIGH);
  digitalWrite(motor1B,LOW);
  digitalWrite(motor2A,HIGH);
  digitalWrite(motor2B,LOW);
}

void atras(){
  digitalWrite(motor1A,LOW);
  digitalWrite(motor1B,HIGH);
  digitalWrite(motor2A,LOW);
  digitalWrite(motor2B,HIGH);
}
