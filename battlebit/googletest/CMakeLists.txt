# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../src)

# 'Google_Tests_run' is the target name
add_executable(battleBit_tests char_buff.cpp game1.cpp game2.cpp repl.cpp)
target_link_libraries(battleBit_tests gtest gtest_main battleBit_lib)

add_executable(battleBit_checkpoint1 char_buff.cpp game1.cpp)
target_link_libraries(battleBit_checkpoint1 gtest gtest_main battleBit_lib)
