#pragma once 
#include <cstdint>

enum class gameBlock : int8_t;

class MeshData {
public:

	MeshData(int l, int d);
	~MeshData();
	int getLength();
	int getDepth();
	gameBlock & getDataAt(int pLength, int pDepth);
	void		setDataAt(int pLength, int pDepth,gameBlock pGameDataThere);
private:
	gameBlock *data;
	int vLength;
	int vDepth;
};