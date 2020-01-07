#include "Display.h"
// ������ �ܰ迡�� 10,21���� �ʱ�ȭ
Display::Display() {
	Width = 10;
	Height = 21;
}

Display::~Display() {}

void Display::DrawBoard() {
	int i, j;
	system("cls");
	// ������ ���� 10,21 ũ���̰� �̸� ���δ� �׵θ��� 2ĭ�� �� Ŀ����.
	for (i = 0; i < GetHeight() + 2; i++) {
		for (j = 0; j < GetWidth() + 2; j++) {
			if (i == GetHeight() + 1) {
				cout << "��";
				continue;
			}
			if (j == 0 || j == GetWidth() + 1) {
				cout << "��";
			}
			else {
				cout << "  ";
			}
		}
		printf("\n");
	}
	gotoPrint(24, 1, "��Dead Line");
}
// ��ǥ x,y�� �̵�
void Display::gotoxy(int x,int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
// ���� �� ���
void Display::ShowNextBlock(int **b) {
	Shape NextBlock;
	NextBlock.ChangeB(b);
	// �������� ǥ�� �Ǿ�� �� ��ǥ�� ���
	NextBlock.SetCen_X(32);
	NextBlock.SetCen_Y(4);
	//NextBlock.SetShape(next_type);
	gotoPrint(30, 3, "�������");
	gotoPrint(30, 4, "��        ��");
	gotoPrint(30, 5, "��        ��");
	gotoPrint(30, 6, "��        ��");
	gotoPrint(30, 7, "��        ��");
	gotoPrint(30, 8, "�������");
	NextBlock.Draw(true);
}
// �������� ���
void Display::ShowGameInfo(int stage, int level, int score) {
	gotoPrint(30, 10, "Stage : ");
	cout << stage;
	gotoPrint(30, 12, "Level : ");
	cout << level;
	gotoPrint(30, 14, "Score : ");
	cout << score;
}
// ��ǥ x,y�� �̵� �� str ���
void Display::gotoPrint(int x, int y, string str) {
	gotoxy(x, y);
	cout << str;
}
