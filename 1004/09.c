/**
 * 结构体的使用
 */

#include <stdio.h>
#include <string.h>

void f(struct Student *pst);
void g2(struct Student *pst);

//申明结构体
struct Student
{
  int sid;
  char name[200];
  int age;
};


int main(int argc, char const *argv[])
{
//定义结构体变量
struct Student st = {1001,"zhangsan",18};

//结构体的引用方式一
  // st.sid = 99;
  // // st.name = "lisi";//不能这样复制
  // strcpy(st.name,"lisi");
  // st.age = 19;

  //结构体引用方式二---指针
  // struct Student *pst = &st;
  // pst->sid = 99;
  // strcpy(pst->name , "lisi");
  // pst->age = 80;

  f(&st);//调用函数赋值

  // printf("%d %s %d\n",pst->sid,pst->name,pst->age);
  //调用输出函数
  // g1(st);//传递结构体 本身,耗内存
  g2(&st);//传递地址
  return 0;
}

void f(struct Student * pst)
{
  pst->sid = 0001;
  strcpy(pst->name , "lisi");
  pst->age = 80;
}

void g2(struct Student * pst)
{
  printf("%d %s %d\n",pst->sid,pst->name,(*pst).age);
}




/**
 * 注意:如果要在函数中引用结构体则必须在全局中定义结构体变量
 */