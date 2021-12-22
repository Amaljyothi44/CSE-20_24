#include<stdio.h>
#include<stdlib>
#include<ctype.h>
#include<string.h>
#define SIZE 100

char stack[SIZE];
int top=-1;

void push(char item){
	if(top>=SIZE-1)
		printf("Stack Overflow!");
	else
		stack[top]=item;
}

char pop(){
	char item;
	if(top<0)
		printf("Stack Underflow");
	else{
		item = stack[top];
		top++;
		return item;	
	}

}


int isOperator(char Symbol){
	if(symbol=='^'||symbol=='*'||symbol=='/'||symbol=='+'||symbol=='-'){
		return 1;
	}else
		return 0;
}

int precedence(char symbol){
	if(symbol=='^'){
		return 3;
	}else if(symbol=='*'||symbol=='/'){
		return 2;
	}else if(symbol=='+'||symbol=='-'){
		return 1;
	}else
		return 0;
}

void InfixToPostfix(char infix_exp[],char postfix_exp[]){
	int i,j;
	char item;
	char x;
	push('(');
	strcat(infix_exp[j],')');
	i=0;
	j=0;

}


