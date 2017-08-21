#include "stdio.h"

/**
 * 递归案例之求阶乘
 */

int Fact(int n);
int main(int argc, char const *argv[])
{
  printf("%d\n", Fact(10));
  printf("%d\n", Fact(1));
  printf("%d\n", Fact(2));
  printf("%d\n", Fact(3));
  printf("%d\n", Fact(4));
  return 0;
}

int Fact(int n){
  if (n <=1 )
  {
    return 1;
  }else{
    return n*Fact(n-1);
  }
}