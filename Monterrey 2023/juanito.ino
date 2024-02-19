//Juanito Belicon (RoboRAVE Version)

//Motor A
int motorPin1  = 5;  // Pin 14
int motorPin2  = 6;  // Pin 10
//Motor B
int motorPin3  = 10; // Pin  7
int motorPin4  = 9;  // Pin  2
int IRFL = 4;
int IRFR = 3;
//int IRBL = 2;
//int IRBR = 1;
int trigPin=13; //Ultrasonico TRIG pin conectado a Arduino pin 13
int echoPin=12;  //Ultrasonico ECHO pin conectado a Arduino pin 12
float pingTime;  //Ping del sensor al objetivo y retorno
float targetDistance; //Distancia del objetivo
float speedOfSound=776.5; //Velocidad del sonido en millas 

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

int getDistance(){
    digitalWrite(trigPin, LOW); //Set trigger pin low
    delayMicroseconds(2000); //Let signal settle
    digitalWrite(trigPin, HIGH); //Set trigPin high
    delayMicroseconds(15); //Delay in high state
    digitalWrite(trigPin, LOW); //ping has now been sent
    delayMicroseconds(10); //Delay in high state
    
    pingTime = pulseIn(echoPin, HIGH);  //pingTime en microsegundos
    pingTime=pingTime/1000000; //pingTime a segundos
    pingTime=pingTime/3600; //pingTime a horas
    targetDistance= speedOfSound * pingTime;  //En millas
    targetDistance=targetDistance/2; //Remember ping travels to target and back from target, so you must divide by 2 for actual target distance.
    return targetDistance =targetDistance*160900; //Millas a centimetro
    
}
  
void loop(){
  int IR_frontL = analogRead(IRFL);
  int IR_frontR = analogRead(IRFR);
  int currentDistance=getDistance();
  
  if (currentDistance<=60)
  {
    atacar();}
  else{
    buscar();
  }
}
