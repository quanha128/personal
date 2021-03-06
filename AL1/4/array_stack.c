/* array_stack.c */

#include <stdio.h>
#include <stdlib.h>
#include "array_stack.h"

STACK stack_construct() {
    array_stack* a_stack = malloc(sizeof(array_stack));
    a_stack->top = 0;

    return a_stack;
}

void stack_free(STACK stack) {
    if(stack == NULL) {
        return;
    }
    free(stack);
}

void stack_print(STACK stack) {
    if(stack == NULL) {
        return;
    }
    for(int i = 0; i < stack->top; i++) {
        if(i != stack->top - 1) {
            printf("%d -> ", stack->elements[i]);
        } else {
            printf("%d\n", stack->elements[i]);
        }
    }
}

void stack_push(STACK stack, T value) {
    if((stack == NULL) || (stack->top == STACK_SIZE)){
        return;
    }
    stack->elements[stack->top] = value;
    stack->top++;
}

T stack_pop(STACK stack) {
    if((stack == NULL) || (stack->top == 0)) {
        return 0;
    }
    stack->top--;
    return stack->elements[stack->top];
}

int stack_empty(STACK stack) {
    return (stack == NULL) || (stack->top == 0);
}

// For Assignment 4-1
T stack_top(STACK stack) {
    if((stack == NULL) || (stack->top == 0)) {
        return 0;
    }
    return stack->elements[(stack->top)-1];
}