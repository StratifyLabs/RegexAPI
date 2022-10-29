cmake_minimum_required (VERSION 3.12)
cmsdk2_minimum_required(2.1.2)

project(RegexAPI CXX)
include(CTest)

add_subdirectory(ctre)
add_subdirectory(library)

option(REGEX_API_IS_TEST "Enable test builds for LibraryAPI" OFF)
if(REGEX_API_IS_TEST)
	add_subdirectory(tests tests)
endif()

