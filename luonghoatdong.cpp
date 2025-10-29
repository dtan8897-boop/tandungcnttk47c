#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
    char customerName[50];
    int transactionType;
    double amount;
} Transaction;

typedef struct {
    Transaction items[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int count;
} CircularQueue;

CircularQueue* createQueue() {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    if (q == NULL) return NULL;
    q->front = 0;
    q->rear = -1;
    q->count = 0;
    return q;
}

bool isFull(CircularQueue* q) {
    return (q->count == MAX_QUEUE_SIZE);
}

bool isEmpty(CircularQueue* q) {
    return (q->count == 0);
}

void enqueue(CircularQueue* q, Transaction newTransaction) {
    if (isFull(q)) {
        printf("!! Hang doi da day, KH '%s' vui long quay lai sau.\\n", newTransaction.customerName);
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->items[q->rear] = newTransaction;
    q->count++;
    printf(">> Giao dich cua KH '%s' da them vao hang doi.\\n", newTransaction.customerName);
}

Transaction dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("!! Hang doi rong, khong co giao dich de xu ly.\\n");
        return (Transaction){"ERROR", 0, 0.0};
    }
    Transaction transactionToProcess = q->items[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->count--;
    return transactionToProcess;
}

void freeQueue(CircularQueue* q) {
    free(q);
}

void printTransaction(Transaction t) {
    if (strcmp(t.customerName, "ERROR") != 0) {
        printf("------------------------------------------\\n");
        printf("Dang xu ly giao dich:\\n");
        printf(" - Khach hang: %s\\n", t.customerName);
        printf(" - Loai GD  : ");
        switch (t.transactionType) {
            case 1: printf("Nop tien\\n"); break;
            case 2: printf("Rut tien\\n"); break;
            case 3: printf("Chuyen khoan\\n"); break;
            default: printf("Khong xac dinh\\n"); break;
        }
        printf(" - So tien  : %.2f VND\\n", t.amount);
        printf("------------------------------------------\\n");
    }
}

int main() {
    CircularQueue* q = createQueue();
    if (q == NULL) return 1;

    printf("--- Mo phong hang doi (toi da %d) ---\\n", MAX_QUEUE_SIZE);
    
    enqueue(q, (Transaction){"Nguyen Van A", 1, 500000});
    enqueue(q, (Transaction){"Tran Thi B", 2, 2000000});
    enqueue(q, (Transaction){"Le Van C", 3, 1000000});
    enqueue(q, (Transaction){"Pham Dinh D", 2, 1500000});
    enqueue(q, (Transaction){"Vo Thi E", 1, 300000});

    enqueue(q, (Transaction){"Hoang F", 1, 900000});

    printf("\\n--- Bat dau xu ly giao dich ---\\n");
    
    printTransaction(dequeue(q));
    printTransaction(dequeue(q));

    printf("\\n>> Co cho trong, them giao dich moi...\\n");
    
    enqueue(q, (Transaction){"Ly Van G", 3, 750000});

    printf("\\n--- Tiep tuc xu ly giao dich con lai ---\\n");
    
    while (!isEmpty(q)) {
        printTransaction(dequeue(q));
    }
    
    printTransaction(dequeue(q));

    freeQueue(q);

    return 0;
}
