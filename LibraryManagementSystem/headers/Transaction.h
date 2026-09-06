#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>

namespace LibrarySystem {

// Tracks a single issue/return event.
//
// NOTE ON DATES: to keep the focus on the OOP concepts this assignment is
// actually testing (statics, operators, file I/O, exceptions) rather than
// calendar-arithmetic edge cases, dates are modeled as simple integer
// "day numbers" stored as strings (e.g. "1", "15", "29"). daysBetween two
// day numbers is just subtraction. See README.md for details.
class Transaction {
private:
    int transactionId;
    int memberId;
    int bookId;
    std::string issueDate;
    std::string dueDate;
    std::string returnDate; // empty until the book is returned
    double fineAmount;

    static int nextTransactionId; // auto-increments with every new Transaction

public:
    static const double FINE_RATE_PER_DAY; // static const: fine per day overdue

    Transaction();
    Transaction(int memberId, int bookId, const std::string& issueDate, const std::string& dueDate);

    int getTransactionId() const;
    int getMemberId() const;
    int getBookId() const;
    std::string getIssueDate() const;
    std::string getDueDate() const;
    std::string getReturnDate() const;
    double getFineAmount() const;
    bool isReturned() const;

    void setReturnDate(const std::string& date);
    double calculateFine(int daysOverdue);

    // Keeps the static counter consistent after loading transactions from file.
    static void setNextId(int id);

    friend std::ostream& operator<<(std::ostream& out, const Transaction& t);
    friend std::istream& operator>>(std::istream& in, Transaction& t);
};

} // namespace LibrarySystem

#endif // TRANSACTION_H
