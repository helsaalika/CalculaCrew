#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include "Common.h"
#include <ctype.h> // for 'isdigit()'
#include <math.h>
#include "Tree.h"
#include "Stack.h"

/* Global Variabel */
char token, space; // variable for reading a character
Root *root;
Stack *st;

// ===================
//    CALCULATION
// ===================

/* Change isError state if there is error token */
// PIC : Mey
void GotError(int *isError);

/* Check if there is error token */
// PIC : Helsa
void CheckAndGetChar(char tmp, int *isError);

/* Calculation with inorder traversal from tree */
// PIC : Mey
double calculate(TreeNode *current);

/* Main control of receive input, calculation, creation of stack and tree */
// PIC : Aini
double mainCalculator();

/* push data in the stack with the method of post-fix
   calculate addition and subtraction */
// PIC : Mey
void sum(int *isQuit, int *isError);

/* push data in the stack with the method of post-fix
   calculate multiple and devision */
// PIC : Helsa
void term(int *isQuit, int *isError);

/* push data in the stack with the method of post-fix
   regards factor as a number */
// PIC : Aini
void factor(int *isQuit, int *isError);

/* Calculation for squareroot */
// PIC : Aini
int squareRoot(int base, int exp);


// ===================
//       HISTORY
// ===================
/* add new data line to file history.txt */
// PIC : Mey
void addHistory(double result);

/* print data to file */
// PIC : Mey
void writeInput(TreeNode *current, FILE *fp);

/* read file history.txt and print data on console */
// PIC : Mey
void printHistory();

#endif // CALCULATOR_H_INCLUDED
