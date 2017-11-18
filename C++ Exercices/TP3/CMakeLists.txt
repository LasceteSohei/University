cmake_minimum_required(VERSION 3.0)

project(TP3_C++)

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(

	GLOB_RECURSE

	source_files

	src/*

)


add_executable(

	toto

	${source_files}
)
