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
	// ��,�Ҹ���
	Display();
	~Display();

	// GET
	int GetWidth() { return Width; }
	int GetHeight() { return Height; }

	void DrawBoard();							// �� �׸���
	void gotoxy(int, int);						// ��ǥ x,y�� �̵�
	void gotoPrint(int, int, string);			// ��ǥ x,y�� �̵� �� ���
	void ShowNextBlock(int **);					//���� ����� ����
	void ShowGameInfo(int, int , int );			// ��������, ����, ������ ����
};