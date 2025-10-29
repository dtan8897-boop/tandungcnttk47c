#include <stdio.h>
#include <stdbool.h>
#define MAX_CUSTOMERS 5

typedef struct {
    int data[MAX_CUSTOMERS];
    int front;
    int rear;
    int count;
} CustomerQueue;

void initializeQueue(CustomerQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

bool isQueueEmpty(CustomerQueue *q) {
    return q->count == 0;
}

bool isQueueFull(CustomerQueue *q) {
    return q->count == MAX_CUSTOMERS;
}

void enqueue(CustomerQueue *q, int id) {
    if (isQueueFull(q)) {
        printf("Hang doi day, khong the them khach hang %d!\n", id);
        return;
    }
    q->rear = (q->rear + 1) % MAX_CUSTOMERS;
    q->data[q->rear] = id;
    q->count++;
    printf("Khach hang %d da vao hang doi.\n", id);
}

int dequeue(CustomerQueue *q) {
    if (isQueueEmpty(q)) {
        printf("Hang doi rong, khong co khach hang de phuc vu!\n");
        return -1;
    }
    int id = q->data[q->front];
    q->front = (q->front + 1) % MAX_CUSTOMERS;
    q->count--;
    return id;
}

int main() {
    CustomerQueue q;
    initializeQueue(&q);
    printf("--- MO PHONG GIAO DICH NGAN HANG ---\n");
    enqueue(&q, 101);
    enqueue(&q, 102);
    enqueue(&q, 103);
    printf("<< DEQUEUE: Phuc vu ID: %d\n", dequeue(&q));
    printf("<< DEQUEUE: Phuc vu ID: %d\n", dequeue(&q));
    enqueue(&q, 104);
    enqueue(&q, 105);
    enqueue(&q, 106);
    printf("<< DEQUEUE: Phuc vu ID: %d\n", dequeue(&q));
    printf("<< DEQUEUE: Phuc vu ID: %d\n", dequeue(&q));
    printf("<< DEQUEUE: Phuc vu ID: %d\n", dequeue(&q));
    printf("<< DEQUEUE: Phuc vu ID: %d\n", dequeue(&q));
    return 0;
}

