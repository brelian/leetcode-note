#include <stdio.h>
#include <string.h>
typedef struct Student
{
  int sid;
  char name[200];
  char sex;
}*PST,ST; //快速定义

int main(int argc, char const *argv[])
{
  ST st; //等价于 struct Student st;
  PST pst = &st;  //PST  == struct Student *
  pst->sid = 10;
  strcpy(pst->name,"lisi");
  printf("%s %d\n",pst->name,pst->sid);
  return 0;
}