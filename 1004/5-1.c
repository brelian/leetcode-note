#include "stdio.h"

int main(int argc, char const *argv[])
{
  int a[5] = {1,2,3,4,5};
  *a = 100;
  printf("%d\n",a[0]);
  return 0;
}