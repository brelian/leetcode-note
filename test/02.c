
#include  <stdio.h>    //头文件用"#"开头,stdio.h
int  main()     //不加;
{
  int  max(int x,int y,int z);
  int a, b, c, d ;
  scanf("%d, %d %d",&a,&b,&c);
  d = max(a,b,c);  //对实参赋值
  printf("max is %d\n",d);
  return 0;
}


int max(int x,int y,int z)
{
 //逻辑错误,参数错误使用
  /*int d;
  if(max(a,b)>c)
    d = max(a,b);
  else
    d = c;*/
  if (x >= y && x >= z)
  {
    return x;
  }

  if (y >= x && y >= z)
  {
    return y;
  }

  return z;
}


// 1. 代码规范,适当缩进
// 2. 基本语法错误,用英文标点,包括,;""()等
// 3. 逻辑错误