#include "stdio.h"
#include "malloc.h"
#include "string.h"

/**
 * 1. 定义一个保存学生基本信息的数据类型 struct student
 * 2. 定义一个动态创建学生的方法 createStudent()
 * 3. 定义一个显示学生信息的方法showStudent()
 */

//1. 定义结构体
typedef struct Student
{
  int sid;
  char name[100];
  int age;
}*PST, ST;

void showStudent(PST);
PST createStudent();
int main(int argc, char const *argv[])
{
  PST p = createStudent();
  showStudent(p);
  return 0;
}

/**
 * 创建一个新元素
 * @return 返回变量地址
 */
PST createStudent(){
  //分配内存
  PST p = (PST)malloc(sizeof(ST));
  p->sid = 1001;
  strcpy(p->name,"syncher");
  p->age = 22;
  return p;
}

void showStudent(PST p){
  printf("sid=%d,name is %s and age=%d\n",p->sid,p->name,p->age);
}