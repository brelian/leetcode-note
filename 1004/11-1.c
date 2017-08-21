#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"

//定义数组: 首个元素的地址,数组长度,有效元素个数

typedef struct Arr {
  int * pBase; //数组第一个元素的指针,相当于数组名字
  int len;
  int cnt; //有效元素个数
}* PA,A;

//实现以下功能
void init_arr(PA pArr,int length);         //初始化数组
// void show_arr(PA pArr);                    //显示数组
// bool is_empty(PA  pArr);                   //检测是否为空
// bool append_arr(PA  pArr,int val);         //追加元素
// bool is_full(PA pArr);                     //检测是否已满
// bool insert_arr(PA pArr,int offset,int val);//插入元素
// bool delete_arr(PA pArr,int pos,int *pVal); //删除 元素
// void inverse_arr(PA pArr);                  //反转数组
// void sort_arr(PA pArr);                     //冒泡排序与


int main(int argc, char const *argv[])
{
  A arr;
  init_arr(&arr,6);
  printf("%p\n",&arr);
  printf("%p\n",arr.pBase);
  return 0;
}

/**
 * 初始化数组
 * @param pArr   [description]
 * @param length [description]
 */
void init_arr(PA pArr, int length){
  pArr->pBase = (int *)malloc(sizeof(int)*length);  //初始化首地址
  if (pArr->pBase == NULL)
  {
    printf("memery malloc failed!\n");
    exit(-1); //引入头文件stdlib.h
  }else{
    pArr->len = length;
    pArr->cnt = 0;
  }
  return;
}

