cmake_minimum_required(VERSION 3.5)

project(disassembler)

add_executable(
	myDisassembler
	disassembler.cpp
	instruction.cpp
	instruction.hpp
)
