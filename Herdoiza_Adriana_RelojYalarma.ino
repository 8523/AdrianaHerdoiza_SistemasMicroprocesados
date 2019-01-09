/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 *        FICA-CIERCOM
 * NOMBRE: Adriana Herdoíza
 * FECHA: 10-01-2019
 * TEMA: RELOJ CON ALARMA
 */

#include <MsTimer2.h>  //libreria de timer2
#include <LiquidCrystal.h>  //libreria para lcd

LiquidCrystal lcd (13, 12, 11, 10, 9, 8); // RS,E,D4,D5,D6,D7 // Pines del Arduino

int hor = 0;  //variable para hora
int minu = 0;  //variable para minutos
int segu = 0;  //variable para segundos
String hora = "00:00:00";  //cadena para escritura de hora completa


String alh;  //variable para alarma de horas
String alm;  //variable para alarma de minutos
String guardar;  //variable para guardar lo que ingreso
int funcionamiento;  //funcionamiento del sistema

int led=3;  //variable para led en el pin 3 de arduino

void alarma()  //método alarma
{ 
  switch (funcionamiento) {    //variable funcionamiento
    case 0:  //ingreso de datos
      { 
        funcionamiento++;
        Serial.println("Ingreso de alarma en horas:minutos");  //formato para ingreso de alarma
        guardar = "";  //vaciar la cadena guardada
      }
      break;
    case 1: //datos para leer
      Serial.println("Datos leidos ");  //datos que será leidos
      funcionamiento++;  //se aumenta funcionamiento
      break;
    case 2: //datos para que sean leidos
      { 
        Serial.println("Datos");  //indica los datos
        if (guardar.length() == 0)  //guardar tamaño
        {
          Serial.println("No es posible ingresar la alarma");  //si se ingresa al mal aparece el mensaje de que no es posible ingresar la alarma
          funcionamiento = 0;  //se resetea el funcionameinto
        }
        else {
          Serial.println("ALARMA CORRECTA");  //caso contrario, la alarma será correcta
          funcionamiento++;  //se aumenta el funcionamiento
        }

      }
      break;
    case 3:
      Serial.println("Los datos que ud ingreso son ");  //muestra los datos que se ingresaron para validarlos
      Serial.println(alh);  //imprime lo que está en alarma hora
      Serial.println(alm);  //imprime lo que está en alarma minuto
      //funcionamiento++;
      break;

      case 4:
     funcionamiento=0;
     Serial.print("fin de ciclo");
      break;
  }
}
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
  
  Serial.begin(9600);
  attachInterrupt(0, alarma, FALLING);//interrupcion del sistema 
  pinMode(led,OUTPUT);  //declaro pin 3 como salida de led
}

void loop() {
  if (funcionamiento == 1) {  
    if (Serial.available() > 0) {   //comprobar la comunicación serial
      guardar = Serial.readString();//Recibe en caracteres que se ingresaron en la cadena
      int tam = guardar.length();//tamaño de la cadena ingresada
      if (guardar.charAt(2) == ':' && guardar.length() == 5) {  //condición que verifique que en la posición 2 debe ir ":" y que la cadena tenga el tamaño de 5
        for (int i = 0; i < tam; i++) { //recorrido de la cadena
          if (guardar.charAt(i) == ':') //condiciones de reconocimiento
          {
            alh = guardar.substring(0, i );  //para guardar el substring de la alarma hora
            alm = guardar.substring(i + 1, guardar.length());  //para guardar la subcadena de la alarma minuto
          }
        }
      } 
      else
      { 
        Serial.println("valor no permitido");  //si el valor no coincide con las especificaciones aparede el mensaje
        guardar = "";  //se vacía la cadena
        funcionamiento = 0;  //el funcionameinto se resetea
      }
      
    }
    if (alh.toInt()>23) {  //convierto a entero la hora y verifica que esté dentro del rango del valor máximo
      Serial.println("El valor de hora se excede del limite");  //si el valor es mayor, aparrece el mensaje
      funcionamiento=0; //se resetea el funcionamiento
      guardar="";  //se vacia la sub cadena guardar
      alh="";  //se vacia la subcadena alarma de hora
      alm="";  //se vacia la subcadena alarma minuto
      
    }
    if (alm.toInt()>59) {  //verifica que los minutos no excedan de 59
      Serial.println("El valor de minuto se excede del limite");  //si es un valor mayor aparece el mensaje
      funcionamiento=0;  //se resetea el funcionamiento
      guardar="";  //se vacia la sub cadena guardar
      alh="";  //se vacia la subcadena alarma de hora
      alm="";  //se vacia la subcadena alarma minuto
    }

  }
if(funcionamiento==3) {  //para usar con el caso 3
  
  if(alh.toInt()==hor&&alm.toInt()==minu) {  //conviero los strings de la alarma a entero para que sean comparadas con los valores que tiene las horas y minutos en el reloj
    digitalWrite(led,HIGH);  //si corresponde a la comprobación, se enciende el led que indica alarma
    Serial.print("Comprueba");  //se imprime un mensaje para comprobar que ingresa la condición
    funcionamiento=0;  //luego se resetea el funcionamiento
  }
  else {  
    digitalWrite(led,LOW);  //en caso de que no se cumpla la condición, el led se mantiene apagado
  }
}
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
    lcd.setCursor(6, 1);  //posición para impresión de los segundos
    lcd.print(segu);  //para imprimir en la primera posición
    lcd.print(segu);  //imprimo en la posición siguiente
    if (minu < 59) {  //cuando minuto sea menor que 59 se cumple lo siguiente
      minu++;  //minuto aumenta en uno
      if (minu <= 9) {  //si minuto es menor o igual que 9, se imprime en una posición
        lcd.setCursor(4, 1);  //posición en la lcd para imprimir minutos
        lcd.print(minu);  //impresión de minutos
      }
      else if (minu > 9) {  //cuando el minuto sea mayor que 9, se imprime en una posición anterior
        lcd.setCursor(3, 1);  //posición para impresión
        lcd.print(minu);  //imprime en esa posición los monutos mayores a 9
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
