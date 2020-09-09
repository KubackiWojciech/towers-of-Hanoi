#pragma once

#include <vector>
#include <windows.h>
#include "FrontEnd.h"

class Donut;

struct returnStruct
{
	std::vector<Donut>::iterator returnIterator;
	char returnStake;
};

class Donut
{
	static std::vector<Donut> stakeA;
	static std::vector<Donut> stakeB;
	static std::vector<Donut> stakeC;

	int size;
	static int moveCounter;

public:
	Donut(int i) { size=i;}
	static void buildStakes(int i);

	static void move(char maneuver[2]);

	int getSize() { return size; }

	static bool isSolved();
	static int getMoveCounter();

private:
	static bool checkingIfStacksAreEmpty(char maneuver[2]);
	static void sortInAscendingOrder(char maneuver[2]); //after run this, maneuver[1] becomes destination and maneuver[0] becomes source
	static bool isVectorEmpty(char stake);
	static std::vector<Donut>* convertCharToVector(char stake);
	static void pushItemToDestiantion(char destination, std::vector<Donut> itemsStake);

	friend class FrontEnd;
};

