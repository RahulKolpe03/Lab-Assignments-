#include <iostream>
#include <limits>
#include <string>

#include "../headers/Person.h"
#include "../headers/Member.h"
#include "../headers/Librarian.h"
#include "../headers/Book.h"
#include "../headers/Container.h"
#include "../headers/Transaction.h"
#include "../headers/Exceptions.h"
#include "../headers/Library.h"

using namespace LibrarySystem;
using namespace std;

void showMenu() {
    cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========\n";
    cout << " 1. Add New Book\n";
    cout << " 2. Remove Book\n";
    cout << " 3. Search Book\n";
    cout << " 4. Display All Books\n";
    cout << " 5. Register Member\n";
    cout << " 6. Remove Member\n";
    cout << " 7. Search Member\n";
    cout << " 8. Display All Members\n";
    cout << " 9. Issue Book\n";
    cout << "10. Return Book\n";
    cout << "11. View Overdue Books\n";
    cout << "12. Save Data\n";
    cout << "13. Load Data\n";
    cout << " 0. Exit\n";
    cout << "================================================\n";
    cout << "Enter your choice: ";
}

int readInt() {
    int value;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    return value;
}

string readLine(const string& prompt) {
    cout << prompt;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string line;
    getline(cin, line);
    return line;
}

// Demonstrates the assignment's core polymorphism requirement:
// Person* p = new Member(...); p->displayInfo(); must run Member's version.
void runPolymorphismDemo() {
    cout << "\n--- Runtime Polymorphism Demo ---\n";
    Person* p1 = new Member(901, "Demo Member", "9990001111");
    Person* p2 = new Librarian(801, "Demo Librarian", "9990002222", "EMP101", 45000.0);

    p1->displayInfo(); // late binding -> Member::displayInfo
    p2->displayInfo(); // late binding -> Librarian::displayInfo

    delete p1; // virtual destructor -> Member's destructor runs, frees issuedBookIds
    delete p2;
    cout << "----------------------------------\n";
}

int main() {
    Library library;
    const string booksFile = "../data/books.txt";
    const string membersFile = "../data/members.txt";
    const string transactionsFile = "../data/transactions.txt";

    cout << "Welcome to the Library Management System\n";
    cout << "(Dates are entered as simple day numbers, e.g. 1, 2, 15 - see README.md)\n";
    runPolymorphismDemo();

    int choice;
    do {
        showMenu();
        choice = readInt();

        try {
            switch (choice) {
                case 1: {
                    cout << "Enter Book ID: ";
                    int id = readInt();
                    string title = readLine("Enter Title: ");
                    string author = readLine("Enter Author: ");
                    string isbn = readLine("Enter ISBN: ");
                    cout << "Enter Quantity: ";
                    int qty = readInt();
                    library.addBook(Book(id, title, author, isbn, qty));
                    cout << "Book added successfully.\n";
                    break;
                }
                case 2: {
                    cout << "Enter Book ID to remove: ";
                    int id = readInt();
                    library.removeBook(id);
                    cout << "Book removed successfully.\n";
                    break;
                }
                case 3: {
                    cout << "Search by (1) ID or (2) Title? ";
                    int mode = readInt();
                    if (mode == 1) {
                        cout << "Enter Book ID: ";
                        int id = readInt();
                        cout << library.searchBookById(id) << "\n";
                    } else {
                        string title = readLine("Enter Title: ");
                        cout << library.searchBookByTitle(title) << "\n";
                    }
                    break;
                }
                case 4:
                    library.displayAllBooks();
                    break;
                case 5: {
                    cout << "Enter Member ID: ";
                    int id = readInt();
                    string name = readLine("Enter Name: ");
                    string phone = readLine("Enter Phone: ");
                    library.registerMember(Member(id, name, phone));
                    cout << "Member registered successfully.\n";
                    break;
                }
                case 6: {
                    cout << "Enter Member ID to remove: ";
                    int id = readInt();
                    library.removeMember(id);
                    cout << "Member removed successfully.\n";
                    break;
                }
                case 7: {
                    cout << "Search by (1) ID or (2) Name? ";
                    int mode = readInt();
                    if (mode == 1) {
                        cout << "Enter Member ID: ";
                        int id = readInt();
                        library.searchMemberById(id).displayInfo();
                    } else {
                        string name = readLine("Enter Name: ");
                        library.searchMemberByName(name).displayInfo();
                    }
                    break;
                }
                case 8:
                    library.displayAllMembers();
                    break;
                case 9: {
                    cout << "Enter Member ID: ";
                    int mid = readInt();
                    cout << "Enter Book ID: ";
                    int bid = readInt();
                    cout << "Enter Issue Day Number (e.g. 1): ";
                    int day = readInt();
                    library.issueBook(mid, bid, to_string(day));
                    break;
                }
                case 10: {
                    cout << "Enter Member ID: ";
                    int mid = readInt();
                    cout << "Enter Book ID: ";
                    int bid = readInt();
                    cout << "Enter Return Day Number: ";
                    int day = readInt();
                    library.returnBook(mid, bid, to_string(day));
                    break;
                }
                case 11: {
                    cout << "Enter Today's Day Number: ";
                    int day = readInt();
                    library.viewOverdueBooks(to_string(day));
                    break;
                }
                case 12:
                    library.saveData(booksFile, membersFile, transactionsFile);
                    break;
                case 13:
                    library.loadData(booksFile, membersFile, transactionsFile);
                    break;
                case 0:
                    cout << "Exiting. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
        catch (const LibraryException& e) {
            cout << "[Library Error] " << e.what() << "\n";
        }
        catch (const std::exception& e) {
            cout << "[Error] " << e.what() << "\n";
        }

    } while (choice != 0);

    return 0;
}
