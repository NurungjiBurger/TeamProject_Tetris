#pragma once
#include "main.h"
#include "Display.h"
class Shape
{
protected:
	int **block;							
	int m_nBlock[4][4] = { 0 };				
	int m_nRotateBlock[4][4] = { 0 };
	int m_nRotation;					// 회전 
	int cen_x, cen_y;					// 블럭의 x,y 좌표
public:
	// 생, 소멸자
	Shape();
	virtual int **Init();
	~Shape();

	///////////////////////////////////
	int GetRotation() const { return m_nRotation; }
	int GetCen_X() const { return cen_x; }
	int GetCen_Y() const { return cen_y; }
	//int GetShape() const { return m_nShape; }

	void SetCen_X(const int &x) { cen_x = x; }
	void SetCen_Y(const int &y) { cen_y = y; }
	void SetRotation(const int &rotation) { m_nRotation = rotation; }
	//void SetShape(const int &shape) { m_nShape = shape; }
	void SetBlock(const int &x, const int &y, const int &r) { cen_x = x, cen_y = y, m_nRotation = r; }

	//function
	virtual bool Draw(bool block);					// 블럭 그리기
	virtual bool isValidBlock(int direction);		// 블럭 유효성 체크 ( 이동방향 )
	virtual bool isValidRotation();					// 블럭 유효성 체크 ( 회전 )
	virtual void fillTheBoard();					// 블럭 채워넣기
	//destructor
	
	/////////////////////////////////////
	void ChangeB(int **);							
	void RChangeB(int **);							
};

