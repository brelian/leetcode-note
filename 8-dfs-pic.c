#include "stdio.h"
#define NAN  99999
int k,total,e[101][101],book[101];
void DFS(int cur);
int main()
{
    int i,j,a,b;
    //��������: ͼ,��total
    printf("please input the number of graph:");
    scanf("%d",&total);

    //��ʼ����ά����
    for(i=1;i<=total;i++)
        for(j=1;j<=total;j++)
            if(i==j) e[i][j] = 0;
            else e[i][j] = NAN;

    //����a,b���бߵĵ�
    printf("input graph:\n");
    for(i=1;i<=total;i++)
    {
        scanf("%d %d",&a,&b);
        e[a][b] = 1;
        e[b][a] = 1;
    }
    //��ʼ������
    book[1] = 1;
    DFS(1);
    printf(" k=%d, total=%d",k,total);
    return 0;
}
//ͼ�ı���: �����������
void DFS(int cur)
{
    int i;   //ѭ����������Ϊ�ֲ�����,�������Ϊȫ�ֱ������ں����ݹ����ʱ�����ط���ʱi��ֵ�Ѿ��ı�
    printf("%d ",cur);
    k++;
    if(k == total)   //kΪ������,totalΪͼ���ܽ�����
        return;

    // �жϸý����ÿ���ڵ��Ƿ�����
    for(i=1;i<=total;i++)
    {
        // �ý�����i������Ƿ�����,����������û�з��ʵ�ǰ���·������ڽڵ�
        if(e[cur][i]==1 && book[i] == 0)
        {
            book[i] = 1;
            DFS(i);
        }
    }
    return;
}
