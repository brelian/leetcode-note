#include<stdio.h>
int maze[51][51] = {0};//�Թ�,û���ϰ�ֵΪ0,���ϰ�ֵΪ1
int book[51][51] = {0};//��ǵ��Ƿ��Ѿ��߹�,�Զ���ʼ��Ϊ0
int startx,starty,p,q;//��������յ����
int m,n;//�Թ��߽�
int mazeBFS();
int main()
{
    int i,j;
    //����n��m
    scanf("%d %d",&n,&m);
    //�����Թ�
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&maze[i][j]);
    //���������յ�
    scanf("%d %d %d %d",&startx,&starty,&p,&q);
    int step = mazeBFS();
    printf("%d",step);
    return 0;
}

int mazeBFS()
{
    struct note
    {
        int x;//���x����
        int y;//���y����
        int s;//��㵽�õ�Ĳ���
    };

    struct note que[2501];  //�������
    int head,tail;
    int tx,ty;//��һ�������
    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; //�ֱ������������
    int k,flag; //flagΪ�Ƿ񵽴��յ�ı�ʶ,1������

    //��ʼ������
    head = tail =  1; //��1��ʼ

    //������
    que[tail].x = startx;
    que[tail].y = starty;
    que[tail].s = 0;
    book[startx][starty] = 1;//�������
    tail++;
    flag = 0;

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
            if(tx==p && ty==q)
            {
                //������
                flag = 1;
                break; //����forѭ��
            }
        //end for
        }
        if(flag==1)
            break;//����whileѭ��

        //������һ��
        head++;
   //end while
    }
    printf("x=%d y=%d",que[tail-1].x,que[tail-1].y);
    return que[tail-1].s; //�������·��
//end BFS
}
