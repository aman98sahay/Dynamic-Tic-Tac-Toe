#pragma once 
#include <cstdint>

class MeshData;
enum class gameBlock: int8_t;
class MeshPrinter {

    static void PrivatePrintLocationColor(gameBlock pBlockType);
public:
    static bool isMarkLocation(int l,int d);
    static bool isDividerLocation(int l);
    static void printatLocation(gameBlock pBlockType, int l, int d);
	static void printMesh(MeshData& obj);
};

/*
* 
* researched way to print different colors in console.
    cout << "\x1B[48;5;45m#\033[0msdfasdf";
    cout << "\x1B[48;5;214m#\033[0msdfasdf";
    cout << "\x1B[48;5;231m#\033[0msdfasdf";
*/