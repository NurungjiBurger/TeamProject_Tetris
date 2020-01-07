#include "main.h"
#include "CConsoleMenu.h"
#include "Tetris.h"
using namespace std;

/*
void Run();
void StartGame();
int HowToPlay();
int Information();

void InitBoard();									//보드 배열 0으로 초기화
void DrawBoard();									//테트리스 판 그리기
void move(Block &b);								//블록 회전 및 이동
void fall(Block &b);								//블록 한 칸씩 떨어뜨리기
int FullLineCheck();								//라인이 가득 찼는지 체크
void RenewalBoard(int line);						//테트리스 판을 갱신
int MakeBlock(Block &b);							//블록을 새로 생성
bool CheckEnd();
*/


int main() {
	Tetris t;
	srand((unsigned)time(NULL));
	SetCursorVisible(false);
	t.Run();
	return 0;
}

// 커서 지우기
void SetCursorVisible(int bVisible) {
	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize = 20;												//커서 두께
	CurInfo.bVisible = bVisible;										//커서가 보이는지
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

