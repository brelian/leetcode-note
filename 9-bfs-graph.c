#include "stdio.h"
#define NAN 9999

int main()
{
    //�������
    int i,j,n,m,a,b;
    int head,tail,que[2500],e[51][51],book[51] = {0}; //�ֲ����������ʼ��
    int cur; //��ǰ����

    //��ʼ����ά����
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i==j)    e[i][j] = 0;
            else    e[i][j] = NAN;

    //����ͼ
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        e[a][b] = e[b][a] = 1;  //�б�
    }
    //���г�ʼ��
    head = 1;
    tail = 1;
    //������
    que[tail] = 1;
    tail++;
    book[1] = 1;
    //ѭ������
    while(head<tail)
    {
        cur = que[head];
        for(i=1;i<=n;i++)
        {
            //ÿ�����뵱ǰ���Ƿ��б߲���û�з��ʹ�,���������õ����
            if(e[cur][i] == 1 && book[i] == 0)
            {
                que[tail] = i;
                tail++;
                book[i] = 1;
            }
            //���tail>n��,�����н���Ѿ�����
            if(tail>n)
                break; //����forѭ��
        }
        //������һ�����
        head++;
    }

    for(i=1;i<tail;i++)
        printf("%d ",que[i]);


    return 0;
}

