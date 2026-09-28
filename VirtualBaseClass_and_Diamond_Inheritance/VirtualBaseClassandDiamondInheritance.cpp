#include <iostream>   // Includes input/output library
#include <string>     // Includes string class
#include <utility>    // Includes move() function

using namespace std;  // Use standard namespace

// Person is the base class
class Person
{
protected:            // Accessible inside derived classes
    string name;      // Variable to store person's name

public:               // Accessible from anywhere

    // Constructor
    // string personName = parameter received during object creation
    Person(string personName)
        : name(move(personName)) // move() transfers value to name
    {
    }

    // const means function will not modify object data
    void displayName() const
    {
        cout << "Name: " << name << endl; // Print name
    }
};

// Student inherits Person virtually
// virtual prevents duplicate Person objects
class Student : virtual public Person
{
public:

    // Default constructor
    Student() : Person("Unknown")
    {
    }
};

// Employee inherits Person virtually
class Employee : virtual public Person
{
public:

    // Default constructor
    Employee() : Person("Unknown")
    {
    }
};

// TeachingAssistant inherits both Student and Employee
class TeachingAssistant : public Student, public Employee
{
public:

    // Constructor
    TeachingAssistant(string assistantName)

        // Calls Person constructor
        // move() passes assistantName efficiently
        : Person(move(assistantName)),

          // Calls Student constructor
          Student(),

          // Calls Employee constructor
          Employee()
    {
    }
};

int main()
{
    // Create object named assistant
    // Constructor receives "Riya"
    TeachingAssistant assistant("shree");

    // Calls displayName() function
    assistant.displayName();

    // Return 0 means successful execution
    return 0;
}