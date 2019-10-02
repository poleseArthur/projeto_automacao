/*
 * heart_beat.cpp
 *
 *  Created on: 25 de set de 2019
 *      Author: poles
 */

#include "Arduino.h"
#include "prjLib.h"

const int redLedPin = A2;       //Pino onde está o LED vermelho
int redLedState = LOW;          //Estado inicial do led
unsigned long previousMillis = 0;        // Variável de controle do tempo
unsigned long redLedInterval = 1000;     // Tempo em ms do intervalo a ser executado

void heartBeat_setup(void)
{
	pinMode(redLedPin, OUTPUT);
}

void heartBeat(void)
{
	//Lógica de verificação do tempo
	if (millis() - previousMillis > redLedInterval)
	{
		previousMillis = millis();    // Salva o tempo atual
		//E aqui muda o estado do led
		//verificando como ele estava anteriormente
		if (redLedState == LOW) redLedState = HIGH;
		else redLedState = LOW;
		digitalWrite(redLedPin, redLedState);
	}
}

