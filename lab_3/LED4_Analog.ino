/*
 * LED4_Analog
 * Lights LEDs in response to Analog input voltage value
 * D. Thorsen
 * 2/15/2015
 */
 int led0 = 2;
 int led1 = 3;
 int led2 = 4;
 int led3 = 5;

 int sensorValue;
 float sensorVoltage;
 
void setup() {
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  Serial.begin(9600);
  while (!Serial) { };
  Serial.println("ready\n");
}

void loop() {
  sensorValue = analogRead(A0); //reads count (0 to 1023) on analog input A0
  sensorVoltage = sensorValue*(5.0/1023); //converts sensorValue count value to voltage value

  Serial.print(sensorValue);     //prints count value to Serial Monitor
  Serial.print("\t Voltage ");   //prints tab then Voltage to serial Monitor
  Serial.println(sensorVoltage); //prints voltage value to Serial Monitor

  if(sensorVoltage > 1 && sensorVoltage < 2){         //Sets led 0 on if sensorVoltage greater than 1 V.
    digitalWrite(led0,HIGH);
  }
  if(sensorVoltage > 2 && sensorVoltage < 3){         //Sets led 1 on if sensorVoltage greater than 2 V.
    digitalWrite(led1, HIGH);
  }
  if(sensorVoltage > 3 && sensorVoltage < 4){         //Sets led 2 on if sensorVoltage greater than 3 V.
    digitalWrite(led2, HIGH);
  }
  if(sensorVoltage > 4 && sensorVoltage <= 5){         //Sets led 3 on if sensorVoltage greater than 4 V.
    digitalWrite(led3, HIGH);
  }
  delay(100);
  digitalWrite(led0,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
}
