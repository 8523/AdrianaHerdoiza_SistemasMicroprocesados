/*UNIVERSIDAD TÉCNICA DEL NORTE
 * FICA-CIERCOM
 * NOMBRE: ADRIANA HERDOIZA
 * DEBER: REALIZAR LOS SIGUIENTES JUEGOS CON 6 LEDS
 */
int leds[6]={8,9,10,11,12,13};  //primero se define el vector para configurar los leds
int i=0;  //variable para recorrido del vector
void setup() {
  // configuración de pines de forma grupal
  for(;i<6;i++) {
    pinMode(leds[i],OUTPUT);
  }
i=0;  //reseteo de la variable de conteo
}

void loop() {
  // 1)Ejercicio 1:encendido de pines impares
 /* for(;i<6;i++) {
    if(i%2==1)  //es una condición para verificar los residuos si dividimos para 2, cuando el residuo sea 1, se enciencen los leds
    {
      digitalWrite(leds[i],HIGH);  //procede a encender los leds 
      delay(200);  //tiempo de espera
    }
  }
    for(;i>=0;i--) {  //se realiza la acción de apagar antes de volver a iniciar
      if(i%2==1) //con la condición va a verificar que el residuo sea 1 para proceder a apagar los leds
      {
       digitalWrite(leds[i],LOW);  //procede a apagar los leds
       delay(200);  //tiempo de espera
      }  
    }
    i=0; //reseteo de las variables*/

   // 2) EJERCICIO 2 
   /*or(;i<6;i++) {
    if(i%2==0)  //es una condición para verificar los residuos si dividimos para 2
    {
      digitalWrite(leds[i],HIGH);  
      delay(200);
    }
  }
    for(;i>=0;i--) {
      if(i%2==0)
      {
       digitalWrite(leds[i],LOW);
       delay(200);
      }  
    }
    i=0; //reseteo de las variables*/
    // 3) EJERCICIO 3 Realizar un juego que se enciendan y apaguen los leds de forma aleatoria. 
   for(;i<6;i++) {
    long variable=random(0,8);//se puede declarar un número aleatorio en un intervalo o rango mediante la  instrucción
    digitalWrite(leds[variable],HIGH); //procede a encender los leds
    delay(200);  //tiempo de espera
   }
   for(;i>=0;i--);{
    long variable=random(0,8); //se declara el numero aleatorio mediante un rango de random
    digitalWrite(leds[variable],LOW); //apaga los leds
    delay(200); //tiempd de espera
   }
   i=0;  //reinicio de variable
  }
  
