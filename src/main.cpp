#include <iostream>
using namespace std;

#include <MeshData.hpp>
#include <MeshPrinter.hpp>


int main() {
	cout << "Currently developing the classes which would be required. Once they are done I will just use them in main."\
		"Till then have a nice day" << endl;;

	MeshData data(4,3);


	MeshPrinter::printMesh(data);
	return 0;

}