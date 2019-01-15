#include <EEPROM.h>  //libreria memoria EEPROM

#include <EEPROM.h>

/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 *      FICA-CIERCOM
 * NOMBRE:Adriana Herdoíza
 * FECHA: 15-01-2019
 * TEMA: EEPROM
 */

 //int valor=0;  //variable
 int interrupcion;    //variable para la interrupcion
 int funcionamiento;  //variable para todo el funcionamiento del programa
 int variable=0;  //
 String dato;  //variable para guardar los datos ingresados
void setup() {
  Serial.begin(9600);  //inicializacion del serial
  attachInterrupt(0,control,FALLING);  //interrupción
  
}

void loop() {  //empieza con el funcionamiento en 2
  if(funcionamiento==2) {
    if(Serial.available() > 0) {  //ingreso de datos
      dato=Serial.readString();  //lectura del dato como string
    }
  }

}

void control() {  //control del funcionamiento con los diferentes casos
  
    switch (funcionamiento)  //
    {
      case 0:
      Serial.println("Ingrese un dato");  //caso 0 para ingresar un dato
       
        funcionamiento++;  //el funcionamiento se aumenta en uno
        break;
      case 1:  //caso uno para leer los datos
        Serial.println("Datos leidos");
       //if(Serial.available() > 0) {
        //dato=Serial.readString(); 
      // }
        // Serial.println(dato);
        funcionamiento++;  //se aumenta en uno el funcionamiento
        break;
        
        case 2:  //caso dos para  guardar el dato
      Serial.println("Dato guardado");
       
        funcionamiento++;  //funcionamiento aumenta en uno para seguir corriendo
        break;
        
        case 3:  //caso tres para comparación de datos
       Serial.println("comparacion de datos");
       metodo();  //llamo al método
        funcionamiento++;  //el funcionamiento aumenta en uno
        break;  

           case 4:  //caso cuatro el funcionamiento vuelve a cero
           funcionamiento=0;
           break;
           
    }
    }

 void metodo() {  //método para comprobación de datos
  if(dato.toInt()>=0&&dato.toInt()<255){  //para realizar la comparación en cuanto al rango, primeramente se debe convertir el dato que esta como string a entero
    Serial.println("Dato correcto");  //se imprime el el mensaje para demostrar que el dato está dentro del rango
    if(dato.toInt()>EEPROM.read(0)){  //se compara el dato guardado en la memoria EEPROM con el dato que se ingresa
      EEPROM.update(0,dato.toInt());   //si cumple con los parámetros y si el dato si es mayor al ingresado anteriormente, el nuevo dato ingresado se reemplaza y se guarda
       
    }  else
    {
      Serial.println("Dato no es mayor");  //caso contrario, el bota el siguiente mensaje
      Serial.println(EEPROM.read(0));  //se escribe el dato que está en la memoria
      funcionamiento=0;  //el funcionamiento vuelve a cero
    }
 
    
  }  else
    {
      Serial.println("Dato fuera del rango"); //si es que el valor no cumple con los parámetros de rango se escribe el mensaje
    }
   
 }
  
