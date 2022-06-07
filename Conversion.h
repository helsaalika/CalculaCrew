#ifndef CONVERSION_H_INCLUDED
#define CONVERSION_H_INCLUDED
#include "Common.h"

/* Convert Char to Integer */
// PIC : Aini
int charToInt(char c);

//=============================
// DECIMAL, FRACTION, PERCENT
//=============================
// PIC : Helsa
//=============================

/* Check fractions is simplest*/
int isSimplest(int numerator, int denominator);
void simplify(int *numerator, int *denominator);

/* Convert Fractions to Decimal */
double fractionsToDecimal();

/* Convert Decimal to Fractions */
Stack decimalToFractions(double decimal);

/* Convert Fractions to Percent */
Stack fractionsToPercent(); 

/* Convert Percent to Fractions */
Stack percentToFractions(double percentage);

/* Convert Decimal to Percent */ 
Stack decimalToPercent(double percent); 

/* Convert Percen to Decimal */
double percentToDecimal(double percentage);

//=============================
// DECIMAL, BINARY, OCTAL, HEX
//=============================
// PIC : Aini
//=============================

/* Convert Biner to Decimal */
double binerToDecimal(int *isValid);

/* Convert Biner to Octal */
Stack binerToOctal(int *isValid);

/* Convert Biner to Hexadecimal */
Stack binerToHexa(int *isValid);

/* Convert Decimal to Biner */
Stack decimalToBiner(int decimal);

/* Convert Decimal to Octal */
Stack decimalToOctal(int decimal);

/* Convert Decimal to Hexadecimal */
Stack decimalToHexa(int decimal);

/* Convert Octal to Biner */
Stack octalToBiner(int *isValid);

/* Convert Octal to Decimal */
double octalToDecimal(int *isValid);

/* Convert Octal to Hexadecimal */
Stack octalToHexa(int *isValid);

/* Convert Hexadecimal to Biner */
Stack hexaToBiner(int *isValid);

/* Convert Hexadecimal to Decimal */
double hexaToDecimal(int *isValid);

/* Convert Hexadecimal to Octal */
Stack hexaToOctal(int *isValid);

//============================
//		  TEMPERATURE
//============================
// PIC : Mey
//============================

/* Convert Celsius to Fahrenheit */
double celsiusToFahrenheit(double temp);

/* Convert Celsius to Reamur */
double celsiusToReamur(double temp);

/* Convert Celsius to Kelvin */
double celsiusToKelvin(double temp);

/* Convert Fahrenheit to Celsius */
double fahrenheitToCelsius(double temp);

/* Convert Fahrenheit to Reamur */
double fahrenheitToReamur(double temp);

/* Convert Fahrenheit to Kelvin */
double fahrenheitToKelvin(double temp);

/* Convert Reamur to Celsius */
double reamurToCelsius(double temp);

/* Convert Reamur to Fahrenheit */
double reamurToFahrenheit(double temp);

/* Convert Reamur to Kelvin */
double reamurToKelvin(double temp);

/* Convert Kelvin to Celsius */
double kelvinToCelsius(double temp);

/* Convert Kelvin to Fahrenheit */
double kelvinToFahrenheit(double temp);

/* Convert Kelvin to Reamur */
double kelvinToReamur(double temp);

#endif
