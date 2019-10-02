################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
..\bibliotecas_projeto\configControlador.cpp \
..\bibliotecas_projeto\heart_beat.cpp \
..\bibliotecas_projeto\teclado.cpp \
..\bibliotecas_projeto\telasDisplay.cpp 

LINK_OBJ += \
.\bibliotecas_projeto\configControlador.cpp.o \
.\bibliotecas_projeto\heart_beat.cpp.o \
.\bibliotecas_projeto\teclado.cpp.o \
.\bibliotecas_projeto\telasDisplay.cpp.o 

CPP_DEPS += \
.\bibliotecas_projeto\configControlador.cpp.d \
.\bibliotecas_projeto\heart_beat.cpp.d \
.\bibliotecas_projeto\teclado.cpp.d \
.\bibliotecas_projeto\telasDisplay.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
bibliotecas_projeto\configControlador.cpp.o: ..\bibliotecas_projeto\configControlador.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\poles\Downloads\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"C:\Users\poles\Downloads\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\cores\arduino" -I"C:\Users\poles\Downloads\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\variants\standard" -I"C:\Users\poles\Downloads\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"C:\Users\poles\Downloads\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

bibliotecas_projeto\heart_beat.cpp.o: ..\bibliotecas_projeto\heart_beat.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\poles\Downloads\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"C:\Users\poles\Downloads\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\cores\arduino" -I"C:\Users\poles\Downloads\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\variants\standard" -I"C:\Users\poles\Downloads\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"C:\Users\poles\Downloads\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

bibliotecas_projeto\teclado.cpp.o: ..\bibliotecas_projeto\teclado.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\poles\Downloads\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"C:\Users\poles\Downloads\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\cores\arduino" -I"C:\Users\poles\Downloads\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\variants\standard" -I"C:\Users\poles\Downloads\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"C:\Users\poles\Downloads\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

bibliotecas_projeto\telasDisplay.cpp.o: ..\bibliotecas_projeto\telasDisplay.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\poles\Downloads\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"C:\Users\poles\Downloads\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\cores\arduino" -I"C:\Users\poles\Downloads\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\variants\standard" -I"C:\Users\poles\Downloads\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"C:\Users\poles\Downloads\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


