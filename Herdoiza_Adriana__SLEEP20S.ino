/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 *    FICA - CIERCOM
 *  NOMBRE: Adriana Herdoíza
 *  FECHA: 05-02-2019
 *  TEMA: Deber Modo Sleep. 20 segundos y lee el conversor análogo digital
 */

#include <LowPower.h>  //libreria para apagar y encender el sistema de arduino

int dato=0;  //variable qie se usará para manejar el tiempo de apagado del sistema

void setup() {
  Serial.begin(9600);  //inicialización del serial
 

}

void loop() {
  for(;dato<5; dato++) {  //dato que se ura para manejar el tiempo de apagado, en este caso se lo realizará 5 veces se apaga 4 segundos, es decir 20 en total y lee el conversor
LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);  //linea de apagado del sistema
  }

Serial.println(analogRead(0));  //lectura del conversor análogo digital
delay(300);  //espera de 300
dato=0;  //se reinicia el sistema

}
