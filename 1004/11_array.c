/**
 * 数据结构学习:
 * 线性结构:把所有的结点用一根线穿起来--连续+离散
 * 数组:
 *     1.什么叫做数组?
 *     2.数组的优缺点?
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Arr
{
  int * pBase;  //初始指针 表示第一个元素的指针,相当于数组名
  int len;      //数组长度
  int cnt;      //有效数组元素
};
//实现以下功能
void init_arr(struct Arr *pArr,int length);         //初始化数组
void show_arr(struct Arr *pArr);                    //显示数组
bool is_empty(struct Arr * pArr);                   //检测是否为空
bool append_arr(struct Arr * pArr,int val);         //追加元素
bool is_full(struct Arr *pArr);                     //检测是否已满
bool insert_arr(struct Arr *pArr,int offset,int val);//插入元素
bool delete_arr(struct Arr *pArr,int pos,int *pVal); //删除 元素
void inverse_arr(struct Arr *pArr);                  //反转数组
void sort_arr(struct Arr *pArr);                     //冒泡排序与



int main(int argc, char const *argv[])
{
  struct Arr arr;
  int *pVal;
  init_arr(&arr,10); //初始化一个长度为6的数组
  // show_arr(&arr);=   //初始化完成输出
  for (int i = 0; i < 7; i++)
  {
    if (!append_arr(&arr,10-i))
      printf("append failed!\n");
  }
  insert_arr(&arr,3,100);
  delete_arr(&arr,5,pVal);
  show_arr(&arr);   //初始化完成输出
  // printf("%d\n",*pVal);
  inverse_arr(&arr);
  show_arr(&arr);
  sort_arr(&arr);
  show_arr(&arr);
  return 0;
}

/**
 * 初始化函数
 * @param pArr   struct Arr * 初始化的结构体的地址
 * @param length int 数组的长度
 */
void init_arr(struct Arr *pArr,int length)
{
  pArr->pBase = (int *)malloc(sizeof(int)*length); //分配内存,用于存储int型
  //判断内存分配是否成功
  if (pArr->pBase == NULL)
  {
    printf("memery malloc failed!\n");
    exit(-1); //引入头文件stdlib.h
  }
  else
  {
    pArr->len = length;
    pArr->cnt = 0;
  }
  return;
}

/**
 * 打印数组元素,如果为空输出提示信息
 * @param pArr [struct Arr *] 传入地址
 */
void show_arr(struct Arr * pArr)
{
  if (is_empty(pArr))
  {
    printf("This array is empty! \n");
  }
  else
  {
    for (int i = 0; i < pArr->cnt; i++)
    {
      printf("%d\n",pArr->pBase[i]); //难理解
    }
    printf("\n");
  }
  return;
}


/**
 * [is_empty 检测数组是否为空]
 * @param  pArr [传地址]
 * @return      [返回布尔型]
 */
bool is_empty(struct Arr * pArr)
{
  if (0 == pArr->cnt)
    return true;
  else
    return false;
}

/**
 * [append_arr 追加元素]
 * @param  pArr [传入地址]
 * @param  val  [追加的值]
 * @return      [返回布尔值]
 */
bool append_arr(struct Arr * pArr,int val)
{
  //判断是否已满
  if (is_full(pArr))
  {
    return false;
  }
  else
  {
    pArr->pBase[pArr->cnt] = val;
    pArr->cnt++;
    return true;
  }
}

/**
 * [is_full 判断是否已满]
 * @param  pArr [传地址]
 * @return      [返回真假]
 */
bool is_full(struct Arr *pArr)
{
  if (pArr->cnt == pArr->len)
    return true;
  else
    return false;
}

/**
 * [insert_arr 在第offset单元插入一个元素]
 * @param  pArr   [传入地址]
 * @param  offset [偏移量]
 * @param  val    [插入值]
 * @return        [返回布尔值]
 */
bool insert_arr(struct Arr *pArr,int offset,int val)
{
  if (is_full(pArr))
  {
    return false;
  }
  else
  {
    for (int i = pArr->cnt; i > offset-1; i--)
    {
      pArr->pBase[i] = pArr->pBase[i-1];
    }
    pArr->pBase[offset] = val;
    pArr->cnt++;
    return true;
  }
}

/**
 * [delete_arr 删除数组元素]
 * @param  pArr [传地址]
 * @param  pos  [删除元素的位置,从1开始计数]
 * @param  pVal [删除元素的保存位置]
 * @return      [返回布尔值]
 */
bool delete_arr(struct Arr *pArr,int pos,int *pVal)
{
  if (is_empty(pArr) || pos<1 || pos>pArr->cnt)
  {
    return false;
  }
  else
  {
    *pVal = pArr->pBase[pos-1];//保存好要删除元素的值
    for (int i = pos-1; i < pArr->cnt; i++)
    {
      pArr->pBase[i] = pArr->pBase[i+1];
    }
    pArr->cnt--;
  }
}


void inverse_arr(struct Arr *pArr)
{
  if (!is_empty(pArr))
  {
    int i = 0;
    int j = pArr->cnt-1;
    int t = 0; //中间变量
    for (i; i < j; i++,j--)
    {
      t = pArr->pBase[i];
      pArr->pBase[i] = pArr->pBase[j];
      pArr->pBase[j] = t;
    }
  }
  return;
}

/**
 * [sort_arr 冒泡排序]
 * @param pArr [传地址]
 */
void sort_arr(struct Arr *pArr)
{
  for (int j = pArr->cnt; j >1; j--)
  {
    // 先找出最大值,相连的元素比较,大的往后
    for (int i = 0; i < j; i++)
    {
      if (pArr->pBase[i] > pArr->pBase[i+1])
      {
        //  交换元素
        int t;
        t = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[i+1];
        pArr->pBase[i+1] = t;
      }
    }
      // 重复步骤找出cnt - 1
  }
}
