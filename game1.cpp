#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#include <ctime>
using namespace std;
int game1() {
	cout << "����һ��һȺɵ���ұ��ص���Ϸ ��û����û����\n\n";
	Sleep(3000);
	system("cls");
	cout << "ѡ��ģʽ��1.�򵥣���������·�ۼ���   2.���ѣ�û�����£�";
	int d;
	cin >> d;
	system("cls"); //dos��������
	int n, k = 1;
	cout << "ѡ�����̴�С:";
	cin >> n;
	system("cls");
	srand((int)time(0));
	int l = rand() % (n * n - 1 + 1) + 1;
	char b[10001];
	int p = (n * n) / 2;
	// char a[n * n];  //g++����������ʹ�ñ��������鳤��
	char *a = new char[n * n]; //�ƹ�ջ�ռ䣬�������ڴ�����ڶѿռ�
	int s = n * n;
	for (int i = 1; i <= s; i++) {
		if (d == 1) {
			a[i] = '#';
		}
		if (d == 2) {
			a[i] = '*';
		}
	}
	a[p] = '*';
	// ��ʼ������#�ž���
	for (int i = 1; i <= s; i++) {
		cout << " ";
		cout << a[i];
		if (i % n == 0) {
			cout << endl;
		}
	}
	// ���̲���
	while (k != 0) {
		k++;
		switch (b[k] = _getch()) { //�ӿ���̨��ȡ���ݣ�������
		case 'd':a[p + 1] = '*'; p++; break;
		case 'w':a[p - n] = '*'; p = p - n; break;
		case 's':a[p + n] = '*'; p = p + n; break;
		case 'a':a[p - 1] = '*'; p--; break;
		}
		system("cls");
		for (int i = 1; i <= s; i++) {
			cout << " ";
			if (i == p) {
				cout << "@";
				if (p == l) {
					system("cls");
					cout << "��Ӯ��";
					//delete []a; //ɾ��a����ֹ�ڴ�й©,�����ˣ���֪��Ϊɶ
					Sleep(1000);
					return 0;
				}
				if (i % n == 0) {
					cout << endl;
				}
				continue;
			}
			cout << a[i];
			if (i % n == 0) {
				cout << endl;
			}
		}
		if (d == 1) {
			if (p / n == l / n) {
				if (p < l) {
					cout << "��ʾ�����ұ�" << endl;
					cout << "ʹ�ò�����" << k;
				}
				if (p > l) {
					cout << "��ʾ�������" << endl;
					cout << "ʹ�ò�����" << k;
				}
				continue;
			}
			if (p < l) {
				cout << "��ʾ�����±�" << endl;
			}
			if (p > l) {
				cout << "��ʾ�����ϱ�" << endl;
			}
		}
		cout << "ʹ�ò�����" << k;

	}

	return 0;
}