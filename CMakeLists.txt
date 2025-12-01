cmake_minimum_required(VERSION 3.31.6)
project(lab1_restart)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

add_executable(lab1_restart main.cpp
     
		file_io.cpp
		file_io.h
		my_struct.h
		sort.cpp
		sort.h
		utils.cpp
		utils.h)