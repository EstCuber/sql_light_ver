cmake_minimum_required(VERSION 3.10)
project(sqlLight C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(sqlLight
    src/repl.c
    src/input.c
    src/vm.c
    src/parser.c
)

target_include_directories(sqlLight PRIVATE include)
