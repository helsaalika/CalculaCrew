#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "Common.h"

// ===================
//   DATA ATTRIBUTE
// ===================

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


// ===================
//       MODUL
// ===================

/* Check if stack is empty */
// PIC : Helsa
int isEmpty_stack(Stack *stack);

/* Allocate new node */
// PIC : Helsa
addressStack make_stack_node();

/* Make new stack */
// PIC : Aini
Stack* make_stack();

/* Print stack nodes */
// PIC : Mey
void print_stack_node(addressStack);

/* Push a node to stack */
// PIC : Mey
void push(Stack *stack, Data datum, int isChar);

/* Pop a node from stack and return it as stackNode */
// PIC : Aini
StackNode pop(Stack *stack);

/* Make new stack */
// PIC : Aini
void remove_stack(Stack *stack);

#endif // STACK_H_INCLUDED
