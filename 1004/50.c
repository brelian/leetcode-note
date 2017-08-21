#include "stdio.h"

void f();
void g();
void k();

void f(){
  printf("F\n");
  g();
}

void g(){
  k();
  printf("G\n");
}

void k(){
  printf("K\n");
}


int main(int argc, char const *argv[])
{
  f();
  return 0;
}