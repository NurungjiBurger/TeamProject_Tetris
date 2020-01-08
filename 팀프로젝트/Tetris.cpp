#include "Tetris.h"
#include <ctime>
#include <thread>
using std::thread;
bool nCrushCheck = true;
int Board[21][10] = { 0 }; // Board[�÷��̾��ȣ][Y��][X��]
int ar[16];
//////////////////////////////
// �� ��� �ٲٱ�
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
// ������ �о�ֱ�
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
// �� ȸ��
int Tetris::Rotate(int x, int y, int r)
{
	switch (r % 4)
	{
	case 0:
		return y * 4 + x;// 0��
	case 1:
		return 12 + y - (x * 4);// 90��
	case 2:
		return 15 - (y * 4) - x;// 180��
	case 3:
		return 3 - y + (x * 4);// 270��
	}
	return 0;
}
// ���� ��
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

// ����
void Tetris::Run() { 
	bool bIteratorFlag = true;
	// �ָܼ޴� ����
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
	cout << "���α׷� ����" << endl;
}
// ���� ����
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
		// �� ����
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
		// ������ �ʱ�ȭ
		InitBoard();
		d.DrawBoard();
		d.ShowNextBlock(NextB);
		nStay = nFrame;

		// ���� ����
		while (1) {
			// ���������� ���� ����
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
				// ���� �ð��� ������ �� ����
				if (--nStay == 0) {
					nStay = nFrame;
					this->Fall(b);
				}
				// ������ �Է�
				if (this->Move(b, block, tempB))
				{
					// �� ȸ��, �̵�
					b.Draw(false);
					block = Change(tempB, block, b.GetRotation());
					b.ChangeB(block);

				}
				nLine = FullLineCheck();
				// ���� Ŭ���� Ȯ��
				if (nLine) {
					nScore += nLevel * 100 * nstage;
					// 3�ܰ�� level ��� x
					if (nstage != 3) {
						if (nLevel * nSpeed * varx * nstage <= nScore) {
							varx *= 2;
							nLevel++;
							nSpeed -= 10;
						}
					}
				}
				// �������� Ȯ��
				if (!CheckEnd()) break;
				// 5���� �� ���� ������ ���� ��������
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
				// �� �浹 üũ ( �ٴڿ� ���̴� �� )
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
				// 3�ܰ迡�� ���� �ð��� ������ ���������� ��ĭ �ö�;��ϱ� ������ �� �ð��� ��� cnt
				cnt++;
				break;
			}
			// �������� Ȯ��
			if (!CheckEnd()) break;
		}
		// �Ҵ� ����
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
// ���������� ������ �����϶�� �Լ�
void Tetris::Gostagelevel() {
	const int nBlank = 10, nNumOfDescription = 4;
	string strDescription[nNumOfDescription] = { "Go Stage & Level", "���Ͻô� ���������� ������ �������ּ���!", "������ : ���������� 1 ~ 3 , ������ 1 ~ 5 �� �ܸ� �Է��Ͻø� default�� ó���˴ϴ�.", "������ : 3���������� 1�ܰ� �ۿ� �����ϴ�." };
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
// �÷��� ��� ���
int Tetris::HowToPlay() {
	const int nBlank = 10, nNumOfDescription = 8;
	string strDescription[nNumOfDescription] = { "HowToPlay", "��ǥ : ������ �������� ����� �׾� ������ ä�켼��!", "������ : ������ �����Ҽ��� ����� �������� �ӵ��� �����մϴ�.", "�� : ȸ��", "�� : �������� �̵�", "�� : ���������� �̵�", "�� : �Ʒ��� �̵�", "SPACE : �� ������ �̵�" };
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
		d.gotoPrint(5, nNumOfDescription + 7, "�־��� ��ȣ �� �ϳ��� ����ּ���");
		d.gotoxy(8, nNumOfDescription + 6);
		cin >> nChoice;
	}
	return nChoice;
}
// ���� ���
int Tetris::Information() {
	const int nBlank = 10, nNumOfInfo = 6;
	string strInfo[nNumOfInfo] = { "Information", "���� : xxxxxxxx �ڻ��", "���� : xxxxxxxx ������", "���� : xxxxxxxx ����ȣ", "���� : xxxxxxxx ������", "Ver.0" };
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
		d.gotoPrint(5, nNumOfInfo + 7, "�־��� ��ȣ �� �ϳ��� ����ּ���");
		d.gotoxy(8, nNumOfInfo + 6);
		cin >> nChoice;
	}
	return nChoice;
}
// �� ����
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
// �� �̵�
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
// ���� Ŭ���� üũ �Լ�
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
			// ������ ���������� 0�� �ְ� �������� ���� ��Ŵ
			RenewalBoard(i);
			cnt++;
		}
	}
	return cnt;
}
// ������ ����
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
			else cout << "��";
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
// �������� Ȯ��
bool Tetris::CheckEnd() { 
	int i;
	for (i = 0; i < d.GetWidth(); i++) {
		if (Board[0][i] == 1) {
			return false;
		}
	}
	return true;
}
// ������ �ʱ�ȭ // 32
void Tetris::InitBoard() {
	int i, j;
	for (i = 0; i < d.GetHeight(); i++) {
		for (j = 0; j < d.GetWidth(); j++) {
			Board[i][j] = 0;
		}
	}
}
// �������� ���� ����
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
			if (Board[i][j] == 1) cout << "��";
			else cout << "  ";
		}
	}
}
// �������� ���� �б�
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
			else cout << "��";
		}
	}
}