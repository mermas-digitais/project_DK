//CARRO COM SENSOR ULTRASSONICO HC-SR04//

//PINOS ANALOGICOS DO SENSOR ULTRASSONICO
#define echoPin A0 // ECHO
#define trigPin A1 
//TRIG
long duration;
int distance;

//BIBLIOTECAS AUXILIARES
#include <AFMotor.h>//Inclui biblioteca AF Motor 
//(INSTALE A BIBLIOTECA "Adafruit Motor Shield Libary")
  
//SELECAO DOS MOTORES
//AF_DCMotor motor1(1); //Seleção do Motor 1
AF_DCMotor motor2(2); //Seleção do Motor 2
AF_DCMotor motor3(3); //Seleção do Motor 3
//AF_DCMotor motor4(4); //Seleção do Motor 4
 
//FUNCOES AUXILIARES
void robot_forward(unsigned char v);  //Função movimenta robô frente
void robot_backward(unsigned char v); //Função movimenta robô trás
void robot_left(unsigned char v);     //Função movimenta robô esquerda
void robot_right(unsigned char v);    //Função movimenta robô direita
void robot_stop(unsigned char v);     //Função para parar o robô
 
//VARIAVEIS GLOBAIS
unsigned char velocidade = 0x00; //armazena velocidade motores (8 bits)
          
//CONFIGURAÇÕES INICIAUS
void setup(){
  //SENSOR UTRASSONICO
  pinMode(trigPin, OUTPUT); //  trigPin COMO OUTPUT
  pinMode(echoPin, INPUT); // echoPin COMO INPUT
  Serial.begin(9600); // // COMUNICAÇÃO SERIAL
  //VELOCIDADE DOS MOTORES
  velocidade = 0xFF; // Velocidade do motores("0x44">>25% // "0x7F">>50% // "0x55">>75% // "0xFF">>100%)
}

//LOOP"INFINITO"
void loop(){
  //INICIO SENSOR
  digitalWrite(trigPin, LOW);
  delayMicroseconds(500);

  //trigPin ATIVO POR 500 MILISEGUNDOS
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(trigPin, LOW);

  //LÊ echoPin
  duration = pulseIn(echoPin, HIGH); 
  //CALCULA A DISTANCIA
  distance = duration * 0.034 /2;// VELOCIDADE EM QUE SOM É EMITIDO



  //FIM SENSOR

  //SE A DISTANCIA FOR MAIOR QUE 50 
    if(distance > 50){
      //PRINTA A DISTANCIA E MOVIMENTA O CARRO  
      //SE A DISTANCIA FOR MENOR QUE 50
      Serial.print("Distancia: ");
      Serial.print(distance);
      Serial.println(" cm");
      //caso o carrinho esteja indo para tras usar a função:
      //robot_backward(velocidade); 
      robot_forward(velocidade);
    }else{
      //SE A DISTANCIA FOR MENOR QUE 30
      //PRINTA PERTO DE ALGO E PARA O CARRO
      Serial.print("PERTO DE ALGO!");
      robot_stop(RELEASE);
        delay(1000);
      //caso o carrinho esteja indo para tras usar a função:
      //robot_forward(velocidade); 
      robot_backward(velocidade);
        delay(1000);
      robot_stop(RELEASE);
        delay(600);
      robot_right(velocidade);
        delay(500);
      robot_stop(RELEASE);
        delay(600);
    }
}
 
 
//FUNÇÕES//

//MOVIMENTA O CARRO PARA FRENTE
void robot_forward(unsigned char v){
  //motor1.setSpeed(v);
  //motor1.run(FORWARD);
  motor2.setSpeed(v);
  motor2.run(FORWARD);
  motor3.setSpeed(v);
  motor3.run(FORWARD);
  //motor4.setSpeed(v);
  //motor4.run(FORWARD);
}
 
//MOVIMENTA O CARRO PARA TRÁS
void robot_backward(unsigned char v){
  //motor1.setSpeed(v);
  //motor1.run(BACKWARD);
  motor2.setSpeed(v);
  motor2.run(BACKWARD);
  motor3.setSpeed(v);
  motor3.run(BACKWARD);
  //motor4.setSpeed(v);
  //motor4.run(BACKWARD);
}
 
//VIRA O CARRO PARA A ESQUERDA
void robot_left(unsigned char v){
  //motor1.setSpeed(v);
  //motor1.run(FORWARD);
  motor2.setSpeed(v);
  motor2.run(BACKWARD);
  motor3.setSpeed(v);
  motor3.run(RELEASE);
  // motor4.setSpeed(v);
  // motor4.run(BACKWARD);
}
 
//VIRA O CARRO PARA A DIREITA 
void robot_right(unsigned char v){
  //motor1.setSpeed(v);
  //motor1.run(RELEASE);
  motor2.setSpeed(v);
  motor2.run(RELEASE);
  motor3.setSpeed(v);
  motor3.run(BACKWARD);
  // motor4.setSpeed(v);
  //motor4.run(FORWARD);
}
 
//PARA O CARRO 
void robot_stop(unsigned char v){
  //motor1.setSpeed(v);
  //motor1.run(RELEASE);
  motor2.setSpeed(v);
  motor2.run(RELEASE);
  motor3.setSpeed(v);
  motor3.run(RELEASE);
  //motor4.setSpeed(v);
  //motor4.run(RELEASE);
}