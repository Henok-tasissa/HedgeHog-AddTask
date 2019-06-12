cmake_minimum_required(VERSION 3.14)
project(AddTask)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules")

find_package(Hedgehog REQUIRED)
add_executable(AddTask main.cpp data/InputData.h task/AddTask.h)
target_include_directories(AddTask PUBLIC ${Hedgehog_INCLUDE_DIR})
target_link_libraries(AddTask ${Hedgehog_LIBRARIES})