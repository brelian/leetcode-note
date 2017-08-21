#include "stdio.h"

void hanoi(int n, char x, char y, char z); //申明

int main(int argc, char const *argv[])
{

  hanoi(10,'A','B','C');   // 64个盘子由A借助B移动到C
  return 0;
}

void hanoi(int n, char A, char B, char C){
  if (n == 1)
  {
    printf("Move %d disk from %c to %c.\n",n,A,C);
  } else{
    hanoi(n-1,A,B,C); //将n-1个盘子由A---B---->C
    printf("Move %d disk form %c to %c. \n",n,A,C);//A上的编号为n的盘子直接移动到C
    hanoi(n-1,B,A,C);//将n-1个盘子由B---A---->C
    return ;
  }
}