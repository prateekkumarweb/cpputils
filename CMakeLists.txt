cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
project(cppopts VERSION 0.1.0)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_library(cppopts STATIC ${SOURCES})

install(TARGETS cppopts DESTINATION lib)
install(FILES ${SOURCES} DESTINATION include)
