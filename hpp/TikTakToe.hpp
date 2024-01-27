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


	
	TikTakToe(int length, int depth);

	~TikTakToe();

	void startGame();
	void takeUserInput();
private:

	bool isDiagonalWinningSequence(bool pIsHorizontalBigger, bool pIsClockWiseLater, int l, int d, bool isX);
	bool isNonDiagonalWinnerSequence(int pI, bool pIsHorizontal);

	bool isGameBlockX(gameBlock block);
	bool isGameBlockO(gameBlock block);
	
	bool isGameOverAndMarkItIfTrue();
	
	void ChangeDataOnInput ();

	CurrentInputLocation vInput;
	MeshData& data;
	bool isGameOver;
	int noOfTurns;
};