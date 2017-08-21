#include "stdio.h"
#define inf 999999

int main(int argc, char const *argv[])
{
  //变量定义
  int e[10][10],dis[10],book[10],i,j,n,m,t1,t2,t3,u,v,min;
  //数据输入
  //读入n和m,n为顶点个数,m为边的条数
  scanf("%d %d",&n,&m);

  //初始化
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j)
      if(i==j)
        e[i][j] = 0;
      else
        e[i][j] = inf;

  //读入边
  for (i = 0; i <= n; ++i)
  {
    scanf("%d %d %d",&t1,&t2,&t3);
    e[t1][t2] = t3;
  }


  //初始化dis数组,dis[i]: 源点到i点的直接距离,不能直接到达则为无穷
  for (i = 1; i <= n; ++i)
    dis[i] = e[1][i];     //e[s][i]源点到i点的距离

  //book数组初始化,book[i] = 1说明i号顶点已经松弛过,在Q集合中
  for (i = 1; i <= n; ++i)
    book[i] = 0;
  book[1] = 1; //1为源点


  //核心算法

    //找到离源点最近的点
  for (i = 0; i < n; ++i)
  {
    min = inf;
    for(j=1;j<=n;j++)
    {
      if (book[j]==0 && dis[j]<min)
      {
        min = dis[j];
        u = j;   //点标记
      }
    }

    book[u] = 1;
    for(v=1;v<=n;v++)
    {
      if (e[u][v]!=inf && (dis[u]+e[u][v])<dis[v])
        dis[v] = dis[u]+e[u][v];
    }
  }

  //输出
  for (i = 1; i <= n; ++i)
    printf(" %d ",dis[i]);
  return 0;
}