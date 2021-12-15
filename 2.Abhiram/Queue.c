#include<stdio.h>
void insert();
void delete();
void display();

int queue[100];
int front=-1,rear=-1,n;

int main(){
    int choice;
    printf("Enter size of Queue: ");
    scanf("%d",&n);
    while(choice!=4){
        printf("\nSelect Operation:\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: return 0;
            default: printf("Invalid Selection!");
        }
    }
    return 0;
}

void insert(){
    if(rear>=n-1){
        printf("Queue Overflow!");
    }else{
        if(front<0){
            front=0;
        }
        printf("\nEnter element: ");
        rear++;
        scanf("%d",&queue[rear]);
    }
}
void delete(){
    if(front==-1||front>rear){
        printf("Queue Underflow!");
    }else{
        printf("\nDeleted element is %d",queue[front]);
        front++;
    }
}

void display(){
    int i;
    if(front==-1)
        printf("Queue Empty!");
    printf("Queue: \n");
    for(i=front;i<=rear;i++){
        printf("%d\n",queue[i]);
    }
    return ;
}