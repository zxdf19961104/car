#include <Wire.h>
//HC SR04接腳
#define  trigPin  13
#define echoPin  12
//L9110S接腳
#define in4  7
#define in3  6
#define in2  5
#define in1  4
#define led1 8
#define led2 9
long duration, distance;
void setup() 
{ 
 
  Wire.begin(8);                
  Wire.onReceive(receiveEvent); 
  //Serial.begin(115200);        
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode (in4, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in1, OUTPUT);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
 
}

void loop()
{   
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  if(distance<30)
    {
      digitalWrite(in1, LOW); 
      digitalWrite(in2, HIGH); 
      digitalWrite(in3, HIGH); 
      digitalWrite(in4, LOW);
    }
  else
    {
      digitalWrite(in1, HIGH); 
      digitalWrite(in2, LOW); 
      digitalWrite(in3, HIGH); 
      digitalWrite(in4, LOW);
    }  
  delay(50);
}
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    //Serial.print(c);         // print the character
  }
  int x = Wire.read(); // receive byte as an integer
  switch(x)
  {
    case 2:
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      break; 
    case 3:
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      break;  
    }
  //Serial.println(x);         // print the integer
}

