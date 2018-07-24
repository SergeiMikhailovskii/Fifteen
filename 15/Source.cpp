#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <conio.h>
using namespace std;
void clearField(int **arr, const int FIELDLEN);
void generateField(int **arr,const int AMOFNUM, const int FIELDLEN);
void generateUniqueNumbers(int **arr, const int FIELDLEN, int &i, int &j);
void showField(int **arr, const int FIELDLEN);
bool allNumbersCorrect(int **arr, const int FIELDLEN, const int AMOFNUM);
void moveDown(int **arr, const int FIELDLEN);
void moveUp(int **arr, const int FIELDLEN);
void moveRight(int **arr, const int FIELDLEN);
void moveLeft(int **arr, const int FIELDLEN);
int main() {
	srand(time(NULL));
	const int AMOFNUM = 15;	//кол-во чисел
	const int FIELDLEN = 4;	//длина стороны
	int **arr = new int*[FIELDLEN];
	for (int i = 0; i < FIELDLEN; i++) {
		arr[i] = new int[FIELDLEN];
	}
	clearField(arr, FIELDLEN);
	generateField(arr, AMOFNUM, FIELDLEN);
	showField(arr, FIELDLEN);
	while (!allNumbersCorrect(arr, FIELDLEN, AMOFNUM)) {
		switch (_getch()) {
		case 80:
			moveDown(arr, FIELDLEN);
			break;
		case 72:
			moveUp(arr, FIELDLEN);
			break;
		case 77:
			moveRight(arr, FIELDLEN);
			break;
		case 75:
			moveLeft(arr, FIELDLEN);
			break;
		}
		system("cls");
		showField(arr, FIELDLEN);
	}
	system("pause");
	return 0;
}

void clearField(int ** arr, const int FIELDLEN)
{
	for (int i = 0; i < FIELDLEN; i++) {
		for (int j = 0; j < FIELDLEN; j++) {
			arr[i][j] = 0;
		}
	}
}

void generateField(int ** arr, const int AMOFNUM, const int FIELDLEN)
{	
	int x, y;
	char a;
	for (int i = 1; i <= AMOFNUM; i++) {
		generateUniqueNumbers(arr, FIELDLEN, x, y);
		arr[x][y] = i;
	}
}

void generateUniqueNumbers(int ** arr, const int FIELDLEN, int &i, int &j)
{
	while (true) {
		i = rand() % FIELDLEN;
		j = rand() % FIELDLEN;
		if (arr[i][j] == 0) {
			return;
		}
	}
}

void showField(int ** arr, const int FIELDLEN)
{
	for (int i = 0; i < FIELDLEN; i++) {
		for (int j = 0; j < FIELDLEN; j++) {
			cout <<setw(3)<< arr[i][j] << " ";
		}
		cout << endl;
		cout << endl;
	}
}

bool allNumbersCorrect(int ** arr, const int FIELDLEN, const int AMOFNUM)
{
	for (int i = 0; i < FIELDLEN - 1; i++) {
		for (int j = 0; j < FIELDLEN; j++) {
			if (arr[i][j] != i * 3 + j + 1) {
				return false;
			}
		}
	}
	if (arr[3][0] == 13 && arr[3][1] == 14 && arr[3][2] == 15 && arr[3][3] == 0) {
		return true;
	}
	return false;
}

void moveDown(int ** arr, const int FIELDLEN)
{
	int x, y;
	for (int i = 0; i < FIELDLEN; i++) {
		for (int j = 0; j < FIELDLEN; j++) {
			if (arr[i][j] == 0) {
				x = i;
				y = j;
				break;
			}
		}
	}
	if (x != 0) {
		arr[x][y] = arr[x - 1][y];
		arr[x - 1][y] = 0;
	}
}

void moveUp(int ** arr, const int FIELDLEN)
{
	int x, y;
	for (int i = 0; i < FIELDLEN; i++) {
		for (int j = 0; j < FIELDLEN; j++) {
			if (arr[i][j] == 0) {
				x = i;
				y = j;
				break;
			}
		}
	}
	if (x != 3) {
		arr[x][y] = arr[x + 1][y];
		arr[x + 1][y] = 0;
	}
}

void moveRight(int ** arr, const int FIELDLEN)
{
	int x, y;
	for (int i = 0; i < FIELDLEN; i++) {
		for (int j = 0; j < FIELDLEN; j++) {
			if (arr[i][j] == 0) {
				x = i;
				y = j;
				break;
			}
		}
	}
	if (y != 0) {
		arr[x][y] = arr[x][y-1];
		arr[x][y-1] = 0;
	}
}

void moveLeft(int ** arr, const int FIELDLEN)
{
	int x, y;
	for (int i = 0; i < FIELDLEN; i++) {
		for (int j = 0; j < FIELDLEN; j++) {
			if (arr[i][j] == 0) {
				x = i;
				y = j;
				break;
			}
		}
	}
	if (y != 3) {
		arr[x][y] = arr[x][y +1];
		arr[x][y + 1] = 0;
	}
}
