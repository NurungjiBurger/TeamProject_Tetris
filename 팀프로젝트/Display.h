#pragma once
#include "main.h"
//#include "CBlock.h"
#include"Shape.h"
using namespace std;

class Display {
private:
	int Width;
	int Height;
public:
	// 생,소멸자
	Display();
	~Display();

	// GET
	int GetWidth() { return Width; }
	int GetHeight() { return Height; }

	void DrawBoard();							// 판 그리기
	void gotoxy(int, int);						// 좌표 x,y로 이동
	void gotoPrint(int, int, string);			// 좌표 x,y로 이동 후 출력
	void ShowNextBlock(int **);					//다음 블록을 보임
	void ShowGameInfo(int, int , int );			// 스테이지, 레벨, 점수를 보임
};