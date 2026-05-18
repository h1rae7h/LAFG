cmake_minimum_required(VERSION 4.3)

project(LAFG
		LANGUAGES CXX 
		VERSION 1.0.0
		DESCRIPTION "Linear algebra library for graphics"
)

file(GLOB LAFG_HEADERS "include/LAFG/*.hpp")

add_library(lafg INTERFACE)
target_include_directories(lafg INTERFACE
	$<BUILD_INTERFACE:include>		# for building target
	$<INSTALL_INTERFACE:include>	# for installation
)

install(FILES ${LAFG_HEADERS} DESTINATION include/LAFG)
install(TARGETS lafg EXPORT lafg DESTINATION lib)
install(EXPORT lafg DESTINATION lib/cmake/lafg)
install(FILES CMake/lafg-config.cmake DESTINATION lib/cmake/lafg)
