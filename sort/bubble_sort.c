#include <stdio.h>

int main(int argc, char const *argv[])
{
  int arr[] = {12,35,99,18,76};
  //外层循环冒泡
  for (int i = 0; i < 4; ++i)
  {
    //内层循环排序
    for (int j = 0; j < 5-i;j++)
    {
      if (arr[j]<arr[j+1]) //小的往后
      {
        int tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }
  }
for (int i = 0; i < 5; ++i)
{
  printf("%d\n",arr[i]);
}

  return 0;
}