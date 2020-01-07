#include "Display.h"
// 생성자 단계에서 10,21으로 초기화
Display::Display() {
	Width = 10;
	Height = 21;
}

Display::~Display() {}

void Display::DrawBoard() {
	int i, j;
	system("cls");
	// 보드의 판이 10,21 크기이고 이를 감싸는 테두리는 2칸씩 더 커야함.
	for (i = 0; i < GetHeight() + 2; i++) {
		for (j = 0; j < GetWidth() + 2; j++) {
			if (i == GetHeight() + 1) {
				cout << "▣";
				continue;
			}
			if (j == 0 || j == GetWidth() + 1) {
				cout << "▣";
			}
			else {
				cout << "  ";
			}
		}
		printf("\n");
	}
	gotoPrint(24, 1, "←Dead Line");
}
// 좌표 x,y로 이동
void Display::gotoxy(int x,int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
// 다음 블럭 출력
void Display::ShowNextBlock(int **b) {
	Shape NextBlock;
	NextBlock.ChangeB(b);
	// 다음블럭이 표시 되어야 할 좌표를 등록
	NextBlock.SetCen_X(32);
	NextBlock.SetCen_Y(4);
	//NextBlock.SetShape(next_type);
	gotoPrint(30, 3, "□□□□□□");
	gotoPrint(30, 4, "□        □");
	gotoPrint(30, 5, "□        □");
	gotoPrint(30, 6, "□        □");
	gotoPrint(30, 7, "□        □");
	gotoPrint(30, 8, "□□□□□□");
	NextBlock.Draw(true);
}
// 게임정보 출력
void Display::ShowGameInfo(int stage, int level, int score) {
	gotoPrint(30, 10, "Stage : ");
	cout << stage;
	gotoPrint(30, 12, "Level : ");
	cout << level;
	gotoPrint(30, 14, "Score : ");
	cout << score;
}
// 좌표 x,y로 이동 후 str 출력
void Display::gotoPrint(int x, int y, string str) {
	gotoxy(x, y);
	cout << str;
}
