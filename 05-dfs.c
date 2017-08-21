// ���Թ� A 1 1 1
//       1 1 1 1
//       1 1 B 1
//       1 1 1 1
//��A-->B�����·��
//��ǰλ��Ϊ(x,y),����next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}} ==> ��һ��λ�õ�����: nx,ny

#include "stdio.h"
//ȫ�ֱ���
int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int n=4,m=4,p=3,q=3,max=0,total=0;
int maze[51][51],book[51][51];

void mazeDFS(int,int,int);
int main(){
    int i,j,startx=1,starty=1;
    book[startx][starty] = 1; //��㿪ʼ����
    mazeDFS(startx,starty,1);

    printf("maxStep=%d,total %d ways!",max,total);
    return 0;
}

void mazeDFS(int x, int y, int step){
    int tx,ty,k;
    //��ֹ����: ��Ŀ�ĵ�
    if(x==p && y==q){
        if(step>max)
            max = step;
        total++;
        return;
    }

    //��ǰ����
    for(k=0;k<3;k++){
        //������һ��x,y
        tx = x+next[k][0];
        ty = y+next[k][1];

        //�ж�Խ��,��1��ʼ,n*m���Թ�
        if(tx<1 || tx>n || ty<1 || ty>m)
            continue;
        //�ж��Ƿ��Ѿ��߹�(�Թ����ϰ�)
        if(book[tx][ty] == 0){
            book[tx][ty] = 1; //����߹�
            mazeDFS(tx,ty,step+1);
            book[tx][ty] = 0;
        }
    }
    return;
}

