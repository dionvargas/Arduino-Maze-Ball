#include <Servo.h>

// Os pinos que estão ligados os potenciometros
int pinoPotX = A4;
int pinoPotY = A5;

// Valor da leitura do potenciomentro
int valorPotX;
int valorPotY;

// Cria os objetos dos servos
Servo servoX;
Servo servoY;

void setup() {
  // Informa que pinos estão ligados a servos
  servoX.attach(10);
  servoY.attach(11);

  // Inicia os motores na posição zero
  servoX.write(90);
  servoY.write(90);
}

void loop() {
  valorPotX = analogRead(pinoPotX);
  valorPotY = analogRead(pinoPotY);

  // mapeia os valores do potenciometro (entre 0 e 1023) para os valores do servo (entre 0 e 180)
  valorPotX = map(valorPotX, 0, 1023, 0, 180);
  valorPotY = map(valorPotY, 0, 1023, 0, 180);

  // manda o valor para o servo
  servoX.write(valorPotX);
  servoY.write(valorPotY);
}