#include "stdio.h"

void show_Array(int * a,int len)
{
  for (int i = 0; i < len; ++i)
  {
    printf("%d\n",a[i]);
  }
}
int main(int argc, char const *argv[])
{
  int a[5] = {2,3,4,5,6};
  show_Array(a,5);
  return 0;
}