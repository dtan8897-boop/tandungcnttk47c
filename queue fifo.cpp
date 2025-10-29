#include <stdio.h>
#include <stdbool.h>
#define QUEUE_SIZE 5

typedef struct {
    int data[QUEUE_SIZE];
    int front;
    int rear;
    int count;
} Queue;

void initializeQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

bool isQueueEmpty(Queue *q) {
    return q->count == 0;
}

bool isQueueFull(Queue *q) {
    return q->count == QUEUE_SIZE;
}

void enqueue(Queue *q, int value) {
    if (isQueueFull(q)) {
        printf("L?i: Queue d?y!\n");
        return;
    }
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->data[q->rear] = value;
    q->count++;
    printf("Queue: Enqueued %d\n", value);
}

int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("L?i: Queue r?ng!\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    q->count--;
    return value;
}

void testQueue() {
    Queue q;
    initializeQueue(&q);
    printf("\n--- KIEM THU QUEUE (FIFO) ---\n");
    enqueue(&q, 100);
    enqueue(&q, 200);
    enqueue(&q, 300);
    printf("Queue: Dequeued 1: %d\n", dequeue(&q));
    printf("Queue: Dequeued 2: %d\n", dequeue(&q));
}

int main() {
    testQueue();
    return 0;
}


