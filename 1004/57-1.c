#include <stdio.h>


void hanoi(char A,char B,char C,int n);
int main()
{
    int n;
    hanoi('A','B','C',10);
    return 0;
}

void hanoi(char A,char B,char C,int n)
{
    if(n==1)
    {
      printf("Move disk %d from %c to %c\n",n,A,C);
    }
    else
    {
      hanoi(A,C,B, n-1);
      printf("Move disk %d from %c to %c\n",n,A,C);
      hanoi(B,A,C,n-1);
    }
}
