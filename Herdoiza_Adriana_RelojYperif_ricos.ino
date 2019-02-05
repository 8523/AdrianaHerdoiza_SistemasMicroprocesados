/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 * FICA-CIERCOM
 * NOMBRE: Adriana Herdoíza
 * FECHA: 05-02-2019
 * TEMA: Reloj Y DORMIR PERIFÉRICOS
 * 
 */

#include <LowPower.h> 
#include <MsTimer2.h>
#include <LiquidCrystal.h>

 #include <avr/sleep.h>
 #include <avr/power.h>
 #include <avr/wdt.h> //libreria perro guardian
 
LiquidCrystal lcd (13, 12, 11, 10, 9, 8); // RS,E,D4,D5,D6,D7 // Pines del Arduino

int hor = 0;  //variable para hora
int minu = 0;  //variable para minutos
int segu = 0;  //variable para segundos
String hora = "00:00:00";  //cadena para escritura de hora completa



void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);  //pantalla lcd
  lcd.setCursor(0, 0);  //posición del mensaje HORA
  lcd.print("HORA");  //mensaje de inicio
  lcd.setCursor(0, 1);  //posición de escritura de la hora
  lcd.print(hora);  //impresión de hora
  Serial.begin(9600);
  MsTimer2::set(100, reloj);  //un segundo para correr el reloj  
  MsTimer2::start();  //inicio de timer

set_sleep_mode(SLEEP_MODE_ADC);
set_sleep_mode(SLEEP_MODE_IDLE);
sleep_enable();

}

void loop() {
power_adc_disable();
power_spi_disable();
sleep_mode();
sleep_disable();
power_timer0_disable();


}

void reloj() {  //método de reloj
  if (segu < 59) {  //los segundos deben ser menores a 59, ya que, en 60 se cambiaría a un minuto
    segu++;  //se aumenta un segundo
    if (segu <= 9) {  //los segundos que sean menores o iguales a 9 se imprimen en la posición (7,1)
      lcd.setCursor(7, 1);  //posición para mostrar los segundos hasta el 9
      lcd.print(segu);  //impresión de segundos
    }
    else if (segu > 9) {  //si los segundos son mayores a 9 se guardarán en otra posición
      lcd.setCursor(6, 1);  //posición para guardar segundos mayores a 9
      lcd.print(segu);  //impresión de segundos
    }
  }
  else {
    segu = 0;  //para imprimir el valor en los segundos como cero
    lcd.setCursor(6, 1);
    lcd.print(segu);  //para imprimir en la primera posición
    lcd.print(segu);  //imprimo en la posición siguiente
    if (minu < 59) {  //cuando minuto sea menor que 59 se cumple lo siguiente
      minu++;  //minuto aumenta en uno
      if (minu <= 9) {  //si minuto es menor o igual que 9, se imprime en una posición
        lcd.setCursor(4, 1);
        lcd.print(minu);
      }
      else if (minu > 9) {  //cuando el minuto sea mayor que 9, se imprime en una posición anterior
        lcd.setCursor(3, 1);
        lcd.print(minu);
      }

    }
    else {
      minu = 0;  //caso contrario, minuto debe ser igual a cero en la posición donde se muestran los minutos
      lcd.setCursor(3, 1);
      lcd.print(minu);  //se imprime dos veces para ocupar los lugares de los dos ceros
      lcd.print(minu);
      if (hor < 23) {  //si la hora es menor a 23 se debe aumentar en uno
        hor++;  //aumento en uno de la hora
        if (hor <= 9) {  //cuando la hora sea menor o igual que 9 se imprimirá en una posición
          lcd.setCursor(1, 1);  //posición para impresión de hora cuando valga hasta 9
          lcd.print(hor);  //impresión de hora
        }
        else if (hor > 9) {  //caso contrario, cuando la hora sea mayor a 9 se debe imprimir en una nueva posición
          lcd.setCursor(0, 1);
          lcd.print(hor);

        }
      }
      else {
        hor = 0;  //caso contrario, la hora debe ser igual a cero
      }
    }
  }

}
