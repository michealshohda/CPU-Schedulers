cmake_minimum_required(VERSION 3.10)
project(CPU_Schedulers)

set(CMAKE_CXX_STANDARD 17)

# Include directories for headers
include_directories(
    "${PROJECT_SOURCE_DIR}/Header Files"
    "${PROJECT_SOURCE_DIR}/GUI"
)

# Gather all source files
file(GLOB_RECURSE SOURCES 
    "Source Files/*.cpp"
    "GUI/*.cpp"
)

add_executable(CPU_Schedulers ${SOURCES})

# Optional warnings
target_compile_options(CPU_Schedulers PRIVATE -Wall -Wextra -Wpedantic)

# Platform specific
if (WIN32)
    set_target_properties(CPU_Schedulers PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
endif()
