// Concept 1: Basic Single Inheritance
// "Concept 1" - this program demonstrates the first concept of inheritance in C++
// "Basic Single Inheritance" - a derived class inherits from only one base class

#include <iostream>   // includes the input/output stream library for using cout and cin
                     // <iostream> is a standard C++ header file
                     // cout is used to display output on the screen

#include <string>     // includes the string library so we can use the string data type
                     // string is used to store text like names

#include <utility>    // includes the utility header for std::move
                     // std::move is used to transfer ownership of an object without copying it

using namespace std; // tells the compiler to use the standard namespace
                     // namespace is a scope that groups identifiers like classes, functions, and variables
                     // std is the standard C++ namespace
                     // without this, we would have to write std::cout, std::string, etc.

class Person {       // defines a base class named Person
                     // a class is a user-defined data type that groups related data and functions
                     // Person is the parent class or super class

protected:           // protected access specifier
                     // members declared under protected can be accessed by the class itself and by derived classes
                     // they cannot be accessed directly from outside the class

string name;         // declares a member variable named name of type string
                     // name stores the person's name
                     // since it is protected, it can be used in the derived class Student

public:              // public access specifier
                     // members declared here can be accessed from anywhere in the program

explicit Person(string personName) : name(std::move(personName)) {}
                     // this is a constructor of the class Person
                     // a constructor is a special member function used to initialize objects when they are created
                     // "explicit" prevents implicit conversions
                     // Person(string personName) means the constructor accepts a string argument
                     // : name(std::move(personName)) is the member initializer list
                     // it initializes the name variable with the value passed in personName
                     // std::move converts the string to an rvalue so it can be moved efficiently instead of copied
                     // {} is the empty body of the constructor because there is no extra work to do

void displayName() const {     // defines a member function named displayName
                              // void means the function does not return any value
                              // const means this function does not modify any member of the class
                              // displayName prints the person's name

std::cout << "Name: " << name << '\n'; 
                              // std::cout is used to print output to the console
                              // << is the insertion operator used to send data to the output stream
                              // "Name: " is a string literal displayed on the screen
                              // name is the member variable whose value is printed
                              // '\n' is a newline character that moves the cursor to the next line
}
};

class Student : public Person {  // defines a derived class named Student
                               // Student inherits from Person
                               // ":" indicates inheritance
                               // "public" means the public members of Person remain public in Student
                               // Student is the child class or subclass

private:                       // private access specifier
                               // members declared under private are accessible only inside Student

int rollNumber;                 // declares an integer variable named rollNumber
                               // this stores the roll number of the student
                               // because it is private, only Student can access it

public:                        // public access specifier

Student(string studentName, int roll) 
: Person(move(studentName)), rollNumber(roll) {}
                               // this is the constructor of the Student class
                               // it takes two parameters: studentName (string) and roll (int)
                               // : Person(move(studentName)) calls the base class constructor Person
                               // this passes the student name to the Person constructor
                               // move(studentName) moves the string instead of copying it
                               // rollNumber(roll) initializes the rollNumber member with the value of roll

void displayStudent() const {   // defines a member function named displayStudent
                               // const means this function does not modify class data
                               // this function prints both the student's name and roll number

displayName();                 // calls the displayName() function inherited from Person
                               // since Student inherits from Person, it can access protected/public members and methods of Person

std::cout << "Roll Number: " << rollNumber << '\n';
                               // prints the text "Roll Number: " on the screen
                               // << rollNumber sends the value of rollNumber to the output stream
                               // '\n' moves the cursor to the next line
}
};

int main() {                   // main function starts here
                              // every C++ program starts execution from main()
                              // int indicates the function returns an integer value

Student student("Shree", 101);  // creates an object named student of type Student
                               // constructor is called with arguments "Shree" and 101
                               // "Shree" is passed as the student name
                               // 101 is passed as the roll number

student.displayStudent();       // calls the displayStudent() method on the object student
                               // this prints the student's name and roll number

return 0;                      // returns 0 to the operating system
                               // it indicates that the program has executed successfully
}