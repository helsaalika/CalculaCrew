#include "Stack.h"
#include "Conversion.h"
#include "Common.h"
#include "Calculator.h"
#include <math.h>

/* Convert Char to Integer */
int charToInt(char c){
	int num = 0;

	//Mengurangi char dengan nilai ascii '0'
	num = c - '0';

	return num;
}

/* Convert Fractions to Decimal */
double fractionsToDecimal(){
	int isQuit, isError;
	double result = mainCalculator(0,0,0);
	return result;
}

/* Convert Decimal to Fractions */
Stack decimalToFractions(double decimal){
	//kamus data
	Stack *S;
	Data result, result2, result3;
	int numerator, denominator;
	
	//Inisialisasi Variabel
	S = make_stack();
	
	//algoritma
	denominator = 10000;
	
	//convert double to int
	numerator = (int)floor(decimal) * denominator + (int)(((decimal - floor(decimal))* denominator) + .5f);
	
	while(true){
		if(numerator%10==0){
			numerator=numerator/10;
			denominator=denominator/10;
		}else{
			break;
		}
	}
	
	if(isSimplest(numerator,denominator) != 0){
		simplify(&numerator,&denominator);
	}
	
	result3.num = denominator;
	push(S,result3,false);
	result2.opr = '/';
	push(S, result2, true);
	result.num = numerator;
	push(S, result, false);
	
	//print_stack_node((*result).topNode);
	return *S;
}

/* Check fractions is Simplest*/
int isSimplest(int numerator, int denominator){
	int i,factor=0;
	
	for(i = 1; i<=numerator && i<= denominator; i++){
		if(numerator % i == 0 && denominator % i == 0 ){
			factor = factor + 1;
		}
	}
	
	return factor;
}

void simplify(int *numerator, int *denominator){
	int i;
	
	for(i = 2; i<=*numerator && i<=*denominator; i++){
		if(*numerator % i == 0 && *denominator % i == 0 ){
			*numerator = *numerator/i;
			*denominator = *denominator/i;
		}
	}
}

/* Convert Fractions to Percent */
Stack fractionsToPercent(){
	//kamus data
	Stack *S;
	Data result, result2;
	
	//Inisialisasi Variabel
	S = make_stack();
	
	//algoritma
	result.num = fractionsToDecimal() * 100;
	result2.opr = '%';
	
	push(S, result2, true);
	push(S, result, false);
	
	//print_stack_node((*result).topNode);
	return *S;
}

/* Convert Percent to Fractions */
Stack percentToFractions(double percentage){
	//kamus data
	Stack *S;
	Data result, result2, result3;
	
	//Inisialisasi Variabel
	S = make_stack();
	
	//algoritma
	result3.num = 100;
	push(S, result3, false);
	result2.opr = '/';
	push(S, result2, true);
	result.num = percentage;
	push(S, result, false);
	
	//print_stack_node((*result).topNode);
	return *S;
}

/* Convert Decimal to Percent */
Stack decimalToPercent(double decimal){
	// Kamus Data
	Stack *S;
	Data result, result2;
	
	//Inisialisasi Variabel
	S = make_stack();
	
	//Algoritma
	result2.opr = '%';
	push(S, result2, true);
	result.num = decimal * 100;
	push(S, result, false);

	
	//print_stack_node((*result).topNode);
	return *S;	
}

/* Convert Percen to Decimal */
double percentToDecimal(double percentage){
	//kamus data
	double result;
	
	//algoritma	
	result = percentage / 100;
	return result;
}

/*** Convert Biner to Decimal ***/
double binerToDecimal(int *isValid){
	
	// Kamus Data
	double result, decimal;
	char tokenBiner, space;
	Data biner; 
	int i;
	Stack *s;
	
	// Inisialisasi Variabel
	s = make_stack();
	result = 0;
	i = 0;
	space = getchar();
	tokenBiner = getchar();
	
	// Input to stack
	while(tokenBiner != '\n'){
		if(tokenBiner == '0' || tokenBiner == '1'){
			biner.num = charToInt(tokenBiner);
			push(s, biner, false);			
		} else {
			*isValid = 0;
		}
		tokenBiner = getchar();
	}
	
	// Pop stack dan hitung
	while(!isEmpty_stack(s)){
		decimal = (pop(s).data.num);
		result = result + (decimal * pow(2,i));
		i++ ;
	}
	return result;
}

/*** Convert Decimal to Biner ***/
Stack decimalToBiner(int decimal){
	
	// Kamus Data
	Stack *result;
	Data mod;
	
	//Inisialisasi Variabel
	result = make_stack();
	
	//Algoritma
	while(decimal != 0){
		mod.num = decimal % 2;
		push(result, mod, false);
		decimal = decimal / 2;
	}
	//print_stack_node((*result).topNode);
	return *result;
}

/*** Convert Decimal to Octal ***/
Stack decimalToOctal(int decimal){
	
	// Kamus Data
	Stack *result;
	Data mod;
	
	//Inisialisasi Variabel
	result = make_stack();
	
	//Algoritma
	while(decimal != 0){
		mod.num = decimal % 8;
		push(result, mod, false);
		decimal = decimal / 8;
	}
	//print_stack_node((*result).topNode);
	return *result;	
}

/* Convert Biner to Octal */
Stack binerToOctal(int *isValid){
	
	//Kamus Data
	Stack result;
	double decimal;
	
	//Algoritma
	decimal = binerToDecimal(&(*isValid));
	if(*isValid == 1){
		result = decimalToOctal(decimal);
		return result;
	}
	else {
		return;
	}
}

/*** Convert Decimal to Hexadecimal ***/
Stack decimalToHexa(int decimal){
	
	// Kamus Data
	Stack *result;
	Data mod;
	
	//Inisialisasi Variabel
	result = make_stack();
	
	//Algoritma
	while(decimal != 0){
		if(decimal % 16 == 10){
			mod.opr = 'A';
			push(result, mod, true);
		} else if (decimal % 16 == 11){
			mod.opr = 'B';
			push(result, mod, true);
		} else if (decimal % 16 == 12){
			mod.opr = 'C';
			push(result, mod, true);
		} else if (decimal % 16 == 13){
			mod.opr = 'D';
			push(result, mod, true);
		} else if (decimal % 16 == 14){
			mod.opr = 'E';
			push(result, mod, true);
		} else if (decimal % 16 == 15){
			mod.opr = 'F';
			push(result, mod, true);
		} else {
			mod.num = decimal % 16;
			push(result, mod, false);
		}		
		decimal = decimal / 16;
	}
	return *result;	
}

/*** Convert Biner to Hexadecimal ***/
Stack binerToHexa(int *isValid){
	
	// Kamus Data
	Stack result;
	double decimal;
	
	//Algoritma
	decimal = binerToDecimal(&(*isValid));
	if(*isValid == 1){
		result = decimalToHexa(decimal);
		return result;		
	}
	else {
		return;
	}
}

/*** Convert Octal to Decimal ***/
double octalToDecimal(int *isValid){
	
	// Kamus Data
	double result, decimal;
	char tokenOctal, space;
	Data octal; 
	int i;
	Stack *s;
	
	// Inisialisasi Variabel
	s = make_stack();
	result = 0;
	i = 0;
	space = getchar();
	tokenOctal = getchar();
	
	// Input to stack
	while(tokenOctal != '\n'){
		if(tokenOctal=='0'||tokenOctal=='1'||tokenOctal=='2'||tokenOctal=='3'||tokenOctal=='4'||tokenOctal=='5'||tokenOctal=='6'||tokenOctal=='7'){
			octal.num = charToInt(tokenOctal);
			push(s, octal, false);
		} else {
			*isValid = 0;
		}
		tokenOctal = getchar();
	}
	
	// Pop stack dan hitung
	while(!isEmpty_stack(s)){
		decimal = (pop(s).data.num);
		result = result + (decimal * pow(8,i));
		i++ ;
	}
	return result;	
}

/*** Convert Octal to Biner ***/
Stack octalToBiner(int *isValid){
	
	// Kamus Data
	Stack result;
	double decimal;
	
	// Algoritma
	decimal = octalToDecimal(&(*isValid));
	if(*isValid == 1){
		result = decimalToBiner(decimal);
		return result;
	} else {
		return;
	}
}

/*** Convert Octal to Hexadecimal ***/
Stack octalToHexa(int *isValid){
	
	// Kamus Data
	Stack result;
	double decimal;
	
	// Algoritma
	decimal = octalToDecimal(&(*isValid));	
	if(*isValid == 1){
		result = decimalToHexa(decimal);
		return result;		
	} else {
		return;
	}

}

/*** Convert Hexadecimal to Decimal ***/
double hexaToDecimal(int *isValid){
	
	// Kamus Data
	double result, decimal;
	char tokenHexa, space;
	Data hexa; 
	int i;
	Stack *s;
	
	// Inisialisasi Variabel
	s = make_stack();
	result = 0;
	i = 0;
	space = getchar();
	tokenHexa = getchar();
	
	// Input to stack
	while(tokenHexa != '\n'){
		if(tokenHexa=='0'||tokenHexa=='1'||tokenHexa=='2'||tokenHexa=='3'||tokenHexa=='4'||tokenHexa=='5'||tokenHexa=='6'||tokenHexa=='7'||tokenHexa=='8'||tokenHexa=='9'||tokenHexa=='a'||tokenHexa=='A'||tokenHexa=='b'||tokenHexa=='B'||tokenHexa=='c'||tokenHexa=='C'||tokenHexa=='d'||tokenHexa=='D'||tokenHexa=='e'||tokenHexa=='E'||tokenHexa=='f'||tokenHexa=='F'){
			if(tokenHexa == 'A' || tokenHexa == 'a'){
				hexa.num = 10;
			} else if (tokenHexa == 'B' || tokenHexa == 'b'){
				hexa.num = 11;
			} else if (tokenHexa == 'C' || tokenHexa == 'c'){
				hexa.num = 12;
			} else if (tokenHexa == 'D' || tokenHexa == 'd'){
				hexa.num = 13;
			} else if (tokenHexa == 'E' || tokenHexa == 'e'){
				hexa.num = 14;
			} else if (tokenHexa == 'F' || tokenHexa == 'f'){
				hexa.num = 15;
			} else {
				hexa.num = charToInt(tokenHexa);
			}
			push(s, hexa, false);			
		} else {
			*isValid = 0;
		}
		tokenHexa = getchar();
	}
	
	// Pop stack dan hitung
	while(!isEmpty_stack(s)){
		decimal = (pop(s).data.num);
		result = result + (decimal * pow(16,i));
		i++ ;
	}
	return result;	
}

/*** Convert Hexadecimal to Biner ***/
Stack hexaToBiner(int *isValid){
	
	// Kamus Data
	Stack result;
	double decimal;
	
	// Algoritma
	decimal = hexaToDecimal(&(*isValid));
	if(*isValid == 1){
		result = decimalToBiner(decimal);
		return result;		
	} else {
		return;
	}
}

/*** Convert Hexadecimal to Octal ***/
Stack hexaToOctal(int *isValid){
	
	// Kamus Data
	Stack result;
	double decimal;
	
	// Algoritma
	decimal = hexaToDecimal(&(*isValid));
	if(*isValid == 1){
		result = decimalToOctal(decimal);
		return result;		
	} else {
		return ;
	}

}

//============================
//		  TEMPERATURE
//============================

/** Convert Celsius to Fahrenheit **/
double celsiusToFahrenheit(double temp){
	double result;
	
	result = (9 * temp) / 5 + 32;
	
	return result;
}

/** Convert Celsius to Reamur **/
double celsiusToReamur(double temp){
	double result;
	
	result = (4 * temp)/5;
	
	return result;
}

/** Convert Celsius to Kelvin **/
double celsiusToKelvin(double temp){
	double result;
	
	result = temp + 273;
	
	return result;
}

/** Convert Fahrenheit to Celsius **/
double fahrenheitToCelsius(double temp){
	double result;
	
	result = 5 * (temp - 32)/9;
	
	return result;
}

/** Convert Fahrenheit to Reamur **/
double fahrenheitToReamur(double temp){
	double result;
	
	result = 4 * (temp - 32)/9;
	
	return result;
}

/** Convert Fahrenheit to Kelvin **/
double fahrenheitToKelvin(double temp){
	double result;
	
	result = fahrenheitToCelsius(temp);
	result = celsiusToKelvin(result);
	
	return result;
}

/** Convert Reamur to Celsius **/
double reamurToCelsius(double temp){
	double result;
	
	result = (5 * temp)/4;
	
	return result;
}

/** Convert Reamur to Fahrenheit **/
double reamurToFahrenheit(double temp){
	double result;
	
	result = (9 * temp)/4 + 32;
	
	return result;
}

/** Convert Reamur to Kelvin **/
double reamurToKelvin(double temp){
	double result;
	
	result = reamurToCelsius(temp);
	result = celsiusToKelvin(result);
	
	return result;
}

/** Convert Kelvin to Celsius **/
double kelvinToCelsius(double temp){
	double result;
	
	result = temp - 273;
	
	return result;
}

/** Convert Kelvin to Fahrenheit **/
double kelvinToFahrenheit(double temp){
	double result;
	
	result = kelvinToCelsius(temp);
	result = celsiusToFahrenheit(result);
	
	return result;
}

/** Convert Kelvin to Reamur **/
double kelvinToReamur(double temp){
	double result;
	
	result = kelvinToCelsius(temp);
	result = celsiusToReamur(result);
	
	return result;
}
