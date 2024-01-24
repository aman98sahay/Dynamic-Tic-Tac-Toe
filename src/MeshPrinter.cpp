#include "MeshPrinter.hpp"
#include "MeshData.hpp"

void MeshPrinter::printMesh(MeshData& obj, bool isShining)
{
	for (size_t i = 0; i < obj.getDepth() * 3; i++)
	{

		for (size_t z = 0; z < obj.getLength(); z++) {
			bool isEnd = z == obj.getLength() - 1;
			if ((i - 1) % 4 == 0) {
				if (isShining) {

				}
			}
		}


	}

}
