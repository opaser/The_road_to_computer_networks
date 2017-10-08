cmake_minimum_required(VERSION 3.0)
project(server)



file(GLOB_RECURSE DIR_SRCS "*.c")
file(GLOB_RECURSE REMOVE_FILES "${CMAKE_BINARY_DIR}/CMakeFiles/*")
list(REMOVE_ITEM DIR_SRCS ${REMOVE_FILES})

include_directories(../lib)
link_directories("../common")
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../)
add_executable(cx_server ${DIR_SRCS})
target_link_libraries(cx_server unp)
target_link_libraries(cx_server pthread)
