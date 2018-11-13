/*UNIVERSIDAD TÉCNICA DEL NORTE
 * FICA- CIERCOM
 * NOMBRE: ADRIANA HERDOIZA
 * VALIDACIÓN DE CÉDULA
 */
 String ced="";  //se declara una cadena vacía
  
void setup() {
Serial.begin(9600);//velocidad de comunicacion serial
}
int verif(String letr)//metotdo para comprobar que no existan letras con la devolucion de un entero
{
  int comprob = 0;//declaracion de una variable que crecera si existen letras en la cedula ingresada
  for (int i = 0; i < letr.length(); i++)//se recorre la cedula ingresada { //irá recorriendo la cédula
    {
    char a= letr.charAt(i);  //sirve para extraer los caracteres de la cedula
    if ((int(a) >= 65) && (int(a) <=122))  //sirve para verificar codigos numericos con ascii
      { comprob++;//si se encuentra con una letra se aumenta el valor de la variable
    }
  }
  return comprob; //retorna la cantidad de letras encontradas
}

void loop() {
  if (Serial.available() > 0) {
    ced= Serial.readString();  //va a recibir
    delay(50); 
    int tam = ced.length();  //indica el tamaño de cadena de texto
    if (tam > 11 && ced.charAt(9) != '-') {  //comprobacion del guion
      Serial.println();
      Serial.println("Cedula Incorrecta");
    }
    else if (verif(ced) > 0) {
      Serial.println();
      Serial.println("La cedula contiene letras");  
    }
    else if (tam==11){  //lo que va a retornar si existe el tamaño correcto
    Serial.println();
    String R= ced.substring (0, 2);
    int dire = R.toInt();
    delay (50);
    if(dire >= 1 && dire <=24) {  //se usa para la region de Ecuador, es decir, los dos primeros numeros no pueden ser mayores a 24
      int ud = ced.substring(10).toInt();
      //operaciones para los pares
      int n1 = (ced.substring(1, 2)).toInt();  //parea transformar de cadena a entero
      int n2 = (ced.substring(3, 4)).toInt();
      int n3 = (ced.substring(5, 6)).toInt();
      int n4 = (ced.substring(7, 8)).toInt();
      int numeros = n1 + n2 + n3 + n4;

      //operaciones de impares
      int m1 = ced.substring (0, 1).toInt();
      m1 = (m1 * 2);
      if (m1 > 9) {
        m1 = (m1 - 9);
      }
      int m3 = ced.substring(2, 3).toInt();
      m3 = (m3 * 2);
      if (m3 > 9) {
        m3 = (m3 - 9);
      }
      int m5 = ced.substring(4, 5).toInt();
      m5 = (m5 * 2);
      if (m5 > 9) {
        m5 = (m5 - 9);
      }
      int m7 = ced.substring (6,7).toInt();
      m7 = (m7 * 2);
      if (m7 > 9) {
        m7 = (m7 - 9);
      }
      int m9 = ced.substring (8, 9).toInt();
      m9 = (m9 * 2);
      if (m9 > 9) {
        m9 = (m9 - 9);
      }
      int impares = m1 + m3 + m5 + m7 + m9;
      int suma = numeros + impares;
      int pdsuma = String(suma).substring(0, 1).toInt();
      int sd = (((pdsuma) + 1) * 10);  //decenas
      int validador = (sd - suma);  //validador del ultimo digito
      if (validador == 10) {
        validador = 0;
      }
      if (validador == ud) {  //condicion  va a validar el ultimo digito
        Serial.println("la cedula que ingreso es correcta");
      }
      else {
        Serial.println("la cedula que ingreso es incorrecta");
      }
    }
    else {
      Serial.println("La cedula no pertenece a una region");  //los dos numeros menores de 24
    }
  }
  else {
    Serial.println("La cedula tiene menos de 11 numeros");  //si no cumple con el tamaño de cedula
  }
  

  }}
