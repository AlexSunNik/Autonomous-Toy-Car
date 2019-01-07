const int Motor1Direction1=12;
const int Motor1Direction2=11;
const int Motor1Speed=9;

const int Motor2Direction1=3;
const int Motor2Direction2=4;
const int Motor2Speed=6;

int long duration, distance;
const int front_trig=10;
const int front_echo=13;
const int right_trig=7;
const int right_echo=8;
const int left_trig=2;
const int left_echo=5;
int front_distance, right_distance, left_distance;

const int left_flex=A1;
const int right_flex=A0;
int leftF, rightF;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(Motor1Direction1, OUTPUT);
  pinMode(Motor1Direction2,OUTPUT);
  pinMode(Motor1Speed, OUTPUT);

  pinMode(Motor2Direction1, OUTPUT);
  pinMode(Motor2Direction2, OUTPUT);
  pinMode(Motor2Speed, OUTPUT);

  pinMode(front_trig, OUTPUT);
  pinMode(front_echo, INPUT);
  
  pinMode(right_trig, OUTPUT);
  pinMode(right_echo, INPUT);
  
  pinMode(left_trig, OUTPUT);
  pinMode(left_echo, INPUT);

  pinMode(left_flex, INPUT);
  pinMode(right_flex, INPUT);
}

int Ultrasensor(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  duration=pulseIn(echoPin, HIGH);
  distance=(duration/2)/29.1;
  
  return distance;
}

void forward()
{
  digitalWrite(Motor1Direction1, HIGH);
  digitalWrite(Motor1Direction2, LOW);
  analogWrite(Motor1Speed,180);

  digitalWrite(Motor2Direction1, HIGH);
  digitalWrite(Motor2Direction2, LOW);
  analogWrite(Motor2Speed,180);
}

void turn_right()
{
  digitalWrite(Motor1Direction1, HIGH);
  digitalWrite(Motor1Direction2, LOW);
  analogWrite(Motor1Speed,180);

  digitalWrite(Motor2Direction1, HIGH);
  digitalWrite(Motor2Direction2, LOW);
  analogWrite(Motor2Speed,100);
}

void turn_left()
{
  digitalWrite(Motor1Direction1, HIGH);
  digitalWrite(Motor1Direction2, LOW);
  analogWrite(Motor1Speed,100);

  digitalWrite(Motor2Direction1, HIGH);
  digitalWrite(Motor2Direction2, LOW);
  analogWrite(Motor2Speed,180);
}

void reverse()
{
  digitalWrite(Motor1Direction1, LOW);
  digitalWrite(Motor1Direction2, HIGH);
  analogWrite(Motor1Speed,180);

  digitalWrite(Motor2Direction1, LOW);
  digitalWrite(Motor2Direction2, HIGH);
  analogWrite(Motor2Speed,180);
}

void car_stop()
{
  digitalWrite(Motor1Direction1, LOW);
  digitalWrite(Motor1Direction2, LOW);
  analogWrite(Motor1Speed,0);

  digitalWrite(Motor2Direction1, LOW);
  digitalWrite(Motor2Direction2, LOW);
  analogWrite(Motor2Speed,0);
}

void spin_left()
{
  digitalWrite(Motor1Direction1, HIGH);
  digitalWrite(Motor1Direction2, LOW);
  analogWrite(Motor1Speed,0);

  digitalWrite(Motor2Direction1, HIGH);
  digitalWrite(Motor2Direction2, LOW);
  analogWrite(Motor2Speed,180);
}

void spin_right()
{
  digitalWrite(Motor1Direction1, HIGH);
  digitalWrite(Motor1Direction2, LOW);
  analogWrite(Motor1Speed,180);

  digitalWrite(Motor2Direction1, HIGH);
  digitalWrite(Motor2Direction2, LOW);
  analogWrite(Motor2Speed,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  front_distance=Ultrasensor(front_trig, front_echo);
  right_distance=Ultrasensor(right_trig, right_echo);
  left_distance=Ultrasensor(left_trig, left_echo);
  
  /*Serial.print(front_distance);
  Serial.print("cm");

  Serial.print(right_distance);
  Serial.print("cm");

  Serial.print(left_distance);
  Serial.print("cm");
  Serial.println();*/
  leftF=analogRead(A1);
  rightF=analogRead(A0);
  Serial.print(leftF);
  Serial.print("   ");
  Serial.print(rightF);
  Serial.println();
    
  if(leftF>=800&&rightF>=800)
  {
      if(front_distance<=5)
      {
        reverse();
        delay(500);
        turn_left();
        delay(500);
      }
      else
      {
        forward();
      }
      /*if(right_distance<=5)
      {
        turn_left();
        delay(1500);
      }
      if(left_distance<=5)
      {
        turn_right();
        delay(1500);
      }*/
  }
  else if(leftF>=800)
  {
    spin_left();
    delay(1000);
  }
  else if(rightF>=800)
  {
    spin_right();
    delay(1000);
  }
  else
  {
    car_stop();
  }
}
