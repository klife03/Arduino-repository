
#define POWERMOTOR_R1 2
#define POWERMOTOR_R2 3
#define POWERMOTOR_R_ENA 5

#define POWERMOTOR_L1 4
#define POWERMOTOR_L2 7
#define POWERMOTOR_L_ENB 6

int line_sensor[5] = {0,0,0,0,0};
int sensor =1;
int sum = 1;

int read_line_sensor()
{
  int i;
  sum = 0;
  for(i = 0; i < 5; i++)
  {
    line_sensor[i] = analogRead(A0 + i);
   if(i==0) if(  line_sensor[i] > 550) sum = sum - 3;       
   if(i==1) if(  line_sensor[i] > 550) sum = sum - 1;
   if(i==2) if(  line_sensor[i] > 550) sum = sum ;
   if(i==3) if(  line_sensor[i] > 550) sum = sum + 1; 
   if(i==4) if(  line_sensor[i] > 550) sum = sum + 3;
    
   
    
  }
  Serial.println(" ");
  return sum;           
}


void motor_control(int speed_l,int dir_l, int speed_r, int dir_r)
{
  if(dir_l ==1) // 전진
   {
     digitalWrite(POWERMOTOR_L1, HIGH);
     digitalWrite(POWERMOTOR_L2, LOW);
     analogWrite(POWERMOTOR_L_ENB, speed_l);  
   }
   else if( dir_l == -1)//후진
   {  
     digitalWrite(POWERMOTOR_L1, LOW);
     digitalWrite(POWERMOTOR_L2, HIGH);
     analogWrite(POWERMOTOR_L_ENB, speed_l); 
   }
   else
   {
     digitalWrite(POWERMOTOR_L1, LOW);
     digitalWrite(POWERMOTOR_L2, LOW);
     analogWrite(POWERMOTOR_L_ENB, 0);
   }  
   if(dir_r ==1) // 전진
   {
     digitalWrite(POWERMOTOR_R1, HIGH);
     digitalWrite(POWERMOTOR_R2, LOW);
     analogWrite(POWERMOTOR_R_ENA, speed_r);  
   }
   else if( dir_r == -1)//후진
   {  
     digitalWrite(POWERMOTOR_R1, LOW);
     digitalWrite(POWERMOTOR_R2, HIGH);
     analogWrite(POWERMOTOR_R_ENA, speed_r); 
   }
   else
   {
     digitalWrite(POWERMOTOR_R1, LOW);
     digitalWrite(POWERMOTOR_R2, LOW);
     analogWrite(POWERMOTOR_R_ENA, 0);
   }  
}
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600); //9600 속도로 통신을 시작 한다.

  pinMode(POWERMOTOR_R1, OUTPUT);
  pinMode(POWERMOTOR_R2,OUTPUT);
  pinMode(POWERMOTOR_R_ENA, OUTPUT);
  pinMode(POWERMOTOR_L1, OUTPUT);
  pinMode(POWERMOTOR_L2, OUTPUT);
  pinMode(POWERMOTOR_L_ENB, OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
 
  line_sensor[5];
  read_line_sensor(); 

  sensor = read_line_sensor();
  if(sensor < 0){
    motor_control(-sum * 100,-1,0,0); 
  }
  else if(sensor > 0){
    motor_control(0,0,sum * 100,-1);
  }
  else{
     motor_control(100,-1,100,-1);
  }
}
