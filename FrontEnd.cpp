#include "FrontEnd.h"
#include <cmath>


FrontEnd::FrontEnd(int i)
{
	numberOfPieces = i;
	theBiggestSize = i * 2 + 1;
	numberOfAllMoves = pow(2, numberOfPieces) - 1;
}

void FrontEnd::render()
{
	system("cls");
	std::cout << "number of moves made: " << Donut::getMoveCounter() <<" / "<<numberOfAllMoves<< std::endl;

	renderStake('A');
	renderStake('B');
	renderStake('C');
	//_getch();
}

void FrontEnd::renderStake(char stake)
{
	std::cout << "Stake: " << stake << std::endl;

	if (Donut::isVectorEmpty(stake))
	{
		for (int i = 0; i < numberOfPieces+1; i++) renderEmptyLevel();
		renderBase();
		return;
	}

	std::vector<Donut>::iterator it;
		it = Donut::convertCharToVector(stake)->end();
		it--;
	int emptyLevels = calculateEmptyLevels(stake);
	int nonEmptyLevels = numberOfPieces - emptyLevels;

	renderEmptyLevel();

	for (int i = 0; i < emptyLevels; i++) renderEmptyLevel();

	for (; it !=Donut::convertCharToVector(stake)->begin(); it--)
	{
		renderStakeLevel(it->getSize());
	}

	renderStakeLevel(it->getSize());

	renderBase();
}

void FrontEnd::renderEmptyLevel()
{
	for (int i = 0; i < theBiggestSize / 2+1; i++) std::cout << " ";
	std::cout << "|\n";
}

void FrontEnd::renderStakeLevel(int x)
{
	int numberOfSpacesOnEachSide = (theBiggestSize - (x*2-1)) / 2;
	
	std::string output = "";
	for (int i = 0; i < numberOfSpacesOnEachSide; i++) output += " ";
	for (int i = 0; i < x*2+1; i++) output += "#";
	for (int i = 0; i < numberOfSpacesOnEachSide; i++) output += " ";

	std::cout << output << std::endl;
}

void FrontEnd::renderBase()
{
	for (int i = 0; i < theBiggestSize+2; i++)
		std::cout << "=";
	std::cout << std::endl;
}

int FrontEnd::calculateEmptyLevels(char stake)
{
	switch (stake)
	{
	case 'A':
		return numberOfPieces - Donut::stakeA.size();
	case 'B':
		return numberOfPieces - Donut::stakeB.size();
	case 'C':
		return numberOfPieces - Donut::stakeC.size();
	default:
		return 0;
	}
}