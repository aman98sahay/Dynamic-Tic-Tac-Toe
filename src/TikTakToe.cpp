#include <iostream>
#include<conio.h>

#include "TikTakToe.hpp"
#include "MeshData.hpp"
#include "MeshPrinter.hpp"

TikTakToe::TikTakToe(int length, int depth) :
	data(*(new MeshData(length, depth))),
	vInput{ 0,0,false },
	isGameOver(false),
	noOfTurns(0)
{

}

void TikTakToe::startGame()
{
	using std::cout;
	while (noOfTurns != data.getLength() * data.getDepth()) {
		system("cls");
		MeshPrinter::printMesh(data);
		takeUserInput();
		ChangeDataOnInput();
		noOfTurns++;
	}


}

// TODO: this is not going to be that easy, approaches till now ,either add another parameter to the 
// function or imagine another interface.
bool TikTakToe::isDiagonalWinningSequence(int pL, bool pIsHorizontalBigger, bool pIsForwardLeading)
{
	if (pIsHorizontalBigger) {

	}
	else {

	}
	return false;
}

bool TikTakToe::isNonDiagonalWinnerSequence(int pI, bool pIsHorizontal)
{
	if (pIsHorizontal) {

	}
	else {

	}
	return false;
}

bool TikTakToe::isGameOverAndMarkItIfTrue()
{
	// checks for columns if they have a winning sequence
	for (int i = 0; i < data.getLength(); i++) {
		bool isCurrentColumnonlyX = true;
		bool isCurrentColumnonlyO = true;
		for (int j = 0; j < data.getDepth(); i++) {

			if (isCurrentColumnonlyO && !(data.getDataAt(i, j) == gameBlock::SET_WITH_O)) {

				isCurrentColumnonlyO = false;
			}

			if (isCurrentColumnonlyX && !(data.getDataAt(i, j) == gameBlock::SET_WITH_X)) {

				isCurrentColumnonlyX = false;
			}
		}

		if (isCurrentColumnonlyO) {
			for (int j = 0; j < data.getDepth(); j++) {
				data.getDataAt(i, j) = gameBlock::SET_WITH_O_WITH_WINNING_SEQUENCE;
			}
			return true;
		}

		if (isCurrentColumnonlyX) {
			for (int j = 0; j < data.getDepth(); j++) {
				data.getDataAt(i, j) = gameBlock::SET_WITH_X_WITH_WINNING_SEQUENCE;
			}
			return true;
		}
	}

	// checks for rows if they have a winning sequence
	for (int i = 0; i < data.getDepth(); i++) {
		bool isCurrentRowOnlyX = true;
		bool isCurrentRowOnlyO = true;
		for (int j = 0; j < data.getLength(); i++) {

			if (isCurrentRowOnlyO && !(data.getDataAt(j, i) == gameBlock::SET_WITH_O)) {

				isCurrentRowOnlyO = false;
			}

			if (isCurrentRowOnlyX && !(data.getDataAt(j, i) == gameBlock::SET_WITH_X)) {

				isCurrentRowOnlyX = false;
			}
		}

		if (isCurrentRowOnlyO) {
			for (int j = 0; j < data.getLength(); j++) {
				data.getDataAt(j, i) = gameBlock::SET_WITH_O_WITH_WINNING_SEQUENCE;
			}
			return true;
		}

		if (isCurrentRowOnlyX) {
			for (int j = 0; j < data.getLength(); j++) {
				data.getDataAt(j, i) = gameBlock::SET_WITH_X_WITH_WINNING_SEQUENCE;
			}
			return true;
		}
	}

	/* check diagonals, how will you check diagonal ?
	*  think there are actually 2 types of diagonals on is forward heading and the other is backward heading

	*/


	// checked all sequences the game is clearly not over
	return false;
}

void TikTakToe::ChangeDataOnInput()
{
	switch (vInput.isPlayerXInput) {
	case true:
		data.setDataAt(vInput.l - 1, vInput.d - 1, gameBlock::SET_WITH_X);
		break;
	case false:
		data.setDataAt(vInput.l - 1, vInput.d - 1, gameBlock::SET_WITH_O);
	}

	vInput.isPlayerXInput = !vInput.isPlayerXInput;
}

void TikTakToe::takeUserInput()
{
	using std::cout, std::cin;
	char ch = 'f';

	cout << "\nChance of player ";

	if (vInput.isPlayerXInput) {
		cout << "'X'";
	}
	else {
		cout << "'O'";
	}

	cout << "\nEnter the location in the format length,depth(ie the length then a ',' and then depth"
		" as is given in the Tik-Tack-Toe board : ";

	while (true) {

		while (!bool(cin >> vInput.l >> ch >> vInput.d)) {
			endl(cout << "invalid input, please try again:");
			cin.clear(); // clears the error flags
			// this line discards all the vInput waiting in the stream
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		if (vInput.l > data.getLength() || vInput.d > data.getDepth() || data.getDataAt(vInput.l - 1, vInput.d - 1) != gameBlock::UNSET) {

			endl(cout << "invalid input, please try again:");
		}
		else
			break;

	}

}
