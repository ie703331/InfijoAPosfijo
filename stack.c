/*
 * stack.c
 *
 *  Created on: 23 mar. 2021
 *      Author: Daniel y Samir
 */
#include "stack.h"

char stack[SIZE];
int top = -1;

void stack_push(char e){
	top = top+1;
	stack[top] = e;
}
char stack_pop(){
	char e ;
	e = stack[top];
	top = top-1;
	return(e);
}
int stack_operator(char op){
	if(op == '*' || op == '/' || op == '+' || op =='-'){
		return 1;
	}
	else{
	return 0;
	}
}

int stack_precedence(char op){
	if(op == '*' || op == '/'){
		return(2);
	}
	else if(op == '+' || op == '-'){
		return(1);
	}
	else{
		return(0);
	}
}

int stack_destroy(char inf[]){
	for(int i = 0; i<top; i++){
		inf[i]=0;
	}
	return (printf("\nStack Eliminado"));
}

void InfAPos(char inf[], char post[]){
	int i, j;
	char e;
	char x;
	stack_push('(');
	strcat(inf,")");
	i=0;
	j=0;
	e=inf[i];

	while(e != '\0'){
		if(e == '('){
			stack_push(e);
		}
		else if(isalnum(e)){
			post[j] = e;
			j++;
		}
		else if(stack_operator(e) == 1){
			x=stack_pop();
			while(stack_operator(x) == 1 && stack_precedence(x)>= stack_precedence(e)){
				post[j] = x;
				j++;
				x = stack_pop();
			}
			stack_push(x);
			stack_push(e);
		}
		else if(e == ')'){
			x = stack_pop();
			while(x != '('){
				post[j] = x;
				j++;
				x = stack_pop();
			}
		}
		i++;
		e = inf[i];
	}
	post[j] = '\0';
}
