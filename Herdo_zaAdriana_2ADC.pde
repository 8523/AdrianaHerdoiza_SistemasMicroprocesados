
/*
    UNIVERSIDAD TÉCNICA DEL NORTE
          FICA - CIERCOM
    NOMBRE: Adriana Herdoíza
    FECHA: 03-07-2019
*/
import controlP5.*;  //Librería importada
import processing.serial.*;  //Librería para Conectar al puerto COM
Serial port;
ControlP5 cp5;
int con=0;
String dato;  //variable para guardar datos
String ADC1;  //variable para almacenar el primer valor en un string
String ADC2;  //variable para almacenar el segundo valor en un string
int CADC1;  //variable para convertir a entero
int CADC2;  //variable para convertir a entero
int guardar;  //variable para almacenar el índice con el espacio

void setup() {
  size (1200, 900);
  background(255);
  cp5=new ControlP5(this);
  
  //Para el botón de Conexión y Desconexión
  cp5.addButton("CONEXION")
    .setPosition(50,20)
    .setSize(200,100);
    
  //Para el primer contenedor del ADC
  cp5.addSlider("Conversor1")
    .setPosition(450,200)
    .setSize(50,400)
    .setColorBackground(color(20,34,39))
    .setRange(0,200)
    .setNumberOfTickMarks(255);
    
  //Para el segundo contenedor del ADC
  cp5.addSlider("Conversor2")
    .setPosition(900,200)
    .setSize(50,400)
    .setColorBackground(color(20,34,39))
    .setRange(0,200)
    .setNumberOfTickMarks(255);
}

void draw() {
  background(255);
  //para colocar nombres a los contenedores
  textSize(25);
  fill(0,255,0);
  text("Slider ADC1",400,120);
  text("Slider ADC2",850,120);
  if(con==1) {  //cuando se conecta al puerto
    if(port.available()>0) {
      dato=port.readString();
      try {
        guardar=dato.indexOf(" ");
        if(guardar <=0)
        guardar = 1;
        ADC1=dato.substring(0,guardar);
        ADC2=dato.substring(guardar+1, dato.length());
        CADC1=int(ADC1);
        CADC2=int(ADC2);
      }
      catch (StringIndexOutOfBoundsException e) {
        CADC1 = 1;
        CADC2 = 1;
      }
      if(CADC1 <=85) {
        cp5.getController("Conversor 1")
          .setValue(CADC1);
        cp5.getController("Conversor 1")
           .setColorForeground(color(230,30,30));
      }
      else if(CADC1>85 && CADC1>=170) {
        cp5.getController("Conversor 1")
          .setValue(CADC1);
        cp5.getController("Conversor 1")
          .setColorForeground(color(254,241,0));
      }
      else if(CADC1>170) {
        cp5.getController("Conversor 1")
          .setValue(CADC1);
        cp5.getController("Conversor 1")
          .setColorForeground(color(30,230,30));      
      }
      if(CADC2<=85) {
        println("rojo");
        cp5.getController("Conversor 2")
          .setValue(CADC2);
          cp5.getController("Conversor 2")
            .setColorForeground(color(230,30,30));
      }
      else if (CADC2>85 && CADC2<=170) {
        println("amarillo");
        cp5.getController("Conversor 2")
          .setValue(CADC2);
        cp5.getController("Conversor 2")
          .setColorForeground(color(254,241,0));
      }
      else if(CADC2>170) {
        println("verde");
        cp5.getController("Conversor 2")
          .setValue(CADC2);
        cp5.getController("Conversor 2")
          .setColorForeground(color(30,230,30));
      }
      }
      }
    }
    
   //Finción para conectar y desconectar 
    void Conexion() {
      con=1-con;
      if(con==1) { //para conectado
      port=new Serial(this, "COM9",9600);
      cp5.getController("CONEXION")
        .setLabel("CONECTADO");
      cp5.getController("CONEXION")
        .setColorBackground(color(30,230,30));
       println("Conectado");
      }
      else {  //para desconectado
      port.stop();
      cp5.getController("CONEXION")
        .setLabel("DESCONECTADO");
      cp5.getController("CONEXION")
        .setColorBackground(color(230,30,30));
        println("Desconectado");
      }
    }
  
