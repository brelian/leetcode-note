/**
 * 确定栈的基本要素: 第一个结点的地址pTop和最后一个结点的地址pBottom,最后
 * 一个结点没有意义,这样的话便于操作
 */
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

//结点
typedef struct Node
{
  int data;
  struct Node * pNext;
}NODE,*PNODE;

//栈
typedef struct Stack
{
  PNODE pTop;
  PNODE pBottom;
}STACK,* PSTACK;

void initStack(PSTACK pS);
void pushStack(PSTACK pS,int data);
void traverseStack(PSTACK pS);

int main(int argc, char const *argv[])
{
  STACK S;
  initStack(&S); //初始化栈方法
  pushStack(&S,2); //压栈
  pushStack(&S,1);
  pushStack(&S,4);
  pushStack(&S,13);
  pushStack(&S,12);
  pushStack(&S,16);
  traverseStack(&S); //遍历输出
  return 0;
}

/**
 * 初始化栈,栈有两部分组成,数组存储区域和指针存储区域
 * 1. 先创建一个无效数据存储节点
 * 2. 初始化改结点的指针域和数据存储域
 * 3. 初始化栈的指针存储域
 * @param pS [description]
 */
void initStack(PSTACK pS){
  // 指针初始化,同时指向一个没有意义的结点
  // pS->pTop = pS->pBottom = (PNODE)malloc(sizeof(NODE));
  PNODE pNew = (PNODE)malloc(sizeof(NODE));
  if (pNew == NULL){
    printf("内存不足!\n");
    exit(-1);
  }else{
    // 初始化该结点的数据和指针域
    pS->pTop = pS->pBottom = pNew;
    pNew->pNext = NULL;
    return;
  }
}

/**
 * 实现压栈功能
 * @param pS   栈地址
 * @param data 入栈结点的数据存储值
 * 步骤: 1. 创建新节点
 *       2. 更新结点存储域和指针域,指针指向入栈前的栈顶
 *       3. 更新栈的指针
 */
void pushStack(PSTACK pS,int data){
  PNODE pNew = (PNODE)malloc(sizeof(NODE));
  if (pNew == NULL)
  {
    printf("malloc failed!\n");
    exit(-1);
  }
  pNew->data = data;
  pNew->pNext = pS->pTop;
  pS->pTop = pNew;
  return;
}

/**
 * 遍历栈,输出栈所有结点存储的数据
 * @param pS [description]
 */
void traverseStack(PSTACK pS){
  while(pS->pTop != pS->pBottom){
    //输出
    printf("%d\n",pS->pTop->data);
    //移动pTop
    pS->pTop = pS->pTop->pNext;
  }
  return;
}