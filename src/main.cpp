#include <iostream>
#include <conio.h>
using namespace std;

#include <MeshData.hpp>
#include <MeshPrinter.hpp>


int main() {
	cout << "Currently developing the classes which would be required. Once they are done I will just use them in main."\
		"Till then have a nice day" << endl;;

	MeshData data(3, 4);
	// Checks if printer works
	for (int i = 0; i < 3 * 4; i++) {
		system("cls");
		if (i % 2 == 0)
			data.setDataAt(i % 3, i / 3, gameBlock::SET_WITH_O);
		else
			data.setDataAt(i % 3, i / 3, gameBlock::SET_WITH_X);

		MeshPrinter::printMesh(data);
		cout << i % 3 << " " << i / 4;
		getch();
	}
	return 0;

}