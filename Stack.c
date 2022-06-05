#include "Stack.h"

/* Check if stack is empty */
// PIC : Helsa
int isEmpty_stack(Stack *stack)
{
	if(!stack) {
		puts("the stack doesn't exist.");
		return true;
	}
	return stack->topNode == NULL;
}

/* Allocate new node */
// PIC : Helsa
addressStack make_stack_node()
{
	StackNode *tmp = (addressStack)calloc(sizeof(StackNode), 1);
	if(!tmp){
		puts("memory is full-using.");
		exit(1);
	}
	return tmp;
}

/* Make new stack */
// PIC : Aini
Stack* make_stack()
{
	Stack *tmp = (Stack*)calloc(sizeof(Stack), 1);
	if(!tmp) {
		puts("memory is full-using.");
		exit(1);
	}
	return tmp;
}

/* Print stack nodes */
// PIC : Mey
void print_stack_node(StackNode *tNode)
{
	if(!tNode)	return;
	while(tNode){
		if(tNode->isChar){
			printf("%c", tNode->data.opr);
		}
		else{
			printf("%g", tNode->data.num);
		}
		tNode = (*tNode).pNode;		
	}
}

/* Push a node to stack */
// PIC : Mey
void push(Stack *stack, Data datum, int isChar)
{
	StackNode *tmp = make_stack_node();
	if(!tmp) {
		puts("memory is full-using.");
		exit(1);
	}
	tmp->data = datum;
	tmp->isChar = isChar;
	tmp->pNode = stack->topNode;
	stack->topNode = tmp;
}

/* Pop a node from stack and return it as stackNode */
// PIC : Aini
StackNode pop(Stack *stack)
{
	StackNode res;
	res.data = dummy_data;
	res.isChar = false;
	if(!stack || isEmpty_stack(stack))	return res;
	res = *(stack->topNode);
	StackNode *tmp = stack->topNode;
	stack->topNode = tmp->pNode;
	free(tmp);
	return res;
}

/* Make new stack */
// PIC : Aini
void remove_stack(Stack *stack)
{
	StackNode sn;
	while(!isEmpty_stack(stack)) {
		sn = pop(stack);
		print_stack_node(&sn);
	}
}
