#include "../headers/Librarian.h"
#include <iostream>

namespace LibrarySystem {

Librarian::Librarian() : Person(), employeeId("EMP000"), salary(0.0) {}

Librarian::Librarian(int id, const std::string& name, const std::string& phone,
                      const std::string& employeeId, double salary)
    : Person(id, name, phone), employeeId(employeeId), salary(salary) {}

void Librarian::displayInfo() const {
    std::cout << "---- Librarian Info ----\n"
              << "ID          : " << id << "\n"
              << "Name        : " << name << "\n"
              << "Phone       : " << phone << "\n"
              << "Employee ID : " << employeeId << "\n"
              << "Salary      : " << salary << "\n";
}

std::string Librarian::getEmployeeId() const { return employeeId; }
double Librarian::getSalary() const { return salary; }
void Librarian::setSalary(double newSalary) { salary = newSalary; }

} // namespace LibrarySystem
