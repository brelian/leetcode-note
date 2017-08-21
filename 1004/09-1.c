#include "stdio.h"
#include <malloc.h>

int main(int argc, char const *argv[])
{
  printf("please input the length of the array you would like to create!\n");
  int len;
  scanf("%d",&len);
  int * pA = (int *)malloc(sizeof(int)*len);

  for (int i = 0; i < len; ++i)
  {
    /* code */
    pA[i] = i*2+3;
  }

void  printArr(int * pA,int len);
  printArr(pA,len);
  return 0;
}

void printArr(int * pA,int len){
  for (int i = 0; i < len; ++i)
  {
    printf("%d\n",pA[i]);
  }
}