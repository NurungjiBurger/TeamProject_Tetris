#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;



#define LEFT	75
#define RIGHT   77
#define UP      72
#define DOWN	80
#define SPACE	32

#define START_GAME	1
#define HOW_TO_PLAY	2
#define INFORMATION	3
#define EXIT		0

extern int Board[21][10];


void SetCursorVisible(int bVisible);
