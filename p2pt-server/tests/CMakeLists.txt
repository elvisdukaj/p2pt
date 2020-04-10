cmake_minimum_required(VERSION 3.16)

project(p2pt_unit_test LANGUAGES CXX)

find_package(Catch2 REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)

