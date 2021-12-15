#include<stdio.h>
void push();
void pop();
void display();

int stack[100];
int n, top=0;

int main(){
    int choice;
    printf("Enter size of Stack: ");
    scanf("%d",&n);
    while(choice!=4){
        printf("Select Operation:\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: return 0;
            default: printf("Invalid Selection!");
        }
    }
    return 0;
}

void push(){
    if(top>n-1){
        printf("Enter Stack Overflow!\n");
    }
    else{
        printf("\nEnter element: ");
        scanf("%d",&stack[top+1]);
        top++;
        return ;
    }
    
}


void pop(){
    if(top<0){
        printf("Enter Stack Underflow!\n");
    }
    else{
        printf("Element deleted is : %d\n",stack[top]);
        top--;
        return ;
    }
}


void display(){
    int i;
    printf("Stack: \n");
    for(i=top;i>0;i--){
        printf("%d\n",stack[i]);
    }
    return ;
}