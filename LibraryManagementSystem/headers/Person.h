#ifndef PERSON_H
#define PERSON_H

#include <string>

namespace LibrarySystem {

// Abstract base class for Member and Librarian.
// displayInfo() is pure virtual -> makes Person abstract (cannot be instantiated).
class Person {
protected:
    int id;
    std::string name;
    std::string phone;

public:
    Person();
    Person(int id, const std::string& name, const std::string& phone);
    Person(const Person& other);
    Person& operator=(const Person& other);

    // Virtual destructor: without this, deleting a derived object through a
    // Person* pointer would only run Person's destructor and leak any dynamic
    // memory owned by the derived class (e.g. Member's issued-book array).
    virtual ~Person();

    int getId() const;
    std::string getName() const;
    std::string getPhone() const;

    void setName(const std::string& newName);
    void setPhone(const std::string& newPhone);

    // Pure virtual -> every derived class must provide its own version,
    // and calling it through a Person* uses runtime polymorphism (late binding).
    virtual void displayInfo() const = 0;
};

} // namespace LibrarySystem

#endif // PERSON_H
