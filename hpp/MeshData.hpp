#pragma once 

#include "basicenums.hpp"

class MeshData {
public:

	MeshData(int l, int d);
	~MeshData();
	int getLength();
	int getDepth();
	gameBlock & getDataAt(int pLength, int pDepth);
private:
	gameBlock *data;
	int vLength;
	int vDepth;
};