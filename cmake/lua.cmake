set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(LUA_SRC
        submodules/lua/lapi.c
        submodules/lua/lauxlib.c
        submodules/lua/lbaselib.c
        submodules/lua/lcode.c
        submodules/lua/lcorolib.c
        submodules/lua/lctype.c
        submodules/lua/ldblib.c
        submodules/lua/ldebug.c
        submodules/lua/ldo.c
        submodules/lua/ldump.c
        submodules/lua/lfunc.c
        submodules/lua/lgc.c
        submodules/lua/linit.c
        submodules/lua/liolib.c
        submodules/lua/llex.c
        submodules/lua/lmathlib.c
        submodules/lua/lmem.c
        submodules/lua/loadlib.c
        submodules/lua/lobject.c
        submodules/lua/lopcodes.c
        submodules/lua/loslib.c
        submodules/lua/lparser.c
        submodules/lua/lstate.c
        submodules/lua/lstring.c
        submodules/lua/lstrlib.c
        submodules/lua/ltable.c
        submodules/lua/ltablib.c
        submodules/lua/ltm.c
        submodules/lua/lundump.c
        submodules/lua/lutf8lib.c
        submodules/lua/lvm.c
        submodules/lua/lzio.c
)

# Create the library target
add_library(lua STATIC ${LUA_SRC})

target_include_directories(lua
        PUBLIC
        submodules/lua
)