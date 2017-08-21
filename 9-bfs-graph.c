#include "stdio.h"
#define NAN 9999

int main()
{
    //定义变量
    int i,j,n,m,a,b;
    int head,tail,que[2500],e[51][51],book[51] = {0}; //局部变量不会初始化
    int cur; //当前变量

    //初始化二维矩阵
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i==j)    e[i][j] = 0;
            else    e[i][j] = NAN;

    //输入图
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        e[a][b] = e[b][a] = 1;  //有边
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
            if(tail>n)
                break; //跳出for循环
        }
        //进入下一层遍历
        head++;
    }

    for(i=1;i<tail;i++)
        printf("%d ",que[i]);


    return 0;
}

