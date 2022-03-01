#include<stdio.h>

int n, TOP = -1, STACK[100];

void push();
void pop();
void display();

int main(){

int choice;

printf("Enter the size of stack (max 100): ");
scanf("%d", &n);

printf("\nChoose an option\n 1. Push \n 2. Pop \n 3. Display \n 4. Exit\n\n");

do {
    
    scanf("%d", &choice);

    switch(choice) {
    
        case 1:
           push();
           break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...");
            return 0;
        default:
            printf("Invalid choice");
        }
    } while(choice != 4);
    
    return 0;
}

void push() {

    if (TOP >= n-1)
        printf("Stack Overflow");
    else {
        int i;
        printf("Enter the number to push: ");
        scanf("%d", &i);
        STACK[++TOP] = i;
        printf("\nEnter next choice\n");
    }
}

void pop() {
    
    if (TOP <= -1)
        printf("Stack Underflow");
    else {
        printf("\nThe popped number is: %d", STACK[--TOP]);
        printf("\nEnter next choice\n");
    }
}

void display() {
    if (TOP >= 0) {
        printf("\nPrinting Queue\n");
        for(int i = TOP; i >= 0; i--)
            printf("\t%d", STACK[i]);
        printf("\nEnter next choice\n");
    } else
        printf("\nStack Empty");
}

