/* Protected Member Access
   This program demonstrates how a protected member of a base class
   can be accessed by a derived class.
   In C++, protected members are not accessible outside the class,
   but they are accessible inside derived classes. */

#include <iostream>   /* includes input and output functions like cout */
#include <string>     /* includes the string data type */
#include <utility>    /* includes std::move used to efficiently move strings */
using namespace std; /* tells the compiler to use the standard namespace */

class Employee {     /* class Employee is the base class */
protected:           /* protected members can be accessed by derived classes */
    string name;   /* name is a string variable of the employee */

public:
    explicit Employee(string employeeName) : name(std::move(employeeName)) {}
    /* constructor of Employee
       it takes a string parameter employeeName
       : name(std::move(employeeName)) initializes the name variable
       std::move is used to move the string instead of copying it */
};

class Developer : public Employee {   /* Developer inherits from Employee */
private:
    string language;            /* language is a private member of Developer */

public:
    Developer(string employeeName, string programmingLanguage)
    : Employee(move(employeeName)), language(move(programmingLanguage)) {}
    /* constructor of Developer
       it calls the Employee constructor using employeeName
       and initializes its own language variable using programmingLanguage */

    void display() const {
        /* display() is a member function of Developer
           const means this function does not change the object's data */

        cout << "Developer: " << name << '\n';
        /* name is protected in Employee
           Developer can access it because it is derived from Employee
           this prints the employee name */

        cout << "Language: " << language << '\n';
        /* prints the programming language of the developer */
    }
};

int main() {
    /* main() is the starting point of the program */

    Developer developer("shree", "python");
    /* creates an object named developer of type Developer
       passes "shree" as the employee name and "python" as the language */

    developer.display();
    /* calls the display() function
       it prints the developer name and language */

    return 0;
    /* returns 0 to indicate successful execution of the program */
}