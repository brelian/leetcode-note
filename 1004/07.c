/**
 * 指针变量
 */

#include <stdio.h>
int main(int argc, char const *argv[])
{
  double a[5] = {2.3,4,5,6,7};
  double *p;
  p = &a[0];
  printf("%p\n", p);
  p = (a+1);
  printf("%p\n", p);
  return 0;
}
/**
 * 程序运行结果表明:
 * 1. 数组中每个元素相连存储
 * 2. double类型变量存储占8个字节
 * 3. 指针变量+1指向下一个地址
 */