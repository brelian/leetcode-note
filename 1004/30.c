/**
 * 栈,静态内存栈分配,动态内存堆分配
 * 栈是一种可以实现先进后出的存储方式
 */

#include "stdio.h"
#include "malloc.h"
int main(int argc, char const *argv[])
{
  int i = 10;
  int * p = (int *)malloc(100);
  return 0;
}


void f(int k){
  int m;
  int *q = (int *)malloc(200);
}