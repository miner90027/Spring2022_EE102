/*
 * LED4_Analog
 * Aleks McCormick
 * 2022/02/07
 * Spring 2022 EE 102
 * Original Program by D. Thorsen 2012/02/15
 * Lights LEDs in response to Analog input voltage value
 */

/******************************************/
/***          Global Variables          ***/
/******************************************/
 // Define the LEDs and what pin they are connected to
 int led0 = 2;
 int led1 = 3;
 int led2 = 4;
 int led3 = 5;

 // Define variables for the recorded value & calculated voltage
 int sensorValue;
 float sensorVoltage;
 
/******************************************/
/***          Setup Function            ***/
/******************************************/
void setup() {
  // define the pins connected to the LEDs as outputs
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

 // Initilize the serial output
  Serial.begin(9600);
  while (!Serial) { };
  Serial.println("ready\n");
}

/******************************************/
/***            Main Program            ***/
/******************************************/
void loop() {
  sensorValue = analogRead(A0); //reads count (0 to 1023) on analog input A0
  sensorVoltage = sensorValue*(5.0/1023); //converts sensorValue count value to voltage value

  Serial.print(sensorValue);     //prints count value to Serial Monitor
  Serial.print("\t Voltage ");   //prints tab then Voltage to serial Monitor
  Serial.println(sensorVoltage); //prints voltage value to Serial Monitor

  if(sensorVoltage > 1 && sensorVoltage < 2){ //Sets led 0 on if sensorVoltage between 1 && 2 volts
    digitalWrite(led0,HIGH);
  }
  if(sensorVoltage > 2 && sensorVoltage < 3){ //Sets led 1 on if sensorVoltage between 2 && 3 volts
    digitalWrite(led1, HIGH);
  }
  if(sensorVoltage > 3 && sensorVoltage < 4){ //Sets led 2 on if sensorVoltage between 3 && 4 volts
    digitalWrite(led2, HIGH);
  }
  if(sensorVoltage > 4 ){ //Sets led 3 on if sensorVoltage greater than 4 V
    digitalWrite(led3, HIGH);
  }
 
 // delay loop for 0.1 seconds
  delay(100);
 
 // Turn off the LEDs
  digitalWrite(led0,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
}
