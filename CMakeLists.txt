cmake_minimum_required(VERSION 3.5.0)
project(Lab08 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Lab08 src/main.cpp)
add_library(InvIndex src/InvIndex.cpp)
target_link_libraries(Lab08 InvIndex)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
