#pragma once
#include "main.h"
#include "Display.h"
using namespace std;

#define MAXMENUCOUNT	 10													//최대 메뉴 개수, 이후 늘리고 싶은 경우 상수 값만 변경

class ConsoleMenu {
private:
	string m_strTitle;														//콘솔 메뉴의 제목
	string m_strMenu[MAXMENUCOUNT + 1];										//(최대 메뉴 개수 + 1(종료를 나타내는 0번째 메뉴))개의 메뉴
	int m_nMenuCount;														//사용할 메뉴의 개수
	int m_nAddCount;														//추가된 메뉴의 개수

public:
	//constructor
	ConsoleMenu();
	ConsoleMenu(string);
	ConsoleMenu(int);
	ConsoleMenu(string, int);

	//desetructor
	~ConsoleMenu() {}

	//get, set functions
	string GetTitle() const { return m_strTitle; }			//제목을 얻음
	int GetMenuCount() const { return m_nMenuCount; }			//사용할 메뉴 개수를 얻음
	int GetAddCount() const { return m_nAddCount; }			//추가된 메뉴 개수를 얻음

	void SetTitle(string title) { m_strTitle = title; }			//제목 설정

	void SetMenuCount(int count) {											//사용할 메뉴 개수 설정
		int i;
		if (count <= MAXMENUCOUNT)
			m_nMenuCount = count;
		if (count < m_nAddCount) {											//설정할 메뉴 개수가 추가된 메뉴 개수보다 작은 경우 
			for (i = m_nAddCount; i > count; i--) {
				RemoveMenu(i);												//높은 번호의 메뉴부터 제거
			}
		}
	}

	//functionality
	bool AddMenu(string str);												//메뉴 추가
	bool RemoveMenu(int);													//인덱스를 받아 메뉴 제거
	bool RemoveMenu(string);												//메뉴 이름을 받아 메뉴 제거
	bool UpdateMenu(int, string);											//바꾸고 싶은 메뉴 수정
	int RetrieveMenu(string);												//메뉴 검색하여 인덱스 반환
	bool SwitchMenu(string, string);										//메뉴 이름을 받아 메뉴 바꾸기
	bool SwitchMenu(int, int);												//메뉴 번호를 받아 메뉴 바꾸기

																			//optional(print,...)
	int DisplayMenu();														//콘솔메뉴 출력

private:
	int InputMenu();														//메뉴 선택
};
/*
member variable
제목
메뉴 제목들
메뉴개수

member function

*/