#include <stdio.h>
#include <stdlib.h>

// mark to caculate the  full arrangemant ! a[step] = 1; stand for put card i to
// step box!

int main()
{
    // _3*6528 = 3_*8256  same number
    int i;
    for(i=0;i<=9;i++){
        if((i*10+3)*6528 == (3*10+i)*8256)
            printf("%d\n",i);
    }
    return 0;
}
