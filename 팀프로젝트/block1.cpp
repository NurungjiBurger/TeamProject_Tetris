#include "block1.h"



block1::block1()
{
	m_nRotation = 0;
	cen_x = 10, cen_y = 0;
}
// 블럭 초기화
int ** block1::Init()
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
	}/*
	block[0][2] = 3;
	block[0][3] = 3;
	block[1][0] = 3;
	block[1][1] = 3;
	block[1][2] = 3;
	block[2][1] = 3;
	block[3][0] = 3;
	block[3][1] = 3;
	block[3][2] = 3;
	*/

	block[1][2] = 1;//5
	block[2][2] = 1;//9
	block[3][1] = 1;//13
	block[3][2] = 1;//14           //ㄴ 반대

	return block;
}


block1::~block1()
{
}
