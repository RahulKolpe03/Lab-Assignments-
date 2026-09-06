#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "Person.h"

namespace LibrarySystem {

// Derived from Person via PUBLIC inheritance.
// Represents staff with permission to add/remove books.
class Librarian : public Person {
private:
    std::string employeeId;
    double salary;

public:
    Librarian();
    Librarian(int id, const std::string& name, const std::string& phone,
              const std::string& employeeId = "EMP000", double salary = 0.0);

    void displayInfo() const override; // overrides Person::displayInfo

    std::string getEmployeeId() const;
    double getSalary() const;
    void setSalary(double newSalary);
};

} // namespace LibrarySystem

#endif // LIBRARIAN_H
