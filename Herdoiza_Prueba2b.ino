/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 *      FICA-CIERCOM
 * NOMBRE: Adriana Herdoíza
 * FECHA: 22-01-2019
 * TEMA:  PRUEBA 1 SEGUNDO BIMESTRE
 */
 #include <MsTimer2.h>  //libreria Timer 
#include<avr/wdt.h>  //avr  //libreria para perro guardián 
#include <EEPROM.h>

int botmaster=2;
int pulsaC = 5; //pin para puslador de la letra C
int pulsaB = 6; //pin para puslador de la letra B
int pulsaA = 7; //pin para puslador de la letra A
String contra ="";
int funcionamiento;
const int intInterrup=2;
volatile int state = LOW;

void setup() {
  attachInterrupt(0,ingreso,FALLING);
  Serial.begin(9600);
  pinMode(pulsaA, INPUT);
  pinMode(pulsaB, INPUT);
  pinMode(pulsaC, INPUT);
  pinMode(botmaster, INPUT);

  EEPROM.update(0,'A');
  EEPROM.update(1,'B');
  EEPROM.update(2,'C');
}

void loop() {
////  EEPROM.read();
//  if(digitalRead(botmaster)==HIGH) {  
//  Serial.println("Activado:");
//  delay(200);
//  } 
//
//else {
//   Serial.println("Descativado");
//   delay(200);
//  }
  
// if(contra.length()<5) //condicion para controlar el tamaño de la contraseña, debe ser 5
//{
if(funcionamiento==2){
  {
    if(digitalRead(pulsaA) ==HIGH) {
      
      delay(300);
      Serial.println("A");
     contra= contra + "A";
    }
     if(digitalRead(pulsaB) == HIGH) {
      delay(300);
      Serial.println("B");
      contra = contra + "B";
    }
    if(digitalRead(pulsaC) == HIGH) {
      delay(300);
      Serial.println("C");
      contra= contra + "C";
    }
   }
//}   else if(contra.length()>5) {
//    contra = "";
//   }
//   else if(contra.length()==5) {
//    contra= "";
////   }    else {
////      contra="";
//      
    //}
   }
  

}

void ingreso() { 
  switch (funcionamiento) {
  case 0:
  Serial.println("ACTIVADO");
  funcionamiento++;
  break;
  case 1:
  Serial.println("Datos leidos");
  funcionamiento++;
  break;
  case 2:
  Serial.println("Contraseña guardada");
  Serial.println(contra);
  funcionamiento++;
  break;
  case 3:
  Serial.println("Comparación de datos");
  funcionamiento++;
  if(contra.length()>=5) {
  Serial.println("Contraseña incorrecta");
  }
  if(contra.length()==0) {
    Serial.println("Ingrese una contraseña");
  }
  if(contra.length()==5){
    Serial.println("Contraseña Correcta");
  }
  break;
  case 4:
  funcionamiento=0;
  break;
  }
  }
