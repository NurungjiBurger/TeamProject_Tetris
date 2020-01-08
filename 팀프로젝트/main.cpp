#include "main.h"
#include "CConsoleMenu.h"
#include "Tetris.h"
#include <thread>
using std::thread;
using namespace std;

/*
void Run();
void StartGame();
int HowToPlay();
int Information();

void InitBoard();									//���� �迭 0���� �ʱ�ȭ
void DrawBoard();									//��Ʈ���� �� �׸���
void move(Block &b);								//��� ȸ�� �� �̵�
void fall(Block &b);								//��� �� ĭ�� ����߸���
int FullLineCheck();								//������ ���� á���� üũ
void RenewalBoard(int line);						//��Ʈ���� ���� ����
int MakeBlock(Block &b);							//����� ���� ����
bool CheckEnd();
*/


int main() {
	/*
	int key;
	key = _getch();

	if (key == 224) key = _getch();
	printf("%d", key);
	return 0;
	*/
	int number;
	//InsertPlayernumber();
	cin >> number;
	Tetris P1(20, 50, 1, 0, 1, 1), P2(20, 50, 1, 0, 1, 2);
	srand((unsigned)time(NULL));
	SetCursorVisible(false);
	thread t(&Tetris::Run, &P1);
	thread t2(&Tetris::Run, &P2);
	t.join();
	t2.join();
	return 0;
	
}

// Ŀ�� �����
void SetCursorVisible(int bVisible) {
	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize = 20;												//Ŀ�� �β�
	CurInfo.bVisible = bVisible;										//Ŀ���� ���̴���
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void InsertPlayernumber() {
	const int nBlank = 10;
	string strDescription = " �÷����� �ο����� �Է����ּ���. �ִ� 2������ �� �̻��� �Է��ϼŵ� 2�� ó���˴ϴ�.";
	int i, nChoice, nMaxLength = strDescription.length();
	int stage, level;
	system("cls");
	for (i = 0; i < nMaxLength + nBlank; i++) {
		cout << "=";
	}
	cout << endl;
	for (i = 0; i < (nMaxLength + nBlank - strDescription.length()) / 2; i++) {
		cout << " ";
	}
	cout << strDescription[0] << endl;
	for (i = 0; i < nMaxLength + nBlank; i++) {
		cout << "=";
	}
	cout << endl;
	cout << strDescription;
	cout << endl;
	for (i = 0; i < nMaxLength + nBlank; i++) {
		cout << "=";
	}
	cout << endl;
	for (i = 0; i < nMaxLength + nBlank; i++) {
		cout << "=";
	}
	cout << endl;
}