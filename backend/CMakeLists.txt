cmake_minimum_required(VERSION 3.22)

project(Kasino_server C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER clang)
set(CMAKE_C_FLAGS "-Wall")

# file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(${PROJECT_NAME} "src/main.c")
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/poker/build/libKasino_poker.a)
