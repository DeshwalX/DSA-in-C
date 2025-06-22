#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void init_stack(Stack *s) {
    s->top = -1;
}

bool is_empty_stack(Stack *s) {
    return s->top == -1;
}

bool is_full_stack(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int val) {
    if (is_full_stack(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++(s->top)] = val;
}

int pop(Stack *s) {
    if (is_empty_stack(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[(s->top)--];
}

int peek(Stack *s) {
    if (is_empty_stack(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top];
}

typedef struct {
    Stack input;
    Stack output;
} Queue;

void init_queue(Queue *q) {
    init_stack(&(q->input));
    init_stack(&(q->output));
}

bool is_queue_empty(Queue *q) {
    return is_empty_stack(&(q->input)) && is_empty_stack(&(q->output));
}

void enqueue(Queue *q, int val) {
    push(&(q->input), val);
}

int dequeue(Queue *q) {
    if (is_queue_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    if (is_empty_stack(&(q->output))) {
        while (!is_empty_stack(&(q->input))) {
            push(&(q->output), pop(&(q->input)));
        }
    }

    return pop(&(q->output));
}

int main() {
    Queue q;
    init_queue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Dequeued: %d\n", dequeue(&q)); 
    printf("Dequeued: %d\n", dequeue(&q)); 

    enqueue(&q, 40);
    printf("Dequeued: %d\n", dequeue(&q)); 
    printf("Dequeued: %d\n", dequeue(&q)); 
    printf("Dequeued: %d\n", dequeue(&q)); 

    return 0;
}

