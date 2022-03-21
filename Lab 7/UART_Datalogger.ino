/*
 * UART_Datalogger
 * Aleks McCormick
 * 2022/03/14
 * Spring 2022 EE 102
 * Program for lab 4 that uses a thermistor to reprot the temperature
 */

// Controls for the data logging system
#define  LOG_INTERVAL 900000 // milli seconds between entries, equal to every 15 minutes

// Time keeper
uint32_t timeStamp = 0; // The time stamp used when recording data points

/******************************************/
/***          Global Variables          ***/
/******************************************/
// Constant values deterined by Thermistor spec sheet
int B = 4100;
int R2 = 10000;
float T2 = 298.15;

int R1 = 680; // Resistance of the known resistor
float Vcc = 4.8; // Measured voltage of the 5V pin on the arduino

// Global variables for recording the data
int sensorValue=0;
float tempVol=0.0;
float tempRes=0.0;
float tempK=0.0;
float tempF=0.0;
float tempC=0.0;

char tempCString[7];

// This variable will hold the data from a read cycle
String dataString = " ";

/******************************************/
/***           Setup Program            ***/
/******************************************/
void setup(void) {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

/******************************************/
/***            Main Program            ***/
/******************************************/
void loop(void) {
  // put your main code here, to run repeatedly:
  // Delay your time interval
  delay(LOG_INTERVAL);

  sensorValue = analogRead(A0);
  tempVol = sensorValue * Vcc/1023;
  tempRes = tempVol * R1 /(Vcc - tempVol);
  tempK = 1.0/((log(tempRes / R2) /B + (1.0 / T2)));
  tempC = tempK - 273.15;
  tempF = tempC * 9/5 + 32;

  // Print the temperature in F
  Serial.println(tempF);
    
}
