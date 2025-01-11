cmake_minimum_required(VERSION 3.16)


project(learn)


file(GLOB SRC_H_CPP
	"${CMAKE_CURRENT_SOURCE_DIR}/*.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/fuction/*.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/fuction/*.h"
)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/fuction")

add_executable(learn ${SRC_H_CPP})