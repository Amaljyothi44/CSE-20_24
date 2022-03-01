#include<stdio.h>

#define MAX 5
 
int DEQUEUE[MAX], rear = -1,  front = -1;

void display() {
    
    if(front == -1){
        printf("Queue is empty");
        return;
    }
    
    printf("Printing DeQueue:\n");
    
    for(int i = front; i <= rear; i++)
        printf("%d ", DEQUEUE[i]);
}

void insertRear() {     

    int a;

    if(rear == (MAX - 1)) {
        printf("Queue is full");
        return;
    } 
        
    if(front == -1)
        front++;
        
    printf("Enter Element: ");
    scanf("%d", &a);
        
    DEQUEUE[++rear] = a;

}

void deleteFront(){

    int value;
    
    if(front == -1) {
        printf("Queue is empty");
        return;
    }
    
    value = DEQUEUE[front];
    
    if(rear == front){
        rear = -1;
        front = -1;
    } else {
        front++;
    }
    
    printf("\nThe deleted element from front is: %d", value);

}

void deleteRear(){
    
    int value;
    
    if(front == -1) {
        printf("Queue is empty");
        return;
    }

    value = DEQUEUE[rear];
    
    if(rear == front){
        rear = -1;
        front = -1;
    } else {
        rear--;
    }

    printf("\nThe deleted element from rear is: %d", value);
    
}

void insertFront() {
    int a;

    if(front == 0) {
        printf("Front is at the beginning - insertion not possible");
        return;
    }
    
    if(front == -1){
        front++;
        rear++;
    } else {
        front--;
    }

    printf("Enter Element: ");
    scanf("%d", &a);

    DEQUEUE[front] = a;
        
}

void main() {
    int c;
    printf("Choose an option:\n1. Insert from Rear\n2. Delete from Front\n3. Insert from Front\n4. Delete from Rear\n5. Display\n");

    menu:
    printf("\nEnter choice: ");
    scanf("%d", &c);

    switch(c) {
    
        case 1:
            insertRear();
            break;
        case 2:
            deleteFront();
            break;
        case 3:
            insertFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            display();
            break;
        default:
            printf("Choice not found");
        } goto menu;
}
