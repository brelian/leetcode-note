/**
 * 学习笔记:
 * 链表是其他的基础
 *   预备知识:
 *       typedef的使用
 */

#include <stdio.h>

struct Student
{
  int sid;
  char name[200];
  char sex;
};

/*
typedef struct Student
{
  int sid;
  char name[200];
  char sex;
} ST;
*/

/*typedef struct Student
{
  int sid;
  char name[200];
  char sex;
} * PST;
*/
/*
typedef struct Student
{
  int sid;
  char name[200];
  char sex;
}*PST,ST; //快速定义
*/

typedef struct Student ST;  //类型别名

int main(int argc, char const *argv[])
{
  St st; //等价于 struct Student st;
  St *pst = &st;
  return 0;
}