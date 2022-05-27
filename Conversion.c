#include "Stack.h"
#include <math.h>

/* Convert Char to Integer */
int charToInt(char c){
	int num = 0;

	//Mengurangi char dengan nilai ascii '0'
	num = c - '0';

	return num;
}

/*** Convert Biner to Decimal ***/
double binerToDecimal(){
	
	// Kamus Data
	double result, decimal;
	char tokenBiner;
	Data biner; 
	int i;
	Stack *s;
	
	// Inisialisasi Variabel
	s = make_stack();
	result = 0;
	i = 0;
	tokenBiner = getchar();
	
	// Input to stack
	while(tokenBiner != '\n'){
		biner.num = charToInt(tokenBiner);
		push(s, biner, FALSE);
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
		push(result, mod, FALSE);
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
		push(result, mod, FALSE);
		decimal = decimal / 8;
	}
	//print_stack_node((*result).topNode);
	return *result;	
}

/* Convert Biner to Octal */
Stack binerToOctal(){
	
	//Kamus Data
	Stack result;
	double decimal;
	
	//Algoritma
	decimal = binerToDecimal();
	result = decimalToOctal(decimal);
	return result;
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
			push(result, mod, TRUE);
		} else if (decimal % 16 == 11){
			mod.opr = 'B';
			push(result, mod, TRUE);
		} else if (decimal % 16 == 12){
			mod.opr = 'C';
			push(result, mod, TRUE);
		} else if (decimal % 16 == 13){
			mod.opr = 'D';
			push(result, mod, TRUE);
		} else if (decimal % 16 == 14){
			mod.opr = 'E';
			push(result, mod, TRUE);
		} else if (decimal % 16 == 15){
			mod.opr = 'F';
			push(result, mod, TRUE);
		} else {
			mod.num = decimal % 16;
			push(result, mod, FALSE);
		}		
		decimal = decimal / 16;
	}
	return *result;	
}

/*** Convert Biner to Hexadecimal ***/
Stack binerToHexa(){
	
	// Kamus Data
	Stack result;
	double decimal;
	
	//Algoritma
	decimal = binerToDecimal();
	result = decimalToHexa(decimal);
	return result;
}

/*** Convert Octal to Decimal ***/
double octalToDecimal(){
	
	// Kamus Data
	double result, decimal;
	char tokenOctal;
	Data octal; 
	int i;
	Stack *s;
	
	// Inisialisasi Variabel
	s = make_stack();
	result = 0;
	i = 0;
	tokenOctal = getchar();
	
	// Input to stack
	while(tokenOctal != '\n'){
		octal.num = charToInt(tokenOctal);
		push(s, octal, FALSE);
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
Stack octalToBiner(){
	
	// Kamus Data
	Stack result;
	double decimal;
	
	// Algoritma
	decimal = octalToDecimal();
	result = decimalToBiner(decimal);
	return result;
}

/*** Convert Octal to Hexadecimal ***/
Stack octalToHexa(){
	
	// Kamus Data
	Stack result;
	double decimal;
	
	// Algoritma
	decimal = octalToDecimal();
	result = decimalToHexa(decimal);
	return result;
}

/*** Convert Hexadecimal to Decimal ***/
double hexaToDecimal(){
	
	// Kamus Data
	double result, decimal;
	char tokenHexa;
	Data hexa; 
	int i;
	Stack *s;
	
	// Inisialisasi Variabel
	s = make_stack();
	result = 0;
	i = 0;
	tokenHexa = getchar();
	
	// Input to stack
	while(tokenHexa != '\n'){
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
		push(s, hexa, FALSE);
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
Stack hexaToBiner(){
	
	// Kamus Data
	Stack result;
	double decimal;
	
	// Algoritma
	decimal = hexaToDecimal();
	result = decimalToBiner(decimal);
	return result;
}

/*** Convert Hexadecimal to Octal ***/
Stack hexaToOctal(){
	
	// Kamus Data
	Stack result;
	double decimal;
	
	// Algoritma
	decimal = hexaToDecimal();
	result = decimalToOctal(decimal);
	return result;
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