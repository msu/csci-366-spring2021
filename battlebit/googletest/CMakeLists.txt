# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../src)

# 'Google_Tests_run' is the target name
add_executable(battleBit_tests char_buff.cpp game.cpp repl.cpp)
target_link_libraries(battleBit_tests gtest gtest_main battleBit_lib)
