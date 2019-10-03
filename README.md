### Controlador Proporcional

* **Objetivo:**

	O projeteo consiste em um sistema de controle de temperatura capaz de aquecer e resfriar o ambiente baseado na temperatura atual e na temperatura programada. O controlador é do tipo Proporcional com saídas para o drive do tipo PWM. Contém um led de vida do sistema (Heart Beat), que oscila em 0,5Hz sempre que o sistema estiver energizado.
	
<div align="center">
<img src="diagramaDeBlocos.PNG" alt="diagrama" width="50%" height="20%"/></center>
</div>

* **Sistema:**

	O bloco de interface contém um display de LCD 16x2 e 4 botões. O display apresenta a temperatura atual, a temperatura desejada (set-point) e o estado atual da saída (aquecendo, resfriando, desabilitado). 
	
	Os botões são utilizados para alterar o os parâmetros do controlador e valor de set point:

<div align="center">
<img src="botoes.PNG" alt="botoes" width="50%" height="20%"/></center>
</div>
	
Teclado:

	P: Programar/Alternar telas.
	+: Incrementa um valor numérico, modifica uma saída para ON.
	-: Decrementa um valor numérico, modifica uma saída para OFF.
	S: Confirma o ajuste atual.

Os botões do teclado servem para ajustar:

	- Um novo set-point.
	- Valor do ganho proporcional do controlador.
	- Desabilitar o controlador (desligar o driver independente do ajuste de
	temperatura)
	- Ligar/Desligar manualmente o aquecedor.
	- Ajustar o valor da saída do aquecedor no modo manual (0...100%).
	- Ligar/Desligar manualmente o ventilador.
	- Ajustar o valor da saída do ventilador no modo manual (0...100%).

* **Display:**

O projeto apresenta as seguintes telas:

	Tela 1: Estado Atual do Sistema
		SP: Set Point (Valor ajustado de temperatura)
		PV: Process Value (Valor atual de temperatura)
		Heat: Aquecendo (Ligado = ON, Desligado = OFF)
		Driver (Habilitado = ON, Desabilitado = OFF)

	Tela 2: Ajuste do Set Point
		SP: Set Point (Valor ajustado de temperatura)

	Tela 3: Ajuste do Ganho Proporcional
		Kp Aquecedor e do Ventilador: Proportional Gain (Valor do ganho proporcional)

	Tela 4: Modo Manual Aquecedor
		Ex.1:
			Estado: ON = Aquecedor Ligado, saída a 50%.
		Ex.2:
			Estado: OFF = Aquecedor desligado, valor da saída não deve aparecer.

	Tela 5: Modo Manual Ventilador
		Ex.1:
			Estado: ON = Ventilador Ligado, saída a 35%.
		Ex.2:
			Estado: OFF = Ventilador desligado, valor da saída não deve aparecer.

	Tela 6: Desabilitar Driver de saída
		Ex. 1:
			Driver habilitado, tanto para o aquecedor quanto para o ventilador

* **Periféricos:**
   - Sensor de temperatura utilizado é o sensor analógico LM35.
   - MCU ATMega328p (Arduino).
   - L293D: Ponte H utilizada para controlar ventilador e aquecedor.
   - Ventilador: Utilizado para o modo Fan.
   - Aquecedor: Utilizado para o modo Heat.

* **Software:**
   - Sloeber, IDE do Eclipse para o Arduino.
 
* **Simulação no Proteus:**

<div align="center">
<img src="proteus.PNG" alt="proteus" width="50%" height="20%"/></center>
</div>

* **Montagem prática:**

<div align="center">
<img src="montagem.jpeg" alt="montagem" width="50%" height="20%"/></center>
</div>
