#include<iostream>
#include<conio.h>
#include<vector>
#include<ctime>
#include<Windows.h>
using namespace std;
void initBackground();
void showVector();
void refreshFood();
void eatFood();
void moveSnake();
void showSnake(); // ����ʹ��
void autoMove();
int k = 1; // ѭ������
vector<vector<char>> actor(20);
vector<vector<int>> snake;
vector<int> snakeBody(2);
int w, h;
int m, n;
int direction = 1; //1 top 2 right 3 dowm 4 left
int game2() {
	for (unsigned int i = 0; i < actor.size(); i++) {//size()����unsigned int���ͣ���������ᱨwarning
		actor[i].resize(40);
	}
	int flag = 0; // ��ĩβ����
	m = actor.size() / 2;
	n = actor[0].size() / 2; // ��ͷ��ʼλ��
	snakeBody[0] = m;
	snakeBody[1] = n;
	snake.push_back(snakeBody);
	refreshFood();
	initBackground();
	while (k)
	{
		k++;
		Sleep(10);
		//���ˢ��ʳ��λ��
		autoMove();
		if (_kbhit()) {
			char ch = _getch();
			switch (ch)
			{
			case 'w':
				direction = 1;
				break;
			case 'd':
				direction = 2;
				break;
			case 's':
				direction = 3;
				break;
			case 'a':
				direction = 4;
				break;
			case 'p':
				system("pause");
			default:
				cout << "������Ч" << endl;
				break;
			}
		}
		//system("cls");
	}
	return 0;
}

void showVector() {
	system("cls");
	for (unsigned int i = 0; i < actor.size(); i++) {
		for (unsigned int j = 0; j < actor[i].size(); j++) {
			cout << actor[i][j];
		}
		cout << endl;
	}
}
void autoMove() {
	if (direction == 1){
		m -= 1;
		if (m == 0) {
			cout << "��ײ����ǽ�ڣ���Ϸʧ��" << endl;
			k = 0;
		}
		else if (m == w && n == h) {
			eatFood();
			refreshFood();
		}
		else {
			moveSnake();
		}
		initBackground();
	}
	else if (direction == 2) {
		n += 1;
		if (n == 39) {
			cout << "��ײ����ǽ�ڣ���Ϸʧ��" << endl;
			k = 0;
		}
		else if (m == w && n == h) {
			eatFood();
			refreshFood();
		}
		else {
			moveSnake();
		}
		initBackground();
	}
	else if (direction == 3) {
		m += 1;
		if (m == 19) {
			cout << "��ײ����ǽ�ڣ���Ϸʧ��" << endl;
			k = 0;
		}
		else if (m == w && n == h) {
			eatFood();
			refreshFood();
		}
		else {
			moveSnake();
		}
		initBackground();
	}
	else if (direction == 4) {
		n -= 1;
		if (n == 0) {
			cout << "��ײ����ǽ�ڣ���Ϸʧ��" << endl;
			k = 0;
		}
		else if (m == w && n == h) {
			eatFood();
			refreshFood();
		}
		else {
			moveSnake();
		}
		initBackground();
	}
	showVector();
}
void eatFood() {
	snakeBody[0] = m;
	snakeBody[1] = n;
	snake.insert(snake.begin(), snakeBody);
}
void moveSnake() {
	snakeBody[0] = m;
	snakeBody[1] = n;
	snake.pop_back();
	snake.insert(snake.begin(), snakeBody);
}
void showSnake() {
	for (unsigned int i = 0; i < snake.size(); i++) {
		for (unsigned int j = 0; j < snakeBody.size(); j++) {
			cout << snake[i][j] << " ";
		}
		cout << endl;
	}
}
void refreshFood() {
	srand(time(0));
	w = rand() % 18 + 1;
	h = rand() % 38 + 1; //w:1-18 h:1-38 ʳ��λ�ó�ʼ
}
void initBackground() {
	for (unsigned int i = 0; i < actor.size(); i++) {
		for (unsigned int j = 0; j < actor[i].size(); j++) {
			if (i == 0 || i == actor.size() - 1) {
				actor[i][j] = '*';
			}
			else {
				if (j == 0 || j == actor[i].size() - 1) {
					actor[i][j] = '*';
				}
				else {
					actor[i][j] = ' ';
				}
			}
		}
	}
	actor[w][h] = '*';
	for (unsigned int i = 0; i < snake.size(); i++) {
		if (i == 0) {
			actor[snake[i][0]][snake[i][1]] = 'O';
		}
		else {
			actor[snake[i][0]][snake[i][1]] = '*';
		}
	}
	// showSnake();
	showVector();
}