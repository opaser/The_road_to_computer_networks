cmake_minimum_required(VERSION 3.0)
project(server)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../lib)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/../lib LIB_SRCS)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} LIB_SRCS)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../)
add_executable(cx_server ${LIB_SRCS})
target_link_libraries(cx_server pthread)

