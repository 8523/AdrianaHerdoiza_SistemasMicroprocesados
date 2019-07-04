#include <TimerOne.h>

/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 *      FICA-CIERCOM
 *   NOMBRE: Adriana Herdoíza
 *   FECHA: 03-07-2019
 *   TEMA: Conversor Análogo Digital
 */

 String trama;  //datos a enviar
 int ADC1;  //para almacenar valores
 int ADC2;  //para almacenar valores
 
void setup() {
 Serial.begin(9600);
 //Definir las entradas de los pines
 pinMode(9,INPUT);
 pinMode(10,INPUT);
 Timer1.initialize(2000000);  //inicializar el timer
 Timer1.attachInterrupt(contar);
}

void loop() {
}

void contar() {
  ADC1=analogRead(9);
  ADC2=analogRead(10);
  trama=String(ADC1)+" "+String(ADC2);
  Serial.print(trama); //se envía los datos por comunicación serial hacia la interfaz de processing
}
