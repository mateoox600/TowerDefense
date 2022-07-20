cmake_minimum_required(VERSION 3.15)

project(raylib-cmake-test)

add_subdirectory(lib/raylib)
add_subdirectory(lib/raylib-cpp)

set(CMAKE_C_STANDARD 11)

file(GLOB SRC
     "src/*.hpp"
     "src/*.cpp"
)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} raylib raylib_cpp)