#include <iostream> // # - preprocessor directive
                    // include - keyword to evoke the preprocessor
                    //  < > - indicates that the header file is a standard library header file
                    // iostream - header file that contains definitions for input/output stream objects
using namespace std;   /* using - keyword to specify the namespace 
                         namespace - a scope that contains identifiers 
                         std - standard namespace 
                         ; - semicolon to terminate the statement */

class Academic {   // class - keyword used to define a class
                   // Academic - user-defined class name
                   // { - opening brace to indicate the start of the class body
protected:         // protected - access specifier that restricts access to derived classes and the class itself
int academicMarks; // academicMarks - member variable to store academic marks

public: // public - access specifier that allows access from outside the class
        // Academic - constructor name matching the class name
explicit Academic(int marks) : academicMarks(marks) {} // explicit - keyword used to prevent implicit conversions
                                                       // int marks - parameter for the constructor
                                                       // : academicMarks(marks) - member initializer list assigning marks to academicMarks

void showAcademic() const { // void - return type indicating no value is returned
                           // showAcademic - member function name
                           // const - keyword indicating the function does not modify the object
cout << "Academic Marks: " << academicMarks << '\n'; // cout - standard output stream object
                                                    // << - insertion operator to send data to the output stream
                                                    // "Academic Marks: " - string literal displayed as output
                                                    // academicMarks - variable storing the academic marks
                                                    // '\n' - newline escape sequence
}
}; // } - closing brace to end the class

class Sports { // class - keyword used to define a class
               // Sports - user-defined class name
protected:     // protected - access specifier that restricts access to derived classes and the class itself
int sportsMarks; // sportsMarks - member variable to store sports marks

public: // public - access specifier that allows access from outside the class
        // Sports - constructor name matching the class name
explicit Sports(int marks) : sportsMarks(marks) {} // explicit - keyword used to prevent implicit conversions
                                                   // int marks - parameter for the constructor
                                                   // : sportsMarks(marks) - member initializer list assigning marks to sportsMarks

void showSports() const { // void - return type indicating no value is returned
                         // showSports - member function name
                         // const - keyword indicating the function does not modify the object
cout << "Sports Marks: " << sportsMarks << '\n'; // cout - standard output stream object
                                                 // << - insertion operator to send data to the output stream
                                                 // "Sports Marks: " - string literal displayed as output
                                                 // sportsMarks - variable storing the sports marks
                                                 // '\n' - newline escape sequence
}
}; // } - closing brace to end the class

class Student : public Academic, public Sports { // class - keyword used to define a class
                                               // Student - derived class name
                                               // : public Academic, public Sports - inheritance from Academic and Sports
public: // public - access specifier that allows access from outside the class
        // Student - constructor name matching the class name
Student(int academic, int sports) // int academic, int sports - parameters for the constructor
: Academic(academic), Sports(sports) {} // : Academic(academic), Sports(sports) - constructor initializer list calling base class constructors

void showTotal() const { // void - return type indicating no value is returned
                       // showTotal - member function name
                       // const - keyword indicating the function does not modify the object
cout << "Total Marks: " << academicMarks + sportsMarks << '\n'; // cout - standard output stream object
                                                                 // << - insertion operator to send data to the output stream
                                                                 // "Total Marks: " - string literal displayed as output
                                                                 // academicMarks + sportsMarks - total of both marks
                                                                 // '\n' - newline escape sequence
}
}; // } - closing brace to end the class

int main() { // int - keyword to declare a variable of type integer
             // main - function name that serves as the entry point of the program
             // { - opening brace to indicate the start of the function body

Student student(90, 35); // Student - class name
                         // student - object of the Student class
                         // (90, 35) - values passed to the constructor

student.showAcademic(); // student - object name
                       // showAcademic() - member function call to display academic marks

student.showSports(); // student - object name
                     // showSports() - member function call to display sports marks

student.showTotal(); // student - object name
                    // showTotal() - member function call to display total marks

return 0; // return - keyword to return a value from the function
          // 0 - integer value indicating successful execution of the program
          // ; - semicolon to terminate the statement
} // } - closing brace to end the function