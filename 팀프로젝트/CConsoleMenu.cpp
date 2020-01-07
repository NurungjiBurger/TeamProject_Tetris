#include "CConsoleMenu.h"
using namespace std;

//�� ��� ���� �ʱ�ȭ
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
	//������ �޴��������� �߰��� �޴������� ���ٸ�
	if (m_nAddCount < m_nMenuCount) {
		//�޴� �߰��ϰ� �߰��� �޴� ���� 1 ����
		m_strMenu[m_nAddCount + 1] = str;
		m_nAddCount++;
		return true;
	}
	else
		return false;
}

bool ConsoleMenu::RemoveMenu(int index) {
	int i;
	//������ ��ȣ�� �߰��� �޴����
	if (index >= 1 && index <= m_nAddCount) {
		//�ش� �޴� ����
		for (i = index; i < m_nAddCount; i++) {
			m_strMenu[i] = m_strMenu[i + 1];
		}
		m_strMenu[i].clear();
		//�߰��� �޴� ���� 1 ����
		m_nAddCount--;
		return true;
	}
	else return false;
}

bool ConsoleMenu::RemoveMenu(string menu) {
	int i, j;
	for (i = 1; i <= m_nAddCount; i++) {
		//�޴� �� ������ �޴��� �ִٸ�
		if (m_strMenu[i] == menu) {
			//�ش� �޴� ����
			for (j = i; j < m_nAddCount; j++) {
				m_strMenu[j] = m_strMenu[j + 1];
			}
			m_strMenu[j].clear();
			//�߰��� �޴� ���� 1 ����
			m_nAddCount--;
			return true;
		}
		else return false;
	}
	return false;
}

//�ش� �ε����� �޴��� ����
bool ConsoleMenu::UpdateMenu(int index, string menu) {
	if (index >= 1 && index <= m_nAddCount) {
		m_strMenu[index] = menu;
		return true;
	}
	else return false;
}

int ConsoleMenu::RetrieveMenu(string menu) {
	int i;
	//�߰��� �޴� �� �ش� �޴��� ���� ��� �޴��� ��ȣ ��ȯ
	for (i = 1; i <= m_nAddCount; i++) {
		if (m_strMenu[i] == menu)
			return  i;
	}
	//���ٸ� ������ ����
	return -1;
}

int ConsoleMenu::DisplayMenu() {
	//i:�ݺ� ���� ����, n_MaxLength: ����� �޴��� �� ���� �� ���� ����
	int i, n_MaxLength;
	//ȭ�������
	system("cls");
	n_MaxLength = m_strTitle.length();
	for (i = 0; i < m_nMenuCount; i++) {
		n_MaxLength = n_MaxLength >= m_strMenu[i].length() ? n_MaxLength : m_strMenu[i].length();
	}
	//������ ����� �� �¿� �� 5ĭ ��ŭ�� ������ �ξ� ���
	for (i = 0; i < n_MaxLength + 10; i++) {
		cout << "=";
	}
	cout << endl;
	//Title�� �߾ӿ� ���
	for (i = 0; i < (n_MaxLength + 10) / 2 - m_strTitle.length() / 2; i++)
		cout << " ";
	cout << m_strTitle << endl;
	for (i = 0; i < n_MaxLength + 10; i++) {
		cout << "=";
	}
	cout << endl;
	//�޴� ���
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
	//InputMenu�� ���� ���ù��� �޴��� ��ȣ ��ȯ
	return InputMenu();
}

bool ConsoleMenu::SwitchMenu(string menu1, string menu2) {
	//menu1, menu2�� m_strMenu�迭�� ���� ���
	if (RetrieveMenu(menu1) != -1 && RetrieveMenu(menu2) != -1) {
		//menu1, menu2�� �� menu2, menu1���� ����
		UpdateMenu(RetrieveMenu(menu1), menu2);
		UpdateMenu(RetrieveMenu(menu2), menu1);
		return true;
	}
	else return false;
}

bool ConsoleMenu::SwitchMenu(int index1, int index2) {
	string tmp;
	//index1�� index2�� �߰��� �޴����
	if (index1 >= 1 && index1 <= m_nAddCount && index2 >= 1 && index2 <= m_nAddCount) {
		//�� �ε����� �ش��ϴ� �޴��� ��ȯ
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
	//�߰����� ���� �޴��� ������ ��� 0(EXIT) ��ȯ
	while (!(nChoice >= 0 && nChoice <= m_nAddCount)) {
		d.gotoPrint(8, m_nAddCount + 6, "                        ");
		d.gotoPrint(5, m_nAddCount + 7, "�־��� ��ȣ �� �ϳ��� ����ּ���");
		d.gotoxy(8, m_nAddCount + 6);
		cin >> nChoice;
	}
	return nChoice;
}