/*
 * teclado.cpp
 *
 *  Created on: 25 de set de 2019
 *      Author: poles
 */

#include <Bounce2.h>
#include "prjLib.h"

const int buttonP = 8;
const int buttonUp = 9;
const int buttonDown = 10;
const int buttonS = 13;

Bounce p_botao    = Bounce();
Bounce up_botao   = Bounce();
Bounce down_botao = Bounce();
Bounce s_botao 	  = Bounce();

void debouncer_setup(void)
{
	pinMode(buttonP, 	INPUT);
	pinMode(buttonUp, 	INPUT);
	pinMode(buttonDown, INPUT);
	pinMode(buttonS, 	INPUT);

	p_botao.attach(buttonP);
	p_botao.interval(5);

	up_botao.attach(buttonUp);
	up_botao.interval(5);

	down_botao.attach(buttonDown);
	down_botao.interval(5);

	s_botao.attach(buttonS);
	s_botao.interval(5);
}

void debouncer_loop(void)
{
	p_botao.update();
	up_botao.update();
	down_botao.update();
	s_botao.update();
}

bool p_fell()
{
	if (p_botao.fell()) return true;
	else return false;
}

bool up_fell()
{
	if (up_botao.fell()) return true;
	else return false;
}

bool down_fell()
{
	if (down_botao.fell()) return true;
	else return false;
}

bool s_fell()
{
	if (s_botao.fell()) return true;
	else return false;
}
