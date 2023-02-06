#pragma once
#include "Constant.h"

void IniBoardThrow(int myTab[][MAX_COLUMN]);
void ThrowDice(int i,int  myTab[][MAX_COLUMN], bool BoardLock[MAX_COLUMN]);
void DisplayBoardThrow(int myTab[][MAX_COLUMN]);
void IniBoardLock(bool BoardLock[MAX_COLUMN]);
void DiceLock(int i, bool BoardLock[MAX_COLUMN]);
void DisplayBoard(int myScore[9]);
void myPoints(int myTab[][MAX_COLUMN], int MyScore[9], int PointersChoice);