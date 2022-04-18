#include "entity.h"

using namespace std;

BaseField ::BaseField(std::string name) {
    this->name = name;
}

template <typename T>
void Field ::operator=(T &value) {
    this->value = value;
}

Entity::Entity() {
}

Entity::~Entity() {
    std::map<string, BaseField *>::iterator iter;

    for (const auto &f : this->fields)
        delete (*iter).second;

    this->fields.clear();
}

void Entity::add_field(BaseField *field) {
    this->fields[field->name] = field;
}