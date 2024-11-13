cmake_minimum_required(VERSION 3.20)

project(brainfuck)

file(GLOB_RECURSE source src/*.cpp src/*.hpp)
message(V ${source})

add_executable(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC includes)
target_sources(${PROJECT_NAME} PUBLIC ${source})
