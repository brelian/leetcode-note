#include <stdio.h>

void f(int *p){ //定义了一个形参p,类型是int *
  *p = 100; //p指向的变量
}

int main(int argc, char const *argv[])
{
  int i = 9;
  f(&i); //引用地址 *p = &i;=> int *p; p = &i;
  printf("i = %d\n",i );
  return 0;
}


/*
实现功能: 通过被调函数修改形参的值
 */