//CARRO COM ARDUINO -  MERMÃS DIGITAIS 2023//

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
  //VELOCIDADE DOS MOTORES
  velocidade = 0x7F; // Velocidade do motores("0x44">>25% // "0x7F">>50% // "0x55">>75% // "0xFF">>100%)
}

//LOOP"INFINITO"
void loop(){

      //MOVIMENTA O CARRO PARA FRENTE:
      robot_forward(velocidade);

      //CONFIGURA UM INTERVALO DE TEMPO PARA O CARRO PARAR ANTES DE ANDAR DENOVO:
        delay(600);
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