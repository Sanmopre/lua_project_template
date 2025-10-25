#include <sol/sol.hpp>
#include <iostream>

int main() {
  sol::state lua;
  lua.open_libraries(sol::lib::base);

  // Bind a function
  lua.set_function("cpp_hello", [](const std::optional<std::string>& arg)
  {
    if (arg.has_value()) {
      std::cout << "Hello from C++! " << arg.value() << std::endl;
    }
  });

  // Execute Lua code
  lua.script(R"(
        print("Hello from Lua!")
        cpp_hello("assa")
    )");

  return 0;
}