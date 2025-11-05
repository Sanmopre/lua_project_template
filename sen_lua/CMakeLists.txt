

add_executable(lua_test
        src/main.cpp
        src/dummy_class.h)

target_include_directories(lua_test PRIVATE
        ../submodules/sol2/include
        ../submodules/inja/single_include
        ../submodules/inja/third_party/include
)

target_link_libraries(lua_test PUBLIC lua)