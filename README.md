# For devloper
## Prequesite
- Using Linux or Unix is requirement for backend
- Our compiler is clang, instead of gcc
- IDE: CLion for debugging

## How to run
```sh
mkdir build
cd build
cmake ../
make
```

## Workflow
- We will split project into libraries

#### Cmake
- We use `cmake`, the `CMakeLists.txt` looks like this, notice lines which I commented is what we need to define ourselves.
```sh
cmake_minimum_required(VERSION 3.22)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER clang)
set(CMAKE_C_FLAGS "-Wall")

project(Kasino_server C) # SET PROJECT NAME HERE, start with Kasino_{name}

file(GLOB_RECURSE SOURCES "src/*.c")

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib) # SET LIB DIR HERE, this is relative directory of "lib" folder from this Cmake dir 
list(APPEND ALL_LIBS card pokergame) # APPEND LIB HERE (directory name of lib)


foreach(LIB IN LISTS ALL_LIBS)
    list(APPEND ALL_INCLUDES "${LIB_DIR}/${LIB}/include")
    list(APPEND ALL_LIBRARIES "${LIB_DIR}/${LIB}/build/libKasino_${LIB}.a")
endforeach()

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${ALL_INCLUDES})
target_link_libraries(${PROJECT_NAME} PUBLIC ${ALL_LIBRARIES})
```
- Libraries have similar file structure:

```
backend
|
|---include
|---src
|   |
|   |---main.c
|---lib
|   {lib_name}
|   |
|   |--- include (must contains {lib_name}.h for other program to include it)
|   |   |
|   |   |---{lib_name}.h (notice the same name with library)
|   |   |
|   |--- src (contains all source code, .c files)
|   |--- test (checkout utils/test.h and pokergame/test I wrote a simple template for testing)
|   |---CmakeLists.txt
|---CMakeLists.txt
|---build
```

- First step to build, we need `build` directory in same path of your `CmakeLists.txt`, checkout the [how to run](#how-to-run)