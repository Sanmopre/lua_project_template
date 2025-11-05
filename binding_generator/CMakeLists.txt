

add_executable(lua_binding_generator
        src/main.cpp
)

target_include_directories(lua_binding_generator PRIVATE
        submodules/inja/single_include
        submodules/inja/third_party/include
)

target_link_libraries(lua_binding_generator PUBLIC inja)