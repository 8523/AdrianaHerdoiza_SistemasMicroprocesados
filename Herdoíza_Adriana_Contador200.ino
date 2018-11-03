/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 * FACULTAD DE INGENIERÍA EN CIENCIAS APLICADAS
 * CARRERA DE INGENIERÍA ELECTRÓNICA Y REDES DE COMUNICACIÓN
     NOMBRE: Adriana Herdoíza
     TEMA: DISPLAYS 7 SEGMENTOS
 * CONTADOR DEL 1 AL 200
 */
 int A=5;  //declaración de variables ausar -> pin5 para la variable A
 int B=4;  //pin 4 para B
 int C=3;  //pin 3´para C
 int D=2;  //pin 2 para D
 //int b1=6;
 int i=0;
 int dec=9;  //se usa el pin 9 para activar el display de decenas
 int uni=8;  //se usa el pin 8 para activar el display para unidades
 int cen=10;  //se usa el pin 10 para activar el display de centenas
 int decenas;  //declaro parámetros a usar para decenas
 int unidades;  //declaro parámetros a usar para unidades
 int centenas;  //declaro parámetros a usar para centenas
void setup() {
 pinMode(A,OUTPUT);  //salida A 
 pinMode(B,OUTPUT);  //salida B
 pinMode(C,OUTPUT);  //salida C
 pinMode(D,OUTPUT);  //salida D
 //pinMode(b1,INPUT);
 pinMode(dec,OUTPUT); // salidas
 pinMode(uni,OUTPUT);
 pinMode(cen,OUTPUT);
}

void loop() {
  //if(digitalRead(b1)==HIGH){
   // delay(200);
    if(i<200){  //si i es igual a 200 (200 es el número hasta el que voy a contar), entonces ejecuta lo siguiente
     i++;  //i aumenta en 1
     centenas=i/100; //para asignar el valor de las centenas
     decenas=i/10-(centenas*10);  //división entera, no con decimal, para asignar el valor de las decenas
     unidades=i-(decenas*10)-(centenas*100);  //para asignar el valor de las centenas
     
     
    }
     else{  //cuando llegue a 200, el programa se va a reiniciar y vuelve a contar
     i=0;
  }
  //}
  digitalWrite(uni,HIGH); //uni activa el display de unidades
     digitalWrite(dec,LOW);  //dec desactiva el display de decenas
     digitalWrite(cen,LOW);  //el display de centenas está desactivado
  contador(unidades); //funcionará el contador de unidades
  delay(100);  //tiempo de espera de 100ms

  digitalWrite(uni,LOW); //display de unidades desactivado
     digitalWrite(dec,HIGH);  //display de decenas activado
     digitalWrite(cen,LOW);  //display de centenas desactivado
   contador(decenas); //funcionará el contador de decenas
  delay(100);  //tiempo de espera de 100ms

  digitalWrite(uni,LOW);  //display de unidades desactivado
     digitalWrite(dec,LOW);  //display de decenas desactivado
     digitalWrite(cen,HIGH);  //display de centenas activado
   contador(centenas); //funcionará el contador que lea las centenas. delay necesita una variable para funcionar
  delay(100);  //tiempo de espera de 100 ms
}
void  contador (int j){  //almacenar una variable. Un nuevo método que se llama contador, para que pueda realizar las operaciones en cada uno de los displays para contar del 0 al 9
  switch(j){
    case 0:
  
  //0 el cero se lee en forma de binario
  digitalWrite(A,LOW);  //A es el menos significativo
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  break;  //espera y pasa al siguiente caso
  //1 , el uno se lee en forma de binario
  case 1:
  digitalWrite(A,HIGH); //MENOS SIGNIFICATIVO
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
   break;
  //2  el dos se lee en forma de binario
  case 2:
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
   break;
  //3, el tres se lee en forma de binario
  case 3:
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
   break;
  //4, el cuatro se lee en forma de binario
  case 4:
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
   break;
  //5, el cinco se lee en forma de binario
  case 5:
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
   break;
  //6, el seis se lee en forma de binario
  case 6:
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
   break;
  //7, el siete se lee en forma de binario
  case 7:
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
   break;
  //8, el ocho se lee en forma de binario
  case 8:
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);
   break;
  //9, el nueve se lee en forma de binario
  case 9:
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);
   break;
}
}
