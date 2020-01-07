#pragma once
#include "Shape.h"
class block3 :
	public Shape
{
public:
	block3();
	virtual int **Init();
	~block3();
};

