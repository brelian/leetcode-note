#include "stdio.h"
#define NAN  99999
int k,total,e[101][101],book[101];
void DFS(int cur);
int main()
{
    int i,j,a,b;
    //读入数据: 图,和total
    printf("please input the number of graph:");
    scanf("%d",&total);

    //初始化二维矩阵
    for(i=1;i<=total;i++)
        for(j=1;j<=total;j++)
            if(i==j) e[i][j] = 0;
            else e[i][j] = NAN;

    //读入a,b的有边的点
    printf("input graph:\n");
    for(i=1;i<=total;i++)
    {
        scanf("%d %d",&a,&b);
        e[a][b] = 1;
        e[b][a] = 1;
    }
    //初始化数据
    book[1] = 1;
    DFS(1);
    printf(" k=%d, total=%d",k,total);
    return 0;
}
//图的遍历: 深度优先搜索
void DFS(int cur)
{
    int i;   //循环变量定义为局部变量,如果定义为全局变量则在函数递归调用时当返回返回时i的值已经改变
    printf("%d ",cur);
    k++;
    if(k == total)   //k为计数器,total为图的总结点个数
        return;

    // 判断该结点与每个节点是否相邻
    for(i=1;i<=total;i++)
    {
        // 该结点与第i个结点是否相邻,若相邻则在没有访问的前提下访问相邻节点
        if(e[cur][i]==1 && book[i] == 0)
        {
            book[i] = 1;
            DFS(i);
        }
    }
    return;
}
