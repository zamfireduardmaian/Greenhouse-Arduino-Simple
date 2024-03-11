// Definim pinii la care sunt conectate dispozitivele
#define SOIL_MOISTURE_PIN_1 A0 // Pinul analogic pentru senzorul de umiditate sol
#define SOIL_MOISTURE_PIN_2 A1 // Pinul analogic pentru senzorul de umiditate sol
#define SOIL_MOISTURE_PIN_3 A2 // Pinul analogic pentru senzorul de umiditate sol
#define SOIL_MOISTURE_PIN_4 A3 // Pinul analogic pentru senzorul de umiditate sol

#define VALVE_PIN_1 2           // Pinul digital pentru valva electrica
#define VALVE_PIN_2 3           // Pinul digital pentru valva electrica
#define VALVE_PIN_3 4           // Pinul digital pentru valva electrica
#define VALVE_PIN_4 5           // Pinul digital pentru valva electrica

// Definim umiditatea minima la care sa se activeze valva (in procente)
const int threshold = 60;

// Definim variabile pentru a tine evidenta timpului
unsigned long previousMillis_1 = 0;
const long interval_1 = 60000; // intervalul de asteptare in milisecunde (1 minut)

unsigned long previousMillis_2 = 0;
const long interval_2 = 60000; // intervalul de asteptare in milisecunde (1 minut)

unsigned long previousMillis_3 = 0;
const long interval_3 = 60000; // intervalul de asteptare in milisecunde (1 minut)

unsigned long previousMillis_4 = 0;
const long interval_4 = 60000; // intervalul de asteptare in milisecunde (1 minut)

void setup() {
  pinMode(VALVE_PIN_1, OUTPUT); // setam pinul valvei ca output
  digitalWrite(VALVE_PIN_1, LOW); // asiguram ca valva este inchisa la pornire
  
  pinMode(VALVE_PIN_2, OUTPUT); // setam pinul valvei ca output
  digitalWrite(VALVE_PIN_2, LOW); // asiguram ca valva este inchisa la pornire
  
  pinMode(VALVE_PIN_3, OUTPUT); // setam pinul valvei ca output
  digitalWrite(VALVE_PIN_3, LOW); // asiguram ca valva este inchisa la pornire
  
  pinMode(VALVE_PIN_4, OUTPUT); // setam pinul valvei ca output
  digitalWrite(VALVE_PIN_4, LOW); // asiguram ca valva este inchisa la pornire
  
  Serial.begin(9600); // initializam comunicatia seriala
}

void loop() {
  // citim umiditatea solului senzor 1
  int soilMoisture_1 = analogRead(SOIL_MOISTURE_PIN_1);

  // verificam daca umiditatea solului este sub pragul setat si daca a trecut suficient timp de la ultima activare a valvei
  if (soilMoisture_1 < threshold && millis() - previousMillis_1 >= interval_1) {
    // pornim valva pentru 5 secunde
    digitalWrite(VALVE_PIN_1, HIGH);
    delay(5000);
    // oprim valva
    digitalWrite(VALVE_PIN_1, LOW);
    // actualizam timpul ultimei activari a valvei
    previousMillis_1 = millis();
    
    // afisam mesaj in consola seriala
    Serial.println("Valva a fost activata pentru 5 secunde.");
  }

  // afisam umiditatea solului in consola seriala
  Serial.print("Umiditate sol senzor 1: ");
  Serial.print(soilMoisture_1);
  Serial.println("%");
  
  // citim umiditatea solului senzor 2
  int soilMoisture_2 = analogRead(SOIL_MOISTURE_PIN_2);

    // verificam daca umiditatea solului este sub pragul setat si daca a trecut suficient timp de la ultima activare a valvei
  if (soilMoisture_2 < threshold && millis() - previousMillis_2 >= interval_2) {
    // pornim valva pentru 5 secunde
    digitalWrite(VALVE_PIN_2, HIGH);
    delay(5000);
    // oprim valva
    digitalWrite(VALVE_PIN_2, LOW);
    // actualizam timpul ultimei activari a valvei
    previousMillis_2 = millis();
    
    // afisam mesaj in consola seriala
    Serial.println("Valva a fost activata pentru 5 secunde.");
  }

  // afisam umiditatea solului in consola seriala
  Serial.print("Umiditate sol senzor 2: ");
  Serial.print(soilMoisture_2);
  Serial.println("%");
  
  // citim umiditatea solului senzor 3
  int soilMoisture_3 = analogRead(SOIL_MOISTURE_PIN_3);

    // verificam daca umiditatea solului este sub pragul setat si daca a trecut suficient timp de la ultima activare a valvei
  if (soilMoisture_3 < threshold && millis() - previousMillis_3 >= interval_3) {
    // pornim valva pentru 5 secunde
    digitalWrite(VALVE_PIN_3, HIGH);
    delay(5000);
    // oprim valva
    digitalWrite(VALVE_PIN_3, LOW);
    // actualizam timpul ultimei activari a valvei
    previousMillis_1 = millis();
    
    // afisam mesaj in consola seriala
    Serial.println("Valva a fost activata pentru 5 secunde.");
  }

  // afisam umiditatea solului in consola seriala
  Serial.print("Umiditate sol senzor 3: ");
  Serial.print(soilMoisture_3);
  Serial.println("%");
  
  // citim umiditatea solului senzor 4
  int soilMoisture_4 = analogRead(SOIL_MOISTURE_PIN_4);

  // verificam daca umiditatea solului este sub pragul setat si daca a trecut suficient timp de la ultima activare a valvei
  if (soilMoisture_4 < threshold && millis() - previousMillis_4 >= interval_4) {
    // pornim valva pentru 5 secunde
    digitalWrite(VALVE_PIN_4, HIGH);
    delay(5000);
    // oprim valva
    digitalWrite(VALVE_PIN_4, LOW);
    // actualizam timpul ultimei activari a valvei
    previousMillis_4 = millis();
    
    // afisam mesaj in consola seriala
    Serial.println("Valva a fost activata pentru 5 secunde.");
  }

  // afisam umiditatea solului in consola seriala
  Serial.print("Umiditate sol senzor 4: ");
  Serial.print(soilMoisture_4);
  Serial.println("%");
  
  // asteptam 50 secunde inainte de a relua verificarea
  delay(50000);
}
