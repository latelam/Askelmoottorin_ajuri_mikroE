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
//  digitalWrite(MS1, HIGH);
//  digitalWrite(MS2, LOW);
//Lähdöt aktiiviset  
  digitalWrite(ENAB, LOW);
//Alas odottamaan ekaa käskyä  
  digitalWrite(STEP, LOW);
//Herätys  
  digitalWrite(SLEEP,HIGH);
//Laite päälle  
  digitalWrite(RESET, HIGH);  
  digitalWrite(DIR, suunta);

  Serial.begin(9600);
}

int tUp=1000;
int tDn=1000;

void fullStep(){

  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  digitalWrite(STEP, HIGH);
  delayMicroseconds(tUp);
  digitalWrite(STEP, LOW);
  delayMicroseconds(tDn);
  
}

void halfStep(){

  digitalWrite(MS1, HIGH);
  digitalWrite(MS2, LOW);
  digitalWrite(STEP, HIGH);
  delayMicroseconds(tUp);
  digitalWrite(STEP, LOW);
  delayMicroseconds(tDn);
  
}

void quarterStep(){

  digitalWrite(MS1, LOW);
  digitalWrite(MS2, HIGH);
  digitalWrite(STEP, HIGH);
  delayMicroseconds(tUp);
  digitalWrite(STEP, LOW);
  delayMicroseconds(tDn);
  
}

void eightMicroStep(){

  digitalWrite(MS1, HIGH);
  digitalWrite(MS2, HIGH);
  digitalWrite(STEP, HIGH);
  delayMicroseconds(tUp);
  digitalWrite(STEP, LOW);
  delayMicroseconds(tDn);
  
}



void loop() {
  if(Serial.available()){
    int x=Serial.read();
    switch(x){
      case 'q':tUp+=10;break;
      case 'a':tUp-=10;break;
      case 'w':tDn+=10;break;
      case 's':tDn-=10;break;
      case 'l':Serial.print(tUp);Serial.print(" ");Serial.println(tDn);break;
    }
  }
  quarterStep();
 
  
  

  
}

