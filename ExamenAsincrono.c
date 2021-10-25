/*
 * stack.c
 *
 *  Created on: 24 mar. 2021
 *      Author: Daniel y Samir
 */
#include"stack.h"

int main(){

	setbuf(stdout, NULL);

	char inf[SIZE];
	char post[SIZE];

	printf("Ingresar Expresion infija:\n");
	scanf("%s", inf);

	InfAPos(inf,post);

	printf("Expresions Posfija:\n");
	printf("%s", post);
	stack_destroy(inf);
	return 0;
}

