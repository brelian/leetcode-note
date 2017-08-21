#include "stdio.h"

void quickSort(int *a,int low,int high);
int findPos(int *a,int low,int high);

int main(int argc, char const *argv[])
{
  int a[10] = {1,3,6,8,2,8,4,0,7,5};
  quickSort(&a[0],0,9);
  for (int i = 0; i < 10; ++i)
    printf(" %d ",a[i]);
  return 0;
}


void quickSort(int *a,int low,int high)
{
  int pos;
  if(low<high)
  {
    pos = findPos(a,low,high);
    quickSort(a,low,pos-1);
    quickSort(a,pos+1,high);
  }
  else
    return;
}


int findPos(int *a,int low,int high)
{
  int temp = a[low];
  while(low != high)
  {
    while(low<high && a[high]>=temp)
      high--;
    a[low] = a[high];
    while(low<high && a[low]<=temp)
      low++;
    a[high] = a[low];
  }
  a[low] = temp;   //基数归位
  return low;
}