#include <Servo.h>

// Constantes de centro dos eixos e variação do angulo de rotação
const int centroX = 90;
const int centroY = 90;
const int variacaoX = 90;
const int variacaoY = 90;

// Os pinos que estão ligados os potenciometros
int pinoPotX = A4;
int pinoPotY = A5;

// Valor da leitura do potenciomentro
int valorPotX;
int valorPotY;

// Angulo da posição do servo

int anguloServoX = centroX;
int anguloServoY = centroY;

// Cria os objetos dos servos
Servo servoX;
Servo servoY;

void setup() {
  // Informa que pinos estão ligados a servos
  servoX.attach(10);
  servoY.attach(11);

  // Inicia os motores na posição zero
  servoX.write(anguloServoX);
  servoY.write(anguloServoY);
}

void loop() {
  valorPotX = analogRead(pinoPotX);
  valorPotY = analogRead(pinoPotY);

  // mapeia os valores do potenciometro (entre 0 e 1023) para os valores do servo (entre 0 e 180)
  anguloServoX = map(valorPotX, 0, 1023, centroX - variacaoX, centroX + variacaoX);
  anguloServoY = map(valorPotY, 0, 1023, centroY - variacaoY, centroY + variacaoY);

  // manda o valor para o servo
  servoX.write(valorPotX);
  servoY.write(valorPotY);
}
