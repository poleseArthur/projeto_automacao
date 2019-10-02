/*
 * configControlador.cpp
 *
 *  Created on: 28 de set de 2019
 *      Author: poles
 */

#include "Arduino.h"
#include "prjLib.h"

int heat_status = 0;
int kp = 15;
int saidaHeat = 0;
int saidaFan = 0;
int fan_status = 0;
int modo_controlador = 0; // O -> automatico / 1 -> manual
float controladorProporcionalHeat;
float controladorProporcionalFan;
float setPoint = 28.0;
float processValue;
const int lm35 = A0;
const int input1 = 5;
const int input2 = 6;
const int enable = A1;

void controlador_setup()
{
	pinMode(input1, OUTPUT);
	pinMode(input2, OUTPUT);
	pinMode(enable, OUTPUT);
	analogWrite(input1, 0);
	analogWrite(input2, 0);
	digitalWrite(enable, LOW);
}

void controlador_proporcional()
{
	/* O controlador utilizado serï¿½ do tipo Proporcional, neste controlador o sinal de erro,
diferenï¿½a entre o sinal de referï¿½ncia e o sinal de realimentaï¿½ï¿½o, ï¿½ multiplicado pelo ganho
proporcional (Kp) e aplicado a saï¿½da. */
	processValue = (float(analogRead(lm35)) * 5 / (1023)) / 0.01;

	// Se a temperatura ambiente for maior que o SetPoint - Aquece
	// Se a temperatura ambiente for menor que o SetPoint - Ventila

	if(processValue < setPoint && driver_status == 1)
	{
		temp_status = 1; // Aquece
		heat();
	}

	else if(processValue > setPoint && driver_status == 1)
	{
		temp_status = 0; // ventila
		fan();
	}

}	

void heat()
{
	// mapeamento para o resistor
	controladorProporcionalHeat = (setPoint - processValue) * kp;
	controladorProporcionalHeat = map(controladorProporcionalHeat, 0, 100, 0, 70);

	// verifica se o Modo Manual do Heat está ativo.
	// Se tiver, recebe o valor da temperatura com o ganho
	// Se não estiver, recebe o valor da saida definida
	if (modo_controlador == 0 && heat_status == 1)
	{
		analogWrite(input1, controladorProporcionalHeat);
		analogWrite(input2, 0);
	}
	else if(heat_status == 1)
	{
		analogWrite(input1, (saidaHeat * 255) / 100);
		analogWrite(input2, 0);
	}
}

void fan()
{
	// mapeamento para o ventilador
	controladorProporcionalFan = (setPoint + processValue) * kp;
	controladorProporcionalFan = map(controladorProporcionalFan, 0, 100, 56, 255);

	if (modo_controlador == 0 && fan_status == 1)
	{
		analogWrite(input1, 0);
		analogWrite(input2, controladorProporcionalFan);
	}
	else if(fan_status == 1)
	{
		analogWrite(input1, 0);
		analogWrite(input2, (saidaFan * 255) / 100);
	}
}

void modo_sistema(void)
{
	if(heat_status == 0 && fan_status == 0)
		modo_controlador = 0;
	else if(heat_status == 1 || fan_status == 1)
		modo_controlador = 1;
}

