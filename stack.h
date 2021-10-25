/*
 * stack.h
 *
 *  Created on: 23 mar. 2021
 *      Author: Samir y Daniel
 */

#ifndef STACK_H_
#define STACK_H_

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define SIZE 20

void stack_push(char item);
char stack_pop();
int stack_operator(char symbol);
int stack_precedence(char symbol);
void InfAPos(char inf[], char post[]);
int stack_destroy(char inf[]);

#endif /* STACK_H_ */

