/**
 * ����Ĵ����ͱ���
 * ����:
 * ����
 */
//����֪ʶ:for ѭ����++i �� i++��һ����Ч��,i������ִ����ѭ������ִ��

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define bool int
int true = 1;
int false = 0;

//�������
typedef struct Node
{
  int data;
  // PNODE pNext; //ָ����һ������ָ��
  struct Node *pNext;
} *PNODE,NODE;

//һϵ����������
PNODE create_list(void); //����
void traverse_list(PNODE pHead); //����
int length_list(PNODE pHead); //�󳤶�
bool is_empty(PNODE pHead);  //����Ƿ�Ϊ��
bool insert_list(PNODE pHead,int pos,int val);//��pHead�����е�pos���������Ԫ��
bool delete_list(PNODE pHead,int pos,int *val);//ɾ����pos�����,ɾ��������浽һ���±�����
void sort_list(PNODE pHead); //��pHead��������

int main(int argc, char const *argv[])
{
  PNODE pHead = NULL;  //����ͷ���
  //create_list()��������ͨ��
  pHead = create_list(); //����������,�纯�������ڴ�
  //is_empty()��������ͨ��
  // if(is_empty(pHead))
  //   printf("empty!\n");
  // else
  //   printf("not empty!\n");
  //traverse_list()��������ͨ��
  // traverse_list(pHead);
  //length_list()��������ͨ��
  int len = length_list(pHead);
  // printf("%d\n",len);
  //insert_list()��������ͨ��
  // insert_list(pHead,0,100);
  // insert_list(pHead,3,100);
  // insert_list(pHead,1,100);
  // traverse_list(pHead);
  //delete_list()��������
  int val = 0;
  delete_list(pHead,1,&val);
  printf("%d\n",val);
  traverse_list(pHead);
  //sort_list()��������
  sort_list(pHead);
  traverse_list(pHead);
  return 0;
}

/**
 * [create_list ����������]
 * @return  [��������ͷָ��]
 */
PNODE create_list(void)
{
  int n;
  int val;
  int i;
  //����ͷ���
  PNODE pHead = (PNODE)malloc(sizeof(NODE));
  if (NULL == pHead)
  {
    /* code */
    printf("error!\n");
    exit(-1);
  }
  //����β���
  PNODE pTail = pHead;
  pTail->pNext = NULL;
  //���봴���Ľ�����
  printf("please input the number of nodes:\n");
  scanf("%d",&n);
  //��ֵ
  //������ʱ���,������ѭ���ڲ�,
/*  PNODE pNew = (PNODE)malloc(sizeof(NODE));
  if (NULL == pNew)
  {
    printf("error!\n");
    exit(-1);
  }*/

  for (int i = 0; i < n; ++i)
  {
    //������ʱ���
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (NULL == pNew)
    {
      /* code */
      printf("error!\n");
      exit(-1);
    }

    printf("input node %d :\n",i+1);
    scanf("%d",&val);
    pNew->data = val; //��ֵ
    pTail->pNext = pNew; //��
    pNew->pNext = NULL; //��ָ����
    pTail = pNew; //����βָ��
  }
  return pHead;
}

/**
 * [traverse_list �������]
 * @param pHead [ͷָ��]
 */
void traverse_list(PNODE pHead)
{
  PNODE q = pHead->pNext;//��ʱָ��,��ʼֵ�����׽��ĵ�ַ
  while(q != NULL)
  {
    printf("%d ",q->data);
    q = q->pNext;
  }
  printf("\n");
  return;
}

/**
 * [is_empty ����Ƿ�Ϊ��]
 * @param  pHead [ͷָ��]
 * @return       [������]
 */
bool is_empty(PNODE pHead)
{
  return pHead->pNext==NULL?true:false;
}

/**
 * [length_list ��������ЧԪ�ظ���]
 * @param  pHead [description]
 * @return       [description]
 */
int length_list(PNODE pHead)
{
  int length = 0;
  PNODE q = pHead->pNext;
  while(q != NULL)
  {
    length++;
    q = q->pNext;
  }
  return length;
}


bool insert_list(PNODE pHead,int pos,int val)
{
  int i = 0;
  //��λ��,��ָ���ƶ���Ҫ����Ľ�㴦
  PNODE q = pHead;
  while (q != NULL)
  {
    if (pos == i)
    {
      //�������
      PNODE pNew = (PNODE)malloc(sizeof(NODE)); //�����½��
      pNew->data = val;
      pNew->pNext = q->pNext;
      q->pNext = pNew;
      return true;
    }

    q = q->pNext;
    i++;
  }
  return false;
}

bool delete_list(PNODE pHead,int pos,int *val)
{
    int i = 0;
  //��λ��,ɾ������q����һ�����
  PNODE q = pHead;
  while (q != NULL)
  {
    if (pos == i+1) //ɾ����pos����Ч���
    {
      //ɾ��ǰ׼������,ɾ������r���
      PNODE r = q->pNext;
      *val= r->data;
      q->pNext = r->pNext;//�˴����ص�
      free(r); //�˴����ص�,��ֹ�ڴ�й©
      return true;
    }
    i++;
    q = q->pNext;
  }
  return false;
}
void sort_list(PNODE pHead)
{
  //�����ѡ������
  int i,j,t;
  PNODE p,q;
  int len = length_list(pHead);
  for (i = 0,p = pHead->pNext; i < len-1; ++i,p = p->pNext)
  {
    for (j = i+1,q = p->pNext; j < len; ++j,q = q->pNext)
    {
      if (p->data>q->data/*a[i]>a[j]*/)
      {
        t = p->data; //t = a[i];
        p->data = q->data; //a[i] = a[j];
        q->data = t; //a[j] = t;
      }
    }
  }
  return;
}


/**
 * ֪ʶ�ܽ�:
 *     �����㷨�����ݵĴ洢��ʽ�������
 *     �����㷨�����ݵĴ洢��ʽ�޹�
 *     ����:
 *         ����ĳ�ּ����ﵽ��Ч������:��ͬ�Ĵ洢��ʽ,ִ�еĲ�����һ����
 */
