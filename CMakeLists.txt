cmake_minimum_required(VERSION 3.10)

project(lua_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(cmake/lua.cmake)

add_executable(lua_test
        src/main.cpp
        src/dummy_class.h)

target_include_directories(lua_test PRIVATE submodules/sol2/include)

target_link_libraries(lua_test PUBLIC lua)