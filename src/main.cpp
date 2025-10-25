#include <chrono>
#include <sol/sol.hpp>

int main()
{

    sol::state lua;
    lua.open_libraries(sol::lib::base, sol::lib::string);

    sol::load_result chunk = lua.load_file("/home/sanmopre/development/lua_project_template/src/scripts/script.lua");
    if (!chunk.valid())
    {
        const sol::error err = chunk;
        std::cerr << "Failed to load script.lua: " << err.what() << "\n";
        return 1;
    }

    if ( const sol::protected_function_result exec = chunk(); !exec.valid())
    {
        const sol::error err = exec;
        std::cerr << "Error running script.lua: " << err.what() << "\n";
        return 1;
    }

    const sol::protected_function registerFunction = lua["register"];
    if (!registerFunction.valid())
    {
        std::cerr << "Lua function 'register' not found.\n";
        return 1;
    }

    const sol::protected_function unregisterFunction = lua["unregister"];
    if (!unregisterFunction.valid())
    {
        std::cerr << "Lua function 'unregister' not found.\n";
        return 1;
    }


    const sol::protected_function updateFunction = lua["update"];
    if (!updateFunction.valid())
    {
        std::cerr << "Lua function 'update' not found.\n";
        return 1;
    }

    std::ignore = registerFunction();

    bool running = true;
    double dt = 0.0;
    while (running)
    {
        // Record start time
        auto start = std::chrono::steady_clock::now();

        sol::protected_function_result result = updateFunction(dt);
        if (!result.valid())
        {
            const sol::error err = result;
            std::cerr << "Error calling update: " << err.what() << "\n";
            return 1;
        }

        std::chrono::duration<double> elapsed_seconds = std::chrono::steady_clock::now() - start;
        dt = elapsed_seconds.count();

        running = result;


    }

    std::ignore = unregisterFunction();

    return 0;
}