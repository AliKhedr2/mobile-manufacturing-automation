int const DETECT = 2; // pin 2 for  sensor
int const LED = 4; 
const int pinIRd = 8;
const int LED2 = 7;
int IRvalueD = 0;
const int LED3 = 13;

void setup() {
  Serial.begin(9600);
  pinMode(DETECT, INPUT);//define detect input pin
  pinMode(pinIRd,INPUT);
  pinMode(LED,OUTPUT);

  pinMode (3, OUTPUT); //trig
  pinMode (12, INPUT);
}

void loop() {
  digitalWrite(3, LOW);
  //delayMicroseconds(4);
  digitalWrite(3, HIGH);
  delayMicroseconds(10);
  digitalWrite(3, LOW);
  long t = pulseIn (12, HIGH);
  int cm = t * 0.034 / 2;
  String CM = "cm" ;
  Serial.println (cm);
  Serial.println ();

 
  if (digitalRead((cm) > 10))
  {
    digitalWrite (LED3, HIGH);
  }
  else
  {
    digitalWrite (LED3, LOW);

  }







  
  Serial.print("\t Digital Reading=");
  Serial.println(IRvalueD);
   IRvalueD = digitalRead(pinIRd);
  if (digitalRead(pinIRd) == 1)
  {
    digitalWrite(LED2, HIGH);
  }
  else 
  {
    digitalWrite(LED2, LOW);
  }

  delay (1000);



int detected = digitalRead(DETECT);// read Laser sensor
 
  if( detected == HIGH)
  {
    
    digitalWrite(LED, LOW);

  }else{
    
    digitalWrite(LED, HIGH);;
    

  }
  delay(200);
}
