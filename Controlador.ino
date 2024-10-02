
float r1 = 100000;
float r2 = 10000;
const int numReadings = 10; // Número de lecturas para el filtro de media móvil
int readings[numReadings];   // Array para almacenar las lecturas
int index = 0;              // Índice actual en el array de lecturas
int total = 0;              // Suma total de las lecturas

int relay = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(relay, OUTPUT);

  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  
  Serial.begin(9600);

  // Inicializa el array de lecturas con 0
  for (int i = 0; i < numReadings; i++) {
    readings[i] = 0;
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  // Lee el valor analógico
  int sensorValue = analogRead(A0);

  // Resta el valor antiguo del array
  total = total - readings[index];

  // Almacena la nueva lectura en el array
  readings[index] = sensorValue;

  // Suma la nueva lectura al total
  total = total + readings[index];

  // Calcula el promedio de las últimas N lecturas
  float average = (float)total / numReadings;

  // Calcula el voltaje usando el filtro de media móvil
  float voltage = ((average * 5.0) / 1024.0 * (r1 + r2) / r2);

  // Imprime el valor del voltaje promediado
  Serial.print("Voltaje: ");
  Serial.print(voltage);
  Serial.println(" voltios");

  delay(1500);

  if (voltage >= 50) {
    digitalWrite(relay, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(10, HIGH);
    Serial.println("Relay Accionado");
  }
  if (voltage <= 47) {
    digitalWrite(relay, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(10, LOW);
    Serial.println("Relay NO Accionado");
  }

  if (digitalRead(relay) == HIGH) {
    // Código para el relay activado
    digitalWrite(6,HIGH);
     delay(50);
     digitalWrite(7,HIGH);
     delay(50);
     digitalWrite(8,HIGH);
     delay(50);
     digitalWrite(9,HIGH);
     delay(50);

     digitalWrite(9,LOW);
     delay(50);
     digitalWrite(8,LOW);
     delay(50);
     digitalWrite(7,LOW);
     delay(50);
     digitalWrite(6,LOW);
     delay(50);
  } else {
    // Código para el relay desactivado
    digitalWrite(11,HIGH);
     delay(50);
     digitalWrite(2,HIGH);
     delay(50);
     digitalWrite(3,HIGH);
     delay(50);
     digitalWrite(4,HIGH);
     delay(50);
  
     digitalWrite(4,LOW);
     delay(50);
     digitalWrite(3,LOW);
     delay(50);
     digitalWrite(2,LOW);
     delay(50);
     digitalWrite(11,LOW);
     delay(50);    


  }

  // Incrementa el índice y vuelve a 0 cuando llega al final del array
  index = (index + 1) % numReadings;

  delay(100); // Espera un breve período antes de la siguiente lectura
}

