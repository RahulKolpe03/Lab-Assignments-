#ifndef LIBRARY_H
#define LIBRARY_H

#include "Container.h"
#include "Book.h"
#include "Member.h"
#include "Transaction.h"
#include "Exceptions.h"
#include <vector>
#include <map>
#include <string>

namespace LibrarySystem {

// Main class that ties together Books, Members, Transactions and file I/O.
class Library {
private:
    Container<Book> books;      // template class in action
    Container<Member> members;  // template class in action
    std::vector<Transaction> transactions;       // STL vector
    std::map<int, int> bookToMember;             // STL map: bookId -> memberId

    static const int LOAN_PERIOD_DAYS = 14;

    int daysBetween(const std::string& day1, const std::string& day2) const;
    std::string addDays(const std::string& day, int days) const;

public:
    Library();

    // Book management
    void addBook(const Book& book);
    void removeBook(int bookId);
    Book& searchBookById(int bookId);
    Book& searchBookByTitle(const std::string& title);
    void displayAllBooks() const;

    // Member management
    void registerMember(const Member& member);
    void removeMember(int memberId);
    Member& searchMemberById(int memberId);
    Member& searchMemberByName(const std::string& name);
    void displayAllMembers() const;

    // Issue / Return
    void issueBook(int memberId, int bookId, const std::string& issueDay);
    void returnBook(int memberId, int bookId, const std::string& returnDay);
    void viewOverdueBooks(const std::string& today) const;

    // File handling (fstream-based persistence)
    void saveData(const std::string& booksFile, const std::string& membersFile,
                  const std::string& transactionsFile) const;
    void loadData(const std::string& booksFile, const std::string& membersFile,
                  const std::string& transactionsFile);
};

} // namespace LibrarySystem

#endif // LIBRARY_H
