cmake_minimum_required (VERSION 3.12)
set(GIT_REPOSITORY "https://github.com/hanickadot/compile-time-regular-expressions")
set(GIT_BRANCH "v3.7.1")
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/ctre)
  message(STATUS "Need to clone for the first call to cmake")
  execute_process(
    COMMAND git clone --depth 1 --branch ${GIT_BRANCH} ${GIT_REPOSITORY}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  )
endif()

set(CTRE_CXX_STANDARD 17)
add_subdirectory(compile-time-regular-expressions)