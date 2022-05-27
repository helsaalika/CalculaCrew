#include <stdio.h>
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

void generalCalculator(){
	
	int tes_angka;
	
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
	printf("   |     +-------+  +-------+  +-------+  +-------+    |\n");
	printf("   |     +-------+  +-------+  +-------+  +-------+    |\n");
	printf("   |     |   1   |  |   2   |  |   3   |  |   -   |    |\n");
	printf("   |     +-------+  +-------+  +-------+  +-------+    |\n");
	printf("   |     +-------+  +-------+  +-------+  +-------+    |\n");
	printf("   |     |   Q   |  |   0   |  |   .   |  |   =   |    |\n");
	printf("   |     +-------+  +-------+  +-------+  +-------+    |\n");
	printf("   |                                                   |\n");
	printf("   +===================================================+\n");
	gotoxy(8,8); scanf("%d", &tes_angka);
	gotoxy(8,13); printf("%d", tes_angka);
	
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
	printf("                                      9. Reamur to Fahrenheit\n");
	printf("                                     10. Fahrenheit to Kelvin\n");
	printf("                                     11. Kelvin to Fahrenheit\n");
	printf("                                     12. Reamur to Kelvin\n");
	printf("                                     13. Kelvin to Reamur\n");
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

void temperatureConversion(){
	int menu_temperature = menuTemperatureConversion();
	int user_input;
	
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
	gotoxy(29,9);scanf("%d", &user_input);
	gotoxy(29,14);printf("%d", user_input);
}

int menuNumberConversion(){
	int no_menu;
	
	system("cls");
	
	printf("\n");
	printf("                                   N u m b e r  C o n v e r s i o n \n");
	printf("               --------------------------------------------------------------------\n");
	printf("\n");
	printf("                                   Choose What You Want to Convert\n");
	printf("                                      1. Fractions to Decimal \n");
	printf("                                      2. Decimal to Fractions\n");
	printf("                                      3. Fractions to Percent\n");
	printf("                                      4. Percent to Fractions\n");
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

void numberConversion(){
	int menu_number = menuNumberConversion();
	int user_input;
	
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
	gotoxy(29,9);scanf("%d", &user_input);
	gotoxy(29,14);printf("%d", user_input);
}

int main() {
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),14); 
	int no_menu = menu();
	if (no_menu == 1){
		generalCalculator();
	} else if(no_menu == 2){
		numberConversion();
	} else if(no_menu == 3){
		temperatureConversion();
	} else {
		//history();
	}
}
