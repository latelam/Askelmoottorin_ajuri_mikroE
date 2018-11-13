const int MS1 = 12;
const int MS2 = 11;
const int ENAB = 10;
const int STEP = 9;
const int SLEEP = 8;
const int RESET = 7;
const int DIR = 5;

const int MP = HIGH;//Myötäpäivään
const int VP = LOW;//Vastapäivään

int suunta = MP;
int viive = 500;

void setup() {

  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(ENAB, OUTPUT);
  pinMode(STEP, OUTPUT);
  pinMode(SLEEP, OUTPUT);
  pinMode(RESET, OUTPUT);
  pinMode(DIR, OUTPUT);

//HALF STEP VAUHTI
  digitalWrite(MS1, HIGH);
  digitalWrite(MS2, LOW);
//Lähdöt aktiiviset  
  digitalWrite(ENAB, LOW);
//Alas odottamaan ekaa käskyä  
  digitalWrite(STEP, LOW);
//Herätys  
  digitalWrite(SLEEP,HIGH);
//Laite päälle  
  digitalWrite(RESET, HIGH);
//  
  digitalWrite(DIR, suunta);
  
}

void step(){
  digitalWrite(STEP, HIGH);
  delay(10);
  digitalWrite(STEP, LOW);
  delay(500);
  
}

void loop() {
  step();

  
}
