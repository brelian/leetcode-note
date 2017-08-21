/*
指针和数组:

 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
  int a[5] = {1,2,3,4,5}; //对a的理解:a是指针常量,存放的是数组元素的第一个元素的地址a = &a[0]
                          // a[i] <<==>> *(a+i)
  a[3] == *(3+a);
  for (int i = 0; i < 5; ++i)
  {
    /* code */
    printf("%p\n",a+i);//p表示输出地址
  }
  printf("%d\n",*(a+2)+3); //*(a+2) ==a[2]==4;
  return 0;
}


