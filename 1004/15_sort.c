/**
 * 冒泡排序和选择排序
 */

#include <stdio.h>
#include <stdlib.h>



void choose_sort(int *pA,int len);
void show_arr(int *pA,int len);
void bubble_sort(int *pA,int len);
int main(int argc, char const *argv[])
{
  int a[5] = {3,10,5,1,4};
  int *pA = &a[0];
  show_arr(pA,5);
  choose_sort(pA,5);
  // bubble_sort(pA,5);
  show_arr(pA,5);

  return 0;
}


void show_arr(int *pA,int len)
{
  for (int i = 0; i < len; ++i)
  {
    printf("%d\n",pA[i]); //传入地址快速访问
  }
}

//选择排序
void choose_sort(int *pA,int len)
{
  int t;
  for (int i = 0; i < len-1; ++i)
  {
    for (int j = i+1; j < len; ++j)
    {
      if (pA[i]>pA[j])
      {
        t = pA[i];
        pA[i] = pA[j];
        pA[j] = t;
      }
    }
  }
}

//冒泡排序
/**
 * [bubble_sort 功能:冒泡排序]
 * 实现流程:依次找出最大值
 * @param  pA  [description]
 * @param  len [description]
 * @return     [description]
 */
void  bubble_sort(int *pA,int len)
{
  //功能-->流程-->检测
  

}
