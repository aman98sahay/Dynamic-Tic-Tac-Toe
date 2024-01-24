cmake_minimum_required(VERSION 3.22)

project (TIC_TAK_TOE LANGUAGES CXX)

add_executable(tik_tak_toe 

	"src/main.cpp"
	"src/MeshData.cpp" 
	"src/MeshPrinter.cpp"
	"src/TikTakToe.cpp"
#	"hpp/MeshData.hpp"
#	"hpp/MeshPrinter.hpp"
#	"hpp/TikTakToe.hpp"

)

target_include_directories(tik_tak_toe PUBLIC

	${CMAKE_SOURCE_DIR}/hpp/
)