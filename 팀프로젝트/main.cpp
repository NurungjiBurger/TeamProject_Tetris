#include "main.h"
#include "CConsoleMenu.h"
#include "Tetris.h"
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
	Tetris t;
	srand((unsigned)time(NULL));
	SetCursorVisible(false);
	t.Run();
	return 0;
}

// Ŀ�� �����
void SetCursorVisible(int bVisible) {
	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize = 20;												//Ŀ�� �β�
	CurInfo.bVisible = bVisible;										//Ŀ���� ���̴���
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

