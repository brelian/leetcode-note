// 走迷宫 A 1 1 1
//       1 1 1 1
//       1 1 B 1
//       1 1 1 1
//从A-->B的最短路径
//当前位置为(x,y),方向next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}} ==> 下一个位置的坐标: nx,ny

#include "stdio.h"
//全局变量
int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int n=4,m=4,p=3,q=3,max=0,total=0;
int maze[51][51],book[51][51];

void mazeDFS(int,int,int);
int main(){
    int i,j,startx=1,starty=1;
    book[startx][starty] = 1; //起点开始搜索
    mazeDFS(startx,starty,1);

    printf("maxStep=%d,total %d ways!",max,total);
    return 0;
}

void mazeDFS(int x, int y, int step){
    int tx,ty,k;
    //终止条件: 到目的地
    if(x==p && y==q){
        if(step>max)
            max = step;
        total++;
        return;
    }

    //当前动作
    for(k=0;k<3;k++){
        //计算下一步x,y
        tx = x+next[k][0];
        ty = y+next[k][1];

        //判断越界,从1开始,n*m的迷宫
        if(tx<1 || tx>n || ty<1 || ty>m)
            continue;
        //判断是否已经走过(迷宫加障碍)
        if(book[tx][ty] == 0){
            book[tx][ty] = 1; //标记走过
            mazeDFS(tx,ty,step+1);
            book[tx][ty] = 0;
        }
    }
    return;
}

