#include  <stdio.h>    //头文件用"#"开头,stdio.h

int  main()     //不加;
{
  int  max(int x,int y);
  int a, b, c, d ;
  scanf("%d, %d, %d",&a,&b,&c);
  // int e = max(a,b);
  d = max(max(a,b),c);
  printf("max is %d\n",d);
  return 0;
}



int max(int x,int y)
{
  return x > y ? x : y;
}