#include<stdio.h>
#include<stdbool.h>
#define MAX  5

int q[MAX];
int left = -1;
int right = -1;

bool isFull(){
    if((right==MAX-1&&left==0)||(right==left-1)){
        return true;
    }
    else   
        return false;
}

bool isEmpty(){
	if(left==-1)
		return true;
	else
		return false;
}
// Insertion at right pos


void InsertR(){
    int item;
    if(isFull()){
        printf("Queue Overflow");
        return;
    }
    else{
        if(left==-1){
            left++;
        }
        if(right==MAX-1){
            right = 0;
        }
        else{
            right++;
            printf("\nEnter ittem to be inserted: ");
            scanf("%d",&q[right]);
            
        }
    }
}

// Insertion at left pos


void InsertL(){
    if(isFull()||left<1){
        printf("\t---Cant insert item---");
        return;
    }
    else{
            printf("\nEnter ittem to be inserted: ");
            left--;
            scanf("%d",&q[left]); 
            
    }
}

// To delete at Left

void deleteL(){
    if(isEmpty()){
        printf("Queue Underflow!");
    }else{
	printf("\nDeleted element is %d",q[left]);
	if(left==right){
        left = -1;
        right = -1;
	}else if(left==MAX-1){
        left = 0;
    }
    else{
        left++;
    }
    }
}

// To delete at Right

void deleteR(){
    if(isEmpty()){
        printf("Queue Underflow!");
    }else{
	printf("\nDeleted element is %d",q[right]);
	if(left==right){
        left = -1;
        right = -1;   
	}else
		right--;
    }
    
}


// TO display DEqueque

void display(){
    int front = left;
    int rear = right;

    printf("\n");
    if(front==-1){
        printf("Queue is Empty!");
        return;
    }else if(front<=rear){
        while(front<=rear){
            printf("%d",q[front]); 
            printf("\t");           
            front++;
        }
    }
    printf("\n");
}

// ----------------------------------------------------------

int main(){
    int choice;
    while(choice!=6){
        printf("\nSelect Operation:\n1.Insert at Left\n2.Insert at Right\n3.Delete at Left\n4.Delete at Right\n5.Display\n6.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: InsertL();
                    break;
            case 2: InsertR();
                    break;
            case 3: deleteL();
                    break;
            case 4: deleteR();
                    break;
            case 5: display();
                    break;
            case 6: return 0;
            default: printf("Invalid Selection!");
        }
    }
    return 0; 
}
