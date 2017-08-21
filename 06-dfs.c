#include "stdio.h"

int n,m,q,p,min=999,max=0;
int a[52][52],book[52][52];

void mazeDFS(int x,int y, int step)
{
    //定义变量
    int tx,ty,k;
    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; //分别代表左下右上
    //终点
    if(x==p && y==q)
    {
        if(step<min)
            min = step;
        if(step>max)
            max = step;
        return;
    }

    //枚举四个方向
    for(k=0;k<=3;k++)
    {
        //计算next x, y
        tx = x+next[k][0];
        ty = y+next[k][1];

        //判断是否越界
        if(tx<1||ty<1||tx>n||ty>m)
            continue;

        //判断该点是否为障碍(点值为1)或者已经走过(book[i][j]==1)
        if(a[tx][ty]==0 && book[tx][ty]==0)
        {
            //标记改点已走过
            book[tx][ty] = 1;
            //继续前进,重复同样动作,递归调用
            mazeDFS(tx,ty,step+1);
            //每次尝试结束,取消改点的标记
            book[tx][ty] = 0;
        }
    }
    return;

//end mazeDFS
}



int main()
{
    int i,j,startx,starty;
    //读入n和m
    scanf("%d %d",&n,&m);
    //读入迷宫
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    //读入起点和终点
    scanf("%d %d %d %d",&startx,&starty,&p,&q);

    //从起点开始搜索
    book[startx][starty] = 1;
    mazeDFS(startx,starty,1);

    //输出最短步数
    printf("min step is: %d, max step is: %d",min,max);

    return 0;
}
