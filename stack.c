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



int i32Unstacking(Stack *stack){

    dbgCheckValidAddr(stack);

    int nbUnstack = 0;

    Element *elementUnstack = stack->first;
    
    if(stack != NULL && stack->first != NULL){
        nbUnstack     = elementUnstack->number;
        stack->first  = elementUnstack->next;

        free(elementUnstack);  
    }

    return nbUnstack;
} // end i32Unstacking()

