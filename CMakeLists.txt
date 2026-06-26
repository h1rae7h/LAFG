cmake_minimum_required(VERSION 4.3)

project(LAFG
		LANGUAGES CXX 
		VERSION 1.1.0
		DESCRIPTION "Linear algebra library for graphics"
)

add_library(LAFG INTERFACE)
target_include_directories(LAFG INTERFACE
	$<BUILD_INTERFACE:${LAFG_SOURCE_DIR}/include>			# for building target
	$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>	# for installation
)
# C++ 20 is needed for concepts
target_compile_features(LAFG INTERFACE cxx_std_20)

install(DIRECTORY include/LAFG DESTINATION include)
install(TARGETS LAFG EXPORT LAFG)
install(EXPORT LAFG DESTINATION lib/cmake/LAFG)
install(FILES cmake/LAFGConfig.cmake DESTINATION lib/cmake/LAFG)
