/**
 * 循环队列实现
 */

#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"

typedef struct Queue
{
  int * pBase; //数组的地址
  int len;     //队列的长度
  int front; //第一个元素的下标
  int rear;  //最后一个有效元素的后一个元素
}QUEUE,* PQUEUE;


//实现以下功能
void initQueue(PQUEUE pQ,int len);
bool inQueue(PQUEUE pQ,int data);
void traverseQueue(PQUEUE pQ);
bool fullQueue(PQUEUE pQ);
bool outQueue(PQUEUE pQ); //出队
bool emptyQueue(PQUEUE pQ);

int main(int argc, char const *argv[])
{
  QUEUE Q;
//测试函数
  initQueue(&Q,6);
  inQueue(&Q,11);
  inQueue(&Q,12);
  inQueue(&Q,13);
  inQueue(&Q,14);
  outQueue(&Q); //11出队
  inQueue(&Q,15);
  inQueue(&Q,16);
  inQueue(&Q,17);
  inQueue(&Q,18);
  traverseQueue(&Q);
  return 0;
}

/**
 * 初始化一个循环队列
 * @param pQ
 * @param len 队列元素个数
 * 思路:
 *   1. 动态分配数组的内存
 *   2. 初始化rear 和 front
 */
void initQueue(PQUEUE pQ,int len){
  pQ->pBase = (int *)malloc(sizeof(int)*len);
  if (pQ->pBase == NULL)
  {
    printf("内存不足!\n");
    exit(-1);
  }else{
    pQ->rear = pQ->front = 0;
    pQ->len = len;
  }
}


/**
 * 判断队列是否已满
 * @param  pQ [description]
 * @return    [description]
 * 本例采用少存储判断,当(rear+1)%len = front时,队列已满
 */
bool fullQueue(PQUEUE pQ){
  return (pQ->rear+1)%pQ->len ==pQ->front ? true : false;
}

/**
 * 入队
 * @param  pQ   [description]
 * @param  data [description]
 * @return      如果队列已满则入队失败返回false
 * 思路:
 *   1. 从对尾入队
 *   2. 更新参数
 */
bool inQueue(PQUEUE pQ,int data){
  if (!fullQueue(pQ))
  {
    pQ->pBase[pQ->rear] = data;  //数据保存
    pQ->rear = (pQ->rear+1)%pQ->len;  //更新参数
    return true;
  }
  return false;
}

/**
 * 遍历输出队列
 * @param pQ [description]
 * 思路:
 *   1. 找一个计数器,k=front,每次循环k = (k+1)%len,当k+1 = rear时终止循环
 */
void traverseQueue(PQUEUE pQ){
  int k = pQ->front;
  while(k != pQ->rear){
    printf("%d\n",pQ->pBase[k]);
    k = (k+1)%pQ->len;
  }
  return;
}

/**
 * 判断是否为空
 * @param  pQ [description]
 * @return    [description]
 */
bool emptyQueue(PQUEUE pQ){
  return pQ->rear == pQ->front ? true : false;
}

/**
 * 出队列
 * @param  pQ [description]
 * @return    [description]
 */
bool outQueue(PQUEUE pQ){
  if (!emptyQueue(pQ))
  {
    //直接更新队首参数
    pQ->front = (pQ->front+1)%pQ->len;
    return true;
  }
  return false;
}


