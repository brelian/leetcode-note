#include "stdio.h"

// deep first search
// ÓÃ1-9: ___+___=___

int a[10],book[10],total=0,n=9; //init automatically
void DFS(int step);
int main(){
    DFS(1);
    printf("total=%d",total>>1);
    return 0;
}

void DFS(int step){
    // a is box ,book is mark
    int i;
    if(step == n+1){
        if(a[1]*100+a[2]*10+a[3]+a[4]*100+a[5]*10+a[6] == a[7]*100+a[8]*10+a[9]) {
            total++;
            printf("%d%d%d + %d%d%d = %d%d%d \n",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
        }
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

