#include "Arduino.h"
#include "bibliotecas_projeto/prjLib.h"

void setup()
{
	// todas as funcoes de setup do sistema
	iniciar_display();
	debouncer_setup();
	controlador_setup();
	heartBeat_setup();
}

void loop()
{
	heartBeat();
	debouncer_loop();
	modo_sistema();
	switch_telas();
}
