/**
 * 求插入排序和快速排序的交接点 ,求 f(x) = x - 8logx 的零点
 */

#include <stdio.h>
#include "math.h"

int main(int argc, char const *argv[])
{
  double x, x0, fun, fun_Derivative;

  x = 16;
  do
  {
    x0 = x;
    fun = 100*x - pow(2,x);
    fun_Derivative = 100 - x * pow(2,(x-1));
    x = x0 - fun/fun_Derivative;
  } while (fabs(x-x0) >= 1e-5);

  printf("%d\n",x);
  return 0;
}