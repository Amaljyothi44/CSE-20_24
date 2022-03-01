#include<stdio.h>
#include<stdbool.h>

#define MAX 5 
 
int QUEUE[MAX], front = 0,  rear = -1;

bool isFull() {
    return (rear - front == MAX - 1);
}

bool isEmpty() {
    return (front < 0 || front > rear);
}

void peek(){
    if(isEmpty())
        printf("Queue is empty");
    else
        printf("Top element is: %d", QUEUE[front]);
}

void enqueue() {
    int data;
    printf("Enter element: ");
    scanf("%d", &data);
    if(isFull()){
        printf("Queue Overflow");
        return;
    } else {
        QUEUE[++rear] = data;
    }
}

void dequeue(){
    if(isEmpty()){
        printf("Queue Underflow");
    } else {
        printf("Removed element: %d", QUEUE[front++]);
    }
}

void display(){
    if(isEmpty())
        printf("Queue Empty");
    else 
        for(int i = front; i <= rear; i++)
            printf("\t%d", QUEUE[i]);
}

void main() {
    int c;
    printf("Choose an option:\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");

    menu:
    printf("\nEnter choice: ");
    scanf("%d", &c);

    switch(c) {
    
        case 1:
           enqueue();
           break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting...");
            return;
        default:
            printf("Choice not found");
        } goto menu;
}
