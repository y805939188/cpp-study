set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

cmake_minimum_required(VERSION 3.17) # cmake版本的最低要求

project(DingProject VERSION 1.0.0) # 这里表示项目名称以及项目版本

add_subdirectory(say-hello) # 增加一个子目录到编译系统
add_subdirectory(hello-gakki)


