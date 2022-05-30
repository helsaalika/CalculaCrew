#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include "Common.h"
#include "boolean.h"
#include <ctype.h> // for 'isdigit()'
#include <math.h>
#include "Tree.h"
#include "Stack.h"

void GotError();

void CheckAndGetChar(char tmp);
void term();
void sum();
void factor();
double calculate(TreeNode *current);

/** main function
 *
 */
double mainCalculator();

/** \brief
 * push data in the stack with the method of post-fix
 * calculate addition and subtraction
 */
void sum();

/** \brief
 * push data in the stack with the method of post-fix
 * calculate multiple and devision
 */
void term();

/** \brief
 * push data in the stack with the method of post-fix
 * regards factor as a number
 */
void factor();

int squareRoot(int base, int exp);

double calculate(TreeNode *current);

// ===================
//       HISTORY
// ===================
/* add new data line to file history.txt */
void addHistory(char* data);

/* read file history.txt and print data on console */
void printHistory();

#endif // CALCULATOR_H_INCLUDED
