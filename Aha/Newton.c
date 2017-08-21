/**
 * 求插入排序和快速排序的交接点 ,求 f(x) = x - 8logx 的零点
 */

#include <stdio.h>
#include "math.h"

int main(int argc, char const *argv[])
{
  double x, x0, fun, fun_Derivative;

  x = 40;
  do
  {
    x0 = x;
    fun = x - 8*log(x)/log(2);
    fun_Derivative = 1 - 8/(x * log(2));
    x = x0 - fun/fun_Derivative;
  } while (fabs(x-x0) >= 1e-5);

  printf("%lf\n",x);
  return 0;
}