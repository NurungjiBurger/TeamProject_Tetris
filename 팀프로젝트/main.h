#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;



#define P2LEFT	75
#define P2RIGHT   77
#define P2UP      72
#define P2DOWN	80
#define P1LEFT	97
#define P1RIGHT   100
#define P1UP      119 
#define P1DOWN	115

#define P2DOWNSHIFT 13
#define P1DOWNSHIFT	9

#define START_GAME	1
#define HOW_TO_PLAY	2
#define INFORMATION	3
#define EXIT		0

extern int Board[21][10];


void SetCursorVisible(int bVisible);
