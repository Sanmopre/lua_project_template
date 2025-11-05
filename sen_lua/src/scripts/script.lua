executionTime = 0.0
dummyClass = {}

function register()
    print("register!")
    dummyClass = DummyClass.new("LuaUser")
end

function update(dt)
    print("updating with execution time of: ", executionTime)
    print(dummyClass:getName())

    local d = Data.new()
    d.id = 1
    d.name = "Alice"
    d.age = 30
    dummyClass:addData(d)

    for i, d in ipairs(dummyClass:getData()) do     -- iterate vector<Data> as a Lua array
        print(i, d.id, d.name, d.age)
    end

    local list = dummyClass:getRandomList()

    for it = 1, #list do
        print(list[it])
    end

    executionTime = executionTime + dt

    if executionTime < 5.0 then return true end

    return false
end

function unregister()
    print("unregister!")
end