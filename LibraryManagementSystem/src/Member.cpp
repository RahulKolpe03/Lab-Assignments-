#include "../headers/Member.h"
#include "../headers/Exceptions.h"
#include <string>

namespace LibrarySystem {

Member::Member() : Person(), numBooksIssued(0), issuedBookIds(nullptr), capacity(MAX_BOOKS) {
    issuedBookIds = new int[capacity];
    for (int i = 0; i < capacity; ++i) issuedBookIds[i] = -1;
}

Member::Member(int id, const std::string& name, const std::string& phone)
    : Person(id, name, phone), numBooksIssued(0), issuedBookIds(nullptr), capacity(MAX_BOOKS) {
    issuedBookIds = new int[capacity];
    for (int i = 0; i < capacity; ++i) issuedBookIds[i] = -1;
}

// Deep copy: allocate our own array instead of copying the pointer.
Member::Member(const Member& other)
    : Person(other), numBooksIssued(other.numBooksIssued), issuedBookIds(nullptr), capacity(other.capacity) {
    issuedBookIds = new int[capacity];
    for (int i = 0; i < capacity; ++i) issuedBookIds[i] = other.issuedBookIds[i];
}

Member& Member::operator=(const Member& other) {
    if (this != &other) {
        Person::operator=(other);
        delete[] issuedBookIds;
        numBooksIssued = other.numBooksIssued;
        capacity = other.capacity;
        issuedBookIds = new int[capacity];
        for (int i = 0; i < capacity; ++i) issuedBookIds[i] = other.issuedBookIds[i];
    }
    return *this;
}

Member::~Member() {
    delete[] issuedBookIds;
    issuedBookIds = nullptr;
}

void Member::displayInfo() const {
    std::cout << "---- Member Info ----\n"
              << "ID    : " << id << "\n"
              << "Name  : " << name << "\n"
              << "Phone : " << phone << "\n"
              << "Books : " << numBooksIssued << "/" << capacity << " issued\n";
}

void Member::issueBookId(int bookId) {
    if (numBooksIssued >= capacity) {
        throw MaxBooksExceededException(
            "Member " + std::to_string(id) + " already has the maximum number of books issued",
            __FUNCTION__, __LINE__);
    }
    issuedBookIds[numBooksIssued++] = bookId;
}

void Member::returnBookId(int bookId) {
    for (int i = 0; i < numBooksIssued; ++i) {
        if (issuedBookIds[i] == bookId) {
            for (int j = i; j < numBooksIssued - 1; ++j) {
                issuedBookIds[j] = issuedBookIds[j + 1];
            }
            issuedBookIds[numBooksIssued - 1] = -1;
            numBooksIssued--;
            return;
        }
    }
}

bool Member::hasBook(int bookId) const {
    for (int i = 0; i < numBooksIssued; ++i) {
        if (issuedBookIds[i] == bookId) return true;
    }
    return false;
}

int Member::getNumBooksIssued() const { return numBooksIssued; }
const int* Member::getIssuedBooks() const { return issuedBookIds; }
int Member::getMaxBooks() { return MAX_BOOKS; }

bool Member::operator==(const Member& other) const {
    return id == other.id;
}

std::ostream& operator<<(std::ostream& out, const Member& m) {
    out << m.id << " " << m.name << " " << m.phone << " " << m.numBooksIssued;
    return out;
}

std::istream& operator>>(std::istream& in, Member& m) {
    in >> m.id >> m.name >> m.phone;
    return in;
}

} // namespace LibrarySystem
