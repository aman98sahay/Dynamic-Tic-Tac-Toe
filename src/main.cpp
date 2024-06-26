#include <iostream>
#include <climits>

using namespace std;

#include <TikTakToe.hpp>

int main() {

	int depth;
	int length;
	char ch;

	cout << "Enter the depth and length of the mesh that will be used for Tic-Tak-Toe "
		"\n(format depth, length(ie the depth then a ',' and then length):";

	while (!bool(cin >> depth >> ch >> length)) {
		endl(cout << "invalid input, please try again:");
		cin.clear(); // clears the error flags
		// this line discards all the vInput waiting in the stream
		cin.ignore(INT_MAX, '\n'); // as std::numeric_limits<std::streamsize>::max() is not compiling in linux
	}

	TikTakToe tk(depth, length);
	tk.startGame();
	
	return 0;

}