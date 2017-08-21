#include <stdio.h>

int main(int argc, char const *argv[])
{
  int i = 10;
  int *p = &i; //等价于int *p; p = &i;
  // p = &i;
  printf("%d\n", p);  //指针是整形数字,用%d输出,不用%s输出
  return 0;
}