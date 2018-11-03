/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 * FACULTAD DE INGENIERÍA EN CIENCIAS APLICADAS
 * CARRERA DE INGENIERÍA ELECTRÓNICA Y REDES DE COMUNICACIÓN
 * NOMBRE: Adriana Herdoiza
 * TEMA: Contador del 1 al 40 con suma y resta
 */
int A=5;  //declaramos las variables a usar con cada valor de pin para cada variable del display
 int B=4;
 int C=3;
 int D=2;
 int b1=6;  //declaramos el botón uno que va a ser quien se encargue de sumar
 int b2=7;  //se declara el botón 2 que va a restar
 int i=0;
 int dec=9;  //asignación de pines para decenas
 int uni=8;  //asignaciónde pin para unidades
 int decenas;
 int unidades;
void setup() {
 pinMode(A,OUTPUT);  //se declaran las salidas del display
 pinMode(B,OUTPUT);
 pinMode(C,OUTPUT);
 pinMode(D,OUTPUT);
 pinMode(b1,INPUT);  //se declaran las entradas de los botones
 pinMode(b2,INPUT);
 pinMode(dec,OUTPUT);  //salida de decenas del display
 pinMode(uni,OUTPUT);  //salida de unidades del display
}

void loop() {
  if(digitalRead(b1)==HIGH){ //se inicia lo que va a hacer el botón 1, que va a ser el encargado de sumar en uno
   delay(200);  //tiempo de espera 200ms
    if(i<40){  //realiza la acción hasta que el valor sea menos 40
     i++; //aumento en uno
     decenas=i/10;  //división entera, no con decimal
     unidades=i-(decenas*10);  //determina el valor de las unidades sin alterar las decenas
     
    }
    
  }
  if(digitalRead(b2)==HIGH){  //se inicia el botón 2, que va a ser el encargado de restar uno
    delay(200);  //tiempo de espera de 200 ms
    if(i>0) {  //realiza la acción si el valor de i es mayor que 0
      i--;  //resta uno
      decenas=i/10;  
      unidades=i-(decenas*10);
    }
  }
  digitalWrite(uni,HIGH); //UNI ACTIVA DISPLAY DE UNIDADES. Escribe el valor de unidades cuando está encendido
     digitalWrite(dec,LOW);  //el display de decenas está apagado
    
  contador(unidades); //delay necesita una variable para funcionar. Contador de unidades en funcionamiento
  delay(100); //tiempode espera de 100 ms

  digitalWrite(uni,LOW);  //el display de unidades esta apagado
     digitalWrite(dec,HIGH);  //escribe solamente el valor de las edcenas en el display, ya que las unidades están en apagado
     
   contador(decenas); //delay necesita una variable para funcionar. Funcionará el contador de las decenas
  delay(100);  //tiempo de espera de 100 ms

  
  
}
void  contador (int j){  //almacenar una variable. El nuevo ciclo de contador empieza a funcionar co cada uno de los casos diferentes
  switch(j){
    case 0:
  
  //0. Todos los valores serán leidos de forma binaria para cada uno de los números del 0 al 9
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  break;
  //1 EN BINARIO
  case 1:
  digitalWrite(A,HIGH); //MENOS SIGNIFICATIVO
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
   break;
  //2
  case 2:
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
   break;
  //3
  case 3:
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
   break;
  //4
  case 4:
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
   break;
  //5
  case 5:
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
   break;
  //6
  case 6:
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
   break;
  //7
  case 7:
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
   break;
  //8
  case 8:
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);
   break;
  //9
  case 9:
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);
   break;
}
}
