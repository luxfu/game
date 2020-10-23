#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#include <ctime>
using namespace std;
int game1() {
	cout << "这是一个一群傻屌找宝藏的游戏 ！没错！你没看错！\n\n";
	Sleep(3000);
	system("cls");
	cout << "选择模式：1.简单（有留下走路痕迹）   2.困难（没有留下）";
	int d;
	cin >> d;
	system("cls"); //dos清屏命令
	int n, k = 1;
	cout << "选择棋盘大小:";
	cin >> n;
	system("cls");
	srand((int)time(0));
	int l = rand() % (n * n - 1 + 1) + 1;
	char b[10001];
	int p = (n * n) / 2;
	// char a[n * n];  //g++编译器允许使用变量做数组长度
	char *a = new char[n * n]; //绕过栈空间，将数组内存分配在堆空间
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
	// 初始化界面#号矩阵
	for (int i = 1; i <= s; i++) {
		cout << " ";
		cout << a[i];
		if (i % n == 0) {
			cout << endl;
		}
	}
	// 键盘操作
	while (k != 0) {
		k++;
		switch (b[k] = _getch()) { //从控制台读取数据，不回显
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
					cout << "你赢了";
					//delete []a; //删除a，防止内存泄漏,报错了，不知道为啥
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
					cout << "提示：在右边" << endl;
					cout << "使用步数：" << k;
				}
				if (p > l) {
					cout << "提示：在左边" << endl;
					cout << "使用步数：" << k;
				}
				continue;
			}
			if (p < l) {
				cout << "提示：在下边" << endl;
			}
			if (p > l) {
				cout << "提示：在上边" << endl;
			}
		}
		cout << "使用步数：" << k;

	}

	return 0;
}