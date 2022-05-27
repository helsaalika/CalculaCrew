#ifndef CONVERSION_H_INCLUDED
#define CONVERSION_H_INCLUDED

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

#endif
