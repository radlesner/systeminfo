cmake_minimum_required(VERSION 2.8.9)
project (systeminfo)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SOURCES ${SOURCE_DIR}/function_output_log.cpp
            ${SOURCE_DIR}/function_output_logo.cpp
            ${SOURCE_DIR}/functions_command.cpp
            ${SOURCE_DIR}/functions_file_memory.cpp
            ${SOURCE_DIR}/functions_file_operations.cpp
            ${SOURCE_DIR}/functions_file_swap.cpp
            ${SOURCE_DIR}/functions_file.cpp
            ${SOURCE_DIR}/functions_network.cpp
            ${SOURCE_DIR}/functions_output.cpp
            ${SOURCE_DIR}/functions_strings_operations.cpp
            ${SOURCE_DIR}/systeminfo.cpp
            )

add_executable(systeminfo ${SOURCES})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/systeminfo_script.sh DESTINATION /usr/local/bin)

install(TARGETS systeminfo RUNTIME DESTINATION bin)