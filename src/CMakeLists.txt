cmake_minimum_required(VERSION 2.6)
project(systeminfo)

add_executable(systeminfo functions_command.cpp)
add_executable(systeminfo functions_file.cpp)
add_executable(systeminfo functions_file_memory.cpp)
add_executable(systeminfo functions_file_operations.cpp)
add_executable(systeminfo functions_file_swap.cpp)
add_executable(systeminfo functions_output.cpp)
add_executable(systeminfo functions_output_memory_swap.cpp)
add_executable(systeminfo systeminfo.cpp)

install(TARGETS systeminfo RUNTIME DESTINATION bin)