#pragma once
//#include "CBlock.h"
#include "CConsoleMenu.h"
#include "Display.h"


///////////////////////////
#include"Shape.h"
#include"block1.h"
#include"block2.h"
#include"block3.h"
#include"block4.h"
#include"block5.h"
#include"block6.h"
#include"block7.h"

////////////////////////



class Tetris {
private:
	int nFrame;						// ���� �ð� üũ
	int nSpeed;						// ���� �ӵ�
	int nLevel;						// ���� �ܰ�
	int nScore;						// ����
	int nstage;						// ���� ��������
	int nNumber;					// �÷��̾� ��
	int playernumber;				// �÷��̾��� ��ȣ

	// ��Ʈ���� Ŭ�������� ���� ������Ʈ��
	Display d;
	Shape b;
	////////////////////////////
	block1 b1;
	block2 b2;
	block3 b3;
	block4 b4;
	block5 b5;
	block6 b6;
	block7 b7;

	/////////////////////////////

public:
	// ��, �Ҹ���
	Tetris();
	Tetris(int, int, int, int, int, int);
	~Tetris();

	int getnFrame();					// 2p�� 1p�� �ʱ⼳���� ������ ���ֱ�����
	int getnSpeed();					// get �޼ҵ��
	int getnLevel();
	int getnStage();
	int getnNumber();

	void setnFrame(int);					// 2p�� 1p�� �ʱ⼳���� ������ ���ֱ�����
	void setnSpeed(int);					// set �޼ҵ��
	void setnLevel(int);
	void setnStage(int);

	
	//void InsertPlayernumber();			// �÷��̾� �� �Է�
	void StartGame();					// ���� ����
	void Run();							// ���� ( �ָܼ޴������ֱ� )
	int HowToPlay();					// �÷��� ���
	int Information();					// ����
	void Gostagelevel();				// ���������� �ܰ� �Է�
	bool Move(Shape &,int **,int **);	// �� �̵�
	void Fall(Shape &);					// �� ����
	int FullLineCheck();				// ���� Ŭ���� üũ
	void RenewalBoard(int);				// ������ ����
	//int MakeBlock(Block &);
	bool CheckEnd();					// �������� Ȯ��
	void InitBoard();					// ������ �ʱ�ȭ
	void SetStage();					// �������� ���� ����
	void UpStage();						// ������ ���� �б�
	/////////////////////////////
	int Rotate(int x, int y, int r);	// �� ȸ��

};