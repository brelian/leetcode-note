/**
 * 链式二叉树
 */

#include "stdio.h"
#include "stdlib.h"

//构造结点
typedef struct BTNode
{
  int data;
  struct BTNode * pLchild;   //指向左孩子
  struct BTNode * pRchild;   //指向右孩子
}BTNODE, *PBTNODE;


int main(int argc, char const *argv[])
{
  PBTNODE pT = creatBTree(); //创建二叉树,返回跟结点的地址
  return 0;
}


PBTNODE creatBTree(void){
  PBTNODE pA = (PBTNODE) 
}












