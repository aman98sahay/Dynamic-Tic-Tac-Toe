cmake_minimum_required(VERSION 3.22)

project (TIC_TAK_TOE LANGUAGES CXX)
set (CMAKE_GENERATOR "Visual Studio 17 2022") # why is it still generating through ninja though I am setting this
add_executable(tik_tak_toe 

	"src/main.cpp"
	"src/MeshData.cpp" 
	"src/MeshPrinter.cpp"
	"src/TikTakToe.cpp"
 	"hpp/MeshData.hpp"
 	"hpp/MeshPrinter.hpp"
 	"hpp/TikTakToe.hpp"

)

target_include_directories(tik_tak_toe PUBLIC

	${CMAKE_SOURCE_DIR}/hpp/
)