/*
定义4个端口控制驱动板卡
蓝牙模块HC-05连接在arduino的rx和tx上
通过判断蓝牙接收到的指令的来控制小车的运动
*/

#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7
#define MaxDataLength 3
#define runTime 200

int readData;

void forward();
void back();
void turnLeft();
void turnRight();;
void _stop();


void setup()
{
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  _stop();
  Serial.begin(9600);
}


void loop()
{
  if(Serial.available())
  {  
    if(Serial.available()>MaxDataLength)
    {
      while(Serial.read() >= 0){};
    }
    readData= Serial.read();  
    switch(readData)
    {
      case'l':{ turnLeft();break;}
      case'f':{forward();break;}
      case'r':{turnRight();break;}
      case'b':{back();break;}
    }
    delay(runTime);
  }
  
  if(!Serial.available())
  {
     _stop();
  }
}
void forward()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}
void back()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}
void turnLeft()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
void turnRight()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void _stop()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
