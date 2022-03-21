/*
 * Author: Thimira Thilakarathna
 * For : EE102
 */
 
import processing.serial.*;

Serial myPort;  // Create object from Serial class
String val;      // Data received from the serial port
PrintWriter output;

void setup() 
{
  size(400, 100);
  textSize(32);
  output = createWriter("logfile.csv");
  output.println("Date[yyyy/mm/dd] time,temp C");
  myPort = new Serial(this, "COM3", 9600);
}

void draw()
{
  text("Do not close this",20,30);
}

void serialEvent(Serial myPort){
   val = myPort.readStringUntil('\n'); 
   if(val!=null){ // We have a reading;
      val = trim(val); // get rid of whitespace
      output.println(year()+"/"+month()+"/"+day()+" "+hour()+":"+minute()+":"+second()+","+val);
      output.flush();
      println(year()+"/"+month()+"/"+day()+" "+hour()+":"+minute()+":"+second()+","+val);     
   }
}
