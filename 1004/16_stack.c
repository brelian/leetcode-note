#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node
{
  int data;
  struct Node * pNext;
}*PNODE,NODE;

typedef struct Stack
{
  PNODE pTop;
  PNODE pBottom;
}*PSTACK,STACK;

//一系列操作函数
void init_stack(PSTACK pS);
void push_stack(PSTACK pS,int val);
void traverse_stack(PSTACK pS);

int main(int argc, char const *argv[])
{
  STACK S;
  init_stack(&S);
  push_stack(&S,1);
  push_stack(&S,2);
  push_stack(&S,3);
  push_stack(&S,4);
  traverse_stack(&S);
  return 0;
}

/**
 * [init_stack 初始化栈,将pTop和pBottom指向一个无用的值]
 * @param pS [栈的地址]
 */
void init_stack(PSTACK pS)
{
  PNODE pNew = (PNODE)malloc(sizeof(NODE));
  if (pNew == NULL)
  {
    printf("malloc failed!\n");
    exit(-1);
  }
  pS->pTop = pS->pBottom = pNew;
  pNew->pNext = NULL; //此结点为栈最底部的结点,为无效结点
  return;
}

/**
 * [push_stack 压栈操作函数]
 * @param pS  [栈的地址]
 * @param val [传入的值]
 */
void push_stack(PSTACK pS,int val)
{
  PNODE pNew = (PNODE)malloc(sizeof(NODE));
  if (pNew == NULL)
  {
    printf("malloc failed!\n");
    exit(-1);
  }
  pNew->data = val;
  pNew->pNext = pS->pTop;
  pS->pTop = pNew;
  return;
}



void traverse_stack(PSTACK pS)
{
  PNODE pTmp = pS->pTop;
  while (pS->pBottom != pTmp)
  {
    printf("%d\n",pTmp->data);
    pTmp = pTmp->pNext;
  }
  return;
}




