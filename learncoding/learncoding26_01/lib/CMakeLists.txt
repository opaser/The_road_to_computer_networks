cmake_minimum_required(VERSION 3.0)
project(unp)

aux_source_directory(./ LIB_SRCS)
include_directories(./)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../common)
add_library(unp ${LIB_SRCS})


