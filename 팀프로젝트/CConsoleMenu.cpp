#include "CConsoleMenu.h"
using namespace std;

//각 멤버 변수 초기화
ConsoleMenu::ConsoleMenu() {
	m_strTitle = "Title";
	m_nMenuCount = 0;
	m_nAddCount = 0;
	m_strMenu[0] = "Exit";
}

ConsoleMenu::ConsoleMenu(string title) {
	m_strTitle = title;
	m_nMenuCount = 0;
	m_nAddCount = 0;
	m_strMenu[0] = "Exit";
}
ConsoleMenu::ConsoleMenu(int menucount) {
	m_strTitle = "Title";
	m_nMenuCount = menucount;
	m_nAddCount = 0;
	m_strMenu[0] = "Exit";
}

ConsoleMenu::ConsoleMenu(string title, int menucount) {
	m_strTitle = title;
	m_nMenuCount = menucount;
	m_nAddCount = 0;
	m_strMenu[0] = "Exit";
}

bool ConsoleMenu::AddMenu(string str) {
	//설정된 메뉴개수보다 추가된 메뉴개수가 적다면
	if (m_nAddCount < m_nMenuCount) {
		//메뉴 추가하고 추가된 메뉴 개수 1 증가
		m_strMenu[m_nAddCount + 1] = str;
		m_nAddCount++;
		return true;
	}
	else
		return false;
}

bool ConsoleMenu::RemoveMenu(int index) {
	int i;
	//제거할 번호가 추가된 메뉴라면
	if (index >= 1 && index <= m_nAddCount) {
		//해당 메뉴 제거
		for (i = index; i < m_nAddCount; i++) {
			m_strMenu[i] = m_strMenu[i + 1];
		}
		m_strMenu[i].clear();
		//추가된 메뉴 개수 1 감소
		m_nAddCount--;
		return true;
	}
	else return false;
}

bool ConsoleMenu::RemoveMenu(string menu) {
	int i, j;
	for (i = 1; i <= m_nAddCount; i++) {
		//메뉴 중 제거할 메뉴가 있다면
		if (m_strMenu[i] == menu) {
			//해당 메뉴 제거
			for (j = i; j < m_nAddCount; j++) {
				m_strMenu[j] = m_strMenu[j + 1];
			}
			m_strMenu[j].clear();
			//추가된 메뉴 개수 1 감소
			m_nAddCount--;
			return true;
		}
		else return false;
	}
	return false;
}

//해당 인덱스의 메뉴를 수정
bool ConsoleMenu::UpdateMenu(int index, string menu) {
	if (index >= 1 && index <= m_nAddCount) {
		m_strMenu[index] = menu;
		return true;
	}
	else return false;
}

int ConsoleMenu::RetrieveMenu(string menu) {
	int i;
	//추가된 메뉴 중 해당 메뉴가 있을 경우 메뉴의 번호 반환
	for (i = 1; i <= m_nAddCount; i++) {
		if (m_strMenu[i] == menu)
			return  i;
	}
	//없다면 비정상 종료
	return -1;
}

int ConsoleMenu::DisplayMenu() {
	//i:반복 제어 변수, n_MaxLength: 제목과 메뉴들 중 가장 긴 길이 저장
	int i, n_MaxLength;
	//화면지우기
	system("cls");
	n_MaxLength = m_strTitle.length();
	for (i = 0; i < m_nMenuCount; i++) {
		n_MaxLength = n_MaxLength >= m_strMenu[i].length() ? n_MaxLength : m_strMenu[i].length();
	}
	//라인을 출력할 때 좌우 각 5칸 만큼의 여유를 두어 출력
	for (i = 0; i < n_MaxLength + 10; i++) {
		cout << "=";
	}
	cout << endl;
	//Title을 중앙에 출력
	for (i = 0; i < (n_MaxLength + 10) / 2 - m_strTitle.length() / 2; i++)
		cout << " ";
	cout << m_strTitle << endl;
	for (i = 0; i < n_MaxLength + 10; i++) {
		cout << "=";
	}
	cout << endl;
	//메뉴 출력
	for (i = 1; i <= m_nAddCount; i++) {
		cout << "     " << i << "." << m_strMenu[i] << endl;
	}
	for (i = 0; i < n_MaxLength + 10; i++) {
		cout << "=";
	}
	cout << endl;
	cout << "     " << "0." << m_strMenu[0] << endl;
	for (i = 0; i < n_MaxLength + 10; i++) {
		cout << "=";
	}
	cout << endl;
	//InputMenu를 통해 선택받은 메뉴의 번호 반환
	return InputMenu();
}

bool ConsoleMenu::SwitchMenu(string menu1, string menu2) {
	//menu1, menu2가 m_strMenu배열에 있을 경우
	if (RetrieveMenu(menu1) != -1 && RetrieveMenu(menu2) != -1) {
		//menu1, menu2를 각 menu2, menu1으로 수정
		UpdateMenu(RetrieveMenu(menu1), menu2);
		UpdateMenu(RetrieveMenu(menu2), menu1);
		return true;
	}
	else return false;
}

bool ConsoleMenu::SwitchMenu(int index1, int index2) {
	string tmp;
	//index1과 index2가 추가된 메뉴라면
	if (index1 >= 1 && index1 <= m_nAddCount && index2 >= 1 && index2 <= m_nAddCount) {
		//각 인덱스에 해당하는 메뉴를 교환
		tmp = m_strMenu[index1];
		m_strMenu[index1] = m_strMenu[index2];
		m_strMenu[index2] = tmp;
		return true;
	}
	else return false;
}

int ConsoleMenu::InputMenu() {
	int nChoice;
	Display d;
	d.gotoPrint(5, m_nAddCount+6, ">> ");
	cin >> nChoice;
	//추가되지 않은 메뉴를 선택할 경우 0(EXIT) 반환
	while (!(nChoice >= 0 && nChoice <= m_nAddCount)) {
		d.gotoPrint(8, m_nAddCount + 6, "                        ");
		d.gotoPrint(5, m_nAddCount + 7, "주어진 번호 중 하나를 골라주세요");
		d.gotoxy(8, m_nAddCount + 6);
		cin >> nChoice;
	}
	return nChoice;
}