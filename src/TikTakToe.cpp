#include <iostream>
#include <climits>

#include "TikTakToe.hpp"
#include "MeshData.hpp"
#include "MeshPrinter.hpp"
#include "basicenums.hpp"

TikTakToe::TikTakToe(int depth, int length) :
	data(*(new MeshData(length, depth))),
	vInput{ 0,0,false },
	isGameOver(false),
	noOfTurns(0)
{

}

TikTakToe::~TikTakToe()
{
	delete& data;
}

// TODO: I just noticed another edge case that my program does not handle and that is 
// consider a 3 X 4 mesh with 'O's from 2,0 to 2,2 that is a winner case that my program does not handle
void TikTakToe::startGame()
{
	using std::cout;
	while (noOfTurns != data.getLength() * data.getDepth() && !isGameOver) {
#if		_WIN32
		system("cls");
#elif	__APPLE__ || __linux__
		system("clear");
#endif
		MeshPrinter::printMesh(data);
		takeUserInput();
		ChangeDataOnInput();
		internalGameRuleChecker();
		noOfTurns++;
	}

	// to refresh the mesh after the last input is given in no win situation 
	system("cls");
	MeshPrinter::printMesh(data);

	if (isGameOver) {
		cout << "The game is won by player with symbol : ";
		if (!vInput.isPlayerXInput) {
			cout << "(X)";
		}
		else
			cout << "(O)";
	}
	else {
		cout << "All the blocks in the Mesh are filled.\n";
		cout << "It was a fierce battle nobody won.\n";
	}
	cout << "\n";
}
/*
*
* There are 2 separate cases that have to be considered
* first if the no of rows more than the number of columns(if they are same
* we can just call the function with one and the logic should work,
* after that we mention is the diagonal we are checking whether it come clockwise first or second
*
*
*/
bool TikTakToe::isDiagonalWinningSequenceMarkIfTrue(bool pIsHorizontalBigger, bool pIsClockWiseLater, int l, int d, bool isX)
{
	bool rc;
	if (pIsHorizontalBigger) {

		if (pIsClockWiseLater) {
			if (d == 0 && (l < data.getDepth() - 1))
				return false;
		}
		else {
			if (d == 0 && (l > data.getLength() - data.getDepth()))
				return false;
		}

		if (isGameBlockX(data.getDataAt(l, d)) == isX && data.getDataAt(l, d) != gameBlock::UNSET) {

			if (d == data.getDepth() - 1) {

				data.setDataAt(l, d, isX ? gameBlock::SET_WITH_X_WITH_WINNING_SEQUENCE : gameBlock::SET_WITH_O_WITH_WINNING_SEQUENCE);
				return true;
			}

			if (pIsClockWiseLater)
				rc = isDiagonalWinningSequenceMarkIfTrue(pIsHorizontalBigger, pIsClockWiseLater, l - 1, d + 1, isX);
			else
				rc = isDiagonalWinningSequenceMarkIfTrue(pIsHorizontalBigger, pIsClockWiseLater, l + 1, d + 1, isX);

			if (rc == true)
				data.setDataAt(l, d, isX ? gameBlock::SET_WITH_X_WITH_WINNING_SEQUENCE : gameBlock::SET_WITH_O_WITH_WINNING_SEQUENCE);
			return rc;
		}
		else
			return false;
	}
	else {

		if (pIsClockWiseLater) {
			if (l == 0 && (d > data.getDepth() - data.getLength()))
				return false;
		}
		else {
			if (l == 0 && (d < data.getLength() - 1))
				return false;
		}

		if (isGameBlockX(data.getDataAt(l, d)) == isX && data.getDataAt(l, d) != gameBlock::UNSET) {

			if (l == data.getLength() - 1) {

				data.setDataAt(l, d, isX ? gameBlock::SET_WITH_X_WITH_WINNING_SEQUENCE : gameBlock::SET_WITH_O_WITH_WINNING_SEQUENCE);
				return true;
			}

			if (pIsClockWiseLater)
				rc = isDiagonalWinningSequenceMarkIfTrue(pIsHorizontalBigger, pIsClockWiseLater, l + 1, d + 1, isX);
			else
				rc = isDiagonalWinningSequenceMarkIfTrue(pIsHorizontalBigger, pIsClockWiseLater, l + 1, d - 1, isX);


			if (rc == true)
				data.setDataAt(l, d, isX ? gameBlock::SET_WITH_X_WITH_WINNING_SEQUENCE : gameBlock::SET_WITH_O_WITH_WINNING_SEQUENCE);
			return rc;
		}
		else
			return false;
	}
	return false;
}

/*
input
	pI : the number ( starting with 0) of the row or column

*/
bool TikTakToe::isNonDiagonalWinnerSequenceMarkIfTrue(int pI, bool pIsHorizontal)
{
	static const int SmallerOfTheDimensions = data.getDepth() >= data.getLength() ? data.getLength() : data.getDepth();
	int vicinity_same = 0;
	gameBlock comparingWith = gameBlock::UNSET;
	gameBlock currentValue;
	bool isForLoopInvariantSet = false;
	if (pIsHorizontal) {

		const int length = data.getLength();

		for (int i = 0; i <= length; i++) {

			if (i == length) {
				if (vicinity_same >= SmallerOfTheDimensions) {
					for (int j = 0; j < vicinity_same; j++)
					{
						data.setDataAt(i - 1 - j, pI, comparingWith == gameBlock::SET_WITH_X ? gameBlock::SET_WITH_X_WITH_WINNING_SEQUENCE : gameBlock::SET_WITH_O_WITH_WINNING_SEQUENCE);

					}
					return true;
				}
				break;
			}
			else
				currentValue = data.getDataAt(i, pI);


			if (!isForLoopInvariantSet) {

				comparingWith = currentValue;
				if (comparingWith == gameBlock::UNSET)
					continue;

				isForLoopInvariantSet = true;
				vicinity_same++;
				continue;
			}


			if (currentValue == gameBlock::UNSET || currentValue != comparingWith) {
				if (vicinity_same >= SmallerOfTheDimensions) {
					for (int j = 0; j < vicinity_same; j++)
					{
						data.setDataAt(i - 1 - j, pI, comparingWith == gameBlock::SET_WITH_X ? gameBlock::SET_WITH_X_WITH_WINNING_SEQUENCE : gameBlock::SET_WITH_O_WITH_WINNING_SEQUENCE);

					}
					return true;
				}
				isForLoopInvariantSet = false;
				vicinity_same = 0;
				if (currentValue != gameBlock::UNSET)
					vicinity_same++;
				continue;
			}

			vicinity_same++;

		}
	}
	else {

		const int depth = data.getDepth();

		for (int i = 0; i <= depth; i++) {

			if (i == depth) {
				if (vicinity_same >= SmallerOfTheDimensions) {
					for (int j = 0; j < vicinity_same; j++)
					{
						data.setDataAt(pI, i - 1 - j, comparingWith == gameBlock::SET_WITH_X ? gameBlock::SET_WITH_X_WITH_WINNING_SEQUENCE : gameBlock::SET_WITH_O_WITH_WINNING_SEQUENCE);
					}
					return true;
				}
				break;
			}
			else
				currentValue = data.getDataAt(pI, i);


			if (!isForLoopInvariantSet) {

				comparingWith = currentValue;
				if (comparingWith == gameBlock::UNSET)
					continue;

				isForLoopInvariantSet = true;
				vicinity_same++;
				continue;
			}


			if (currentValue == gameBlock::UNSET || currentValue != comparingWith) {
				if (vicinity_same >= SmallerOfTheDimensions) {
					for (int j = 0; j < vicinity_same; j++)
					{
						data.setDataAt(pI, i - 1 - j, comparingWith == gameBlock::SET_WITH_X ? gameBlock::SET_WITH_X_WITH_WINNING_SEQUENCE : gameBlock::SET_WITH_O_WITH_WINNING_SEQUENCE);

					}
					return true;
				}
				isForLoopInvariantSet = false;
				vicinity_same = 0;
				if (currentValue != gameBlock::UNSET)
					vicinity_same++;
				continue;
			}

			vicinity_same++;

		}
	}

	return false;
}

bool TikTakToe::isGameBlockX(gameBlock block)
{
	return block == gameBlock::SET_WITH_X || block == gameBlock::SET_WITH_X_WITH_WINNING_SEQUENCE;
}

bool TikTakToe::areBlocksSameAndBothNotUnset(gameBlock block1, gameBlock block2)
{
	if (block1 == gameBlock::UNSET || block2 == gameBlock::UNSET)
		return false;

	return block1 == block2;
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

void TikTakToe::internalGameRuleChecker()
{
	// checking horizontals
	for (int i = 0; i < data.getDepth(); i++)
	{
		isGameOver = TikTakToe::isNonDiagonalWinnerSequenceMarkIfTrue(i, true) || isGameOver;
	}

	// checking verticals 
	for (int i = 0; i < data.getLength(); i++)
	{
		isGameOver = TikTakToe::isNonDiagonalWinnerSequenceMarkIfTrue(i, false) || isGameOver;
	}

	// checking diagonals 
	if (data.getLength() >= data.getDepth()) {
		for (int i = 0; i < data.getLength(); i++)
		{
			bool isX = TikTakToe::isGameBlockX(data.getDataAt(i, 0));
			isGameOver = TikTakToe::isDiagonalWinningSequenceMarkIfTrue(true, false, i, 0, isX) || isGameOver;
			isGameOver = TikTakToe::isDiagonalWinningSequenceMarkIfTrue(true, true, i, 0, isX) || isGameOver;
		}
	}
	else {
		for (int i = 0; i < data.getDepth(); i++)
		{
			bool isX = TikTakToe::isGameBlockX(data.getDataAt(0, i));
			isGameOver = TikTakToe::isDiagonalWinningSequenceMarkIfTrue(false, false, 0, i, isX) || isGameOver;
			isGameOver = TikTakToe::isDiagonalWinningSequenceMarkIfTrue(false, true, 0, i, isX) || isGameOver;
		}
	}
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

	cout << "\nEnter the location in the format depth, length(ie the depth then a ',' and then length)"
		" as is given in the Tik-Tack-Toe board : ";

	while (true) {

		while (!bool(cin >> vInput.d >> ch >> vInput.l)) {
			endl(cout << "invalid input, please try again:");
			cin.clear(); // clears the error flags
			// this line discards all the vInput waiting in the stream
			cin.ignore(INT_MAX, '\n');  //as std::numeric_limits<std::streamsize>::max() is not compiling in linux
		}

		if (vInput.l > data.getLength() || vInput.d > data.getDepth() || data.getDataAt(vInput.l - 1, vInput.d - 1) != gameBlock::UNSET) {

			endl(cout << "invalid input, please try again:");
		}
		else
			break;

	}

}
