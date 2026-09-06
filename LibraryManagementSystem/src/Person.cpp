#include "../headers/Person.h"

namespace LibrarySystem {

Person::Person() : id(0), name(""), phone("") {}

Person::Person(int id, const std::string& name, const std::string& phone)
    : id(id), name(name), phone(phone) {}

Person::Person(const Person& other)
    : id(other.id), name(other.name), phone(other.phone) {}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        id = other.id;
        name = other.name;
        phone = other.phone;
    }
    return *this;
}

Person::~Person() {
    // Nothing to clean up here directly, but this being virtual is what
    // guarantees Member/Librarian destructors run when deleted via Person*.
}

int Person::getId() const { return id; }
std::string Person::getName() const { return name; }
std::string Person::getPhone() const { return phone; }

void Person::setName(const std::string& newName) { name = newName; }
void Person::setPhone(const std::string& newPhone) { phone = newPhone; }

} // namespace LibrarySystem
