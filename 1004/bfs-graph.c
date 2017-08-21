#include "stdio.h"
#define NAN 9999

int main()
{
    //定义变量
    int i,j,n,m,a,b,c;
    int head,tail,que[2500],e[51][51],book[51] = {0}; //局部变量不会初始化
    int cur,aim; //当前点和目标点
    int len = 0,min_len = NAN; //当前距离和最短距离


    //初始化二维矩阵
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i==j)    e[i][j] = 0;
            else    e[i][j] = NAN;

    //输入图
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b,&c);
        e[a][b] = e[b][a] = c;  //有边
    }
    //队列初始化
    head = 1;
    tail = 1;
    //起点入队
    que[tail] = 1;
    tail++;
    book[1] = 1;
    //循环遍历
    while(head<tail)
    {
        cur = que[head];
        if(cur==aim)
        {
            
        }
        for(i=1;i<=n;i++)
        {
            //每个点与当前点是否有边并且没有访问过,条件成立该点入队
            if(e[cur][i] == 1 && book[i] == 0)
            {
                que[tail] = i;
                tail++;
                book[i] = 1;
            }
            //如果tail>n了,则所有结点已经访问
        }
        //进入下一层遍历
        head++;
    }

    for(i=1;i<tail;i++)
        printf("%d ",que[i]);


    return 0;
}

