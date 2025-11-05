cmake_minimum_required(VERSION 3.10)

project(sen_lua)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(cmake/lua.cmake)

add_subdirectory(submodules/inja)
add_subdirectory(binding_generator)
add_subdirectory(sen_lua)