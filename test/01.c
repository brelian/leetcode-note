#include "stdio.h"
#include "stdlib.h"

float f(float x);
float bineryFindx(float a,float b,float s);
int a[100];
int n;
int main(int argc, char const *argv[])
{
  //输入几阶函数
  scanf("%d",&n);
  //输入函数的系数
  for (int i = 0; i <= n; ++i)
  {
    scanf("%d",&a[i]);
  }

  float s = f(3);
  //测试f函数
  printf("%f\n",s);
  float res = bineryFindx(2,4,0.001);
  printf("%f\n",res);
  return 0;
}


float bineryFindx(float a,float b,float s)
{
  float temp;
  if (f(a)*f(b)>0)
    exit(-1);
  //递归基
  if (b-a < s)
   return a;


  if (f(a)*f(b) == 0)
    return f(a) == 0 ? a : b;
  else
  {
    temp = (a+b)/2;
    if (f(temp)*f(a) <= 0)
      bineryFindx(a,temp,s);
    else
      bineryFindx(temp,b,s);
  }
}


float f(float x)
{
  float s = a[0];
  for (int i = 0; i < n; ++i)
  {
    s = s*x + a[i+1];
  }
  return s;
}

