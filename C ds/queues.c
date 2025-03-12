#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char *items[MAX];
    int front, rear;
} Queue;

void initialize(Queue *q) {
    q -> front = -1;
    q -> rear = -1;
}

int isEmpty(Queue *q) {
    return q -> front == -1;
}

int isFull(Queue *q) {
    return q -> rear == MAX - 1;
}

void enqueue(Queue *q, const char *data) {
    if (isFull(q)) {
        printf("Queue is full!! \n");
        return;
    }
    if (isEmpty(q)) {
        q -> front = 0;
    }
    q -> rear++;
    q -> items[q -> rear] = strdup(data);
}

void dequeue(Queue *q) {
    if (isEmpty(q)){
        printf("Queue is empty!! \n");
        return;
    }
    printf("Popped element: %s \n", q -> items[q -> front]);

    free(q -> items[q -> front]);

    if (q -> front == q -> rear) {
        q -> front = q -> rear = -1;
    } else {
        q -> front++;
    }
}

void length(Queue *q) {
    if (isEmpty(q)) {
        printf("Length: 0 \n");
    } else {
        printf("Length: %d \n", q -> rear - q -> front + 1);
    }
}

void checkEmpty(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. \n");
    } else {
        printf("Queue is NOT empty. \n");
    }
}

void display(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue is empty!! \n");
        return;
    }
    printf("Queue contents: ");
    for (int i = q -> front; i <= q -> rear; i++){
        printf("--> %s", q -> items[i]);
    }
    printf("\n");
}
int main()
{
    Queue q;
    initialize(&q);
    checkEmpty(&q);
    enqueue(&q, "Honda Civic");
    enqueue(&q, "Honda Acura NSX");
    enqueue(&q, "Honda S2000");
    enqueue(&q, "Honda CBR650R");
    display(&q);
    dequeue(&q);
    display(&q);
    checkEmpty(&q);
    length(&q);
    
    return 0;
}
