/*
 * temp_sensor
 * Aleks McCormick
 * 2022/02/14
 * Spring 2022 EE 102
 * Program for lab 4 that uses a thermistor to reprot the temperature
 */

/******************************************/
/***          Globa Variables           ***/
/******************************************/
// Constant values deterined by Thermistor spec sheet
int B = 4100;
int R2 = 10000;
float T2 = 298.15; 

int R1 = 680; // Resistance of the resistor
float Vcc = 4.8; // measured between 5v & gnd pins

float preVal = 0; // define the previous value recorded

// define the pins connected to which LED
int ledHigh = 4;
int ledLow = 2;


/******************************************/
/***           Setup Program            ***/
/******************************************/
void setup() {
  // Define the pins used by the LED as an output
  pinMode(ledHigh, OUTPUT);
  pinMode(ledLow, OUTPUT);
  
  // Initialize serial output
  Serial.begin(9600);
}


/******************************************/
/***            Main Program            ***/
/******************************************/
void loop() {
  
  // Record the raw value reported from the port the thermistor is connected to 
  int tempVal = analogRead(A0);
  // Print the value to the serial output
  Serial.print("Temp sample: ");
  Serial.print(tempVal);

  // Calculate the voltage accross the thermistor
  float tempVolt = tempVal * Vcc/1023;
  // Print the value to the serial output
  Serial.print("\tTemp voltage: ");
  Serial.print(tempVolt);

  // Calculate the resistance of the thermistor
  float tempRes = tempVolt * R1 /(Vcc -tempVolt);
  // Print the value to the serial output
  Serial.print("\tTemp resistance: ");
  Serial.print(tempRes);

  // Calculate the temperature in Kelvin
  float tempKel = 1.0/((log(tempRes / R2) / B + (1.0 /T2)));
  // Print the value to the serial output
  Serial.print("\tTemp in Kelvin: ");
  Serial.print(tempKel);

  // Calculate the temperature in Celsius
  float tempCel = tempKel - 273.15;
  // Print the value to the serial output
  Serial.print("\tTemp in Celsius: ");
  Serial.print(tempCel);

  // Calculate the temperature in Fahrenheit
  float tempFahr = tempCel * (9/5) + 32;
  // Print the value to the serial output
  Serial.print("\tTemp in Fahrenheit: ");
  Serial.print(tempFahr);

  // Compare the current recorded voltage with the previous voltage
  if(tempVolt < preVal){ // If the current voltage is less; then the Temp is higher
    // Print to serial that the temp is higher
    Serial.print("\tTemp High");
    // Turn on the LED marking a high temp
    digitalWrite(ledHigh, HIGH);
  }
  else if(tempVolt > preVal){// If the current voltage is higher; then the temp is lower
    // Print to serial that the temp is low
    Serial.print("\tTemp Low");
    // Turn on the LED marking a low temp
    digitalWrite(ledLow, HIGH);
  }
  else{ // If the Voltage is equal; then the temp is stable
    // Print to serial that the temp is stable
    Serial.print("\tTemp Stable");
    // Turn on both LEDs to mark a stable temperature
    digitalWrite(ledHigh, HIGH);
    digitalWrite(ledLow, HIGH);
  }
  
  // update the previous value recorded
  preVal = tempVolt;
  // Start new line in serial output
  Serial.print("\n");
  
  // 2.5 second delay between loop cycles
  delay(2500);

  // turn off the LEDs
  digitalWrite(ledHigh, LOW);
  digitalWrite(ledLow, LOW);
}
