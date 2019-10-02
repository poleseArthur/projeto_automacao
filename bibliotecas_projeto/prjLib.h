/*
 * telasDisplay.h
 *
 *  Created on: 25 de set de 2019
 *      Author: poles
 */

#ifndef BIBLIOTECAS_PROJETO_PRJLIB_H_
#define BIBLIOTECAS_PROJETO_PRJLIB_H_

// telasDisplay
void iniciar_display();
void limpa_lcd();
void estado_atual_do_sistema();
void ajuste_do_set_point();
void ajuste_do_ganho_proporcional();
void modo_manual_aquecedor();
void modo_manual_ventilador();
void desabilitar_driver_de_saida();
void posicao_porcentagem();
void switch_telas();

// teclado
void debouncer_setup();
void debouncer_loop();
bool p_fell();
bool up_fell();
bool down_fell();
bool s_fell();

// heartBeat
void heartBeat_setup();
void heartBeat();

// configControlador
void controlador_setup();
void controlador_proporcional();
void heat();
void fan();
void modo_sistema();

// variaveis
extern int tela;
extern int heat_status;
extern int kp;
extern int saidaHeat;
extern int saidaFan;
extern int fan_status;
extern int driver_status;
extern int modo_controlador;
extern int temp_status;
extern float setPoint;
extern float processValue;
extern const int input1;
extern const int input2;
extern const int enable;

#endif /* BIBLIOTECAS_PROJETO_PRJLIB_H_ */
