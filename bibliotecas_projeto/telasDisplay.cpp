/*
 * telasDisplay.cpp
 *
 *  Created on: 25 de set de 2019
 *      Author: poles
 */
#include "Arduino.h"
#include <LiquidCrystal.h>
#include "prjLib.h"

int tela=1;
int temp_status = 0; // 0 -> Ventilando / 1 - > Aquece
int driver_status = 0;
int buttonS_saidaHeat = 0;
int buttonS_saidaFan = 0;
int seleciona = 0;
int selecionaKpHeat = 0;
int selecionaKpFan = 0;

LiquidCrystal lcd(12, 11, 7, 4, 3, 2);

void iniciar_display(void)
{
	Serial.begin(9600);
	//Define o n�mero de colunas e linhas do LCD
	lcd.begin(16, 2);
	lcd.clear();
}

void limpa_lcd(void)
{
	lcd.clear();
}

/*
 * funcoes de controle das telas dos sistema
 * e as operacoes dos botoes para incremento/decremento de variaveis
 */
void estado_atual_do_sistema(void)
{
	const char linha1[] = "SP:     C", linha2[] = "PV:     C", linhaDriver[] = "Driver";
	const char linhaHeat[] = "Heat", linhaFan[] = "Fan ", linhaOn[] = "ON", linhaOff[] = "OFF";

	controlador_proporcional();

	lcd.setCursor(0, 0);
	lcd.print(linha1);
	lcd.setCursor(4, 0);
	lcd.print(setPoint,1);
	lcd.setCursor(0, 1);
	lcd.print(linha2);
	lcd.setCursor(4, 1);
	lcd.print(processValue,1);

	if(driver_status == 1)
	{
		if(modo_controlador == 0)
		{
			if(temp_status == 1)
			{
				lcd.setCursor(12, 0);
				lcd.print(linhaHeat);
			}
			else
			{
				lcd.setCursor(12, 0);
				lcd.print(linhaFan);
			}
		}
		else
		{
			if(heat_status == 1)
			{
				lcd.setCursor(12, 0);
				lcd.print(linhaHeat);
			}
			else
			{
				lcd.setCursor(12, 0);
				lcd.print(linhaFan);
			}
		}

	}

	if(driver_status == 0)
	{
		lcd.setCursor(10, 0);
		lcd.print(linhaDriver);
		lcd.setCursor(12, 1);
		lcd.print(linhaOff);
	}
	else
	{
		lcd.setCursor(12, 1);
		lcd.print(linhaOn);
	}



}

void ajuste_do_set_point(void)
{
	const char linha1[] = "New Set Point", linha2[] = "SP: ";

	lcd.setCursor(0, 0);
	lcd.print(linha1);
	lcd.setCursor(0, 1);
	lcd.print(linha2);
	lcd.setCursor(4, 1);
	lcd.print(setPoint,1);

	if(up_fell())
	{
		limpa_lcd();
		setPoint++;
	}

	if(down_fell())
	{
		limpa_lcd();
		setPoint--;
		if(setPoint<0) setPoint=0;
	}
}

void ajuste_do_ganho_proporcional(void)
{
	const char linha1[] = "New Prop Gain", linha2Heat[] = "Kp Heat:", linha2Fan[] = "Kp Fan:";
	const char linhaSeleciona[] = "*";

	if(seleciona == 0)
	{
		lcd.setCursor(0, 0);
		lcd.print(linha1);
		lcd.setCursor(1, 1);
		lcd.print(linha2Heat);
		lcd.setCursor(10, 1);
		lcd.print(kpHeat);

		if(selecionaKpHeat==0)
		{
			if(s_fell())
			{
				limpa_lcd();
				selecionaKpHeat=1;
			}
			if(down_fell())
			{
				limpa_lcd();
				seleciona = 1;
			}
		}
		else
		{
			lcd.setCursor(0, 1);
			lcd.print(linhaSeleciona);

			if(s_fell())
			{
				limpa_lcd();
				selecionaKpHeat=0;
			}
			if(down_fell())
			{
				limpa_lcd();
				if(kpHeat<1) kpHeat = 1;
				kpHeat--;
			}
			if(up_fell())
			{
				limpa_lcd();
				kpHeat++;
			}
		}
	}
	else
	{
		lcd.setCursor(0, 0);
		lcd.print(linha1);
		lcd.setCursor(1, 1);
		lcd.print(linha2Fan);
		lcd.setCursor(9, 1);
		lcd.print(kpFan);

		if(selecionaKpFan==0)
		{
			if(s_fell())
			{
				limpa_lcd();
				selecionaKpFan=1;
			}
			if(up_fell())
			{
				limpa_lcd();
				seleciona = 0;
			}
		}
		else
		{
			lcd.setCursor(0, 1);
			lcd.print(linhaSeleciona);

			if(s_fell())
			{
				limpa_lcd();
				selecionaKpFan=0;
			}
			if(down_fell())
			{
				limpa_lcd();
				if(kpFan<1) kpFan = 1;
				kpFan--;
			}
			if(up_fell())
			{
				limpa_lcd();
				kpFan++;
			}
		}
	}
}

void modo_manual_aquecedor(void)
{
	const char linha1[] = "  Manual Mode", linha2[] = "Heat: ";
	const char heat_on[] = "ON", heat_off[] = "OFF";

	lcd.setCursor(0, 0);
	lcd.print(linha1);
	lcd.setCursor(0, 1);
	lcd.print(linha2);
	lcd.setCursor(5, 1);
	
	if(heat_status == 1)
	{
		lcd.print(heat_on);
		lcd.setCursor(11,1);
		lcd.print(saidaHeat);
		posicao_porcentagem();

		if(s_fell() && buttonS_saidaHeat == 0)
		{
			buttonS_saidaHeat = 1;
			while(buttonS_saidaHeat == 1)
			{
				debouncer_loop();
				lcd.setCursor(9,1);
				lcd.print("->");

				if(up_fell() && buttonS_saidaHeat == 1)
				{
					saidaHeat += 5;
					if(saidaHeat > 100) saidaHeat = 100;
					posicao_porcentagem();
				}

				if(down_fell() && buttonS_saidaHeat == 1)
				{
					saidaHeat -= 5;
					if(saidaHeat < 0) saidaHeat = 0;
					posicao_porcentagem();
				}

				if(s_fell() && buttonS_saidaHeat == 1)
				{
					limpa_lcd();
					buttonS_saidaHeat = 0;
				}
			}
		}
	}
	else lcd.print(heat_off);

	if(up_fell())
	{
		limpa_lcd();
		heat_status = 1;
		fan_status = 0;
	}
	if(down_fell())
	{
		limpa_lcd();
		heat_status = 0;
	}

}

void modo_manual_ventilador(void)
{
	const char linha1[] = "  Manual Mode", linha2[] = "Fan: ";
	const char fan_on[] = "ON", fan_off[] = "OFF";

	lcd.setCursor(0, 0);
	lcd.print(linha1);
	lcd.setCursor(0, 1);
	lcd.print(linha2);
	lcd.setCursor(4, 1);

	if(fan_status == 1)
	{
		lcd.print(fan_on);
		lcd.setCursor(11,1);
		lcd.print(saidaFan);
		posicao_porcentagem();

		if(s_fell() && buttonS_saidaFan == 0)
		{
			buttonS_saidaFan = 1;
			while(buttonS_saidaFan == 1)
			{
				debouncer_loop();
				lcd.setCursor(9,1);
				lcd.print("->");

				if(up_fell() && buttonS_saidaFan == 1)
				{
					saidaFan += 5;
					if(saidaFan>100) saidaFan = 100;
					posicao_porcentagem();
				}

				if(down_fell() && buttonS_saidaFan == 1)
				{
					saidaFan -= 5;
					if(saidaFan<0) saidaFan = 0;
					posicao_porcentagem();
				}

				if(s_fell() && buttonS_saidaFan == 1)
				{
					limpa_lcd();
					buttonS_saidaFan = 0;
				}
			}
		}
	}
	else lcd.print(fan_off);

	if(up_fell())
	{
		limpa_lcd();
		fan_status = 1;
		heat_status = 0;
	}
	if(down_fell())
	{
		limpa_lcd();
		fan_status = 0;
	}
}

void desabilitar_driver_de_saida(void)
{
	const char linha1[] = "  Driver Status";
	const char linha2_enable[] = "    Enable";
	const char linha2_disable[] = "    Disable";

	lcd.setCursor(0, 0);
	lcd.print(linha1);

	if(driver_status == 1)
	{
		digitalWrite(enable, HIGH);
		lcd.setCursor(0, 1);
		lcd.print(linha2_enable);
	}
	else
	{
		digitalWrite(enable, LOW);
		lcd.setCursor(0, 1);
		lcd.print(linha2_disable);
	}

	if(up_fell())
	{
		limpa_lcd();
		driver_status = 1;
	}
	if(down_fell())
	{
		limpa_lcd();
		driver_status = 0;
	}

}

void posicao_porcentagem(void)
{
	// funcao para definir a posicao do simbolo % no display
	if(tela==4)
	{
		if(saidaHeat < 10)
		{
			lcd.setCursor(11,1);
			lcd.print(saidaHeat);
			lcd.setCursor(12,1);
			lcd.print("%  ");
		}
		else if(saidaHeat >= 10 && saidaHeat < 100)
		{
			lcd.setCursor(11,1);
			lcd.print(saidaHeat);
			lcd.setCursor(13,1);
			lcd.print("%  ");
		}
		else if(saidaHeat==100)
		{
			lcd.setCursor(11,1);
			lcd.print(saidaHeat);
			lcd.setCursor(14,1);
			lcd.print("%");
		}
	}
	else if(tela==5)
	{
		if(saidaFan < 10)
		{
			lcd.setCursor(11,1);
			lcd.print(saidaFan);
			lcd.setCursor(12,1);
			lcd.print("%  ");
		}
		else if(saidaFan >= 10 && saidaFan < 100)
		{
			lcd.setCursor(11,1);
			lcd.print(saidaFan);
			lcd.setCursor(13,1);
			lcd.print("%  ");
		}
		else if(saidaFan==100)
		{
			lcd.setCursor(11,1);
			lcd.print(saidaFan);
			lcd.setCursor(14,1);
			lcd.print("%");
		}
	}

}

void switch_telas(void)
{
	if(p_fell())
	{
		limpa_lcd();
		tela++;
		if(tela==7) tela=1;
	}
	switch(tela)
	{
		case 1:
			estado_atual_do_sistema();
		break;
		case 2:
			ajuste_do_set_point();
		break;
		case 3:
			ajuste_do_ganho_proporcional();
		break;
		case 4:
			modo_manual_aquecedor();
		break;
		case 5:
			modo_manual_ventilador();
		break;
		case 6:
			desabilitar_driver_de_saida();
		break;
	}
}

