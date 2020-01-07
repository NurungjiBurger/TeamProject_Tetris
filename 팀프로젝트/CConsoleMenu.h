#pragma once
#include "main.h"
#include "Display.h"
using namespace std;

#define MAXMENUCOUNT	 10													//�ִ� �޴� ����, ���� �ø��� ���� ��� ��� ���� ����

class ConsoleMenu {
private:
	string m_strTitle;														//�ܼ� �޴��� ����
	string m_strMenu[MAXMENUCOUNT + 1];										//(�ִ� �޴� ���� + 1(���Ḧ ��Ÿ���� 0��° �޴�))���� �޴�
	int m_nMenuCount;														//����� �޴��� ����
	int m_nAddCount;														//�߰��� �޴��� ����

public:
	//constructor
	ConsoleMenu();
	ConsoleMenu(string);
	ConsoleMenu(int);
	ConsoleMenu(string, int);

	//desetructor
	~ConsoleMenu() {}

	//get, set functions
	string GetTitle() const { return m_strTitle; }			//������ ����
	int GetMenuCount() const { return m_nMenuCount; }			//����� �޴� ������ ����
	int GetAddCount() const { return m_nAddCount; }			//�߰��� �޴� ������ ����

	void SetTitle(string title) { m_strTitle = title; }			//���� ����

	void SetMenuCount(int count) {											//����� �޴� ���� ����
		int i;
		if (count <= MAXMENUCOUNT)
			m_nMenuCount = count;
		if (count < m_nAddCount) {											//������ �޴� ������ �߰��� �޴� �������� ���� ��� 
			for (i = m_nAddCount; i > count; i--) {
				RemoveMenu(i);												//���� ��ȣ�� �޴����� ����
			}
		}
	}

	//functionality
	bool AddMenu(string str);												//�޴� �߰�
	bool RemoveMenu(int);													//�ε����� �޾� �޴� ����
	bool RemoveMenu(string);												//�޴� �̸��� �޾� �޴� ����
	bool UpdateMenu(int, string);											//�ٲٰ� ���� �޴� ����
	int RetrieveMenu(string);												//�޴� �˻��Ͽ� �ε��� ��ȯ
	bool SwitchMenu(string, string);										//�޴� �̸��� �޾� �޴� �ٲٱ�
	bool SwitchMenu(int, int);												//�޴� ��ȣ�� �޾� �޴� �ٲٱ�

																			//optional(print,...)
	int DisplayMenu();														//�ָܼ޴� ���

private:
	int InputMenu();														//�޴� ����
};
/*
member variable
����
�޴� �����
�޴�����

member function

*/