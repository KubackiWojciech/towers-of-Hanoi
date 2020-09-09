#include "Donut.h"
#include <cctype>

std::vector<Donut> Donut::stakeA;
std::vector<Donut> Donut::stakeB;
std::vector<Donut> Donut::stakeC;

int Donut::moveCounter;

void Donut::move(char maneuver[2])
{
	if (checkingIfStacksAreEmpty(maneuver)) return;

	moveCounter++;

	sortInAscendingOrder(maneuver);
	pushItemToDestiantion(maneuver[1], *convertCharToVector(maneuver[0]));
	convertCharToVector(maneuver[0])->pop_back();
}

void Donut::sortInAscendingOrder(char maneuver[2])
{
	if (isVectorEmpty(maneuver[1])) return;
	if (isVectorEmpty(maneuver[0]))
	{
		std::swap(maneuver[0], maneuver[1]);
		return;
	}

	auto firstIterator = convertCharToVector(maneuver[0])->end();
		firstIterator--;
	auto secondIterator = convertCharToVector(maneuver[1])->end();
		secondIterator--;
	if (firstIterator->getSize() > secondIterator->getSize())
		std::swap(maneuver[0], maneuver[1]);
}

bool Donut::isVectorEmpty(char stake)
{
	return convertCharToVector(stake)->empty();
}

std::vector<Donut>* Donut::convertCharToVector(char stake)
{
	switch (stake)
	{
	case 'A':
		return &stakeA;
	case 'B':
		return &stakeB;
	case 'C':
		return &stakeC;
	default:
		return NULL;
	}
}

bool Donut::checkingIfStacksAreEmpty(char maneuver[2])
{
	int emptyStakesCounter = 0;

	if(convertCharToVector(maneuver[0])->empty()) emptyStakesCounter++;
	if(convertCharToVector(maneuver[1])->empty()) emptyStakesCounter++;

	return emptyStakesCounter == 2;
}

void Donut::pushItemToDestiantion(char destination, std::vector<Donut> itemsStake)
{
	auto itemIterator = itemsStake.end();
	itemIterator--;

	convertCharToVector(destination)->push_back(itemIterator->getSize());
}

void Donut::buildStakes(int i)
{
	for (int j = i; j >= 1; j--)
	{
		stakeC.push_back(j);
	}

	moveCounter = 0;
}

bool Donut::isSolved()
{
	if (!stakeB.empty()) return false;
	if (!stakeC.empty()) return false;

	return true;
}

int Donut::getMoveCounter()
{
	return moveCounter;
}