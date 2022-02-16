/*
 * temp_sensor
 * Aleks McCormick
 * 2022/02/14
 * Spring 2022 EE 102
 * 
 */


int B = 4100;
int R2 = 10000;
float T2 = 298.15;
int R1 = 680;
float Vcc = 4.8; // measured between 5v & gnd pins

float preVal = 0;
int ledHigh = 4;
int ledLow = 2;

void setup() {
  pinMode(ledHigh, OUTPUT);
  pinMode(ledLow, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int tempVal = analogRead(A0);
  Serial.print("Temp sample: ");
  Serial.print(tempVal);

  float tempVolt = tempVal * Vcc/1023;
  Serial.print("\tTemp voltage: ");
  Serial.print(tempVolt);

  float tempRes = tempVolt * R1 /(Vcc -tempVolt);
  Serial.print("\tTemp resistance: ");
  Serial.print(tempRes);

  float tempKel = 1.0/((log(tempRes / R2) / B + (1.0 /T2)));
  Serial.print("\tTemp in Kelvin: ");
  Serial.print(tempKel);

  float tempCel = tempKel - 273.15;
  Serial.print("\tTemp in Celsius: ");
  Serial.print(tempCel);

  float tempFahr = tempCel * (9/5) + 32;
  Serial.print("\tTemp in Fahrenheit: ");
  Serial.print(tempFahr);

  if(tempVolt < preVal){
    Serial.print("\tTemp High");
    digitalWrite(ledHigh, HIGH);
  }
  else if(tempVolt > preVal){
    Serial.print("\tTemp Low");
    digitalWrite(ledLow, HIGH);
  }
  else{
    Serial.print("\tTemp Stable");
    digitalWrite(ledHigh, HIGH);
    digitalWrite(ledLow, HIGH);
  }

  preVal = tempVolt;

  Serial.print("\n");
  delay(2500);

  digitalWrite(ledHigh, LOW);
  digitalWrite(ledLow, LOW);
}
