#include "stdio.h"
/**
 * 通过函数修改指针变量的值
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
void f(int ** p){
 *p = (int *)0xFFFFEEEE;
}
int main(int argc, char const *argv[])
{
  int i = 10;
  int * q = &i;
  printf("%p\n", q);
  printf("%p\n", q);
  f(&q);
  return 0;
}