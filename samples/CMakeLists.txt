cmake_minimum_required(VERSION 3.16)
project(366_demos C CXX)

set(CMAKE_C_STANDARD 99)

add_executable(intro intro.c)
add_executable(functions functions.c functions.h)
add_executable(pointers pointers.c)
add_executable(bit_manipulation bit_manipulation.c)
add_executable(strings_structs strings_structs.c)
target_compile_options(strings_structs PRIVATE -fno-stack-protector)
add_executable(stack_and_heap stack_and_heap.c)
add_executable(sockets sockets.c)
add_executable(concurrency concurrency.c)
target_link_libraries(concurrency PUBLIC pthread)

add_executable(linking linking.c linking2.c linking.h)

add_executable(cpp CPPDemo.h CPPDemo.cpp)

enable_language(ASM_NASM)
set(CMAKE_ASM_NASM_LINK_EXECUTABLE "ld <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
set(CMAKE_ASM_NASM_OBJECT_FORMAT elf64)
set_source_files_properties(nasm_demo.asm PROPERTIES LANGUAGE ASM_NASM)
add_executable(assembly assembly.c nasm_demo.asm)
