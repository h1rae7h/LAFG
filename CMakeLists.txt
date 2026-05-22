cmake_minimum_required(VERSION 4.3)

project(LAFG
		LANGUAGES CXX 
		VERSION 1.0.0
		DESCRIPTION "Linear algebra library for graphics"
)

add_library(LAFG INTERFACE)
target_include_directories(LAFG INTERFACE
	$<BUILD_INTERFACE:include>		# for building target
	$<INSTALL_INTERFACE:include>	# for installation
)

install(DIRECTORY include/LAFG DESTINATION include)
install(TARGETS LAFG EXPORT LAFG)
install(EXPORT LAFG DESTINATION lib/cmake/LAFG)
install(FILES cmake/LAFGConfig.cmake DESTINATION lib/cmake/LAFG)
