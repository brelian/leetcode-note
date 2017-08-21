#include <stdio.h>
#include <malloc.h>

int main(int argc, char const *argv[])
{
  int len;
  printf("please input length: len = ");
  scanf("%d",&len);
  int *pArr = (int *)malloc(sizeof(int)*len);// malloc函数的使用
  for (int i = 0; i < len; ++i)
  {
    pArr[i] = i*3;
    printf("%d\n",*(pArr+i));
  }
  free(pArr);//释放内存函数
  return 0;
}