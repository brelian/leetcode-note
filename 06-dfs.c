#include "stdio.h"

int n,m,q,p,min=999,max=0;
int a[52][52],book[52][52];

void mazeDFS(int x,int y, int step)
{
    //�������
    int tx,ty,k;
    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; //�ֱ������������
    //�յ�
    if(x==p && y==q)
    {
        if(step<min)
            min = step;
        if(step>max)
            max = step;
        return;
    }

    //ö���ĸ�����
    for(k=0;k<=3;k++)
    {
        //����next x, y
        tx = x+next[k][0];
        ty = y+next[k][1];

        //�ж��Ƿ�Խ��
        if(tx<1||ty<1||tx>n||ty>m)
            continue;

        //�жϸõ��Ƿ�Ϊ�ϰ�(��ֵΪ1)�����Ѿ��߹�(book[i][j]==1)
        if(a[tx][ty]==0 && book[tx][ty]==0)
        {
            //��Ǹĵ����߹�
            book[tx][ty] = 1;
            //����ǰ��,�ظ�ͬ������,�ݹ����
            mazeDFS(tx,ty,step+1);
            //ÿ�γ��Խ���,ȡ���ĵ�ı��
            book[tx][ty] = 0;
        }
    }
    return;

//end mazeDFS
}



int main()
{
    int i,j,startx,starty;
    //����n��m
    scanf("%d %d",&n,&m);
    //�����Թ�
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    //���������յ�
    scanf("%d %d %d %d",&startx,&starty,&p,&q);

    //����㿪ʼ����
    book[startx][starty] = 1;
    mazeDFS(startx,starty,1);

    //�����̲���
    printf("min step is: %d, max step is: %d",min,max);

    return 0;
}
