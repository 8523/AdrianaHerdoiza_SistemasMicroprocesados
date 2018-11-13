/*  UNIVERSIDAD TÃ‰CNICA DEL NORTE
      FACULTAD DE INGENIERÃ�A EN CIENCIAS APLICADAS
  CARRERA DE INGENIERÃ�A ELECTRÃ“NICA Y REDES DE COMUNICACIÃ“N
    NOMBRE: Adriana Herdoiza
    FECHA: 13-11-2018
    DEBER: Contador de vocales*/
String texto; //se declara una cadena de texto para los datos ingresados
int tamao; //da el tamaño de la cadena de texto
int i = 0; //declaro la variable para el contador
int voc = 0; //Contador para el numero de vocales
void setup() {
  Serial.begin(9600);  //para activar la comunicacion serial
  Serial.println("Ingresar palabra");

}

void loop() {
  if (Serial.available() > 0) { //verifica si existen datos en la comunicaciÃ³n
    texto = Serial.readString(); //significa que va a leer los datos
    
    tamao = texto.length();  //se encarga de extraer el tamaño de la cadena de texto
    char vector [tamao];  //se encarga de definir el vector con el mismo tamaño de la cadena
    texto.toCharArray(vector, tamao + 1);  //se encarga de conversir un String a Chat
    for (;i<tamao;i++) {  ////recorre el char
      switch (vector[i]) {  //se encarga de contar las vocales
        case 'a':
          voc++;
          break;
        case 'e':
          voc++;
          break;
        case 'i':
          voc++;
        case 'o':
          voc++;
          break;
        case 'u':
          voc++;
          break;
        case 'A':
          voc++;
          break;
        case 'E':
          voc++;
          break;
        case 'I':
          voc++;
          break;
        case 'O':
          voc++;
          break;
        case 'U':
          voc++;
          break;
      }
    }
    Serial.print("Palabra:");  //Demuestra resultados
    Serial.println(texto);  //Texto que se ingresa
    Serial.print("Cantidad de vocales:");
    Serial.println(voc);  //Candidad de vocales ingresadas
  }
}
