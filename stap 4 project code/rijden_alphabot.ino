#define PWMA   6           
#define AIN2   A0          
#define AIN1   A1          
#define PWMB   5           
#define BIN1   A2          
#define BIN2   A3          
#define ECHO   2
#define TRIG   3

int Distance = 10;
int Speed = 80;

int Distance_test();
void naar_voor();
void backward();
void right();
void left();
void stop();

void setup ()
{   Serial.begin(115200);  
  Serial.println("Ontwijkende Alphabot");
  pinMode(ECHO, INPUT);    
  pinMode(TRIG, OUTPUT);   
  pinMode(PWMA,OUTPUT);                     
  pinMode(AIN2,OUTPUT);      
  pinMode(AIN1,OUTPUT);
  pinMode(PWMB,OUTPUT);       
  pinMode(AIN1,OUTPUT);     
  pinMode(AIN2,OUTPUT); 
  analogWrite(PWMA,Speed);
  analogWrite(PWMB,Speed);
  stop();  
  }

void loop()
{ Distance = Distance_test();                 //display distance 
  Serial.print("Distance = ");            //print distance
  Serial.print(Distance);       
  Serial.println("cm");  
  if(Distance < 30) {
    right();
    delay(200);
    stop();
    }
 else
{
 naar_voor();
  }
 delay(200);
  }

  int Distance_test()         
{
  digitalWrite(TRIG, LOW);   
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);   
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);    
  float Fdistance = pulseIn(ECHO, HIGH);  
  Fdistance= Fdistance/58;       
       
  return (int)Fdistance;
}  

void naar_voor()
{
  analogWrite(PWMA,Speed);
  analogWrite(PWMB,Speed);
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);
  digitalWrite(BIN1,LOW);  
  digitalWrite(BIN2,HIGH); 
}

void backward()
{
  analogWrite(PWMA,Speed);
  analogWrite(PWMB,Speed);
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);
  digitalWrite(BIN1,HIGH); 
  digitalWrite(BIN2,LOW);  
}

void right()
{
  analogWrite(PWMA,70);
  analogWrite(PWMB,70);
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);
  digitalWrite(BIN1,HIGH); 
  digitalWrite(BIN2,LOW);  
}

void left()
{
  analogWrite(PWMA,50);
  analogWrite(PWMB,50);
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,HIGH);  
}

void stop()
{
  analogWrite(PWMA,0);
  analogWrite(PWMB,0);
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,LOW);
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,LOW);  
}







  
