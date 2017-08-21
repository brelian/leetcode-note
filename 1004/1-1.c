#include "stdio.h"

void f(int i){
  i = 100;
}

int main(int argc, char const *argv[])
{
  void g(int * j);
  int i = 10;
  int j = 10;
  f(i);
  g(&j);
  printf("i = %d, j = %d\n", i,j); //10 还是100?  如果是10证明函数的参数传递是传值而不是引用(传地址)
  return 0;

}


/**
 * 总结: 结果是10,函数参数调用为传值而不是引用,下例演示引用传参
 */

void g(int * j){
  *j = 100;
}