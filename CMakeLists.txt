cmake_minimum_required(VERSION 3.20)

project (TIC_TAK_TOE LANGUAGES CXX)
set (CMAKE_GENERATOR "Visual Studio 17 2022") 
set(CMAKE_CXX_STANDARD 20)

add_executable(dynamic_tik_tak_toe 

	"src/main.cpp"
	"src/MeshData.cpp" 
	"src/MeshPrinter.cpp"
	"src/TikTakToe.cpp"
 	"hpp/MeshData.hpp"
 	"hpp/MeshPrinter.hpp"
 	"hpp/TikTakToe.hpp"

)

target_include_directories(dynamic_tik_tak_toe PUBLIC

	${CMAKE_SOURCE_DIR}/hpp/
)