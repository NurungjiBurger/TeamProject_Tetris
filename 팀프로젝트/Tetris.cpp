#include "Tetris.h"
#include <ctime>
#include <thread>
using std::thread;
bool nCrushCheck = true;
int Board[21][10] = { 0 }; // Board[플레이어번호][Y축][X축]
int ar[16];
//////////////////////////////
// 블럭 모양 바꾸기
int **Change(int **b1, int **b2, int r)
{
	int i, j, index = 0;
	//int ar[16];
//	printf("ar[]");

	Tetris t;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			b1[j][i] = t.Rotate(i, j, r);
		}
	}

	int k;
	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 4; k++)
			{
				if (i == b1[j][k])
				{
					b2[j][k] = ar[i];
				}
			}
		}
	}
	return b2;
}
// 다음블럭 밀어넣기
void arr(int **block)
{
	int i, j, index = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++, index++)
		{
			if (block[i][j] == 1)
			{
				ar[index] = 1;
			}
			else
			{
				ar[index] = 0;
			}

			//printf("%d ", ar[index]);
		}
	}
}
// 블럭 회전
int Tetris::Rotate(int x, int y, int r)
{
	switch (r % 4)
	{
	case 0:
		return y * 4 + x;// 0도
	case 1:
		return 12 + y - (x * 4);// 90도
	case 2:
		return 15 - (y * 4) - x;// 180도
	case 3:
		return 3 - y + (x * 4);// 270도
	}
	return 0;
}
// 다음 블럭
int **NEXT()
{
	block1 b1;
	block2 b2;
	block3 b3;
	block4 b4;
	block5 b5;
	block6 b6;
	block7 b7;
	int **NextB=NULL;
	switch (rand() % 7)
	{
	case 0:
		NextB = b1.Init();
		break;
	case 1:
		NextB = b2.Init();
		break;
	case 2:
		NextB = b3.Init();
		break;
	case 3:
		NextB = b4.Init();
		break;
	case 4:
		NextB = b5.Init();
		break;
	case 5:
		NextB = b6.Init();
		break;
	case 6:
		NextB = b7.Init();
		break;
	}
	return NextB;
}
Tetris::Tetris() {
	nFrame = 20, nSpeed = 50, nLevel = 1, nScore = 0, nstage = 1, playernumber = 1;
}


//////////////////////////////
Tetris::Tetris(int frame, int speed, int level, int score, int stage, int number) {
	nFrame = frame, nSpeed = speed, nLevel = level, nstage = stage, nScore = score, playernumber = number; 
}

Tetris::~Tetris() {}

// get method
int Tetris::getnFrame() { return nFrame; }
int Tetris::getnSpeed() { return nSpeed; }
int Tetris::getnLevel() { return nLevel; }
int Tetris::getnStage() { return nstage; }
int Tetris::getnNumber() { return nNumber; }

// set method
void Tetris::setnFrame(int frame) { nFrame = frame; }
void Tetris::setnSpeed(int speed) { nSpeed = speed; }
void Tetris::setnLevel(int level) { nLevel = level; }
void Tetris::setnStage(int stage) { nstage = stage; }

// 실행
void Tetris::Run() { 
	bool bIteratorFlag = true;
	// 콘솔메뉴 생성
	ConsoleMenu MainMenu("Tetris", 5);
	MainMenu.AddMenu("Start Game");
	MainMenu.AddMenu("How to Play");
	MainMenu.AddMenu("Information");
	while (bIteratorFlag) {
		switch (MainMenu.DisplayMenu()) {
		case START_GAME:
			StartGame();
			break;
		case HOW_TO_PLAY:
			HowToPlay();
			break;
		case INFORMATION:
			if (!Information()) {
				bIteratorFlag = false;
			}
			break;
		case EXIT:
			bIteratorFlag = false;
		}
	}
	system("cls");
	cout << "프로그램 종료" << endl;
}
// 게임 시작
void Tetris::StartGame() {
	int varx = 10, token = 1, cnt = 0, limit = 1;
	int nFrame = 20, nSpeed = 50, nLevel = 1, nstage = 1, nScore = 0;
	if (playernumber == 1) {
		cin >> nNumber;
		Gostagelevel();
		cin >> nstage;
		cin >> nLevel;
		/*
		if (nNumber >= 2) {
			nNumber = 2;
			Tetris P2(nFrame, nSpeed, nLevel, 0, nstage, 2);
			thread t(&Tetris::StartGame, &P2);
			t.join();
		}
		*/
	}
	if (!(nstage >= 1 && nstage <= 3)) nstage = 1;
	if (!(nLevel >= 1 && nLevel <= 5)) nLevel = 1;
	else {
		if (nstage != 3) {
			for (int i = 1; i < nLevel; i++) {
				nSpeed -= 10;
				varx *= 2;
			}
		}

		int nStay, nLine;
		////////////////////////////////////////////
		//rand() % 7;
		// 블럭 설정
		int** block, ** tempB, CNT = 0, **NextB;
		int i, j;
		tempB = new int* [4];
		NextB = new int* [4];
		for (i = 0; i < 4; i++)
		{
			tempB[i] = new int[4];
			NextB[i] = new int[4];
		}
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				tempB[i][j] = CNT;
				CNT++;
				//printf("%d ", tempB[i][j]);
			}
			//printf("\n");
		}
		block = b1.Init();
		arr(block);
		b.ChangeB(block);
		NextB = NEXT();

		///////////////////////////////////
		// 보드판 초기화
		InitBoard();
		d.DrawBoard();
		d.ShowNextBlock(NextB);
		nStay = nFrame;

		// 게임 시작
		while (1) {
			// 스테이지별 보드 설정
			if (token && nstage == 2) {
				SetStage();
				token = 0;
			}
			if (nstage == 3) {
				if (token && nScore == 0) {
					SetStage();
					token = 0;
				}
				if (cnt % 300 == 0) {
					UpStage();
				}
			}
			while (1) {
				// 일정 시간이 지나고 블럭 낙하
				if (--nStay == 0) {
					nStay = nFrame;
					this->Fall(b);
				}
				// 움직임 입력
				if (this->Move(b, block, tempB))
				{
					// 블럭 회전, 이동
					b.Draw(false);
					block = Change(tempB, block, b.GetRotation());
					b.ChangeB(block);

				}
				nLine = FullLineCheck();
				// 라인 클리어 확인
				if (nLine) {
					nScore += nLevel * 100 * nstage;
					// 3단계는 level 상승 x
					if (nstage != 3) {
						if (nLevel * nSpeed * varx * nstage <= nScore) {
							varx *= 2;
							nLevel++;
							nSpeed -= 10;
						}
					}
				}
				// 종료조건 확인
				if (!CheckEnd()) break;
				// 5레벨 후 점수 만족시 다음 스테이지
				if (nLevel == 6) {
					if (nstage != 3) {
						nstage++;
						varx = 10;
						nLevel = 1;
						nFrame = 20;
						nSpeed = 50;
						if (nstage == 2) token = 1;
						break;
					}
				}
				// 블럭 충돌 체크 ( 바닥에 쌓이는 것 )
				if (nCrushCheck) {
					b.ChangeB(NextB);
					for (i = 0; i < 4; i++)
					{
						delete block[i];
					}
					delete block;
					block = NextB;
					NextB = NEXT();
					d.ShowNextBlock(NextB);
					b.SetBlock(10, 0, 0);
					nCrushCheck = false;
					d.ShowGameInfo(nstage, nLevel, nScore);
					///////////////////////
					arr(block);
					///////////////////////
				}
				b.Draw(true);
				Sleep(nSpeed);
				// 3단계에서 일정 시간이 지나면 스태이지가 한칸 올라와야하기 때문에 그 시간을 재는 cnt
				cnt++;
				break;
			}
			// 종료조건 확인
			if (!CheckEnd()) break;
		}
		// 할당 해제
		for (i = 0; i < 4; i++)
		{
			delete tempB[i];
			delete NextB[i];
		}
		delete tempB;
		delete NextB;
		system("cls");
		cout << "Game Over!!" << endl;
		system("pause");
	}
}
// 스테이지와 레벨을 선택하라는 함수
void Tetris::Gostagelevel() {
	const int nBlank = 10, nNumOfDescription = 4;
	string strDescription[nNumOfDescription] = { "Go Stage & Level", "원하시는 스테이지와 레벨을 설정해주세요!", "※주의 : 스테이지는 1 ~ 3 , 레벨은 1 ~ 5 그 외를 입력하시면 default로 처리됩니다.", "※주의 : 3스테이지는 1단계 밖에 없습니다." };
	int i, nChoice, nMaxLength = strDescription[0].length();
	int stage, level;
	for (i = 1; i < nNumOfDescription; i++) {
		nMaxLength = nMaxLength >= strDescription[i].length() ? nMaxLength : strDescription[i].length();
	}
	system("cls");
	for (i = 0; i < nMaxLength + nBlank; i++) {
		cout << "=";
	}
	cout << endl;
	for (i = 0; i < (nMaxLength + nBlank - strDescription[0].length()) / 2; i++) {
		cout << " ";
	}
	cout << strDescription[0] << endl;
	for (i = 0; i < nMaxLength + nBlank; i++) {
		cout << "=";
	}
	cout << endl;
	for (i = 1; i < nNumOfDescription; i++) {
		d.gotoPrint(5, 2 + i, strDescription[i]);
	}
	cout << endl;
	for (i = 0; i < nMaxLength + nBlank; i++) {
		cout << "=";
	}
	cout << endl;
	for (i = 0; i < nMaxLength + nBlank; i++) {
		cout << "=";
	}
	d.gotoPrint(5, nNumOfDescription + 6, ">> ");
}
// 플레이 방법 출력
int Tetris::HowToPlay() {
	const int nBlank = 10, nNumOfDescription = 8;
	string strDescription[nNumOfDescription] = { "HowToPlay", "목표 : 끝없이 내려오는 블록을 쌓아 라인을 채우세요!", "※주의 : 레벨이 증가할수록 블록이 떨어지는 속도가 증가합니다.", "↑ : 회전", "← : 왼쪽으로 이동", "→ : 오른쪽으로 이동", "↓ : 아래로 이동", "SPACE : 맨 밑으로 이동" };
	int i, nChoice, nMaxLength = strDescription[0].length();
	for (i = 1; i < nNumOfDescription; i++) {
		nMaxLength = nMaxLength >= strDescription[i].length() ? nMaxLength : strDescription[i].length();
	}
	system("cls");
	for (i = 0; i < nMaxLength + nBlank; i++) {
		cout << "=";
	}
	cout << endl;
	for (i = 0; i < (nMaxLength + nBlank - strDescription[0].length()) / 2; i++) {
		cout << " ";
	}
	cout << strDescription[0] << endl;
	for (i = 0; i < nMaxLength + nBlank; i++) {
		cout << "=";
	}
	for (i = 1; i < nNumOfDescription; i++) {
		d.gotoPrint(5, 2 + i, strDescription[i]);
	}
	cout << endl;
	for (i = 0; i < nMaxLength + nBlank; i++) {
		cout << "=";
	}
	d.gotoPrint(5, nNumOfDescription + 3, "0. Exit");
	d.gotoPrint(5, nNumOfDescription + 4, "1. Return MainMenu");
	cout << endl;
	for (i = 0; i < nMaxLength + nBlank; i++) {
		cout << "=";
	}
	d.gotoPrint(5, nNumOfDescription + 6, ">> ");
	cin >> nChoice;
	while (nChoice != 0 && nChoice != 1) {
		d.gotoPrint(8, nNumOfDescription + 6, "                                  ");
		d.gotoPrint(5, nNumOfDescription + 7, "주어진 번호 중 하나를 골라주세요");
		d.gotoxy(8, nNumOfDescription + 6);
		cin >> nChoice;
	}
	return nChoice;
}
// 정보 출력
int Tetris::Information() {
	const int nBlank = 10, nNumOfInfo = 6;
	string strInfo[nNumOfInfo] = { "Information", "팀장 : xxxxxxxx 박상빈", "팀원 : xxxxxxxx 이찬희", "팀원 : xxxxxxxx 강대호", "팀원 : xxxxxxxx 김정현", "Ver.0" };
	int i, nChoice, nMaxLength = strInfo[0].length();
	for (i = 1; i < nNumOfInfo; i++) {
		nMaxLength = nMaxLength >= strInfo[i].length() ? nMaxLength : strInfo[i].length();
	}
	system("cls");
	for (i = 0; i < nMaxLength + nBlank; i++) {
		cout << "=";
	}
	cout << endl;
	for (i = 0; i < (nMaxLength + nBlank - strInfo[0].length()) / 2; i++) {
		cout << " ";
	}
	cout << strInfo[0] << endl;
	for (i = 0; i < nMaxLength + nBlank; i++) {
		cout << "=";
	}
	for (i = 1;i < nNumOfInfo;i++) {
		d.gotoPrint(5, 2 + i, strInfo[i]);
	}
	cout << endl;
	for (i = 0; i < nMaxLength + nBlank; i++) {
		cout << "=";
	}
	d.gotoPrint(5, nNumOfInfo + 3, "0. Exit");
	d.gotoPrint(5, nNumOfInfo + 4, "1. Return MainMenu");
	cout << endl;
	for (i = 0; i < nMaxLength + nBlank; i++) {
		cout << "=";
	}
	d.gotoPrint(5, nNumOfInfo + 6, ">> ");
	cin >> nChoice;
	while (nChoice != 0 && nChoice != 1) {
		d.gotoPrint(8, nNumOfInfo + 6, "                                  ");
		d.gotoPrint(5, nNumOfInfo + 7, "주어진 번호 중 하나를 골라주세요");
		d.gotoxy(8, nNumOfInfo + 6);
		cin >> nChoice;
	}
	return nChoice;
}
// 블럭 낙하
void Tetris::Fall(Shape &b) {
	if (b.isValidBlock(P2DOWN)) {
		b.Draw(false);
		b.SetCen_Y(b.GetCen_Y() + 1);
		b.Draw(true);
	}
	else {
		b.fillTheBoard();
		nCrushCheck = true;
	}
}
// 블럭 이동
bool Tetris::Move(Shape &b,int **block,int **tempB) {
	int nInput;
	if (playernumber == 1) {
		if (_kbhit()) {
			nInput = _getch();
			switch (nInput) {
			case P2UP:
				block = Change(tempB, block, (b.GetRotation() + 1) % 4);
				b.RChangeB(block);
				if (b.isValidRotation()) {
					b.Draw(false);
					b.SetRotation((b.GetRotation() + 1) % 4);
					b.Draw(true);
					return true;
					break;
				}
				else {
					b.Draw(false);
					b.SetCen_X(b.GetCen_X() - 2);
					if (b.isValidRotation()) {
						b.SetRotation((b.GetRotation() + 1) % 4);
						b.Draw(true);
						return true;

						break;
					}
					b.SetCen_X(b.GetCen_X() - 2);
					if (b.isValidRotation()) {
						b.SetRotation((b.GetRotation() + 1) % 4);
						b.Draw(true);
						return true;

						break;
					}
					b.SetCen_X(b.GetCen_X() + 6);
					if (b.isValidRotation()) {
						b.SetRotation((b.GetRotation() + 1) % 4);
						b.Draw(true);
						return true;

						break;
					}
					b.SetCen_X(b.GetCen_X() - 2);
					b.Draw(true);
				}
				return true;
				break;
			case P2DOWN:
				if (b.isValidBlock(P2DOWN)) {
					b.Draw(false);
					b.SetCen_Y(b.GetCen_Y() + 1);
					b.Draw(true);
				}
				break;
			case P2LEFT:
				if (b.isValidBlock(P2LEFT)) {
					b.Draw(false);
					b.SetCen_X(b.GetCen_X() - 2);
					b.Draw(true);
				}
				break;
			case P2RIGHT:
				if (b.isValidBlock(P2RIGHT)) {
					b.Draw(false);
					b.SetCen_X(b.GetCen_X() + 2);
					b.Draw(true);
				}
				break;
			case P2DOWNSHIFT:;
				b.Draw(false);
				while (b.isValidBlock(P2DOWN)) {
					b.SetCen_Y(b.GetCen_Y() + 1);
				}
				b.fillTheBoard();
				b.Draw(true);
				nCrushCheck = true;
				return false;
				////////////
			}
		}
		return false;
	}
	else {
		if (_kbhit()) {
			nInput = _getch();
			switch (nInput) {
			case P1UP:
				block = Change(tempB, block, (b.GetRotation() + 1) % 4);
				b.RChangeB(block);
				if (b.isValidRotation()) {
					b.Draw(false);
					b.SetRotation((b.GetRotation() + 1) % 4);
					b.Draw(true);
					return true;
					break;
				}
				else {
					b.Draw(false);
					b.SetCen_X(b.GetCen_X() - 2);
					if (b.isValidRotation()) {
						b.SetRotation((b.GetRotation() + 1) % 4);
						b.Draw(true);
						return true;

						break;
					}
					b.SetCen_X(b.GetCen_X() - 2);
					if (b.isValidRotation()) {
						b.SetRotation((b.GetRotation() + 1) % 4);
						b.Draw(true);
						return true;

						break;
					}
					b.SetCen_X(b.GetCen_X() + 6);
					if (b.isValidRotation()) {
						b.SetRotation((b.GetRotation() + 1) % 4);
						b.Draw(true);
						return true;

						break;
					}
					b.SetCen_X(b.GetCen_X() - 2);
					b.Draw(true);
				}
				return true;
				break;
			case P1DOWN:
				if (b.isValidBlock(P1DOWN)) {
					b.Draw(false);
					b.SetCen_Y(b.GetCen_Y() + 1);
					b.Draw(true);
				}
				break;
			case P1LEFT:
				if (b.isValidBlock(P1LEFT)) {
					b.Draw(false);
					b.SetCen_X(b.GetCen_X() - 2);
					b.Draw(true);
				}
				break;
			case P1RIGHT:
				if (b.isValidBlock(P1RIGHT)) {
					b.Draw(false);
					b.SetCen_X(b.GetCen_X() + 2);
					b.Draw(true);
				}
				break;
			case P1DOWNSHIFT:;
				b.Draw(false);
				while (b.isValidBlock(P1DOWN)) {
					b.SetCen_Y(b.GetCen_Y() + 1);
				}
				b.fillTheBoard();
				b.Draw(true);
				nCrushCheck = true;
				return false;
				////////////
			}
		}
		return false;
	}
}
// 라인 클리어 체크 함수
int Tetris::FullLineCheck() {
	int i, j, flag = 1, cnt = 0;
	for (i = 0; i < d.GetHeight(); i++) {
		flag = 1;
		for (j = 0; j < d.GetWidth(); j++) {
			if (Board[i][j] == 0) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			for (j = 0; j < d.GetWidth(); j++) {
				Board[i][j] = 0;
			}
			// 라인이 꽉차있으면 0을 넣고 보드판을 갱신 시킴
			RenewalBoard(i);
			cnt++;
		}
	}
	return cnt;
}
// 보드판 갱신
void Tetris::RenewalBoard(int line) {
	int i, j;
	for (i = line; i > 0; i--) {
		for (j = 0; j < d.GetWidth(); j++) {
			Board[i][j] = Board[i - 1][j];
		}
	}
	for (j = 0; j < d.GetWidth(); j++) {
		Board[0][j] = 0;
	}
	for (i = 0; i < d.GetHeight(); i++) {
		d.gotoxy(2, i + 1);
		for (j = 0; j < d.GetWidth(); j++) {
			if (Board[i][j] == 0) cout << "  ";
			else cout << "■";
		}
	}
}
/*
int Tetris::MakeBlock(Block &b) {
	int type;
	static int next_type = 0;
	type = next_type;
	next_type = rand() % 7;
	b.SetShape(type);
	b.SetBlock(10, 0, 0);
	return next_type;
}*/
// 종료조건 확인
bool Tetris::CheckEnd() { 
	int i;
	for (i = 0; i < d.GetWidth(); i++) {
		if (Board[0][i] == 1) {
			return false;
		}
	}
	return true;
}
// 보드판 초기화 // 32
void Tetris::InitBoard() {
	int i, j;
	for (i = 0; i < d.GetHeight(); i++) {
		for (j = 0; j < d.GetWidth(); j++) {
			Board[i][j] = 0;
		}
	}
}
// 스테이지 랜덤 설정
void Tetris::SetStage() {
	int cnt = 0;
	int x1, x2, y = 15, i, j;
	InitBoard();
	while (y < d.GetHeight()) {
		x1 = rand() % 10;
		x2 = rand() % 10;
		for (i = 0;i < d.GetWidth();i++) {
			if (i == x1 || i == x2) {
				continue;
			}
			else Board[y][i] = 1;
		}
		y++;
	}
	for (i = 0;i < d.GetHeight();i++) {
		d.gotoxy(2, i + 1);
		for (j = 0;j < d.GetWidth();j++) {
			if (Board[i][j] == 1) cout << "■";
			else cout << "  ";
		}
	}
}
// 스테이지 위로 밀기
void Tetris::UpStage() {
	int i, j, flag, tmp;
	for (i = d.GetHeight()-1;i >= 0;i--) {
		flag = 1;
		for (j = 0;j < d.GetWidth();j++) {
			if (Board[i][j] == 1) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			while (i < d.GetHeight()) {
				for (j = 0;j < d.GetWidth();j++) {
					Board[i - 1][j] = Board[i][j];
				}
				i++;
			}
			break;
		}
	}
	
	srand(time(NULL));

	int cnt = 3;
	for (j = 0;j < d.GetWidth();j++) {
		tmp = 1;
		if (cnt) {
			tmp = rand() % 2;
			if (!tmp) cnt--;
		}
		Board[d.GetHeight()-1][j] = tmp;
	}

	for (i = 0; i < d.GetHeight(); i++) {
		d.gotoxy(2, i + 1);
		for (j = 0; j < d.GetWidth(); j++) {
			if (Board[i][j] == 0) cout << "  ";
			else cout << "■";
		}
	}
}