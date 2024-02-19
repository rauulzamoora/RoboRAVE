//Juanito Belicón (RoboRAVE Version)

//Motor A
const int motorPin1  = 5;  // Pin 14
const int motorPin2  = 6;  // Pin 10
//Motor B
const int motorPin3  = 10; // Pin  7
const int motorPin4  = 9;  // Pin  2
const int IRFL = 4;
const int IRFR = 3;
//int IRBL = 2;
//int IRBR = 1;
const int trigPin=13; //Ultrasonico TRIG pin conectado a Arduino pin 13
const int echoPin=12;  //Ultrasonico ECHO pin conectado a Arduino pin 12
const float pingTime;  //Ping del sensor al objetivo y retorno
const float Distancia; //Distancia del objetivo

void setup(){
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(IRFL, INPUT);
    pinMode(IRFR, INPUT);
    //pinMode(IRBL, INPUT);
    //pinMode(IRBR, INPUT);

    delay(5000); //Tiempo antes de iniciar rutina
}

void buscar(){
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
}

void atacar(){
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
  }

void reversa(){
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
}

int Distancia(){
    digitalWrite(trigPin, LOW); //Set trigger pin low
    delayMicroseconds(2); //Let signal settle
    digitalWrite(trigPin, HIGH); //Set trigPin high
    delayMicroseconds(15); //Delay in high state
    digitalWrite(trigPin, LOW); //ping has now been sent

    float duracion = pulseIn(echoPin, HIG);
    float distancia = duracion/58.2; //Constante
    return distancia;
}
  
void loop(){
  int IR_frontL = analogRead(IRFL);
  int IR_frontR = analogRead(IRFR);
  int currentDistance=Distancia();
  Serial.print(Distancia);
  Serial.print(IRFL);
  Serial.print(IRFR);
  Serial.println("cm");
  delay(1);
  if (currentDistance<=60)
  {
    atacar();}
  else{
    buscar();
  }
}
