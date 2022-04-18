#pragma once
#include <map>
#include <string>

class BaseField {
  public:
    std::string name;

    BaseField(std::string name);
    virtual ~BaseField() {
    }
};

template <typename T>
class Field : BaseField {
  private:
    T value;

  public:
    void operator=(T &value);
};

class CharField : Field<std::string> {};

class Entity {
  private:
    std::map<std::string, BaseField *> fields;

  public:
    Entity();
    ~Entity();

    void add_field(BaseField *field);
};