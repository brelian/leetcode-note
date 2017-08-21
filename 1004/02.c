#include "stdio.h"

int main(int argc, char const *argv[])
{
  int *p;
  int i = 10;
  int j;

  p = &i; //p保存了i的地址
  *p = 20; //*p代表的是指针变量p指向的变量 即等价于i = 20;
  printf("i=%d,j=%d,*p=%d\n",i,j,*p ); //i:20 j:随机 *p 
  return 0;
}