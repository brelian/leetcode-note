#include <stdio.h>

int main(void)
{
  int a[] = {8,5,5,3,2};
  //1.定义9个桶并初始化为0,桶个数比最大数大1
  int bucket[9];
  for (int i = 0; i < 9; ++i)
  {
    bucket[i] = 0;
  }

  //2.将数组a中的值放入到相应的桶中并计数
  for (int i = 0; i < 5; ++i)
  {
    int t = a[i]; //中间变量易于理解
    bucket[t]++;  //计数
  }

  //3.输出,桶内无元素则不输出,有多个元素重复输出
  
  for (int i = 0; i < 9; ++i)
  {
    for (int j = 1;j <= bucket[i];j++)
      printf("%d\n",i);  //输出的是i
  }

  return 0;
}