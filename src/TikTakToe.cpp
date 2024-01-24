#include "TikTakToe.hpp"
#include "MeshData.hpp"
#include "MeshPrinter.hpp"

TikTakToe::TikTakToe(int length, int depth) : data(*(new MeshData(length,depth))), printer(*(new MeshPrinter))
{

}

void TikTakToe::startGame()
{



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

			if (isCurrentRowOnlyO && !(data.getDataAt(j,i) == gameBlock::SET_WITH_O)) {

				isCurrentRowOnlyO = false;
			}

			if (isCurrentRowOnlyX && !(data.getDataAt(j,i) == gameBlock::SET_WITH_X)) {

				isCurrentRowOnlyX = false;
			}
		}

		if (isCurrentRowOnlyO) {
			for (int j = 0; j < data.getLength(); j++) {
				data.getDataAt(j,i) = gameBlock::SET_WITH_O_WITH_WINNING_SEQUENCE;
			}
			return true;
		}

		if (isCurrentRowOnlyX) {
			for (int j = 0; j < data.getLength(); j++) {
				data.getDataAt(j,i) = gameBlock::SET_WITH_X_WITH_WINNING_SEQUENCE;
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
