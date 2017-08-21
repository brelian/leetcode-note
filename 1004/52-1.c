/**
 * 递归案例之求和: 1+2+3+...+100
 */

#include "stdio.h"

int sum(int n){
  if (n==1)
  {
    return 1;
  }else{
    return n+sum(n-1);
  }
}

int main(int argc, char const *argv[])
{
  printf("%d\n",sum(100));
  return 0;
}