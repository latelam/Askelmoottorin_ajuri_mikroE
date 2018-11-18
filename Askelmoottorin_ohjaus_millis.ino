const int MS1 = 12;
const int MS2 = 11;
const int ENAB = 10;
const int STEP = 9;
const int SLEEP = 8;
const int RESET = 7;
const int DIR = 5;
const int MP = HIGH; 
const int VP = LOW;  
const int NAPPI = 2;
const int PAINETTU = LOW;
const int TOIMINTA = 0;
const int SEIS = 1;


int suunta;
int viive = 980;
int vanhaTila;
int tila = SEIS;
int suodatus = 15;

unsigned long previousMillis = 0;        
const long interval = 150;

void setup() {

  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(ENAB, OUTPUT);
  pinMode(STEP, OUTPUT);
  pinMode(SLEEP, OUTPUT);
  pinMode(RESET, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(NAPPI, INPUT_PULLUP);

  digitalWrite(ENAB, LOW);
  digitalWrite(SLEEP,HIGH);
  digitalWrite(RESET, HIGH); 
  vanhaTila = digitalRead(NAPPI); 

  Serial.begin(9600);

}

void loop() {
  nappi();
  if (tila == TOIMINTA) {
  suunnanvaihto();
  } else {
    suunta=SEIS;
  }
    digitalWrite(DIR, suunta);
  }



void suunnanvaihto() {
  
  unsigned long currentMillis = millis();
  
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  digitalWrite(STEP, HIGH);
  delayMicroseconds(viive);
  digitalWrite(STEP, LOW);
  delayMicroseconds(viive);
    
   if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (suunta == VP) {
      suunta = MP;
      Serial.println("oikee");
    } else {
      suunta = VP;
      Serial.println("vasen");
    }

  digitalWrite(DIR, suunta);
    
  }
}

void nappi() {

  int uusiTila = digitalRead(NAPPI);
  
  if (uusiTila != vanhaTila) {
    if (uusiTila == PAINETTU) {
      if (tila == SEIS) {
        tila = TOIMINTA;
      } else {
        tila = SEIS;
        Serial.print("SEIS");
      }
    } 
    delay(suodatus);
  } 
  vanhaTila=uusiTila;
}
