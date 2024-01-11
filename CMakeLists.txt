cmake_minimum_required(VERSION 3.0.0)
project(Tarea1_Listas VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Tarea1_Listas main.cpp forward_list.h double_list.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
