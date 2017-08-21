#include<stdio.h>
int maze[51][51] = {0};//迷宫,没有障碍值为0,有障碍值为1
int book[51][51] = {0};//标记点是否已经走过,自动初始化为0
int startx,starty,p,q;//定义起点终点变量
int m,n;//迷宫边界
int mazeBFS();
int main()
{
    int i,j;
    //读入n和m
    scanf("%d %d",&n,&m);
    //读入迷宫
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&maze[i][j]);
    //读入起点和终点
    scanf("%d %d %d %d",&startx,&starty,&p,&q);
    int step = mazeBFS();
    printf("%d",step);
    return 0;
}

int mazeBFS()
{
    struct note
    {
        int x;//点的x坐标
        int y;//点的y坐标
        int s;//起点到该点的步数
    };

    struct note que[2501];  //定义队列
    int head,tail;
    int tx,ty;//下一个坐标点
    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; //分别代表左下右上
    int k,flag; //flag为是否到达终点的标识,1代表到达

    //初始化队列
    head = tail =  1; //从1开始

    //起点入队
    que[tail].x = startx;
    que[tail].y = starty;
    que[tail].s = 0;
    book[startx][starty] = 1;//起点已走
    tail++;
    flag = 0;

    while(head<tail)
    {
        //搜索下一个点队尾入队
        for(k=0;k<=3;k++)
        {
            tx = que[head].x+next[k][0];
            ty = que[head].y+next[k][1];

            //判断是否越界
            if(tx<1||ty<1||tx>n||ty>m)
                continue;
            //判断是否已经走过或者有障碍
            if(book[tx][ty]==0 && maze[tx][ty] == 0)
            {
                book[tx][ty] = 1; //标记已经走过
                //入队
                que[tail].x = tx;
                que[tail].y = ty;
                que[tail].s = que[head].s+1;  //步数比父节点多1
                tail++; //队尾入队,更新参数
            }

            //判断是否到达
            if(tx==p && ty==q)
            {
                //立旗帜
                flag = 1;
                break; //跳出for循环
            }
        //end for
        }
        if(flag==1)
            break;//跳出while循环

        //进入下一层
        head++;
   //end while
    }
    printf("x=%d y=%d",que[tail-1].x,que[tail-1].y);
    return que[tail-1].s; //返回最短路径
//end BFS
}
