//Program 3: Multilevel Inheritance
// Scenario: Demonstrate how a class can inherit from another class that is already inherited.

#include <iostream> // # - preprocessor directive
                    // include - keyword to include a header file in the program
                    // < > - angle brackets indicate a standard library header file
                    // iostream - header file used for input and output operations
#include <string>    // string - header file for using the string class
#include <utility>   // utility - header file for std::move function
using namespace std;  /* using - keyword to bring the standard namespace into scope
                       namespace - a logical region where identifiers are stored
                       std - standard namespace used for C++ standard library
                       ; - semicolon to terminate the statement */

class Person {   // class - keyword used to define a user-defined data type
                 // Person - name of the class
                 // { - opening brace to start the class body

protected:       // protected - access specifier that allows derived classes to access members
string name;     // string - data type used to store text
                 // name - member variable to store the person's name

public:          // public - access specifier that allows access from outside the class
explicit Person(string personName) : name(std::move(personName)) {}  // Person - constructor name same as class
                                                                    // string personName - parameter of type string
                                                                    // : name(std::move(personName)) - initializes the name member with moved value
                                                                    // {} - empty constructor body

void showPerson() const {   // void - return type indicating no value is returned
                           // showPerson - function name to display person's information
                           // const - function cannot modify class members
cout << "Name: " << name << '\n';  // cout - standard output stream object
                                   // << - insertion operator used to send data to output
                                   // "Name: " - text printed before the name
                                   // name - variable containing the person's name
                                   // '\n' - newline character to move to next line
}

};  // } - closing brace of the class
    // ; - semicolon to end class declaration

class Employee : public Person {  // class - keyword to define a new class
                                 // Employee - derived class name
                                 // : public Person - inheritance from Person using public access
                                 // { - opening brace for class body

protected:   // protected - members are accessible to derived classes
int employeeId;  // int - data type for integer values
                 // employeeId - member variable to store employee identification number

public:      // public - access specifier
Employee(string employeeName, int id)   // Employee - constructor of Employee class
: Person(std::move(employeeName)), employeeId(id) {}  // : Person(...) - call base class constructor
                                                     // employeeId(id) - initialize employeeId with the passed value
                                                     // {} - empty constructor body

void showEmployee() const {   // void - return type
                             // showEmployee - function to show employee details
                             // const - prevents modification of data members
cout << "Employee ID: " << employeeId << '\n';  // cout - output stream object
                                                // employeeId - variable storing the ID
                                                // '\n' - newline character
}
};  // } - closing brace of Employee class
    // ; - semicolon

class Manager : public Employee {  // class - keyword to define a new class
                                  // Manager - derived class name
                                  // : public Employee - multilevel inheritance from Employee
                                  // { - opening brace

private:   // private - access specifier that restricts access to class members
int teamSize;  // int - integer data type
               // teamSize - variable storing manager's team size

public:    // public - access specifier
Manager(string managerName, int id, int size)  // Manager - constructor name
: Employee(move(managerName), id), teamSize(size) {}  // Employee(move(managerName), id) - call Employee constructor
                                                    // teamSize(size) - initialize teamSize using passed value
                                                    // {} - constructor body empty

void showManager() const {   // void - return type
                            // showManager - function to print manager information
                            // const - function cannot change data members
showPerson();   // showPerson() - calls base class function to display person's name
showEmployee(); // showEmployee() - calls Employee class function to display employee ID
cout << "Team Size: " << teamSize << '\n';  // cout - output stream object
                                            // << - insertion operator
                                            // teamSize - variable storing manager team count
                                            // '\n' - newline character
}
};  // } - closing brace of Manager class
    // ; - semicolon

int main() {    // int - return type of main function
                // main - entry point of the C++ program
                // { - opening brace of function body

Manager manager("Ravi", 501, 8);  // Manager - object creation of Manager class
                                   // manager - object name
                                   // "Ravi" - manager's name
                                   // 501 - employee ID
                                   // 8 - team size

manager.showManager();  // manager - object of Manager class
                        // . - member access operator
                        // showManager() - function call to display all details

return 0;  // return - keyword used to return a value to the operating system
           // 0 - indicates successful execution of the program
           // ; - semicolon to end the statement

}  // } - closing brace of the main function