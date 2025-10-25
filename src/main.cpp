#include <iostream>

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

int main()
{
  lua_State* L = luaL_newstate();
  if (!L)
  {
    std::cerr << "Failed to create Lua state!" << std::endl;
    return 1;
  }

  luaL_openlibs(L);

  auto script = "/home/sanmopre/development/lua_project_template/src/scripts/script.lua";

  if (luaL_dofile(L, script) != LUA_OK)
  {
    std::cerr << "Error running Lua script: " << lua_tostring(L, -1) << std::endl;
    lua_pop(L, 1);
  }

  lua_close(L);

  return 0;
}