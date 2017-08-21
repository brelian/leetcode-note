#include<stdio.h>
struct note
{
    int x;//���x����
    int y;//���y����
    int s;//��㵽�õ�Ĳ���
};

int main()
{
    struct note que[2501];  //�������
    int maze[51][51] = {0};//�Թ�,û���ϰ�ֵΪ0,���ϰ�ֵΪ1
    int book[51][51] = {0};//��ǵ��Ƿ��Ѿ��߹�,�Զ���ʼ��Ϊ0
    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; //�ֱ������������

    int head,tail;

    int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;//��������յ����

    //����n��m
    scanf("%d %d",&n,&m);
    //�����Թ�
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&maze[i][j]);
    //���������յ�
    scanf("%d %d %d %d",&startx,&starty,&p,&q);

    //��ʼ������
    head = tail =  1; //��1��ʼ

    //������
    que[tail].x = startx;
    que[tail].y = starty;
    que[tail].s = 0;
    book[startx][starty] = 1;//�������
    tail++;

    flag = 0; //û�е���
    while(head<tail)
    {
        //������һ�����β���
        for(k=0;k<=3;k++)
        {
            tx = que[head].x+next[k][0];
            ty = que[head].y+next[k][1];

            //�ж��Ƿ�Խ��
            if(tx<1||ty<1||tx>n||ty>m)
                continue;
            //�ж��Ƿ��Ѿ��߹��������ϰ�
            if(book[tx][ty]==0 && maze[tx][ty] == 0)
            {
                book[tx][ty] = 1; //����Ѿ��߹�
                //���
                que[tail].x = tx;
                que[tail].y = ty;
                que[tail].s = que[head].s+1;  //�����ȸ��ڵ��1
                tail++; //��β���,���²���
            }

            //�ж��Ƿ񵽴�
            if(tx==q && ty==p)
            {
                //������
                flag = 1;
                break; //����forѭ��
            }

            if(flag==1)
                break;//����whileѭ��

            //������һ��
            head++;
        //end or
        }
    //end while
    }
    printf("x=%d y=%d, step=%d",que[tail-1].x,que[tail-1].y,que[tail-1].s);
    return 0;
}
