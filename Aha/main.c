#include "stdio.h"
#include "stdlib.h"
#define true 1
#define false 0
typedef int bool;
//小猫钓鱼

// 定义队列
typedef struct queue{
    int data[200]; //存储扑克牌
    int head; //队首
    int tail; //队尾
} *PQUEUE;

// stack
struct stack{
    int data[10]; //storage the data
    int top;  //op of stack
};


//declaration
void inQueue(PQUEUE pQ, int val);
int main(){
    int i,t;
    struct queue q1, q2;
    struct stack s;

    //init
    q1.head = q1.tail = 0;
    q2.head = q2.tail = 0;
    s.top = 0;

    //book: storage the desk cards
    int book[10];  //cards value from 1 to 9
    for(i=1;i<=9;i++)
        book[i] = 0; //that means the number without cards corresponding the value;
    //q1: 2 4 1 2 5 6
    inQueue(&q1,2);
    inQueue(&q1,4);
    inQueue(&q1,1);
    inQueue(&q1,2);
    inQueue(&q1,5);
    inQueue(&q1,6);

    //q2: 3 1 3 5 6 4
    inQueue(&q2,3);
    inQueue(&q2,1);
    inQueue(&q2,3);
    inQueue(&q2,5);
    inQueue(&q2,6);
    inQueue(&q2,4);

    // until q1 or q2 is not empty
    while(q1.head<q1.tail && q2.head<q2.tail) {

        t = q1.data[q1.head];
        if(book[t] == 0){
        //no win
            q1.head++; //out queue and in stack (desk)
            s.top++;
            s.data[s.top] = t;
            book[t] = 1;
        }else{
        //win
            q1.head++;
            q1.data[q1.tail] = t; //reback just out queue card
            q1.tail++; //t in queue
            // cards in queue
            while(s.data[s.top] != t){
                book[s.data[s.top]] = 0; //reset the mark
                q1.data[q1.tail] = s.data[s.top];
                q1.tail++;
                s.top--;
            }
        }

        t = q2.data[q2.head];
        if(book[t] == 0){
        //no win
            q2.head++; //out queue and in stack (desk)
            s.top++;
            s.data[s.top] = t;
            book[t] = 1;
        }else{
        //win
            q2.head++;
            q2.data[q2.tail] = t; //reback just out queue card
            q2.tail++; //t in queue
            // cards in queue
            while(s.data[s.top] != t){
                book[s.data[s.top]] = 0; //reset the mark
                q2.data[q2.tail] = s.data[s.top];
                q2.tail++;
                s.top--;
            }
        }

    //end while
    }

    if(q1.head == q1.tail){
        printf("q2 win !\n");
        printf("q2 cards are: ");
        while(q2.tail != q2.head){
            printf("%d ",q2.data[q2.head]);
            q2.head++;
        }
        if(s.top>0){
            printf("the desk:\n");
            for(i=1;i<=s.top;i++)
                printf("  %d",s.data[i]);
        }else{
                printf("there are not cards in desk!\n");
        }
    }else{
        printf("q1 win !\n");
        printf("q1 cards are: ");
        while(q1.tail != q1.head){
            printf("%d ",q1.data[q1.head]);
            q1.head++;
        }
        if(s.top>0){
            printf("the desk:\n");
            for(i=1;i<=s.top;i++)
                printf("  %d",s.data[i]);
        }else{
                printf("there are not cards in desk!\n");
        }
    }

    getchar();getchar();

    return 0;
}

//ignore the queue is full;
void inQueue(PQUEUE pQ, int val){
    pQ->data[pQ->tail] = val;  //from tail in queue
    pQ->tail++;
    return;
}
