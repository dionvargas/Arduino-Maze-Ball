#include <Servo.h>

// Constantes de centro dos eixos e variação do ângulo de rotação
const int centroX = 90;
const int centroY = 90;
const int variacaoX = 10;
const int variacaoY = 10;

// Os pinos que estão ligados os potenciômetros
int pinoPotX = A4;
int pinoPotY = A5;

// Valor da leitura do potenciômentro
int valorPotX;
int valorPotY;

// Ângulo da posição do servo
int anguloServoX = centroX;
int anguloServoY = centroY;

// Cria os objetos dos servos
Servo servoX;
Servo servoY;

void setup() {
  // Informa em quais pinos estão ligados a servos
  servoX.attach(10);
  servoY.attach(11);

  // Inicia os motores na posição central
  servoX.write(anguloServoX);
  servoY.write(anguloServoY);
}

void loop() {
  valorPotX = analogRead(pinoPotX);
  valorPotY = analogRead(pinoPotY);

  // mapeia os valores do potenciômetro (entre 0 e 1023) para os valores do servo
  anguloServoX = map(valorPotX, 0, 1023, centroX - variacaoX, centroX + variacaoX);
  anguloServoY = map(valorPotY, 0, 1023, centroY - variacaoY, centroY + variacaoY);

  // grava o valor no servo
  servoX.write(valorPotX);
  servoY.write(valorPotY);
}
