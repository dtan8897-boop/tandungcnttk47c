#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#define MAX_CUSTOMERS 5
typedef struct{
    char customerName[50];
    int transactionType;
    double amount;
}Transaction;
typedef struct{
    Transaction data[MAX_CUSTOMERS];
    int front;
    int rear;
    int count;
}CircularQueue;
CircularQueue* createQueue(){
    CircularQueue* q=(CircularQueue*)malloc(sizeof(CircularQueue));
    if(q==NULL){
        return NULL;
    }
    q->front=0;
    q->rear=-1;
    q->count=0;
    return q;
}
bool isQueueEmpty(CircularQueue *q){
    return q->count==0;
}
bool isQueueFull(CircularQueue *q){
    return q->count==MAX_CUSTOMERS;
}
void enqueue(CircularQueue *q, Transaction newT){
    if(isQueueFull(q)){
        printf("Hang doi da day. Khach hang ID %d phai cho\n", newT.customerName);
        return;
    }
    q->rear=(q->rear+1)%MAX_CUSTOMERS;
    q->data[q->rear]=newT;
    q->count++;
    printf("ENQUEUE: Khach hang ID %d da vao hang doi.\n", newT.customerName);
}
Transaction dequeue(CircularQueue *q){
    if(isQueueEmpty(q)){
        printf("Loi DEQUEUE: Hang doi rong. Khong co khach hang de phuc vu.\n");
        return (Transaction){"ERROR", 0, 0.0};
    }
    Transaction t=q->data[q->front];
    q->front=(q->front+1)%MAX_CUSTOMERS;
    q->count--;
    return t;
}
void freeQueue(CircularQueue* q){
    free(q);
}
void printTransaction(Transaction t){
    if(strcmp(t.customerName, "ERROR")!=0){
        printf("Dang xu ly giao dich:\n");
        printf("-Khach hang: %s\n", t.customerName);
        printf("-Loai GD: ");
        switch(t.transactionType){
            case 1: printf("Nop tien\n"); break;
            case 2: printf("Rut tien\n"); break;
            case 3: printf("Chuyen khoang\n"); break;
            default: printf("Khong xac dinh\n"); break;
        }
        printf("-So tien: %.2f VND\n", t.amount);
    }
}
main(){
    CircularQueue* q=createQueue();
    printf("--Mo phong hang doi (toi da %d)--\n",MAX_CUSTOMERS);
    enqueue(q, (Transaction){"Nguyen Van A", 1, 5000000});
    enqueue(q, (Transaction){"Tran Thi B", 2, 3000000});
    enqueue(q, (Transaction){"Le Van C", 3, 2300000});
    enqueue(q, (Transaction){"Pham Dinh D", 2, 1000000});
    enqueue(q, (Transaction){"Vo Thi E", 1, 2000000});
    enqueue(q, (Transaction){"Nguyen F", 1, 9000000});
    printf("--Xu ly giao dich--\n");
    printTransaction(dequeue(q));
    printTransaction(dequeue(q));
    printf("Co cho trong, co the them giao dich moi\n");
    enqueue(q, (Transaction){"Ly Van O", 2, 5500000});
    printf("Tiep tuc xu ly giao dich\n");
    while(!isQueueEmpty(q)){
        printTransaction(dequeue(q));
    }
    freeQueue(q);
    return 0;
}
