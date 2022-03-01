#include<stdio.h>
#include<stdlib.h>
#include <stddef.h>

struct Node {
    int data;
    struct Node *link;
};

struct Node* HEAD = NULL;

void insertStart(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node*));

    newNode->data = value;
    HEAD = newNode;
    newNode->link = NULL;
}

void insertEnd(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* ptr = HEAD;

    while(ptr->link != NULL)
        ptr = ptr->link;

    ptr->link = newNode;
    newNode->link = NULL;
}

void insert(int value, int key) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node*));
    newNode->data = value;

    struct Node* ptr = HEAD;
    struct Node* prev;

    while(ptr->data != key) {
        prev = ptr;
        ptr = ptr->link;
    }

    newNode->link = ptr->link;
    ptr->link = newNode;
}

void display() {

    if(HEAD == NULL) {
        printf("\nLinked list empty!\n");
        return;
    }

    struct Node* ptr = HEAD;

    while(ptr->link != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->link;
    }

    printf("%d\t\n", ptr->data);

}

void deleteStart() {

    if(HEAD == NULL){
        printf("Linked list empty!");
        return;
    }

    if(HEAD->link == NULL) {
        HEAD = NULL;
        return;
    }

    struct Node* temp = HEAD;
    printf("The deleted element is: %d\n",temp->data);
    HEAD = HEAD->link;
    free(temp);
}

void deleteEnd() {

    struct Node* ptr = HEAD;
    struct Node* prev;

    while(ptr->link != NULL) {
        prev = ptr;
        ptr = ptr->link;
    }

    printf("The deleted element is: %d\n",ptr->data);
    prev->link = NULL;
    free(ptr);
}

void delete(int key) {

    struct Node* ptr = HEAD;
    struct Node* prev;

    while(ptr->data != key) {
        prev = ptr;
        ptr = ptr->link;
    }

    printf("The deleted element is: %d\n",ptr->data);
    prev->link = ptr->link;
    free(ptr);

}

int getValue(char s[]) {
    int n;
    printf("Enter the %s: ", s);
    scanf("%d", &n);
    return n;
}

void main(){

    int choice;
    printf("1. Insert at the beginning");
    printf("\n2. Insert at the end");
    printf("\n3. Insert after a value");
    printf("\n4. Delete from beginning");
    printf("\n5. Delete from the end");
    printf("\n6. Delete a specific value");
    printf("\n7. Display");
    printf("\n8. Exit\n");

    while(1) {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                insertStart(getValue("value"));
                break;
            case 2:
                insertEnd(getValue("value"));
                break;
            case 3:
                insert(getValue("value"), getValue("key"));
                break;
            case 4:
                deleteStart();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                delete(getValue("key"));
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Invalid choice");
                break;

        }
    }

}
