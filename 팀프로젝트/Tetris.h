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
	int nFrame;						// 낙하 시간 체크
	int nSpeed;						// 낙하 속도
	int nLevel;						// 게임 단계
	int nScore;						// 점수
	int nstage;						// 게임 스테이지
	int nNumber;					// 플레이어 수
	int playernumber;				// 플레이어의 번호

	// 테트리스 클래스에서 사용될 오브젝트들
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
	// 생, 소멸자
	Tetris();
	Tetris(int, int, int, int, int, int);
	~Tetris();

	int getnFrame();					// 2p와 1p의 초기설정을 같도록 해주기위한
	int getnSpeed();					// get 메소드들
	int getnLevel();
	int getnStage();
	int getnNumber();

	void setnFrame(int);					// 2p와 1p의 초기설정을 같도록 해주기위한
	void setnSpeed(int);					// set 메소드들
	void setnLevel(int);
	void setnStage(int);

	
	//void InsertPlayernumber();			// 플레이어 수 입력
	void StartGame();					// 게임 시작
	void Run();							// 실행 ( 콘솔메뉴보여주기 )
	int HowToPlay();					// 플레이 방법
	int Information();					// 정보
	void Gostagelevel();				// 스테이지와 단계 입력
	bool Move(Shape &,int **,int **);	// 블럭 이동
	void Fall(Shape &);					// 블럭 낙하
	int FullLineCheck();				// 라인 클리어 체크
	void RenewalBoard(int);				// 보드판 갱신
	//int MakeBlock(Block &);
	bool CheckEnd();					// 종료조건 확인
	void InitBoard();					// 보드판 초기화
	void SetStage();					// 스테이지 랜덤 설정
	void UpStage();						// 보드판 위로 밀기
	/////////////////////////////
	int Rotate(int x, int y, int r);	// 블럭 회전

};