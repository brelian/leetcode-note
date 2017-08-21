/**
 * 指针与数组
 */

#include "stdio.h"

int main(int argc, char const *argv[])
{
  int a[5] = {1,2,3,4,5};
  printf("%d\n", a);
  printf("%d\n", a+1);
  int * p ;
  p = &a[3];
  printf("%d\n", *p);
  return 0;
}