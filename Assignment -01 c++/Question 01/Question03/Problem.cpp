#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Employee
{
private:

    int empId;
    string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive;

    static int employeeCount;

public:

    // Constructor
    Employee()
    {
        empId = 1001 + employeeCount;
        employeeCount++;

        name = "";
        department = "";
        grade = 'D';
        basicSalary = 0;
        isActive = true;
    }

    // ---------------- SETTERS ----------------

    void setName(const string& n)
    {
        if (n.empty())
        {
            cout << "ERROR: Name cannot be empty." << endl;
        }
        else
        {
            name = n;
        }
    }

    void setDepartment(const string& dept)
    {
        if (dept == "Engineering" ||
            dept == "HR" ||
            dept == "Finance" ||
            dept == "Operations")
        {
            department = dept;
        }
        else
        {
            cout << "ERROR: '" << dept
                 << "' is not a registered department."
                 << endl;
        }
    }

    void setGrade(char g)
    {
        if (g == 'A' || g == 'B' ||
            g == 'C' || g == 'D')
        {
            grade = g;
        }
        else
        {
            cout << "ERROR: Invalid grade '" << g
                 << "'. Accepted values: A, B, C, D."
                 << endl;
        }
    }

    void setBasicSalary(double salary)
    {
        if (salary > 10000 && salary < 500000)
        {
            basicSalary = salary;
        }
        else
        {
            cout << "ERROR: Salary must be between "
                 << "Rs.10,000 and Rs.5,00,000. "
                 << "Value rejected." << endl;
        }
    }

    void deactivate()
    {
        isActive = false;
    }

    // ---------------- GETTERS ----------------

    int getEmpId() const
    {
        return empId;
    }

    string getName() const
    {
        return name;
    }

    string getDepartment() const
    {
        return department;
    }

    char getGrade() const
    {
        return grade;
    }

    double getBasicSalary() const
    {
        return basicSalary;
    }

    bool getIsActive() const
    {
        return isActive;
    }

    // ---------------- BUSINESS LOGIC ----------------

    double computeAllowances() const
    {
        if (grade == 'A')
        {
            return basicSalary * 0.40;
        }
        else if (grade == 'B')
        {
            return basicSalary * 0.30;
        }
        else if (grade == 'C')
        {
            return basicSalary * 0.20;
        }
        else
        {
            return basicSalary * 0.10;
        }
    }

    double computeGrossSalary() const
    {
        return basicSalary + computeAllowances();
    }

    double computeTax() const
    {
        double gross = computeGrossSalary();

        if (gross <= 50000)
        {
            return 0;
        }
        else if (gross <= 100000)
        {
            return (gross - 50000) * 0.10;
        }
        else
        {
            return 5000 + (gross - 100000) * 0.20;
        }
    }

    double computeNetSalary() const
    {
        return computeGrossSalary() - computeTax();
    }

    // ---------------- PAYSLIP ----------------

    void printPayslip() const
    {
        cout << endl;
        cout << "============================================" << endl;
        cout << "EMPLOYEE PAYSLIP - AUG 2026" << endl;
        cout << "============================================" << endl;

        cout << "Emp ID      : " << empId << endl;
        cout << "Name        : " << name << endl;
        cout << "Department  : " << department << endl;
        cout << "Grade       : " << grade << endl;

        cout << "Status      : ";

        if (isActive)
        {
            cout << "Active";
        }
        else
        {
            cout << "Inactive";
        }

        cout << endl;

        cout << "--------------------------------------------" << endl;

        cout << fixed << setprecision(2);

        cout << "Basic Salary     : Rs. "
             << basicSalary << endl;

        cout << "Allowances       : Rs. "
             << computeAllowances() << endl;

        cout << "Gross Salary     : Rs. "
             << computeGrossSalary() << endl;

        cout << "--------------------------------------------" << endl;

        cout << "Tax Deduction    : Rs. "
             << computeTax() << endl;

        cout << "Net Salary       : Rs. "
             << computeNetSalary() << endl;

        cout << "============================================" << endl;
    }

    // ---------------- INPUT ----------------

    void acceptDetails()
    {
        string inputName;
        string inputDepartment;
        char inputGrade;
        double inputSalary;

        cout << "\nEnter name: ";
        getline(cin >> ws, inputName);
        setName(inputName);

        cout << "Enter department: ";
        getline(cin >> ws, inputDepartment);
        setDepartment(inputDepartment);

        cout << "Enter grade: ";
        cin >> inputGrade;
        setGrade(inputGrade);

        cout << "Enter basic salary: ";
        cin >> inputSalary;
        setBasicSalary(inputSalary);
    }

    // ---------------- STATIC FUNCTION ----------------

    static int getEmployeeCount()
    {
        return employeeCount;
    }
};


// Static member definition
int Employee::employeeCount = 0;


int main()
{
    /*
    e1.empId = 999;
    e1.basicSalary = -1000;

    These statements give a compiler error because
    empId and basicSalary are private data members.
    Private members cannot be accessed directly from main().
    They can only be accessed through public member functions
    such as getters and setters.
    This is called Encapsulation.
    */


    // Stack object
    Employee e1;

    // Heap objects
    Employee* e2 = new Employee();
    Employee* e3 = new Employee();

    // Accept employee details
    e1.acceptDetails();
    e2->acceptDetails();
    e3->acceptDetails();


    // Print payslips
    e1.printPayslip();
    e2->printPayslip();
    e3->printPayslip();


    // Simulate resignation
    e3->deactivate();

    if (!e3->getIsActive())
    {
        cout << e3->getName()
             << " is no longer active. Payroll skipped."
             << endl;
    }


    // Static member
    cout << "Total Employees : "
         << Employee::getEmployeeCount()
         << endl;


    // Free heap memory
    delete e2;
    delete e3;

    return 0;
}