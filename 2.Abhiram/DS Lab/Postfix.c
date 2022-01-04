#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 50
char stack[MAX];
int top=-1;

void push(char item)
{
    if(top>=MAX-1)
        printf("\n\t\t--STACK OVERFLOW---");
    else
    {
            top++;
            stack[top]=item;
    }
}

char pop()
{
    char a;
    if(top<0)
    {
        printf("\n\t\t---EMPTY STACK---");
        exit(1);
    }
    else
    {
        a=stack[top];
        top--;
        return a;
    }
}

int is_operator(char symbol)
{
    if(symbol=='^' || symbol=='*' || symbol=='/' || symbol=='+' || symbol=='-')
        return 1;
    else
        return 0;
}

int precedence(char symbol)
{
    if(symbol=='^')
        return 3;
    else if(symbol=='*' || symbol=='/')
        return 2;
    else if(symbol=='+' || symbol=='-')
        return 1;
    else
        return 0;    
}

void in_post(char infix_exp[])
{
    int i=0,j=0;
    char x,postfix_exp[MAX],item;
    push('(');
    strcat(infix_exp,")");
    item=infix_exp[i];
    while(item!='\0')
    {
        if(item=='(')
            push(item);
        else if(isdigit(item) || isalpha(item))
        {
            postfix_exp[j]=item;
            j++;
        }
        else if(is_operator(item)==1)
        {
            x=pop();
            while(is_operator(x) && precedence(x)>=precedence(item))
            {
                postfix_exp[j]=x;
                j++;
                x=pop();
            }
            push(x);
            push(item);
        }
        else if(item==')')
        {
            x=pop();
            while(x!='(')
            {
                postfix_exp[j]=x;
                j++;
                x=pop();
            }
        }
        else
        {    
            printf("\n\t---INVALID INFIX EXPRESSIOn---");
            exit(1);
        }
        i++;
        item=infix_exp[i];
    }
    if(top>0)
    {
        printf("\n\t---INVALID INFIX EXPRESSIOn---");
        exit(1);
    }
    postfix_exp[j]='\0';
    printf("\n\tThe postfix expression is : ");
    puts(postfix_exp);
}
int main()
{
    char infix[MAX];
    printf("\n\tEnter the infix expression : ");
    gets(infix);
    in_post(infix);
    return 0;
}