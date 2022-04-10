/*******************************************************
Nom ......... : stack.h
Role ........ : stack header file
Auteur ...... : Aussman I
Version ..... : V1.1 2022
Licence ..... : GPL

Compilation : iarcompiler/ GCC
********************************************************/
#ifndef _STACK_H_
#define _STACK_H_
#include "debug.h"
#include <stdlib.h>

typedef struct Element Element;
typedef struct Stack   Stack;

struct Element{
    int number;
    Element *next;
};

struct Stack{
    Element *first;
};


void vidStacking(Stack *stack, int newNumber);

int i32Unstacking(Stack *stack);












#endif