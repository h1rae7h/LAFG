cmake_minimum_required(VERSION 4.3)

project(LAFG
		LANGUAGES CXX 
		VERSION 1.0.0
		DESCRIPTION "Linear algebra library for graphics"
)

add_library(lafg INTERFACE)
target_include_directories(lafg INTERFACE include)
