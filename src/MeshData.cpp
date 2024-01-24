#include "MeshData.hpp"
#include <assert.h>
MeshData::MeshData(int l, int d) 
{
	data = new gameBlock[l * d];
	vLength = l;
	vDepth = d;
	for (size_t i = 0; i < l * d; i++)
	{
		data[i] = gameBlock::UNSET;
	}
}

int MeshData::getLength()
{
	return vLength;
}

int MeshData::getDepth()
{
	return vDepth;
}

gameBlock & MeshData::getDataAt(int pLength, int pDepth)
{
	assert(pLength <= vLength || pDepth <= vDepth);
	return data[pLength + vLength * pDepth];
}


