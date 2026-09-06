#include "../headers/Library.h"
#include <iostream>
#include <fstream>
#include <sstream>

namespace LibrarySystem {

Library::Library() {}

int Library::daysBetween(const std::string& day1, const std::string& day2) const {
    int d1 = day1.empty() ? 0 : std::stoi(day1);
    int d2 = day2.empty() ? 0 : std::stoi(day2);
    return d2 - d1;
}

std::string Library::addDays(const std::string& day, int days) const {
    int d = day.empty() ? 0 : std::stoi(day);
    return std::to_string(d + days);
}

// ---------------- Book management ----------------

void Library::addBook(const Book& book) {
    if (books.find(book.getId()) != -1) {
        throw LibraryException("A book with this ID already exists", __FUNCTION__, __LINE__);
    }
    books.add(book);
}

void Library::removeBook(int bookId) {
    int idx = books.find(bookId);
    if (idx == -1) {
        throw BookNotFoundException("Book with ID " + std::to_string(bookId) + " not found",
                                     __FUNCTION__, __LINE__);
    }
    books.removeAt(idx);
}

Book& Library::searchBookById(int bookId) {
    int idx = books.find(bookId);
    if (idx == -1) {
        throw BookNotFoundException("Book with ID " + std::to_string(bookId) + " not found",
                                     __FUNCTION__, __LINE__);
    }
    return books[idx];
}

Book& Library::searchBookByTitle(const std::string& title) {
    int idx = books.find(title);
    if (idx == -1) {
        throw BookNotFoundException("Book titled \"" + title + "\" not found",
                                     __FUNCTION__, __LINE__);
    }
    return books[idx];
}

void Library::displayAllBooks() const {
    if (books.isEmpty()) {
        std::cout << "No books in the library.\n";
        return;
    }
    std::cout << "\n--- All Books (id|title|author|isbn|status|qty|available) ---\n";
    for (int i = 0; i < books.getSize(); ++i) {
        std::cout << books[i] << "\n";
    }
}

// ---------------- Member management ----------------

void Library::registerMember(const Member& member) {
    if (members.find(member.getId()) != -1) {
        throw LibraryException("A member with this ID already exists", __FUNCTION__, __LINE__);
    }
    members.add(member);
}

void Library::removeMember(int memberId) {
    int idx = members.find(memberId);
    if (idx == -1) {
        throw MemberNotFoundException("Member with ID " + std::to_string(memberId) + " not found",
                                       __FUNCTION__, __LINE__);
    }
    members.removeAt(idx);
}

Member& Library::searchMemberById(int memberId) {
    int idx = members.find(memberId);
    if (idx == -1) {
        throw MemberNotFoundException("Member with ID " + std::to_string(memberId) + " not found",
                                       __FUNCTION__, __LINE__);
    }
    return members[idx];
}

Member& Library::searchMemberByName(const std::string& name) {
    int idx = members.find(name);
    if (idx == -1) {
        throw MemberNotFoundException("Member named \"" + name + "\" not found",
                                       __FUNCTION__, __LINE__);
    }
    return members[idx];
}

void Library::displayAllMembers() const {
    if (members.isEmpty()) {
        std::cout << "No members registered.\n";
        return;
    }
    std::cout << "\n--- All Members ---\n";
    for (int i = 0; i < members.getSize(); ++i) {
        members[i].displayInfo();
    }
}

// ---------------- Issue / Return ----------------

void Library::issueBook(int memberId, int bookId, const std::string& issueDay) {
    Member& member = searchMemberById(memberId);
    Book& book = searchBookById(bookId);

    if (book.getAvailableCopies() <= 0) {
        throw BookNotAvailableException("Book \"" + book.getTitle() + "\" is currently not available",
                                         __FUNCTION__, __LINE__);
    }

    member.issueBookId(bookId); // may throw MaxBooksExceededException
    --book;                     // one fewer available copy

    std::string dueDay = addDays(issueDay, LOAN_PERIOD_DAYS);
    Transaction t(memberId, bookId, issueDay, dueDay);
    transactions.push_back(t);
    bookToMember[bookId] = memberId;

    std::cout << "Book \"" << book.getTitle() << "\" issued to " << member.getName()
              << ". Due on day " << dueDay << ".\n";
}

void Library::returnBook(int memberId, int bookId, const std::string& returnDay) {
    Member& member = searchMemberById(memberId);
    Book& book = searchBookById(bookId);

    if (!member.hasBook(bookId)) {
        throw LibraryException("Member " + std::to_string(memberId) + " has not issued book " +
                                std::to_string(bookId), __FUNCTION__, __LINE__);
    }

    Transaction* target = nullptr;
    for (auto& t : transactions) {
        if (t.getMemberId() == memberId && t.getBookId() == bookId && !t.isReturned()) {
            target = &t; // keep the most recent open transaction for this pair
        }
    }

    double fine = 0.0;
    if (target != nullptr) {
        target->setReturnDate(returnDay);
        int overdue = daysBetween(target->getDueDate(), returnDay);
        fine = target->calculateFine(overdue);
    }

    member.returnBookId(bookId);
    ++book; // one more available copy
    bookToMember.erase(bookId);

    std::cout << "Book \"" << book.getTitle() << "\" returned by " << member.getName() << ".";
    if (fine > 0) std::cout << " Fine due: " << fine;
    std::cout << "\n";
}

void Library::viewOverdueBooks(const std::string& today) const {
    bool any = false;
    std::cout << "\n--- Overdue Books ---\n";
    for (const auto& t : transactions) {
        if (!t.isReturned()) {
            int overdue = daysBetween(t.getDueDate(), today);
            if (overdue > 0) {
                any = true;
                std::cout << "Transaction #" << t.getTransactionId()
                          << " | Member: " << t.getMemberId()
                          << " | Book: " << t.getBookId()
                          << " | Due: day " << t.getDueDate()
                          << " | Overdue by: " << overdue << " day(s)\n";
            }
        }
    }
    if (!any) std::cout << "No overdue books.\n";
}

// ---------------- File handling ----------------

void Library::saveData(const std::string& booksFile, const std::string& membersFile,
                        const std::string& transactionsFile) const {
    std::ofstream bOut(booksFile);
    if (!bOut) throw LibraryException("Unable to open books file for writing", __FUNCTION__, __LINE__);
    for (int i = 0; i < books.getSize(); ++i) bOut << books[i] << "\n";
    bOut.close();

    std::ofstream mOut(membersFile);
    if (!mOut) throw LibraryException("Unable to open members file for writing", __FUNCTION__, __LINE__);
    for (int i = 0; i < members.getSize(); ++i) {
        const Member& m = members[i];
        mOut << m.getId() << "|" << m.getName() << "|" << m.getPhone() << "|" << m.getNumBooksIssued();
        for (int j = 0; j < m.getNumBooksIssued(); ++j) mOut << "|" << m.getIssuedBooks()[j];
        mOut << "\n";
    }
    mOut.close();

    std::ofstream tOut(transactionsFile);
    if (!tOut) throw LibraryException("Unable to open transactions file for writing", __FUNCTION__, __LINE__);
    for (const auto& t : transactions) tOut << t << "\n";
    tOut.close();

    std::cout << "Data saved successfully.\n";
}

void Library::loadData(const std::string& booksFile, const std::string& membersFile,
                        const std::string& transactionsFile) {
    while (books.getSize() > 0) books.removeAt(0);
    while (members.getSize() > 0) members.removeAt(0);
    transactions.clear();
    bookToMember.clear();

    std::ifstream bIn(booksFile);
    if (bIn) {
        Book b;
        while (bIn >> b) books.add(b);
        bIn.close();
    }

    std::ifstream mIn(membersFile);
    if (mIn) {
        std::string line;
        while (std::getline(mIn, line)) {
            if (line.empty()) continue;
            std::stringstream ss(line);
            std::string field;

            std::getline(ss, field, '|'); int id = field.empty() ? 0 : std::stoi(field);
            std::getline(ss, field, '|'); std::string name = field;
            std::getline(ss, field, '|'); std::string phone = field;
            std::getline(ss, field, '|'); int count = field.empty() ? 0 : std::stoi(field);

            Member m(id, name, phone);
            for (int i = 0; i < count && std::getline(ss, field, '|'); ++i) {
                int bid = std::stoi(field);
                m.issueBookId(bid);
                bookToMember[bid] = id;
            }
            members.add(m);
        }
        mIn.close();
    }

    std::ifstream tIn(transactionsFile);
    if (tIn) {
        Transaction t;
        while (tIn >> t) transactions.push_back(t);
        tIn.close();
    }

    std::cout << "Data loaded successfully.\n";
}

} // namespace LibrarySystem
