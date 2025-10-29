#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100
typedef struct {
    int id;
    char description[50];
} Transaction;
typedef struct {
    Transaction items[MAX_SIZE];
    int front;
    int rear;
    int count;
} CircularQueue;

CircularQueue* createQueue() {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->front = 0;
    q->rear = -1;
    q->count = 0;
    return q;
}

bool isFull(CircularQueue* q) {
    return q->count == MAX_SIZE;
}

bool isEmpty(CircularQueue* q) {
    return q->count == 0;
}

void enqueue(CircularQueue* q, Transaction newTransaction) {
    if (isFull(q)) {
        printf("Hang doi day, khong the them giao dich moi.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = newTransaction;
    q->count++;
}
Transaction dequeue(CircularQueue* q) {
    Transaction errorTransaction = { -1, "Loi: hang doi rong" };
    if (isEmpty(q)) {
        printf("Hang doi rong, khong co giao dich de lay.\n");
        return errorTransaction;
    }
    Transaction t = q->items[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->count--;
    return t;
}

void printTransaction(Transaction t) {
    printf("ID: %d | Mo ta: %s\n", t.id, t.description);
}

int main() {
    CircularQueue* q = createQueue();

    Transaction t1 = {1, "Giao dich nap tien"};
    Transaction t2 = {2, "Giao dich rut tien"};

    enqueue(q, t1);
    enqueue(q, t2);

    printf("Cac giao dich trong hang doi:\n");
    printTransaction(dequeue(q));
    printTransaction(dequeue(q));

    return 0;
}

