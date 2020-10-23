#include<iostream>
#include<conio.h>
//#include<stdio.h>
using namespace std;
int game1();
int game2();
int main() {
	cout << "ÇëÑ¡ÔñÄãÒªÍæµÄÓÎÏ·£º" << endl;
	cout << "1.É³µñÕÒ±¦²ØÓÎÏ·" << endl;
	cout << "2.Ì°³ÔÉß" << endl;
	char choice;
	choice = _getch();
	switch (choice)
	{
	case '1':
		system("cls");
		game1();
		break;
	case '2':
		system("cls");
		game2();
		break;
	default:
		cout << "ÄãÃ»ÓÐ×ö³öÑ¡Ôñ" << endl;
		break;
	}
}