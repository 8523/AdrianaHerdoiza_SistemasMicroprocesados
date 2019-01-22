/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 *      FICA-CIERCOM
 * NOMBRE: Adriana Herdoíza
 * FECHA: 22-01-2019
 * TEMA: Realizar un programa que permita que el conversor análogo digital configure al perro guardían a 10,20,30 y 40 segundos. Este proceso se visualiza en una lcd.
 */

#include <MsTimer2.h>  //libreria Timer 
#include<avr/wdt.h>  //avr  //libreria para perro guardián 
#include <LiquidCrystal.h>  //LIBRERIA para lcd
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);  //pines para usar la lcd

float conversor;  //variable que recibe CAD
int dato; //variable para recibir los datos del conversor análogo para visualizar en lcd
int cont = 0;  //variable para el contador a usar para para igualar los valores y activar el perro guardián
int valor;  //variable para asignar el valor del número  donde quiero activar el perro guardián
int i = 0;
void setup() {
  Serial.begin(9600);  //inicializo cx serial
  lcd.begin(16, 2);  //inicializar la lcd
  lcd.setCursor(5, 0);  //seleccionar la posición en la lcd donde se va a imprimir al inicializarlo
  lcd.print("ACTIVADO");  //impresión de mensaje de activado en la lcd
  MsTimer2::set(1000, perro);  //timer que llama al método con valor de 1 segundo, inicialización del timer
  MsTimer2::start();  //inicializa el contador
  Serial.println("RESET");//se comenta esto 
}

void loop() {
  conversor = analogRead(0); //recibe el dato del CAD
  dato = (5 * conversor) / 1023;  //conversor análogo digital
  lcd.setCursor(0, 1);  //posición donde se imprime el dato es decir el valor del conversor
  lcd.print(dato);  //se imprime en lcd lo que tenemos en dato del conversor
  delay(200);  //delay de 200ms

  if (dato == 1) {  //cuando el dato que se obtiene del conversor es igual a 1
    valor = 6;  //se asigna q el wdt se active cuando el contador esté en 6 para que sume los 4 segundos de activación del perro guarián y se active cuando esté en 6 el contador
  }
  if (dato == 2) {  //cuando el dato que se obtiene del conversor es igual a 2
    valor = 16;  //se asigna q el wdt se active cuando el contador esté en 16 para que sume los 4 segundos de activación del perro guarián y se active cuando esté en 20 el contador 
  }
  if (dato == 3) {  //cuando el dato que se obtiene del conversor es igual a 3
    valor = 26;  //se asigna q el wdt se active cuando el contador esté en 16 para que sume los 4 segundos de activación del perro guarián y se active cuando esté en 26 el contador
  }
  if (dato == 4) {  //cuando el dato que se obtiene del conversor es igual a 4
    valor = 36;  //se asigna q el wdt se active cuando el contador esté en 16 para que sume los 4 segundos de activación del perro guarián y se active cuando esté en 36 el contador
  }

}


void perro() {  //método para activación del perro guardián
  cont++;  //contador aumenta en 1
  lcd.setCursor(0, 0);  //en la posición (0,0) de la lcd 
  lcd.print(cont);  //se imprime el contador en la posición anterior
  lcd.setCursor(2, 0);  //en la posición (2,0) de la lcd
  lcd.print("              ");  //impresión de espacios para borrar el mensaje de Activación colocado anteriormente
  delay(10);  //delay de 10 ml
  if (cont == valor) { //si el contador es igual al valor que se asiga, es decir 6, 16, 26 y 36 se realiza la acción de activar el perro guardián en 4 segundos
    wdt_enable(WDTO_4S);  //activación del perro guardián en 4 segundos para sumarse a los valores anteriores y así obtener la activación en los valores reales.
  }

}
