#pragma once 

#include <basicenums.hpp>

class MeshData;
class MeshPrinter;
struct CurrentInputLocation {
	int l;
	int d;
	bool isPlayerXInput;
};

class TikTakToe {

public:


	
	TikTakToe(int depth, int length);

	~TikTakToe();

	void startGame();
	void takeUserInput();
private:

	bool isDiagonalWinningSequenceMarkIfTrue(bool pIsHorizontalBigger, bool pIsClockWiseLater, int l, int d, bool isX);
	bool isNonDiagonalWinnerSequenceMarkIfTrue(int pI, bool pIsHorizontal);

	static bool isGameBlockX(gameBlock block);
	
	void ChangeDataOnInput ();

	void internalGameRuleChecker();

	CurrentInputLocation vInput;
	MeshData& data;
	bool isGameOver;
	int noOfTurns;
};