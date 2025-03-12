#include <stdio.h>
#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

void initialize(Stack *s) {
    s -> top = -1;
}

int isEmpty(Stack *s) {
    return s -> top == -1;
}

int isFull(Stack *s) {
    return s -> top == MAX - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow!! \n");
        return;
    }
    s -> items[++s -> top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!! \n");
        return -1;
    }
    return s -> items[s -> top--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!! \n");
        return -1;
    }
    return s -> items[s -> top];
}

int main()
{
    Stack s;
    initialize(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: \d \n", peek(&s));
    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s)); // This will cause underflow

    return 0;

}
