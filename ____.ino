
#define MOTOR_R_IN1 2
#define MOTOR_R_IN2 3
#define MOTOR_R_ENA 5
#define MOTOR_L_IN1 4
#define MOTOR_L_IN2 7
#define MOTOR_L_ENB 6
#define F_Sonar 8
#define R_Sonar 9
#define L_Sonar 11
    int speed_l=100;
    int dir_l=1;
    int speed_r=100;
    int dir_r=-1;
    float duration=0.0; //감지하는 값
    float distance=0.0; //계산된 실제 거리(mm)
    float F_sonar(void){
      pinMode(F_Sonar, OUTPUT);   //정면부 초음파 센서 핀 모드를 아웃풋으로
      digitalWrite(F_Sonar,LOW);  //정면부 초음파 센서의 출력은 없다
      digitalWrite(F_Sonar,HIGH); //정면부 초음파 센서의 출력이 있다
      delay(10);                  //이를 0.01초 동안 해라
      digitalWrite(F_Sonar,LOW);  //정면부 초음파 센서의 출력은 없다
      pinMode(F_Sonar, INPUT);    //정면부 초음파 센서의 핀 모드를 인풋으로
      duration=pulseIn(F_Sonar,HIGH);  //정면부 초음파 센서의 펄스 길이를 측정하여 duration에 넣어라
      distance=((float)(340*duration)/1000)/2;  //duration을 mm로 계산해 distance로 넣어라
      return distance;  //distance값을 함수 밖으로 내보내라
  } //정면부 초음파 센서 거리 측정 함수
      
    float R_sonar(void){
      float duration=0.0; //감지하는 값
      float distance=0.0; //계산된 실제 거리(mm)
      pinMode(R_Sonar, OUTPUT);   //오른쪽 초음파 센서 핀 모드를 아웃풋으로
      digitalWrite(R_Sonar,LOW);  //오른쪽 초음파 센서의 출력은 없다
      digitalWrite(R_Sonar,HIGH); //오른쪽 초음파 센서의 출력이 있다
      delay(10);                  //이를 0.01초 동안 해라
      digitalWrite(R_Sonar,LOW);  //오른쪽 초음파 센서의 출력은 없다
      pinMode(R_Sonar, INPUT);    //오른쪽 초음파 센서의 핀 모드를 인풋으로
      duration=pulseIn(R_Sonar,HIGH);  //오른쪽 초음파 센서의 펄스 길이를 측정하여 duration에 넣어라
      distance=((float)(340*duration)/1000)/2;  //duration을 mm로 계산해 distance로 넣어라
      return distance;  //distance값을 함수 밖으로 내보내라
      } //오른쪽 초음파 센서 거리 측정 함수
  
    float L_sonar(void){
      float duration=0.0; //감지하는 값
      float distance=0.0; //계산된 실제 거리(mm)
      pinMode(L_Sonar, OUTPUT);   //왼쪽 초음파 센서 핀 모드를 아웃풋으로
      digitalWrite(L_Sonar,LOW);  //왼쪽 초음파 센서의 출력은 없다
      digitalWrite(L_Sonar,HIGH); //왼쪽 초음파 센서의 출력이 있다
      delay(10);                  //이를 0.01초 동안 해라
      digitalWrite(L_Sonar,LOW);  //왼쪽 초음파 센서의 출력은 없다
      pinMode(L_Sonar, INPUT);    //왼쪽 초음파 센서의 핀 모드를 인풋으로
      duration=pulseIn(L_Sonar,HIGH);  //왼쪽 초음파 센서의 펄스 길이를 측정하여 duration에 넣어라
      distance=((float)(340*duration)/1000)/2;  //duration을 mm로 계산해 distance로 넣어라
      return distance;  //distance값을 함수 밖으로 내보내라
      } //왼쪽 초음파 센서 거리 측정 함수
  
  void motor_control(int speed_l,int dir_l, int speed_r, int dir_r)
    {
      if(dir_l ==1) // 전진
      {
        digitalWrite(MOTOR_L_IN1, HIGH);
        digitalWrite(MOTOR_L_IN2, LOW);
        analogWrite(MOTOR_L_ENB, speed_l);  
      }
      else if( dir_l == -1)//후진
      {  
        digitalWrite(MOTOR_L_IN1, LOW);
        digitalWrite(MOTOR_L_IN2, HIGH);
        analogWrite(MOTOR_L_ENB, speed_l); 
      }
      else
      {
        digitalWrite(MOTOR_L_IN1, LOW);
        digitalWrite(MOTOR_L_IN2, LOW);
        analogWrite(MOTOR_L_ENB, 0);
      }
      if(dir_r ==1) // 전진
      {
        digitalWrite(MOTOR_R_IN1, HIGH);
        digitalWrite(MOTOR_R_IN2, LOW);
        analogWrite(MOTOR_R_ENA, speed_l);  
      }
      else if( dir_r == -1)//후진
      {  
        digitalWrite(MOTOR_R_IN1, LOW);
        digitalWrite(MOTOR_R_IN2, HIGH);
        analogWrite(MOTOR_R_ENA, speed_l); 
      }
      else
      {
        digitalWrite(MOTOR_R_IN1, LOW);
        digitalWrite(MOTOR_R_IN2, LOW);
        analogWrite(MOTOR_R_ENA, 0);
      }    
    }

   void setup() {
    // put your setup code here, to run once:
      Serial.begin(9600); //9600 속도로 통신을 시작 한다.
      pinMode(MOTOR_R_IN1, OUTPUT);
      pinMode(MOTOR_R_IN2,OUTPUT);
      pinMode(MOTOR_R_ENA, OUTPUT);
      pinMode(MOTOR_L_IN1, OUTPUT);
      pinMode(MOTOR_L_IN2, OUTPUT);
      pinMode(MOTOR_L_ENB, OUTPUT);  
    } // 설정 함수

    void loop() {
    // put your main code here, to run repeatedly:
      motor_control(dir_l, speed_l, dir_r, speed_r);
      if(distance <= 150)
      {
        motor_control(-1,100,1,100);
      }
    }
   
