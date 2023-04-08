/***********************************************************
Project 18: Smart Fan
Description: When an object comes in front of it, it detects and fan starts rotating
Company: Texoham eLearning Platform
Website: www.texoham.com/elearning
***********************************************************/
 int count = 0;
int sensor_pin =5;            //arduino 11th pin connected to echo Pin of the ultrasonic sensor
const int ledPin =12;
//const int Input1 = 3;                 //arduino 3rd pin connected to L293D pin input1
//const int Input2 = 4;                 //arduino 4th pin connected to L293D pin input2
const int Input3 = 8;                 //arduino 8th pin connected to L293D pin input3
const int Input4 = 9;  
const int EN2 = 2 ;//arduino 9th pin connected to L293D pin input4
int val;
void setup() 
{
  pinMode(ledPin,OUTPUT);
  pinMode(sensor_pin, INPUT);
  pinMode (Input4, OUTPUT);
  pinMode (Input3, OUTPUT);
  pinMode (EN2,OUTPUT);
  //pinMode (Input2, OUTPUT);
  //pinMode (Input1, OUTPUT);
  Serial.begin(9600);
}
long duration, distance;
void stop()
{
  digitalWrite(Input4, LOW); 
  digitalWrite(Input3, LOW); 
  digitalWrite(EN2, HIGH);
  //digitalWrite(Input2, LOW); 
  //digitalWrite(Input1, LOW);
}

void start()
{
  digitalWrite(Input4, LOW); 
  digitalWrite(Input3, HIGH); 
  digitalWrite(EN2, HIGH);
  //digitalWrite(Input2, HIGH); 
  //digitalWrite(Input1, LOW);
}


void loop()
{
  val = digitalRead(sensor_pin);
//  distance = duration/58.2;   // The speed of sound is 340 m/s or 29 microseconds per centimeter.// The echo travels out and back, so to find the distance of the
  Serial.println(count);                                        // object we take half of the distance travelled.
  Serial.println(" count ");
                                          
  if(val==0)
  {
    if(count % 2 == 0)
    {
    digitalWrite(Input4,HIGH);
    digitalWrite(Input3,LOW); 
    digitalWrite(ledPin,LOW);     
    start();
    count++;
    delay(2000);
    }
   else if(count % 2 == 1)
  {
  digitalWrite(Input4,LOW);
    digitalWrite(Input3,HIGH); 
    count++;
    delay(2000);
  }
  else 
   digitalWrite(ledPin,HIGH);
    stop(); 
  }
}
  

  
