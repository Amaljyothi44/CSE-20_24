#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(){
    int choice;
    struct node *new_node=NULL;
    new_node = (struct node*)malloc(sizeof(struct node));    
    printf("Where to insert\n1.At beginning\n2.Between nodes\n3.At end\n");
    scanf("%d",&choice);
    if(choice==1){
        printf("Enter data to be stored in node:\t");
        scanf("%d",&new_node->data);
        if(head==NULL){
            head=new_node;
        }else{
            new_node->next = head;
            head = new_node;
        }
    }else if(choice==2){
        int key;
        printf("Enter key:\n");
        scanf("%d",&key);
        printf("Enter data to be stored in node:\t");
        scanf("%d",&new_node->data);
        struct node *ptr = head;
        while(ptr->data!=key){
            ptr = ptr->next;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
    }else if(choice==3){
        struct node *ptr = head;
        printf("Enter data to be stored in node:\t");
        scanf("%d",&new_node->data);
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }else{
        printf("Enter valid option!");
    }
}

void traversal(){
    struct node *ptr = head;
    while(ptr->next!=NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    printf("%d\t",ptr->data);
}

void delete(){
    int choice;
    printf("Where to delete from \n1.Beginning\n2.Between nodes\n3.End\n");
    scanf("%d",&choice);
    if(choice==1){
        if(head==NULL){
            printf("Liist is empty!");
        }else{
            struct node *ptr = head;
            printf("Deleted element: %d",ptr->data);
            head = ptr->next;
            free(ptr);
        }
    }else if(choice==2){
        int key;
        printf("Enter key:\n");
        scanf("%d",&key);
        struct node *ptr = head;
        struct node *ptr1;
        while(ptr->data!=key){
            ptr1=ptr;
            ptr = ptr->next;
        }
        printf("Deleted element: %d",ptr->data);
        ptr1->next = ptr->next;
        free(ptr);
    }else if(choice==3){
        struct node *ptr = head;
        struct node *ptr1;
        while(ptr->next!=NULL){
            ptr1=ptr;
            ptr = ptr->next;
        }
        printf("Deleted element: %d",ptr->data);
        ptr1->next = NULL;
        free(ptr);
    }else{
        printf("Enter valid option!");
    }
}

int main(){
    int n;
    while(n!=4){
        printf("Select Operation:\n1.Insertion\n2.Deletion\n3.Traversal\n4.Exit\n");
        scanf("%d",&n);
        switch(n){
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: traversal();
                    break;
            case 4: return 0;
            default: printf("Enter valid option!");
        }
    }
    return 0;
}