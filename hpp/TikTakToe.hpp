#pragma once 

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



	void startGame();
	void takeUserInput();
private:

	bool isDiagonalWinningSequence(int pL, bool pIsHorizontalBigger, bool pIsForwardLeading);
	bool isNonDiagonalWinnerSequence(int pI, bool pIsHorizontal);

	bool isGameOverAndMarkItIfTrue();
	
	void ChangeDataOnInput ();

	CurrentInputLocation input;
	MeshData& data;
};