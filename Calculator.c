#include "Calculator.h"

/* Change isError state if there is error token */
// PIC : Mey
void GotError(int *isError)
{
	*isError = 1;
}

/* Check if there is error token */
// PIC : Helsa
void CheckAndGetChar(char tmp, int *isError)
{
	if(tmp != token){
		GotError(&(*isError));
	}
	token = getchar();
}

/* Main control of receive input, calculation, creation of stack and tree */
// PIC : Aini
double mainCalculator(int *isQuit, int *isError, int generalCalc)
{
	double value;
	StackNode tmp;
	TreeNode *tn = NULL;
	/// make data structures for each cases
	root = make_root_node();
	st = make_stack();

	/// process
	space = getchar();
    token = getchar();
    sum(&(*isQuit), &(*isError));
	// now, stack is already built

	/// construct tree
	while(!isEmpty_stack(st))
	{
		// As the stack is being removed, constructs tree
		tmp = pop(st);
		while(tmp.isChar)
		{
			// operator
			tn = make_child(tn, tmp.data, tmp.isChar);
			if(root->root == NULL)	root->root = tn;
			tmp = pop(st);
		}
		// number
		tn = make_child(tn, tmp.data, tmp.isChar);
		if(root->root == NULL)	root->root = tn;
	}	
	
    value = calculate(root->root);

	if(generalCalc == 1 && value != 0){
		addHistory(value);
	}

    /// delete
    remove_all_tree_nodes(root);
    return value;
}

/* push data in the stack with the method of post-fix
   calculate addition and subtraction */
// PIC : Mey
void sum(int *isQuit, int *isError)
{
	term(&(*isQuit), &(*isError));
	Data datum;
	if(token == 'q' || token == 'Q'){
		*isQuit = true;
	} else {
		while(token == '+' || token == '-')
		{
			if(token == '+')
			{
				datum.opr = '+';
				CheckAndGetChar('+', &(*isError));
				term(&(*isQuit));
				push(st, datum, true);
			}
			else if(token == '-')
			{
				datum.opr = '-';
				CheckAndGetChar('-', &(*isError));
				term(&(*isQuit));
				push(st, datum, true);
			}
		}		
	}
}

/* push data in the stack with the method of post-fix
   calculate multiple and devision */
// PIC : Helsa
void term(int *isQuit, int *isError)
{
	factor(&(*isQuit), &(*isError));
	Data datum;
	if(token == 'q' || token == 'Q'){
		*isQuit = true;
	} else {
		while(token == '*' || token == '/' || token == '^' || token == '|')
		{
			if(token == '^')
			{
				datum.opr = '^';
				CheckAndGetChar('^', &(*isError));
				factor(&(*isQuit), &(*isError));
				push(st, datum, true);			
			}
			else if(token == '|')
			{
				datum.opr = '|';
				CheckAndGetChar('|', &(*isError));
				factor(&(*isQuit), &(*isError));
				push(st, datum, true);			
			}		
			else if(token == '*')
			{
				datum.opr = '*';
				CheckAndGetChar('*', &(*isError));
				factor(&(*isQuit), &(*isError));
				push(st, datum, true);
			}
			else if(token == '/')
			{
				datum.opr = '/';
				CheckAndGetChar('/', &(*isError));
				factor(&(*isQuit), &(*isError));
				push(st, datum, true);
			}
		}		
	}
}

/* push data in the stack with the method of post-fix
   regards factor as a number */
// PIC : Aini
void factor(int *isQuit, int *isError)
{
	double temp = 0.0;
	Data datum;
	
	if(token == 'q' || token == 'Q'){
		*isQuit = true;
	} else {
		if(token == '(')
		{
			// start with new sum again
			CheckAndGetChar('(', &(*isError));
			sum(&(*isQuit), &(*isError));
			CheckAndGetChar(')', &(*isError));
		}
		else if(token == '-')
		{
			// negation
			CheckAndGetChar('-', &(*isError));
			datum.opr = '-';
			factor(&(*isQuit), &(*isError));
			push(st, datum, true);
		}
		else if(token == '+')
		{
			// there is no meaning, but just exception dealing
			CheckAndGetChar('+', &(*isError));
			factor(&(*isQuit), &(*isError));
		}
		else if(isdigit(token))
		{
			ungetc(token, stdin);
			scanf("%lf", &temp);
			datum.num = temp;
			push(st, datum, false);
			token = getchar();
		}
		else GotError(&(*isError));		
	}	
}

/* Calculation for squareroot */
// PIC : Mey
int squareRoot(int base, int exp){
	int i=1,j,result=1;
	while(i<base){
		result = 1;
		for (j=1;j<=exp;j++){
			result = result * i;
		}
		if(result == base){
			break;
		}
		i++ ;
	}
	if(i == base){
		gotoxy(8,13);printf("  Hasil berbentuk format tidak didukung");
		return 0;
	} else {
		return i;
	}
}

/* Calculation with inorder traversal from tree */
// PIC : Mey
double calculate(TreeNode *current){
	if(current == NULL){
		return;
	}
	double result = 0;
	result = calculate(current->left);
	
	if(current->isChar==false){
		return current->data.num;
	}else{
		switch(current->data.opr){
			case '+': result += calculate(current->right); break;
			case '-': result -= calculate(current->right); break;
			case '/': result /= calculate(current->right); break;
			case '*': result *= calculate(current->right); break;
			case '^': result = pow(result,calculate(current->right)); break;
			case '|': result = squareRoot(result,calculate(current->right)); break;
		}
	}
	
	return result;
}

// ===================
//       HISTORY
// ===================
/* add new data line to file history.txt */
void addHistory(double result){
	char *filename = "history.txt";
	
	FILE *fp = fopen(filename,"a");
	if(fp == NULL){
		printf("Error opening file %s",filename);
		return;
	}
	
	writeInput(root->root,fp);	
	fprintf(fp, " = %g\n",result);
	
	fclose(fp);
}

/* print data to file */
void writeInput(TreeNode *current, FILE *fp){
	if(current == NULL){
		return;
	}
	writeInput(current->left,fp);
	if(current->isChar==false){
		fprintf(fp,"%g",current->data.num);
	}else{
		fprintf(fp,"%c",current->data.opr);
	}
	writeInput(current->right,fp);
	
}

/* read file history.txt and print data on console */
void printHistory(){
	system("cls");
	char *filename = "history.txt";
	
	FILE *fp = fopen(filename,"r");
	char data;
	
	printf("\n                            H I S T O R Y\n");
	printf("--------------------------------------------------------------------\n");
	
	if(fp == NULL){
		printf("Error opening file %s",filename);
		exit(1);
	}
	 
	while((data=getc(fp))!=EOF){
		putch(data);
	}
	
	fclose(fp);
	
	printf("\n\nclick ENTER to back");
    getchar();
    char c = fgetc(stdin);
    if(c==0x0A){
    	main();
	}
}
