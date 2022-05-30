#ifndef CONVERSION_H_INCLUDED
#define CONVERSION_H_INCLUDED
#include "Common.h"

/* Convert Fractions to Decimal */
Stack fractionsToDecimal();

/* Convert Decimal to Fractions */
Stack decimalToFractions();

/* Convert Fractions to Percent */
Stack fractionsToPercent(); 

/* Convert Percent to Fractions */
Stack percentToFractions();

/* Convert Decimal to Percent */ 
Stack decimalToPercent(); 

/* Convert Percen to Decimal */
double percentToDecimal();

/* Convert Char to Integer */
int charToInt(char c);

/* Convert Biner to Decimal */
double binerToDecimal();

/* Convert Biner to Octal */
Stack binerToOctal();

/* Convert Biner to Hexadecimal */
Stack binerToHexa();

/* Convert Decimal to Biner */
Stack decimalToBiner(int decimal);

/* Convert Decimal to Octal */
Stack decimalToOctal(int decimal);

/* Convert Decimal to Hexadecimal */
Stack decimalToHexa(int decimal);

/* Convert Octal to Biner */
Stack octalToBiner();

/* Convert Octal to Decimal */
double octalToDecimal();

/* Convert Octal to Hexadecimal */
Stack octalToHexa();

/* Convert Hexadecimal to Biner */
Stack hexaToBiner();

/* Convert Hexadecimal to Decimal */
double hexaToDecimal();

/* Convert Hexadecimal to Octal */
Stack hexaToOctal();

//============================
//		  TEMPERATURE
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
