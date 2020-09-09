#pragma once

#include <iostream>
#include <vector>
#include <conio.h>
#include "Donut.h"

class Donut;

class FrontEnd
{
	int numberOfPieces;
	int theBiggestSize;

public:
	FrontEnd(int i);
	void render();

private:
	void renderStake(char stake);
	void renderEmptyLevel();
	void renderStakeLevel(int x);
	void renderBase();

	int calculateEmptyLevels(char stake);

	int numberOfAllMoves;
};

