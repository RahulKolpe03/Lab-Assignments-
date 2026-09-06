#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

namespace LibrarySystem {

enum class BookStatus { AVAILABLE, ISSUED, DAMAGED, LOST };
enum class BookGenre { FICTION, NONFICTION, SCIENCE, HISTORY, TECHNOLOGY, OTHER };

std::string statusToString(BookStatus status);
BookStatus statusFromString(const std::string& s);
std::string genreToString(BookGenre genre);
BookGenre genreFromString(const std::string& s);

class Book {
private:
    int bookId;
    std::string title;
    std::string author;
    std::string isbn;
    BookStatus status;
    BookGenre genre;
    int quantity;
    int availableCopies;

public:
    Book();
    Book(int bookId, const std::string& title, const std::string& author,
         const std::string& isbn, int quantity, BookGenre genre = BookGenre::OTHER);

    // Getters
    int getBookId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getIsbn() const;
    BookStatus getStatus() const;
    BookGenre getGenre() const;
    int getQuantity() const;
    int getAvailableCopies() const;

    // Generic aliases so Container<T>::find() can treat Book the same way
    // as Member (search by "id" / search by "name" == title here).
    int getId() const;
    std::string getName() const;

    // Setters
    void setStatus(BookStatus s);
    void setTitle(const std::string& t);

    // Operator overloads (part of the "at least 5 operators" requirement)
    Book& operator++();      // pre-increment: one copy returned to shelf
    Book operator++(int);    // post-increment
    Book& operator--();      // pre-decrement: one copy issued out
    bool operator==(const Book& other) const; // compare by bookId
    bool operator<(const Book& other) const;  // compare by title (for sorting)

    // index: 0=id, 1=title, 2=author, 3=isbn, 4=status, 5=quantity, 6=available
    std::string operator[](int index) const;

    friend std::ostream& operator<<(std::ostream& out, const Book& b);
    friend std::istream& operator>>(std::istream& in, Book& b);
};

} // namespace LibrarySystem

#endif // BOOK_H
