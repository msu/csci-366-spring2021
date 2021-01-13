cmake_minimum_required(VERSION 3.16)
project(battleship C)
enable_language(ASM_NASM)
set(CMAKE_ASM_NASM_LINK_EXECUTABLE "ld <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
set(CMAKE_ASM_NASM_OBJECT_FORMAT elf64)

add_executable(battleBit src/main.c src/server.c src/server.h src/repl.c src/repl.h src/game.c src/game.h src/char_buff.c
        src/char_buff.h src/helper.h src/helper.c)
target_link_libraries(battleBit PUBLIC pthread)

set_source_files_properties(assembly_demo.asm PROPERTIES LANGUAGE ASM_NASM)

add_library(battleBit_lib src/main.c src/server.c src/server.h src/repl.c src/repl.h src/game.c src/game.h src/char_buff.c src/char_buff.h src/helper.h src/helper.c)

add_subdirectory(googletest)

