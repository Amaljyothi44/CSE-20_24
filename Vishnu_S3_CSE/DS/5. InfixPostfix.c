#include<stdio.h>
#include<ctype.h>

char STACK[100];
int TOP = -1;

void push(char c){
    STACK[++TOP] = c;
}

char pop(){
    if(TOP == -1)
        return -1;
    else
        return STACK[TOP--];
}

int priority(char x){
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;   
     return 0;
}

int main(){	

    char expression[100];
    char *e, x;
    printf("\nEnter the expression: ");
    scanf("%s", expression);
    printf("\n");
    e = expression;
   
    while(*e != '\0'){
        if(isalnum(*e))
            printf("%c ", *e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
            while((x = pop()) != '(')
                printf("%c ", x);
        else{
             while(priority(STACK[TOP]) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }
    
    while(TOP != -1)
        printf("%c ",pop());

    printf("\n\n");
    return 0;

}
