#include <stdio.h>
#include <malloc.h>
struct Student
{
  int sid;
  int age;
};

struct Student * createStudent();
void showStudent(struct Student *);
int main(int argc, char const *argv[])
{
  struct Student *p;
  p = createStudent();//创建一个学生,返回一个地址
  showStudent(p);//显示学生信息
  return 0;
}

/**
 * 创建一个新学生
 * @return 返回一个地址
 */
struct Student * createStudent()
{
  struct Student *p = (struct Student *)malloc(sizeof(struct Student));//动态分配内存,实现跨函数调用内存
  p->sid = 1001;
  p->age = 29;
  return p;
}

/**
 * @param struct Student * 一个结构体类型的指针
 */
void showStudent(struct Student * pst)
{
  printf("%d %d\n", pst->sid,pst->age);
}