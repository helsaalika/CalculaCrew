#include<stdio.h>
#include "Calculator.h"
#include "Conversion.h"
#include "Stack.h"
#include <windows.h>
#include <stdlib.h>

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int menu(){
		
	int no_menu;
	
	system("cls");
	printf("\n");
	gotoxy(5,2); printf("+$$$$$$$  +$$$$$+  $$      +$$$$$$$  $$    $$  $$      +$$$$$+\n");
	gotoxy(5,3); printf("$$        $$   $$  $$      $$        $$    $$  $$      $$   $$\n");
	gotoxy(5,4); printf("$$        $$$$$$$  $$      $$        $$    $$  $$      $$$$$$$\n");
	gotoxy(5,5); printf("$$        $$   $$  $$      $$        $$    $$  $$      $$   $$\n");
	gotoxy(5,6); printf("+$$$$$$$  $$   $$  +$$$$$  +$$$$$$$  +$$$$$$+  +$$$$$  $$   $$\n");
	printf("\n");
	printf("\n");
	gotoxy(14,9); printf("+$$$$$$$  $$$$$$$+   +$$$$$$  $$            $$\n");
	gotoxy(14,10);printf("$$        $$      $  $$        $$          $$ \n");
	gotoxy(14,11);printf("$$        $$$$$$$+   $$$$       $$   $$   $$  \n");
	gotoxy(14,12);printf("$$        $$   $$    $$          $$ $$$$ $$   \n");
	gotoxy(14,13);printf("+$$$$$$$  $$    $$   +$$$$$$      $$$  $$$    \n");
	printf("\n");
	printf("\n");
	gotoxy(1,16); printf("----------------------------------------------------------------------------\n");
	printf("\n");
	gotoxy(23,18); printf("C  A  L  C  U  L  A  T  O  R\n");
	printf("\n");
	gotoxy(26,20);printf("1. General Calculator\n");
	gotoxy(26,21);printf("2. Number Conversion\n");
	gotoxy(26,22);printf("3. Temperature Conversion");
	gotoxy(26,23);printf("4. History");
	printf("\n");
	gotoxy(28,25);printf("type your choice ..");
	gotoxy(30,26);printf("  ----- ");
	gotoxy(31,27);printf("[");
	gotoxy(37,27);printf("]");
	gotoxy(30,28);printf("  ----- ");
	gotoxy(34,27); scanf("%d", &no_menu);
	printf("\n");
	
	return no_menu;
}

void generalCalculator(boolean *isQuit){
	
	double result;
	
	system("cls");
	printf("\n");
	printf("                               G E N E R A L  C A L C U L A T O R \n");
	printf("               --------------------------------------------------------------------\n");
	printf("\n");
	printf("\n");
	printf("   +===================================================+\n");
	printf("   | User Input ..                                     |\n");
	printf("   |   ---------------------------------------------   |\n");
	printf("   |  [                                             ]  |\n");
	printf("   |   ---------------------------------------------   |     +===========================+\n");
	printf("   |                                                   |     |      SIMBOL CONDITION     |\n");
	printf("   | Result ..                                         |     +===========================+\n");
	printf("   |   ---------------------------------------------   |     |  '+'  =  Summation        |\n");
	printf("   |  [                                             ]  |     |  '-'  =  Subtraction      |\n");
	printf("   |   ---------------------------------------------   |     |  '*'  =  Multiplication   |\n");
	printf("   |                                                   |     |  '/'  =  Distribution     |\n");
	printf("   |     +-------+  +-------+  +-------+  +-------+    |     |  '%%'  =  Modulus          |\n");
	printf("   |     |   R   |  |       |  |   %%   |  |   /   |    |     |  'R'  =  Reset            |\n");
	printf("   |     +-------+  +-------+  +-------+  +-------+    |     |  'Q'  = Quit              |\n");
	printf("   |     +-------+  +-------+  +-------+  +-------+    |     +===========================+\n");
	printf("   |     |   7   |  |   8   |  |   9   |  |   *   |    |\n");
	printf("   |     +-------+  +-------+  +-------+  +-------+    |\n");
	printf("   |     +-------+  +-------+  +-------+  +-------+    |\n");
	printf("   |     |   4   |  |   5   |  |   6   |  |   +   |    |\n");
	printf("   |     +-------+  +-------+  +-------+  +-------+    |      * Enter 1 kali untuk menampilkan hasil\n");
	printf("   |     +-------+  +-------+  +-------+  +-------+    |      * Enter 2 kali untuk mengulang\n");
	printf("   |     |   1   |  |   2   |  |   3   |  |   -   |    |      * Ketik 'Q' untuk keluar (Setelah melakukan operasi)\n");
	printf("   |     +-------+  +-------+  +-------+  +-------+    |\n");
	printf("   |     +-------+  +-------+  +-------+  +-------+    |\n");
	printf("   |     |   Q   |  |   0   |  |   .   |  |   =   |    |\n");
	printf("   |     +-------+  +-------+  +-------+  +-------+    |\n");
	printf("   |                                                   |\n");
	printf("   +===================================================+\n");
	gotoxy(8,8); result = mainCalculator();
	gotoxy(8,13); printf("%g", result);
	char enter,option;
	gotoxy(7,15);option = getchar();
	enter = getchar();
	if(option == 'q' || option == 'Q'){
		*isQuit = true;
	}
	ungetc(enter, stdin);
}

int menuTemperatureConversion(){
	
	int no_menu;
	
	system("cls");
	
	printf("\n");
	printf("                              T e m p e r a t u r e  C o n v e r s i o n \n");
	printf("               --------------------------------------------------------------------\n");
	printf("\n");
	printf("                                   Choose What You Want to Convert\n");
	printf("                                      1. Celcius to Fehrenheit\n");
	printf("                                      2. Fahrenheit to Celcius\n");
	printf("                                      3. Celcius to Reamur\n");
	printf("                                      4. Reamur to Celcius\n");
	printf("                                      5. Celcius to Kelvin\n");
	printf("                                      6. Kelvin to Celcius\n");
	printf("                                      7. Fahrenheit to Reamur\n");
	printf("                                      8. Reamur to Fahrenheit\n");
	printf("                                      9. Fahrenheit to Kelvin\n");
	printf("                                     10. Kelvin to Fahrenheit\n");
	printf("                                     11. Reamur to Kelvin\n");
	printf("                                     12. Kelvin to Reamur\n");
	printf("\n");
	gotoxy(39,18);printf("type your choice ..");
	gotoxy(43,19);printf("  ----- ");
	gotoxy(44,20);printf("[");
	gotoxy(50,20);printf("]");
	gotoxy(43,21);printf("  ----- ");
	gotoxy(47,20); scanf("%d", &no_menu);
	printf("\n");
	
	return no_menu;
}

void temperatureConversion(boolean *isQuit){
	int menu_temperature = menuTemperatureConversion();
	double user_input, result;
	
	system("cls");
	printf("\n");
	printf("                              T e m p e r a t u r e  C o n v e r s i o n \n");
	printf("               --------------------------------------------------------------------\n");
	printf("\n");
	printf("\n");
	switch(menu_temperature){
		case 1 : 
			printf("                                         Celcius to Fahrenhit\n"); break;
		case 2 :
			printf("                                         Fahrenheit to Celcius\n"); break;
		case 3 :
			printf("                                         Celcius to Reamur\n"); break;
		case 4 :
			printf("                                         Reamur to Celcius\n"); break;
		case 5 :
			printf("                                         Celcius to Kelvin\n"); break;
		case 6 :
			printf("                                         Kelvin to Celcius\n"); break;
		case 7 :
			printf("                                         Fahrenheit to Reamur\n"); break;
		case 8 :
			printf("                                         Reamur to Fahrenheit\n"); break;
		case 9 :
			printf("                                         Fahrenheit to Kelvin\n"); break;
		case 10 :
			printf("                                         Kelvin to Fahrenheit\n"); break;
		case 11 :
			printf("                                         Reamur to Kelvin\n"); break;
		case 12 :
			printf("                                         Kelvin to Reamur\n"); break;
	}
	printf("                        +===================================================+\n");
	printf("                        | User Input ..                                     |\n");
	printf("                        |   ---------------------------------------------   |\n");
	printf("                        |  [                                             ]  |\n");
	printf("                        |   ---------------------------------------------   |\n");
	printf("                        |                                                   |\n");
	printf("                        | Result ..                                         |\n");
	printf("                        |   ---------------------------------------------   |\n");
	printf("                        |  [                                             ]  |\n");
	printf("                        |   ---------------------------------------------   |\n");
	printf("                        |                                                   |\n");
	printf("                        +===================================================+\n");
	gotoxy(29,9);scanf("%lf", &user_input);
	switch(menu_temperature){
		case 1 : 
			result = celsiusToFahrenheit(user_input); break;
		case 2 :
			result = fahrenheitToCelsius(user_input); break;
		case 3 :
			result = celsiusToReamur(user_input); break;
		case 4 :
			result = reamurToCelsius(user_input); break;
		case 5 :
			result = celsiusToKelvin(user_input); break;
		case 6 :
			result = kelvinToCelsius(user_input); break;
		case 7 :
			result = fahrenheitToReamur(user_input); break;
		case 8 :
			result = reamurToFahrenheit(user_input); break;
		case 9 :
			result = fahrenheitToKelvin(user_input); break;
		case 10 :
			result = kelvinToFahrenheit(user_input); break;
		case 11 :
			result = reamurToKelvin(user_input); break;
		case 12 :
			result = kelvinToReamur(user_input); break;
	}
	gotoxy(29,14);printf("%g", result);
	char enter,option;
	gotoxy(7,15);option = getchar();
	enter = getchar();
	if(option == 'q' || option == 'Q'){
		*isQuit = true;
	}
	ungetc(enter, stdin);
}

int menuNumberConversion(){
	int no_menu;
	
	system("cls");
	
	printf("\n");
	printf("                                   N u m b e r  C o n v e r s i o n \n");
	printf("               --------------------------------------------------------------------\n");
	printf("\n");
	printf("                                   Choose What You Want to Convert\n");
	printf("                                      1. Fractions to Decimal (program belum berjalan) \n");
	printf("                                      2. Decimal to Fractions (program belum berjalan)\n");
	printf("                                      3. Fractions to Percent (program belum berjalan)\n");
	printf("                                      4. Percent to Fractions (program belum berjalan)\n");
	printf("                                      5. Decimal to Percent\n");
	printf("                                      6. Percent to Decimal\n");
	printf("                                      7. Binary to Decimal\n");
	printf("                                      8. Binary to Octal\n");
	printf("                                      9. Binary to HexaDecimal\n");
	printf("                                     10. Decimal to Binary\n");
	printf("                                     11. Decimal to Octal\n");
	printf("                                     12. Decimal to HexaDecimal\n");
	printf("                                     13. Octal to Binary\n");
	printf("                                     14. Octal to Decimal\n");
	printf("                                     15. Octal to HexaDecimal\n");
	printf("                                     16. HexaDecimal ke Binary\n");
	printf("                                     17. HexaDecimal ke Decimal\n");
	printf("                                     18. HexaDecimal ke Octal\n");
	printf("\n");
	gotoxy(39,24);printf("type your choice ..");
	gotoxy(43,25);printf("  ----- ");
	gotoxy(44,26);printf("[");
	gotoxy(50,26);printf("]");
	gotoxy(43,27);printf("  ----- ");
	gotoxy(47,26); scanf("%d", &no_menu);
	
	return no_menu;
}

void numberConversion(boolean *isQuit){
	int menu_number = menuNumberConversion();
	double user_input, result;
	Stack S;
	
	system("cls");
	printf("\n");
	printf("                                   N u m b e r  C o n v e r s i o n \n");
	printf("               --------------------------------------------------------------------\n");
	printf("\n");
	printf("\n");
	switch(menu_number){
		case 1 : 
			printf("                                         Fractions to Decimal\n"); break;
		case 2 :
			printf("                                         Decimal to Fractions\n"); break;
		case 3 :
			printf("                                         Fractions to Percent\n"); break;
		case 4 :
			printf("                                         Percent to Fractions\n"); break;
		case 5 :
			printf("                                         Decimal to Percent\n"); break;
		case 6 :
			printf("                                         Percent to Decimal\n"); break;
		case 7 :
			printf("                                         Binary to Decimal\n"); break;
		case 8 :
			printf("                                         Binary to Octal\n"); break;
		case 9 :
			printf("                                         Binary to HexaDecimal\n"); break;
		case 10 :
			printf("                                         Decimal to Binary\n"); break;
		case 11 :
			printf("                                         Decimal to Octal\n"); break;
		case 12 :
			printf("                                         Decimal to HexaDecimal\n"); break;
		case 13 :
			printf("                                         Octal to Binary\n"); break;
		case 14 :
			printf("                                         Octal to Decimal\n"); break;
		case 15 :
			printf("                                         Octal to HexaDecimal\n"); break;
		case 16 :
			printf("                                         HexaDecimal ke Binary\n"); break;
		case 17 :
			printf("                                         HexaDecimal ke Decimal\n"); break;
		case 18 :
			printf("                                         HexaDecimal ke Octal\n"); break;
	}
	printf("                        +===================================================+\n");
	printf("                        | User Input ..                                     |\n");
	printf("                        |   ---------------------------------------------   |\n");
	printf("                        |  [                                             ]  |\n");
	printf("                        |   ---------------------------------------------   |\n");
	printf("                        |                                                   |\n");
	printf("                        | Result ..                                         |\n");
	printf("                        |   ---------------------------------------------   |\n");
	printf("                        |  [                                             ]  |\n");
	printf("                        |   ---------------------------------------------   |\n");
	printf("                        |                                                   |\n");
	printf("                        +===================================================+\n");
	
	switch(menu_number){
		case 1 : 
			gotoxy(29,9);
			double decimal;
			char space = getchar(), ambil = getchar();
			Data token;
			Stack *st;
			st = make_stack(); 
			while(ambil != '\n'){
				token.opr = ambil;
				push(st, token, true);
				ambil = getchar();
			}
			
			decimal = fractionsToDecimal(st); 
			gotoxy(29,14); printf("%f", decimal);
			break;
		case 2 :
			gotoxy(29,9);scanf("%lf", &user_input);
			gotoxy(29,9);S = decimalToFractions(user_input); 
			gotoxy(29,14); print_stack_node((S).topNode);
			break;
		case 3 :
			gotoxy(29,9);S = fractionsToPercent(); 
			gotoxy(29,14); print_stack_node((S).topNode); 
			break;
		case 4 :
			gotoxy(29,9);scanf("%lf", &user_input);
			gotoxy(29,9);S = percentToFractions(user_input); 
			gotoxy(29,14); print_stack_node((S).topNode);
			break;
		case 5 :
			gotoxy(29,9);scanf("%lf", &user_input);
			gotoxy(29,9);S = decimalToPercent(user_input); 
			gotoxy(29,14); print_stack_node((S).topNode);  
			break;
		case 6 :
			gotoxy(29,9);scanf("%lf", &user_input);
			gotoxy(29,9);result = percentToDecimal(user_input); 
			gotoxy(29,14);printf("%lf", result); 
			break;
		case 7 :
			gotoxy(29,9);scanf("%lf", &user_input);
			gotoxy(29,9);result = binerToDecimal(); 
			gotoxy(29,14);printf("%lf", result); 
			break;
		case 8 :
			gotoxy(29,9);scanf("%lf", &user_input);
			S = binerToOctal(); 
			gotoxy(29,14); print_stack_node((S).topNode);
			break;
		case 9 :
			gotoxy(29,9);scanf("%lf", &user_input);
			S = binerToHexa(); 
			gotoxy(29,14); print_stack_node((S).topNode);
			break;
		case 10 :
			gotoxy(29,9); scanf("%lf", &user_input); 
			S = decimalToBiner(user_input); 
			gotoxy(29,14); print_stack_node((S).topNode);
			break;
		case 11 :
			gotoxy(29,9); scanf("%lf", &user_input); 
			S = decimalToOctal(user_input); 
			gotoxy(29,14); print_stack_node((S).topNode);
			break;
		case 12 :
			gotoxy(29,9); scanf("%lf", &user_input); 
			S = decimalToHexa(user_input); 
			gotoxy(29,14); print_stack_node((S).topNode);
			break;
		case 13 :
			gotoxy(29,9);scanf("%lf", &user_input);
			S = octalToBiner(); 
			gotoxy(29,14); print_stack_node((S).topNode);
			break;
		case 14 :
			gotoxy(29,9);scanf("%lf", &user_input);
			gotoxy(29,9);result = octalToDecimal(); 
			gotoxy(29,14);printf("%lf", result); 
			break;
		case 15 :
			gotoxy(29,9);scanf("%lf", &user_input);
			S = octalToHexa(); 
			gotoxy(29,14); print_stack_node((S).topNode);
			break;
		case 16 :
			gotoxy(29,9);scanf("%lf", &user_input);
			S = hexaToBiner(); 
			gotoxy(29,14); print_stack_node((S).topNode);
			break;
		case 17 :
			gotoxy(29,9);scanf("%lf", &user_input);
			gotoxy(29,9);result = hexaToDecimal(); 
			gotoxy(29,14);printf("%lf", result); 
			break;
		case 18 :
			gotoxy(29,9);scanf("%lf", &user_input);
			S = hexaToOctal(); 
			gotoxy(29,14); print_stack_node((S).topNode);
			break;
	}
	char enter,option;
	gotoxy(7,15);option = getchar();
	enter = getchar();
	if(option == 'q' || option == 'Q'){
		*isQuit = true;
	}
	ungetc(enter, stdin);
}

int main() {
	boolean isQuit;
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),14); 
	int no_menu;
	while(true){
		isQuit = false;
		no_menu = menu();
		if (no_menu == 1){
			while(!isQuit){
				generalCalculator(&isQuit);
			}
		} else if(no_menu == 2){
			while(!isQuit){
				numberConversion(&isQuit);
			}
		} else if(no_menu == 3){
			while(!isQuit){
				temperatureConversion(&isQuit);
			}
		} else {
			//history();
		}		
	}
}
