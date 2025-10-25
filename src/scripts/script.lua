function register()
    print("register!")
end

executionTime = 0.0

function update(dt)
    print("updating with execution time of: ", executionTime)
    executionTime = executionTime + dt

    if executionTime < 5.0 then return true end

    return false
end

function unregister()
    print("unregister!")
end