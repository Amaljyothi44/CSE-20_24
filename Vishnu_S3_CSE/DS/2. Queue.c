#include<stdio.h>
#include<stdlib.h>

#define MAX 50

void insert();
void delete();
void display();

int QUEUE[MAX], rear = -1, front = -1;

void main() {
    
    int choice;
    
    printf("\nMenu\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");

    while(1){

        printf("\nEnter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
    
        case 1:
           insert();
           break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...");
            exit(1);
        default:
            printf("Invalid choice");
        }
    }
}

void insert() {
    int x;
    if (rear == MAX - 1) 
        printf("Queue Overflow");
    else {
        if(front == -1)
            front = 0;
        printf("Enter Element: ");
        scanf("%d", &x);
        QUEUE[++rear] = x;
    }
}

void delete() {
    if(front == -1 || front  > rear){
        printf("Queue Underflow");
        return;
    } else 
        printf("Element deleted: %d", QUEUE[front++]);
}

void display() {
    int i;
    if(front == -1)
        printf("Queue Empty");
    else
        for(int i = front; i <= rear; i++)
            printf("\t%d", QUEUE[i]);
}    
