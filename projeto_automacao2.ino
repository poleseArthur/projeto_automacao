#include "Arduino.h"
#include "bibliotecas_projeto/prjLib.h"

void setup()
{
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
