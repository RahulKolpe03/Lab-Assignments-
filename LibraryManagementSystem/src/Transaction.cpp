#include "../headers/Transaction.h"
#include <sstream>

namespace LibrarySystem {

int Transaction::nextTransactionId = 1;
const double Transaction::FINE_RATE_PER_DAY = 5.0;

Transaction::Transaction()
    : transactionId(0), memberId(0), bookId(0), issueDate(""), dueDate(""),
      returnDate(""), fineAmount(0.0) {}

Transaction::Transaction(int memberId, int bookId, const std::string& issueDate, const std::string& dueDate)
    : transactionId(nextTransactionId++), memberId(memberId), bookId(bookId),
      issueDate(issueDate), dueDate(dueDate), returnDate(""), fineAmount(0.0) {}

int Transaction::getTransactionId() const { return transactionId; }
int Transaction::getMemberId() const { return memberId; }
int Transaction::getBookId() const { return bookId; }
std::string Transaction::getIssueDate() const { return issueDate; }
std::string Transaction::getDueDate() const { return dueDate; }
std::string Transaction::getReturnDate() const { return returnDate; }
double Transaction::getFineAmount() const { return fineAmount; }
bool Transaction::isReturned() const { return !returnDate.empty(); }

void Transaction::setReturnDate(const std::string& date) { returnDate = date; }

double Transaction::calculateFine(int daysOverdue) {
    fineAmount = (daysOverdue > 0) ? daysOverdue * FINE_RATE_PER_DAY : 0.0;
    return fineAmount;
}

void Transaction::setNextId(int id) {
    if (id > nextTransactionId) nextTransactionId = id;
}

std::ostream& operator<<(std::ostream& out, const Transaction& t) {
    out << t.transactionId << "|" << t.memberId << "|" << t.bookId << "|"
        << t.issueDate << "|" << t.dueDate << "|" << t.returnDate << "|" << t.fineAmount;
    return out;
}

std::istream& operator>>(std::istream& in, Transaction& t) {
    std::string line;
    if (std::getline(in, line)) {
        if (line.empty()) return in;
        std::stringstream ss(line);
        std::string field;

        std::getline(ss, field, '|'); t.transactionId = field.empty() ? 0 : std::stoi(field);
        std::getline(ss, field, '|'); t.memberId = field.empty() ? 0 : std::stoi(field);
        std::getline(ss, field, '|'); t.bookId = field.empty() ? 0 : std::stoi(field);
        std::getline(ss, field, '|'); t.issueDate = field;
        std::getline(ss, field, '|'); t.dueDate = field;
        std::getline(ss, field, '|'); t.returnDate = field;
        std::getline(ss, field, '|'); t.fineAmount = field.empty() ? 0.0 : std::stod(field);

        Transaction::setNextId(t.transactionId + 1);
    }
    return in;
}

} // namespace LibrarySystem
