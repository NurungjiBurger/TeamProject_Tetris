#include "block3.h"



block3::block3()
{
	m_nRotation = 0;
	cen_x = 10, cen_y = 0;
}
// 블럭 초기화
int ** block3::Init()
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
	block[1][1] = 1;//5
	block[1][2] = 1;//9
	block[2][1] = 1;//13
	block[2][2] = 1;//14           //ㅁ

	return block;
}


block3::~block3()
{
}
