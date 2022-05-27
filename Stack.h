#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "Common.h"
#include "boolean.h"

typedef struct StackNode *addressStack;

typedef struct StackNode
{
	int isChar;
	Data data;
	addressStack pNode;
} StackNode;

typedef struct Stack
{
	addressStack topNode;
} Stack;

int isEmpty_stack(Stack *stack);
addressStack make_stack_node();
Stack* make_stack();
void print_stack_node(addressStack);
void push(Stack *stack, Data datum, int isChar);
StackNode pop(Stack *stack);
void remove_stack(Stack *stack);

#endif // STACK_H_INCLUDED
