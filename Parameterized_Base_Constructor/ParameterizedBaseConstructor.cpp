#include <iostream>   // Used for input and output (cout, cin)
#include <string>     // Used for string data type
#include <utility>    // Used for move() function

using namespace std;  // Allows using standard library names without std::

// Base class
class Person {
protected:            // protected members can be accessed by derived classes
    string name;      // string stores text data

public:
    // explicit prevents automatic type conversion
    explicit Person(string personName) : name(move(personName)) {
        // move() transfers data instead of copying it
    }
};

// Derived class inheriting from Person
class Student : public Person {
private:              // private members can only be accessed inside the class
    int rollNumber;   // int stores integer values

public:
    // Constructor initializes base class and roll number
    Student(string studentName, int roll)
        : Person(move(studentName)), rollNumber(roll) {}

    // const means this function does not modify object data
    void display() const {
        cout << "Name: " << name << '\n';
        cout << "Roll Number: " << rollNumber << '\n';
    }
};

int main() {
    // Create object of Student class
    Student student("Shree", 23);

    // Call member function
    student.display();

    return 0; // Program ends successfully
}