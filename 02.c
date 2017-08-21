#include "stdio.h"

// deep first search

int a[1000],book[1000],n=5; //init automatically
void DFS(int step);
int main(){
    DFS(1);
    return 0;
}

void DFS(int step){
    // a is box ,book is mark
    int i;
    if(step == n+1){
        for(i=1;i<=n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }

    for(i=1;i<=n;i++){
        if(book[i] == 0){
            a[step] = i;
            book[i] = 1;

            DFS(step+1);
            book[i] = 0;
        }
    }
    return; //necessary
}
