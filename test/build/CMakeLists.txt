cmake_minimum_required (VERSION 2.8)

project (cue_tests)

file (GLOB_RECURSE cue_source "../source/*.cpp")

include_directories (../../include ${GTEST_INCLUDE})

link_directories (${GTEST_LIB})

add_definitions (-std=c++14)

add_executable (cue_tests ${cue_source})
target_link_libraries (cue_tests gtest gtest_main pthread)
