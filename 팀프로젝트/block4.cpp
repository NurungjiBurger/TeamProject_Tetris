#include "block4.h"



block4::block4()
{
	m_nRotation = 0;
	cen_x = 10, cen_y = 0;
}
// 블럭 초기화
int ** block4::Init()
{
	int i, j;
	block = new int*[4];
	for (i = 0; i < 4; i++)
	{
		block[i] = new int[4];
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			block[i][j] = 0;
		}
	}
	block[0][1] = 1;//5
	block[1][1] = 1;//9
	block[2][1] = 1;//13
	block[3][1] = 1;//14           //ㅣ

	return block;
}


block4::~block4()
{
}
