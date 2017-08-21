/**
 * 链表的创建和遍历
 * 创建:
 * 遍历
 */
//补充知识:for 循环中++i 和 i++是一样的效果,i都是在执行完循环体后才执行

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define bool int
int true = 1;
int false = 0;

//创建结点
typedef struct Node
{
  int data;
  // PNODE pNext; //指向下一个结点的指针
  struct Node *pNext;
} *PNODE,NODE;

//一系列链表处理函数
PNODE create_list(void); //创建
void traverse_list(PNODE pHead); //遍历
int length_list(PNODE pHead); //求长度
bool is_empty(PNODE pHead);  //检测是否为空
bool insert_list(PNODE pHead,int pos,int val);//向pHead链表中的pos个结点后插入元素
bool delete_list(PNODE pHead,int pos,int *val);//删除第pos个结点,删除结果保存到一个新变量中
void sort_list(PNODE pHead); //对pHead链表排序

int main(int argc, char const *argv[])
{
  PNODE pHead = NULL;  //定义头结点
  //create_list()函数测试通过
  pHead = create_list(); //创建链表函数,跨函数调用内存
  //is_empty()函数测试通过
  // if(is_empty(pHead))
  //   printf("empty!\n");
  // else
  //   printf("not empty!\n");
  //traverse_list()函数测试通过
  // traverse_list(pHead);
  //length_list()函数测试通过
  int len = length_list(pHead);
  // printf("%d\n",len);
  //insert_list()函数测试通过
  // insert_list(pHead,0,100);
  // insert_list(pHead,3,100);
  // insert_list(pHead,1,100);
  // traverse_list(pHead);
  //delete_list()函数测试
  int val = 0;
  delete_list(pHead,1,&val);
  printf("%d\n",val);
  traverse_list(pHead);
  //sort_list()函数测试
  sort_list(pHead);
  traverse_list(pHead);
  return 0;
}

/**
 * [create_list 创建链表函数]
 * @return  [返回链表头指针]
 */
PNODE create_list(void)
{
  int n;
  int val;
  int i;
  //创建头结点
  PNODE pHead = (PNODE)malloc(sizeof(NODE));
  if (NULL == pHead)
  {
    /* code */
    printf("error!\n");
    exit(-1);
  }
  //创建尾结点
  PNODE pTail = pHead;
  pTail->pNext = NULL;
  //输入创建的结点个数
  printf("please input the number of nodes:\n");
  scanf("%d",&n);
  //赋值
  //创建临时结点,必须在循环内部,
/*  PNODE pNew = (PNODE)malloc(sizeof(NODE));
  if (NULL == pNew)
  {
    printf("error!\n");
    exit(-1);
  }*/

  for (int i = 0; i < n; ++i)
  {
    //创建临时结点
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (NULL == pNew)
    {
      /* code */
      printf("error!\n");
      exit(-1);
    }

    printf("input node %d :\n",i+1);
    scanf("%d",&val);
    pNew->data = val; //赋值
    pTail->pNext = pNew; //挂
    pNew->pNext = NULL; //清指针域
    pTail = pNew; //更新尾指针
  }
  return pHead;
}

/**
 * [traverse_list 输出链表]
 * @param pHead [头指针]
 */
void traverse_list(PNODE pHead)
{
  PNODE q = pHead->pNext;//临时指针,初始值等于首结点的地址
  while(q != NULL)
  {
    printf("%d ",q->data);
    q = q->pNext;
  }
  printf("\n");
  return;
}

/**
 * [is_empty 检测是否为空]
 * @param  pHead [头指针]
 * @return       [布尔型]
 */
bool is_empty(PNODE pHead)
{
  return pHead->pNext==NULL?true:false;
}

/**
 * [length_list 求链表有效元素个数]
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
  //找位置,将指针移动到要插入的结点处
  PNODE q = pHead;
  while (q != NULL)
  {
    if (pos == i)
    {
      //插入操作
      PNODE pNew = (PNODE)malloc(sizeof(NODE)); //创建新结点
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
  //找位置,删除的是q的下一个结点
  PNODE q = pHead;
  while (q != NULL)
  {
    if (pos == i+1) //删除第pos号有效结点
    {
      //删除前准备工作,删除的是r结点
      PNODE r = q->pNext;
      *val= r->data;
      q->pNext = r->pNext;//此处事重点
      free(r); //此处是重点,防止内存泄漏
      return true;
    }
    i++;
    q = q->pNext;
  }
  return false;
}
void sort_list(PNODE pHead)
{
  //数组的选择排序
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
 * 知识总结:
 *     狭义算法与数据的存储方式密切相关
 *     广义算法与数据的存储方式无关
 *     泛型:
 *         利用某种技术达到的效果就是:不同的存储方式,执行的操作是一样的
 */
