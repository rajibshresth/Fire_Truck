/*------ Arduino Fire Fighting Robot Code----- */
 
#include <Servo.h>
Servo myservo;
#include <TimeLib.h>

#define TIME_HEADER  "T"   // Header tag for serial time sync message
#define TIME_REQUEST 7    // ASCII bell character requests a time sync message 
 
int pos = 0;    
boolean fire = false;
 
#define Left_S 9      // left sensor
#define Right_S 10      // right sensor
#define Forward_S 8 //forward sensor
#define relay 7 //relay defined
int counter=0;
 
void setup()
{
  Serial.begin(9600);
  pinMode(Left_S, INPUT);
  pinMode(Right_S, INPUT);
  pinMode(Forward_S, INPUT);
  pinMode(relay, OUTPUT);
 
  myservo.attach(11);
  myservo.write(90); 
}
 
void put_off_fire()
{
    delay (500);
 

    for (pos = 50; pos <= 130; pos += 1) { 
    myservo.write(pos); 
    delay(10);  
  }
  for (pos = 130; pos >= 50; pos -= 1) { 
    myservo.write(pos); 
    delay(10);
  }
  
  digitalWrite(relay,LOW);
  myservo.write(90);
  
  fire=false;
}

void loop()
{
   myservo.write(90); //Sweep_Servo(); 
    
   if (digitalRead(Left_S) ==0 || digitalRead(Right_S)==0 || digitalRead(Forward_S) ==0) //If Fire is straight ahead
    {
    
    digitalWrite(relay, LOW);
    fire = true;
    
    
    }
 
     else  //If Fire not detected all sensors are zero
    {

    digitalWrite(relay, HIGH);
    
    }
     
    
delay(300); //Slow down the speed of robot
 
     while (fire == true)
     {
      put_off_fire();
      counter=counter+1;
      Serial.print("No of fire detcted :");
      Serial.println(counter);
      
      Serial.println("Time : ");
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print("/");
  Serial.print(month());
  Serial.print("/");
  Serial.print(year()); 
    Serial.println(); 
     }
     
      if (Serial.available()) {
    processSyncMessage();
  }
}
void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}


void processSyncMessage() {
  unsigned long pctime;
  const unsigned long DEFAULT_TIME = 1559977726; // Jan 1 2013

  if(Serial.find(TIME_HEADER)) {
     pctime = Serial.parseInt();
     if( pctime >= DEFAULT_TIME) { // check the integer is a valid time (greater than Jan 1 2013)
       setTime(pctime); // Sync Arduino clock to the time received on the serial port
     }
  }
}
