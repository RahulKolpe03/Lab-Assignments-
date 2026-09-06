#include "../headers/Book.h"
#include <sstream>

namespace LibrarySystem {

std::string statusToString(BookStatus status) {
    switch (status) {
        case BookStatus::AVAILABLE: return "AVAILABLE";
        case BookStatus::ISSUED:    return "ISSUED";
        case BookStatus::DAMAGED:   return "DAMAGED";
        case BookStatus::LOST:      return "LOST";
    }
    return "UNKNOWN";
}

BookStatus statusFromString(const std::string& s) {
    if (s == "ISSUED")  return BookStatus::ISSUED;
    if (s == "DAMAGED") return BookStatus::DAMAGED;
    if (s == "LOST")    return BookStatus::LOST;
    return BookStatus::AVAILABLE;
}

std::string genreToString(BookGenre genre) {
    switch (genre) {
        case BookGenre::FICTION:    return "FICTION";
        case BookGenre::NONFICTION: return "NONFICTION";
        case BookGenre::SCIENCE:    return "SCIENCE";
        case BookGenre::HISTORY:    return "HISTORY";
        case BookGenre::TECHNOLOGY: return "TECHNOLOGY";
        default:                    return "OTHER";
    }
}

BookGenre genreFromString(const std::string& s) {
    if (s == "FICTION")    return BookGenre::FICTION;
    if (s == "NONFICTION") return BookGenre::NONFICTION;
    if (s == "SCIENCE")    return BookGenre::SCIENCE;
    if (s == "HISTORY")    return BookGenre::HISTORY;
    if (s == "TECHNOLOGY") return BookGenre::TECHNOLOGY;
    return BookGenre::OTHER;
}

Book::Book()
    : bookId(0), title(""), author(""), isbn(""), status(BookStatus::AVAILABLE),
      genre(BookGenre::OTHER), quantity(0), availableCopies(0) {}

Book::Book(int bookId, const std::string& title, const std::string& author,
           const std::string& isbn, int quantity, BookGenre genre)
    : bookId(bookId), title(title), author(author), isbn(isbn),
      status(quantity > 0 ? BookStatus::AVAILABLE : BookStatus::ISSUED),
      genre(genre), quantity(quantity), availableCopies(quantity) {}

int Book::getBookId() const { return bookId; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
std::string Book::getIsbn() const { return isbn; }
BookStatus Book::getStatus() const { return status; }
BookGenre Book::getGenre() const { return genre; }
int Book::getQuantity() const { return quantity; }
int Book::getAvailableCopies() const { return availableCopies; }

int Book::getId() const { return bookId; }
std::string Book::getName() const { return title; }

void Book::setStatus(BookStatus s) { status = s; }
void Book::setTitle(const std::string& t) { title = t; }

Book& Book::operator++() { // a copy comes back to the shelf
    if (availableCopies < quantity) ++availableCopies;
    status = (availableCopies > 0) ? BookStatus::AVAILABLE : BookStatus::ISSUED;
    return *this;
}

Book Book::operator++(int) {
    Book temp = *this;
    ++(*this);
    return temp;
}

Book& Book::operator--() { // a copy goes out
    if (availableCopies > 0) --availableCopies;
    status = (availableCopies > 0) ? BookStatus::AVAILABLE : BookStatus::ISSUED;
    return *this;
}

bool Book::operator==(const Book& other) const {
    return bookId == other.bookId;
}

bool Book::operator<(const Book& other) const {
    return title < other.title;
}

std::string Book::operator[](int index) const {
    switch (index) {
        case 0: return std::to_string(bookId);
        case 1: return title;
        case 2: return author;
        case 3: return isbn;
        case 4: return statusToString(status);
        case 5: return std::to_string(quantity);
        case 6: return std::to_string(availableCopies);
        default: return "";
    }
}

// Matches the assignment's sample file format:
// id|title|author|isbn|status|quantity|available
std::ostream& operator<<(std::ostream& out, const Book& b) {
    out << b.bookId << "|" << b.title << "|" << b.author << "|" << b.isbn << "|"
        << statusToString(b.status) << "|" << b.quantity << "|" << b.availableCopies;
    return out;
}

std::istream& operator>>(std::istream& in, Book& b) {
    std::string line;
    if (std::getline(in, line)) {
        if (line.empty()) return in;
        std::stringstream ss(line);
        std::string field;

        std::getline(ss, field, '|'); b.bookId = field.empty() ? 0 : std::stoi(field);
        std::getline(ss, field, '|'); b.title = field;
        std::getline(ss, field, '|'); b.author = field;
        std::getline(ss, field, '|'); b.isbn = field;
        std::getline(ss, field, '|'); b.status = statusFromString(field);
        std::getline(ss, field, '|'); b.quantity = field.empty() ? 0 : std::stoi(field);
        std::getline(ss, field, '|'); b.availableCopies = field.empty() ? 0 : std::stoi(field);
    }
    return in;
}

} // namespace LibrarySystem
