const int MS1 = 12;
const int MS2 = 11;
const int ENAB = 10;
const int STEP = 9;
const int SLEEP = 8;
const int RESET = 7;
const int DIR = 5;
const int MP = HIGH; //Myötäp.
const int VP = LOW;  //Vastap.

int suunta;
int viive = 980;

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

  digitalWrite(ENAB, LOW);
  digitalWrite(SLEEP,HIGH);
  digitalWrite(RESET, HIGH);  

  Serial.begin(9600);

}

void loop() {
  suunnanvaihto();

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

