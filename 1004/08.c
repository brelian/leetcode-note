/**
 * 修改实参的值
 */

#include <stdio.h>
void f(int ** q);
int main(int argc, char const *argv[])
{
  int a = 4;
  int * p = &a;
  printf("%p\n",p);
  f(&p);
  printf("%p\n",p);
  return 0;
}


void f(int ** q) //形参为指针变量的地址
{
  *q = (int *)0xFFFFFFFF;
}