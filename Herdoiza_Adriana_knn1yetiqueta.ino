/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 * FICA-CIERCOM
 * EMBEBIDOS
 * NOMBRE: Adriana Herdoíza
 * TEMA: KNN
 */

#include "datos.h"


int col; //Para recorrer las columnas
int fila = 0; //Para recorrer las filas
float datos_entrada [4] = {5.5,2.6,4.4,1.2}; //Datos usados para realizar pruebas
float promedio=0; //Para almacenar el promedio de las distancias
float distancia; //Para almacenar la raíz de la distancia
const int k = 3; //Número de vecinos
float dist_menores [2][k]; //Matriz para distancias y etiquetas
int i=0; //Contador
int j=0; //Contador
float aux; //Auxiliar para almacenar Distancia
float aux1; //Auxiliar para almacenar Etiqueta
int guardar;

void setup () {
Serial.begin(9600);
for(;i<k;i++) {  //Primero almacena valores de las distancias altas
dist_menores[0][i]=4000+i;  //Escoger un valor alto para entrar a la condición
dist_menores[1][i]=0;  //Valor para cualquier etiqueta
}
i=0;  //Reseteo de la variable para volver a sere usada
}

void loop() {
for(;fila<90; fila++) {  //Para recorrer todas las filas de la matriz
for(col=0; col<4; col++) {  //Para recorrer las cuatro primeras columnas
promedio=promedio+(pow(datos_entrada[col]-matriz[col][fila],2));  //Fórmula para Potencia
}
distancia=sqrt(promedio);  //Fórmula para la raíz de la distancia
promedio=0;  //Reseteo de la variable

//Para comparar las distancias existentes, si es menor, la distancia se almacena al fiinal de la fila
  if(distancia<dist_menores[0][k-1]) {  //Inicio de comparación
  dist_menores[0][k-1]=distancia;  //Almacena la distancia después de ser comparada
  dist_menores[1][k-1]=matriz[fila][4];  //Almacena la etiqueta
  }  //Se termina la comparación

//Para ordenar las distancias
  for(;i<k;i++) {  //Para recorrer las filas

    for(j=i+1;j<k;j++) {  //Para recorrer las columnas
      if(dist_menores[0][j]>dist_menores[0][i]){  //Compara las distancias de dos en dos siempre
      aux=dist_menores[0][i];  //Primero ordena la fila de la distancia
      dist_menores[0][i]=dist_menores[0][j];
      dist_menores[0][j]=aux;

/////// etiquetas
    aux1=dist_menores[1][i];  //Para ordenar la fila de las etiquetas
    dist_menores[1][i]=dist_menores[1][j];
    dist_menores[1][j]=aux1;
    }
  }
  }  //Fin ordenar
}
i=0; //Reseteo de la variable

for (; i < k; i++) { //Recorre la fila etiquetas
  
    if (dist_menores [1][i] != 0)
      guardar = dist_menores [1][i]; //Para almacenar la etiqueta
  }
  Serial.print("Etiqueta tipo: ");  //Para imprimir la etiqueta final
  Serial.println(guardar);  //Imprimo el dato de la etiqueta que se guardó
}
