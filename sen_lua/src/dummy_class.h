#pragma once
#include <string>
#include <utility>
#include <vector>


struct Data
{
  int id;
  std::string name;
  int age;
};

class DummyClass
{
public:
  explicit DummyClass(std::string  name) : name(std::move(name)) {}
  ~DummyClass() = default;

  [[nodiscard]] const std::string& getName() const noexcept
  {
   return name;
  }

  [[nodiscard]] std::vector<std::string> getRandomList() const noexcept
  {
    return {"gaga", "bubu", "papa"};
  }

  void addData(const Data& data)
  {
    this->data.push_back(data);
  }

  const std::vector<Data>& getData() const noexcept
  {
    return this->data;
  }

private:
  std::string name;
  std::vector<Data> data;
};

