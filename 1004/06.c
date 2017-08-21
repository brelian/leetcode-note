/**
 * 显示数组内容
 * 
 */

#include <stdio.h>
void Show_Array(int *p,int len)
{
  // p[3] = -1; //p[3] == *(p+3) == a[3]
  for (int i = 0; i < 5; ++i)
  {
    printf("%d\n",p[i]);
  }
}

int main(int argc, char const *argv[])
{
  int a[5] = {1,2,3,4,5};
  Show_Array(a,5);//a=&a[0],a本身就是int *类型 传递第一个元素的地址和元素的长度
  printf("%d\n", a[3]);
  return 0;
}
