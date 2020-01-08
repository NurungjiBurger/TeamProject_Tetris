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

// 커서 지우기
void SetCursorVisible(int bVisible) {
	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize = 20;												//커서 두께
	CurInfo.bVisible = bVisible;										//커서가 보이는지
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void InsertPlayernumber() {
	const int nBlank = 10;
	string strDescription = " 플레이할 인원수를 입력해주세요. 최대 2인으로 그 이상을 입력하셔도 2로 처리됩니다.";
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