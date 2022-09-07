
#include <Arduino.h>
int A,B,C,D;
int Z,Y,X,W;
void comp(int A,int B,int C,int D)
{
  digitalWrite(2,A);
  digitalWrite(3,B);
  digitalWrite(4,C);
  digitalWrite(5,D);
}
void setup()
{
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
}
void loop()
{

 W=digitalRead(6);
 X=digitalRead(7);
 Y=digitalRead(8);
 Z=digitalRead(9);
 A=(!Z&&W) || (!Z&&X) || (!Z&&Y&&!X) || (Z&&!Y&&!X&&!W);
 B=(!Z&&Y&&!X&&!W) || (!Y&&!X&&W) || (!Z&&!Y&&X);
 C=(!Z&&!X&&W) || (!Y&&!X&&W) || (!Z&&X&&!W);
 D=(!Z&&W) || (!Y&&!X&&W);

 comp(A,B,C,D);
}
