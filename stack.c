/*******************************************************
Nom ......... : stack.c
Role ........ : stack source file
Auteur ...... : Aussman I
Version ..... : V1.1 2022
Licence ..... : GPL

Compilation : iarcompiler/ GCC
********************************************************/
#include "stack.h"


void vidStacking(Stack *stack, int newNumber)
{
    Element *newElement = malloc(sizeof(newElement));
    dbgCheckValidAddr(stack);
    dbgCheckValidAddr(newElement);

    newElement->number = newNumber;
    newElement->next   = stack->first;
    stack->first       = newElement;


} //end vidStacking()