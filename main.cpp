#include<iostream>
#include<conio.h>
//#include<stdio.h>
using namespace std;
int game1();
int game2();
int main() {
	cout << "��ѡ����Ҫ�����Ϸ��" << endl;
	cout << "1.ɳ���ұ�����Ϸ" << endl;
	cout << "2.̰����" << endl;
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
		cout << "��û������ѡ��" << endl;
		break;
	}
}