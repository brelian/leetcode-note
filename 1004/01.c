#include "stdio.h"

int main(void)
{
  int *p;  // p是变量名,int * 表示只能保存int类型变量的地址 
  int i = 10;
  int j;
  p = &i;
  *p = 20;
  j = *p; //等价于 j = i;
  printf("%d\n", j);
  printf("%d\n", i);
  return 0;
}