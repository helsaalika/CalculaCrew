#include "Calculator.h"

char token, space; // variable for reading a charactor
Root *root;
Stack *st;

void GotError()
{
	puts("error found.\nplease check your input message.");
	exit(1);
}

void CheckAndGetChar(char tmp)
{
	if(tmp != token){
		GotError();
	}
	token = getchar();
}
void term();
void sum();
void factor();
double calculate(TreeNode *current);

/*Calculate*/
double mainCalculator()
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
    sum();
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
    /// printing
//    printf("prefix : ");
//    traversal(root, PREORDER);
//    puts("");
//    printf("infix : ");
//    traversal(root, INORDER);
//    puts("");
//    printf("postfix : ");
//    traversal(root, POSTORDER);
//    puts("");
//    printf("result : %g\n", calculate(root->root));
    value = calculate(root->root);

    /// delete
    remove_all_tree_nodes(root);
    return value;
}

/** \brief
 * push data in the stack with the method of post-fix
 * calculate addition and subtraction
 */
void sum()
{
	term();
	Data datum;
	while(token == '+' || token == '-')
	{
		if(token == '+')
		{
			datum.opr = '+';
			CheckAndGetChar('+');
			term();
			push(st, datum, TRUE);
		}
		else if(token == '-')
		{
			datum.opr = '-';
			CheckAndGetChar('-');
			term();
			push(st, datum, TRUE);
		}
	}
}

/** \brief
 * push data in the stack with the method of post-fix
 * calculate multiple and devision
 */
void term()
{
	factor();
	Data datum;
	while(token == '*' || token == '/' || token == '^')
	{
		if(token == '^')
		{
			datum.opr = '^';
			CheckAndGetChar('^');
			factor();
			push(st, datum, TRUE);			
		}
		else if(token == '|')
		{
			datum.opr = '|';
			CheckAndGetChar('|');
			factor();
			push(st, datum, TRUE);			
		}		
		else if(token == '*')
		{
			datum.opr = '*';
			CheckAndGetChar('*');
			factor();
			push(st, datum, TRUE);
		}
		else if(token == '/')
		{
			datum.opr = '/';
			CheckAndGetChar('/');
			factor();
			push(st, datum, TRUE);
		}
	}
}

/** \brief
 * push data in the stack with the method of post-fix
 * regards factor as a number
 */
void factor()
{
	double temp = 0.0;
	Data datum;
	if(token == '(')
	{
		// start with new sum again
		CheckAndGetChar('(');
		sum();
		CheckAndGetChar(')');
	}
//	else if(token == '^')
//	{
//		CheckAndGetChar('^');
//		datum.opr = '^';
//		factor();
//		push(st, datum, TRUE);
//	}
	else if(token == '-')
	{
		// negation
		CheckAndGetChar('-');
		datum.opr = '-';
		factor();
		push(st, datum, TRUE);
	}
	else if(token == '+')
	{
		// there is no meaning, but just exception dealing
		CheckAndGetChar('+');
		factor();
	}
	else if(isdigit(token))
	{
		ungetc(token, stdin);
		scanf("%lf", &temp);
		datum.num = temp;
		push(st, datum, FALSE);
		token = getchar();
	}
	else GotError();
}

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
		printf("Hasil berbentuk format tidak didukung");
		return;
	} else {
		return i;
	}
}

double calculate(TreeNode *current){
	if(current == NULL){
		return;
	}
	double result = calculate(current->left);
	
	if(current->isChar==FALSE){
		return current->data.num;
	}else{
		switch(current->data.opr){
			case '+': result += calculate(current->right); break;
			case '-': result -= calculate(current->right); break;
			case '/': result /= calculate(current->right); break;
			case '*': result *= calculate(current->right); break;
			case '^': result = pow(result,calculate(current->right)); break;
			//case '|': result = squareRoot(result,)
		}
	}
	
	return result;
}
