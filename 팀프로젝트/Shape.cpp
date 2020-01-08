#include "Shape.h"

Display d;

Shape::Shape()
{
}

int ** Shape::Init()
{
	return 0;
}


Shape::~Shape()
{
}
/////////////////////////////////////////////////
// �� �׸���
bool Shape::Draw(bool blank) {
	Display d;
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (m_nBlock[i][j] == 1) {
				d.gotoxy(cen_x + 2 * j, cen_y + i);
				if (blank)
					cout << "��";
				else
					cout << "  ";
			}
		}
	}
	return true;
}
// ���� �����̴� ���� �������� üũ
bool Shape::isValidBlock(int direction) {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (m_nBlock[i][j] == 1) {
				switch (direction) {
				case P2DOWN:if (!(cen_y + i < d.GetHeight()) || Board[cen_y + i][(cen_x + 2 * j) / 2 - 1] == 1) { return false; } break;
				case P2LEFT:
					if (!(cen_x + 2 * j > 2) || Board[cen_y + i - 1][(cen_x + 2 * j) / 2 - 2] == 1)
					{
						return false;
					}
					break;
				case P2RIGHT:if (!(cen_x + 2 * j < 2 * d.GetWidth()) || Board[cen_y + i - 1][(cen_x + 2 * j) / 2] == 1) { return false; } break;
				}
			}
		}
	}
	return true;
}
// �� ȸ���� �������� üũ
bool Shape::isValidRotation() {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (m_nRotateBlock[i][j] == 1) {
				if (Board[cen_y + i - 1][(cen_x + 2 * j) / 2 - 1] == 1) { return false; }
				if (!(cen_y + i <= d.GetHeight())) { return false; }
				if (!(cen_x + 2 * j >= 2)) { return false; }
				if (!(cen_x + 2 * j <= 2 * d.GetWidth())) { return false; }
			}
		}
	}
	return true;
}
// ���忡 �� ä���ֱ�
void Shape::fillTheBoard() {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (m_nBlock[i][j] == 1) {
				Board[cen_y + i - 1][(cen_x + 2 * j) / 2 - 1] = 1;
			}
		}
	}
}
// �ٲ� ���� ����
void Shape::ChangeB(int **b)
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			m_nBlock[i][j] = b[i][j];
		}
	}
}
// �ٲ� ���� ����
void Shape::RChangeB(int **b)
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			m_nRotateBlock[i][j] = b[i][j];
		}
	}
}