#pragma once 

class MeshData;
class MeshPrinter;

class TikTakToe {

public:
	
	TikTakToe(int length, int depth);


	void startGame();

private:

	bool isGameOverAndMarkItIfTrue();


	MeshData& data;
	MeshPrinter& printer;


};