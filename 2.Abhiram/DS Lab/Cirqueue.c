#include<stdio.h>
#include<stdbool.h>
void insert();
void delete();
void display();
bool isFull();
bool isEmpty();

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
bool isFull(){
	if((front==0 && rear==n-1)||(front==rear+1))
		return true;
	else
		return false;
}
bool isEmpty(){
	if(front==-1)
		return true;
	else
		return false;
}
void insert(){
    if(isFull()){
        printf("Queue Overflow!");
    }else{
        if(front==-1){
            front=0;
        }
        printf("\nEnter element: ");
        rear=(rear+1)%n;
        scanf("%d",&queue[rear]);
    }
}
void delete(){
    if(isEmpty()){
        printf("Queue Underflow!");
    }else{
	printf("\nDeleted element is %d",queue[front]);
	if(front==rear){
        	front=-1;
		rear= -1;
	}else
		front= (front+1)%n;
    }
    
}
void display(){
    int i;
    if(isEmpty()){
	printf("Queue is Empty!");
	return;
    }
    printf("Queue: \n");
    for(i=front;i!=rear;i++){
        printf("\t%d",queue[i]);
    }
    printf("\t%d",queue[i]);
    return ;
}
