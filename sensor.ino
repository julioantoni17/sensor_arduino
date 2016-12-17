/* Programa que simula el funcionamiento de un sensor de aparcamiento,
pitando con una frecuencia mayor conforme nos aproximamos al objeto */

int speakerPin = 8;
long distancia;
long tiempo;
int j;

void setup(){
  Serial.begin(9600);
  pinMode(6, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(7, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
}

void loop(){
  digitalWrite(6,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(6, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo=pulseIn(7, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo
 				que transcurrido entre el envío del pulso ultrasónico y cuando el
 				sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el 					rebote, HIGH, hasta que deja de hacerlo, LOW, la longitud 
				del pulso entrante*/

  distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/

  /*Monitorización en centímetros por el monitor serial*/
  Serial.println("Distancia ");
  Serial.println(distancia);
  Serial.println(" cm");
  //delay(1000);
  if(distancia<=40)
  {
  if(distancia >=0 && distancia<=3)
    j = 1;
  if(distancia >3 && distancia<=8)
    j = 50;
  if(distancia >8 && distancia<=20)
    j = 300;
  if(distancia >20 && distancia<=30)
    j = 600;
  if(distancia >30 && distancia<=40)
    j = 900;
  if(distancia >40)
    j = 1200;
  tone(speakerPin,349);
    delay(j);
    noTone(speakerPin);
    delay(100);
  }
  else
  {
   noTone(speakerPin);
  }

}

