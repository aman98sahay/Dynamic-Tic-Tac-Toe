#include "MeshPrinter.hpp"
#include "MeshData.hpp"
#include <iostream>

void MeshPrinter::PrivatePrintLocationColor(gameBlock pBlockType)
{
	using std::cout;
	switch (pBlockType) {
	case gameBlock::UNSET:
		cout << " "; break;
	case gameBlock::SET_WITH_O:
		cout << "\x1B[48;5;45m#\033[0m"; break;
	case gameBlock::SET_WITH_X:
		cout << "\x1B[48;5;214m#\033[0m"; break;
	case gameBlock::SET_WITH_O_WITH_WINNING_SEQUENCE:
	case gameBlock::SET_WITH_X_WITH_WINNING_SEQUENCE:
		cout << "\x1B[48;5;231m#\033[0m"; break;
	}
}

bool MeshPrinter::isMarkLocation(int l, int d)
{
	if (((l - 1) / 4) * 4 + 1 == l && ((d - 1) / 4) * 4 + 1 == d) {
		return true;
	}
	return false;
}

bool MeshPrinter::isDividerLocation(int l)
{
	if (((l + 1) / 4) * 4 - 1 == l)
		return true;
	return false;
}

void MeshPrinter::printatLocation(gameBlock pBlockType, int l, int d)
{
	using std::cout;
	if (isDividerLocation(l) && isDividerLocation(d)) {

		cout << "+";
		return;
	}

	if (isDividerLocation(l)) {
		cout << "|";
		return;
	}

	if (isDividerLocation(d)) {
		cout << "-";
		return;
	}

	if (isMarkLocation(l, d)) {
		switch (pBlockType) {
		case gameBlock::UNSET:
			cout << "#"; break; 
		case gameBlock::SET_WITH_O:
		case gameBlock::SET_WITH_O_WITH_WINNING_SEQUENCE:
			cout << "O"; break;
		case gameBlock::SET_WITH_X:
		case gameBlock::SET_WITH_X_WITH_WINNING_SEQUENCE:
			cout << "X"; break;
		}

		return;
	}

	PrivatePrintLocationColor(pBlockType);

	return;

}

void MeshPrinter::printMesh(MeshData& obj)
{
	using std::cout;
	printf("       ");
	for (int l = 0; l <obj.getLength(); l++) {
		printf("%2d  ", l + 1);
	}

	cout << "\n";

	for (int d = 0; d < 4 * obj.getDepth() - 1; d++) {

		if (((d - 1) / 4) * 4 + 1 == d) {
			printf("%5d  ", d / 4 + 1);
		}
		else {
			printf("       ");
		}
		for (int l = 0; l < 4 * obj.getLength() - 1; l++) {
			printatLocation(obj.getDataAt(l/4, d/4), l, d);
		}
		cout << "\n";
	}

}
