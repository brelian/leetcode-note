#include "stdio.h"

int main(int argc, char const *argv[])
{
  int s = 1;

  for (int i = 1; i <= 5; ++i)
  {
    /* code */
    s = s*i;
  }

  printf("%d\n", s);
  return 0;
}