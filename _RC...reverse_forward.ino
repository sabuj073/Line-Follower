int Motor_A_Enable = 9;
int Motor_A_Reverse = 3;  //Motor A pin1
int Motor_A_Forward = 4;

int Motor_B_Enable = 10;
int Motor_B_Reverse = 12;  // Motor B pin
int Motor_B_Forward = 7;

int sensor1 = A0;
int sensor2 = A1;
int sensor3 = A2;
int sensor4 = A3;
int sensor5 = A4;

int BLACK = 0;
int WHITE = 1;


int motor_pinmode[] ={Motor_A_Enable,Motor_A_Reverse,Motor_A_Forward,Motor_B_Enable,Motor_B_Reverse,Motor_B_Forward};  
int sensor_pinmode[] = {sensor1,sensor2,sensor3,sensor4,sensor5};




void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  pin_Mode();
  
}

void loop() {
    
    motor_control(); 
  
}



void pin_Mode()   //pinMode setup method
{
  for(int i = 0 ; i<6 ; i++)
  {
     pinMode(motor_pinmode[i],OUTPUT);    //Motors PinMode
  }
  
  for(int i = 0 ; i<5 ; i++)
  {
     pinMode(sensor_pinmode[i],INPUT);  //Sensors pinMode
  }
}



void motor_control()  //Give instructions to motor
{
  
  if(digitalRead(sensor1)==BLACK)  //Rapid left
  {
        analogWrite(Motor_A_Enable,70);
        analogWrite(Motor_B_Enable,70);
        
        digitalWrite(Motor_A_Forward,LOW);
        digitalWrite(Motor_A_Reverse,HIGH);
        digitalWrite(Motor_B_Reverse, LOW);
        digitalWrite(Motor_B_Forward, HIGH);
  }
  
  if(digitalRead(sensor5) == BLACK)  //Rapid right
  {
        analogWrite(Motor_A_Enable,70);
        analogWrite(Motor_B_Enable,70);
        
        digitalWrite(Motor_A_Reverse, LOW);
        digitalWrite(Motor_A_Forward, HIGH);
        digitalWrite(Motor_B_Forward,LOW);
        digitalWrite(Motor_B_Reverse,HIGH);
  }
  
  
   if(digitalRead(sensor2)== WHITE && digitalRead(sensor3) == BLACK  && digitalRead(sensor4)==WHITE )   //Forward condition
  {
      forward();
  }
  
  
   if(digitalRead(sensor2)== BLACK && digitalRead(sensor3) == WHITE  && digitalRead(sensor4)==WHITE )  //Left
  {
    
     left();
  }
  
     if(digitalRead(sensor2)== WHITE && digitalRead(sensor3) == WHITE  && digitalRead(sensor4)==BLACK )  //Right
  {
    
   right();
  }
  
  if(digitalRead(sensor2)== WHITE && digitalRead(sensor3) == WHITE  && digitalRead(sensor4)== WHITE)
  {
    
    stop_motor();
   
  }

}

void forward()  //Move Motor forward
{ 
        analogWrite(Motor_A_Enable,60);
        analogWrite(Motor_B_Enable,60);
        
        digitalWrite(Motor_A_Reverse, LOW);
        digitalWrite(Motor_B_Reverse, LOW);
        digitalWrite(Motor_A_Forward, HIGH);
        digitalWrite(Motor_B_Forward, HIGH);
}
 
 
void left()    // Move motors left
{
        analogWrite(Motor_A_Enable,40);
        analogWrite(Motor_B_Enable,40);
        
        digitalWrite(Motor_A_Forward,LOW);
        digitalWrite(Motor_A_Reverse,HIGH);
        digitalWrite(Motor_B_Reverse, LOW);
        digitalWrite(Motor_B_Forward, HIGH);
}

void right()  //Move motors right
{
        analogWrite(Motor_A_Enable,40);
        analogWrite(Motor_B_Enable,40);
        digitalWrite(Motor_A_Reverse, LOW);
        digitalWrite(Motor_A_Forward, HIGH);
        digitalWrite(Motor_B_Forward,LOW);
        digitalWrite(Motor_B_Reverse,HIGH);
}

void stop_motor()
{
        analogWrite(Motor_A_Enable,0);
        analogWrite(Motor_B_Enable,0);
}
