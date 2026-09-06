#ifndef MEMBER_H
#define MEMBER_H

#include "Person.h"
#include <iostream>

namespace LibrarySystem {

// Derived from Person via PUBLIC inheritance.
class Member : public Person {
private:
    int numBooksIssued;
    int* issuedBookIds;   // dynamic array (Rule of Three: needs copy ctor, op=, dtor)
    int capacity;

    static const int MAX_BOOKS = 5;

public:
    Member();
    Member(int id, const std::string& name, const std::string& phone);

    Member(const Member& other);              // deep copy constructor
    Member& operator=(const Member& other);   // deep copy assignment
    ~Member() override;                       // frees issuedBookIds

    void displayInfo() const override;        // overrides Person::displayInfo

    void issueBookId(int bookId);   // throws MaxBooksExceededException if full
    void returnBookId(int bookId);
    bool hasBook(int bookId) const;

    int getNumBooksIssued() const;
    const int* getIssuedBooks() const;
    static int getMaxBooks();

    bool operator==(const Member& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Member& m);
    friend std::istream& operator>>(std::istream& in, Member& m);
};

} // namespace LibrarySystem

#endif // MEMBER_H
