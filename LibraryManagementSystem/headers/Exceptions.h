#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>
#include <sstream>

namespace LibrarySystem {

// Base exception for the whole library system.
// Stores a message plus the function name / line number where it was thrown,
// so error output is actually useful for debugging (uses __FUNCTION__ / __LINE__).
class LibraryException : public std::exception {
protected:
    std::string message;
    std::string functionName;
    int lineNumber;
    mutable std::string fullMessage; // built lazily inside what()

public:
    LibraryException(const std::string& msg, const std::string& func, int line)
        : message(msg), functionName(func), lineNumber(line) {}

    const char* what() const noexcept override {
        std::ostringstream oss;
        oss << message << " [in " << functionName << "() at line " << lineNumber << "]";
        fullMessage = oss.str();
        return fullMessage.c_str();
    }

    ~LibraryException() noexcept override = default;
};

class BookNotFoundException : public LibraryException {
public:
    BookNotFoundException(const std::string& msg, const std::string& func, int line)
        : LibraryException(msg, func, line) {}
};

class MemberNotFoundException : public LibraryException {
public:
    MemberNotFoundException(const std::string& msg, const std::string& func, int line)
        : LibraryException(msg, func, line) {}
};

class BookNotAvailableException : public LibraryException {
public:
    BookNotAvailableException(const std::string& msg, const std::string& func, int line)
        : LibraryException(msg, func, line) {}
};

class MaxBooksExceededException : public LibraryException {
public:
    MaxBooksExceededException(const std::string& msg, const std::string& func, int line)
        : LibraryException(msg, func, line) {}
};

} // namespace LibrarySystem

#endif // EXCEPTIONS_H
