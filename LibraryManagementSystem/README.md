# Library Management System (C++)

A menu-driven Library Management System covering books, members, librarians,
issue/return transactions, fine calculation, and file-based persistence.

## Folder Structure

```
LibraryManagementSystem/
├── headers/        # .h files - one class per file
├── src/            # .cpp files - implementations + main.cpp
├── data/           # books.txt / members.txt / transactions.txt (created by Save)
└── README.md
```

## How to Build & Run

From inside `LibraryManagementSystem/`:

```bash
g++ -std=c++17 -Wall -Wextra -Iheaders src/*.cpp -o library_system
cd src && ../library_system
```

(Run it from `src/`, or adjust the paths in `main.cpp`, because the data file
paths are written relative to `src/` as `../data/*.txt`.)

Compiles cleanly with `-Wall -Wextra`, no warnings.

## Design Note: Dates as Day Numbers

Rather than pulling in `<chrono>`/calendar-parsing complexity (which isn't
part of the concept checklist for this assignment), dates are modeled as
simple integer "day numbers" entered as strings, e.g. `1`, `15`, `29`. When
you issue a book on day `1`, the due date is automatically calculated as
day `1 + 14 = 15` (14-day loan period). Returning it on day `20` overdue
means `20 - 15 = 5` days overdue, fined at `Transaction::FINE_RATE_PER_DAY`
(5.0/day) via `Transaction::calculateFine()`. This keeps the fine-calculation
logic (the actual point of that requirement) front and center, without date
parsing noise. Swapping in real calendar dates later would only require
changing `Library::daysBetween()` / `Library::addDays()`.

## Class Overview

| Class | File(s) | Notes |
|---|---|---|
| `Person` | Person.h/.cpp | Abstract (pure virtual `displayInfo()`), virtual destructor |
| `Member` | Member.h/.cpp | `public` from `Person`; owns a dynamic `int*` array of issued book IDs (Rule of Three: deep-copy ctor, deep-copy `operator=`, destructor) |
| `Librarian` | Librarian.h/.cpp | `public` from `Person`; employeeId + salary |
| `Book` | Book.h/.cpp | `enum class BookStatus`, `enum class BookGenre`; overloads `++` (pre/post), `--`, `==`, `<`, `[]`, `<<`, `>>` |
| `Container<T>` | Container.h (header-only) | Generic dynamic array for `Book`/`Member`; overloaded `find(int)` / `find(string)` |
| `Transaction` | Transaction.h/.cpp | `static int nextTransactionId` auto-increment; `static const double FINE_RATE_PER_DAY` |
| `Library` | Library.h/.cpp | Owns `Container<Book>`, `Container<Member>`, `std::vector<Transaction>`, `std::map<int,int>` (bookId→memberId); file I/O via `fstream` |
| Exceptions | Exceptions.h | `LibraryException : std::exception` base + 4 derived types, each carrying `__FUNCTION__` / `__LINE__` |

Everything lives inside `namespace LibrarySystem`.

## Runtime Polymorphism

`main()` runs a small demo on startup:

```cpp
Person* p1 = new Member(901, "Demo Member", "9990001111");
p1->displayInfo(); // prints Member's version, not Person's - late binding
delete p1;         // virtual destructor -> Member's destructor actually runs
```

## File Format

`books.txt` matches the sample from the assignment:
```
101|Introduction to C++|Bjarne Stroustrup|978-0321958327|AVAILABLE|5|5
```
`members.txt` stores `id|name|phone|numBooksIssued|bookId1|bookId2|...`
`transactions.txt` stores `id|memberId|bookId|issueDay|dueDay|returnDay|fine`

## Concept Checklist Coverage

| Concept | Where |
|---|---|
| Pointers & dynamic memory | `Container<T>` internal array; `Member::issuedBookIds` |
| References | Function parameters throughout (e.g. `const Book&`) |
| Access specifiers | `private`/`protected`/`public` used per class |
| Constructors | Default, parameterized, and copy constructors on `Person`, `Member`, `Book`, `Container` |
| Destructors | `Container<T>`, `Member` |
| Inheritance (public) | `Person → Member`, `Person → Librarian` |
| Virtual functions / pure virtual | `Person::displayInfo()` |
| Virtual destructor | `Person::~Person()` |
| Runtime polymorphism / upcasting | `Person*` demo in `main()` |
| `this` pointer | Used implicitly in setters and all `operator=` self-checks |
| `const` member functions | All getters |
| `static` members | `Transaction::nextTransactionId`, `Transaction::FINE_RATE_PER_DAY`, `Member::MAX_BOOKS` |
| Namespaces | `LibrarySystem` wraps everything |
| Function overloading | `Container<T>::find(int)` / `find(const std::string&)` |
| Operator overloading (5+) | `Book`: `++`,`--`,`==`,`<`,`[]`,`<<`,`>>`; `Member`: `==`,`<<`,`>>` |
| Templates | `Container<T>` (header-only, per requirement) |
| STL | `std::vector<Transaction>`, `std::map<int,int>` in `Library` |
| File handling | `Library::saveData()` / `loadData()` via `fstream` |
| Exception handling | Custom hierarchy in `Exceptions.h`, all caught in `main()`'s menu loop |
| Enums | `BookStatus`, `BookGenre` (both `enum class`) |

## Sample Test Scenario (verified working)

1. Add 3 books
2. Register 2 members
3. Issue a book to member 1
4. Try to issue the same book to member 2 → `BookNotAvailableException`
5. Return the book
6. Issue the same book to member 2 → succeeds
7. Save all data to files
8. Restart, Load data → all previous data restored correctly

This exact flow was run against the `Library` class directly during
development and produces the expected output at every step.
