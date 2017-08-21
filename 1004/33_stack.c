/**
 * 确定栈的基本要素: 第一个结点的地址pTop和最后一个结点的地址pBottom,最后
 * 一个结点没有意义,这样的话便于操作
 */
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

#define true 1
#define false 0
typedef int bool;

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

//实现以下功能
void initStack(PSTACK pS);                       //初始化栈
void pushStack(PSTACK pS,int data);              //压栈
void traverseStack(PSTACK pS);                   //遍历栈
bool emptyStack(PSTACK pS);                      //判断栈是否为空
bool popStack(PSTACK pS);                        //出栈
bool clearStack(PSTACK pS);                      //清空栈所有有效结点

int main(int argc, char const *argv[])
{
  STACK S;
  //测试函数
  initStack(&S); //初始化栈方法
  pushStack(&S,2); //压栈
  pushStack(&S,1);
  clearStack(&S);  //清空
  pushStack(&S,4);
  pushStack(&S,13);
  pushStack(&S,12);
  popStack(&S);
  pushStack(&S,16);
  traverseStack(&S); //遍历输出
  clearStack(&S);
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

/**
 * 判断栈是否为空
 * @param  pS
 * @return   空返回true
 * 思路: 当栈的pTop和pBottom指针指向同一个结点是栈为空,所指向的结点无数据存储,
 * 仅为辅助结点
 */
bool emptyStack(PSTACK pS){
  return pS->pTop == pS->pBottom ? true : false ;
}

/**
 * 出栈
 * @param pS [description]
 * @return 成功返回true,失败返回false
 * 步骤:1. 保存出栈结点的指针域
 *      2. 销毁出栈结点
 *      3. 更新栈的指针
 */
bool popStack(PSTACK pS){
  if(!emptyStack(pS)){
    PNODE pTemp = pS->pTop->pNext;
    free(pS->pTop);
    pS->pTop = pTemp;
    return true;
  }else{
    return false;
  }
}

/**
 * 清楚栈所有有效结点
 * @param  pS
 * @return  成功清楚返回true
 * 思路1:
 *     循环调用popStack方法,指导pTop == pBottom
 * 思路2:
 *     自己写
 */
bool clearStack(PSTACK pS){
  PNODE pTemp;
  if (emptyStack(pS))
  {
    return true;
  }
  while(pS->pTop != pS->pBottom){
    // 保存指针
    pTemp = pS->pTop->pNext;
    //销毁结点
    free(pS->pTop);
    //更新栈
    pS->pTop = pTemp;
  }
  return true;
}