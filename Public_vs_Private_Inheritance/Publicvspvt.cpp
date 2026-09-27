
/* Concept 3: Public versus Private Inheritance
   This concept explains the difference between public inheritance and private inheritance.
   In public inheritance, public members of the base class remain public in the derived class.
   In private inheritance, public members of the base class become private in the derived class.
   This example demonstrates how access control changes in both cases. */

#include <iostream>   /* #include is a preprocessor directive.
                       It tells the compiler to include the standard input-output library.
                       <iostream> is the header file that provides cout and cin.
                       The angle brackets <> are used for standard library headers. */

using namespace std;  /* using namespace std; tells the compiler to use the std namespace.
                        std is the standard C++ namespace where cout, cin, and other standard library features are defined.
                        The semicolon ; ends the statement. */

class Base {          /* class Base { ... } defines a base class named Base.
                       A class is a blueprint for creating objects.
                       Base is the parent class. */
public:               /* public: means members declared after this are accessible from outside the class.
                       They can also be accessed by derived classes. */
    void show() const {    /* void show() const is a member function named show.
                            void means the function does not return any value.
                            () indicates the parameter list.
                            const means this function cannot modify the object.
                            The opening brace { starts the function body. */
        cout << "Base public function\n";  /* cout is the standard output stream.
                                           << is the insertion operator.
                                           "Base public function\n" is a string literal to print.
                                           \n is an escape sequence that inserts a new line.
                                           The semicolon ; ends the statement. */
    }   /* The closing brace } ends the function body. */
};  /* The semicolon ; ends the class definition. */

class PublicDerived : public Base {  /* class PublicDerived : public Base { ... }
                                      This is public inheritance.
                                      PublicDerived inherits from Base.
                                      The colon : means inheritance.
                                      public means the public members of Base remain public in PublicDerived. */
};  /* The semicolon ; ends the class definition. */

class PrivateDerived : private Base {  /* class PrivateDerived : private Base { ... }
                                        This is private inheritance.
                                        PrivateDerived inherits from Base.
                                        private means the public members of Base become private in PrivateDerived. */
public:                               /* public: means members declared after this are accessible from outside the class. */
    void callBaseShow() const {        /* void callBaseShow() const is a method inside PrivateDerived.
                                        It is used to call the base class function show().
                                        const means the function does not modify the object. */
        show();                       /* show() is called here.
                                        Even though Base is privately inherited, the function can still be used inside PrivateDerived.
                                        The semicolon ; ends the statement. */
    }   /* Closing brace of the function. */
};  /* Closing brace of the class. */

int main() {    /* int main() { ... } is the main function.
                 Every C++ program starts from main().
                 int means the function returns an integer value.
                 () is the parameter list.
                 { starts the function body. */

    PublicDerived publicObject;   /* PublicDerived publicObject; creates an object named publicObject of type PublicDerived.
                                    The object is created using the default constructor. */
    publicObject.show();          /* publicObject.show(); calls the function show() from the base class.
                                    Since inheritance is public, show() is accessible here.
                                    The semicolon ; ends the statement. */

    PrivateDerived privateObject;  /* PrivateDerived privateObject; creates an object named privateObject of type PrivateDerived. */
    privateObject.callBaseShow();  /* privateObject.callBaseShow(); calls the public method of PrivateDerived.
                                    This method internally calls show().
                                    The semicolon ; ends the statement. */

    // privateObject.show(); // Error: show() is private through private inheritance.
    /* This line is commented out because it would cause an error.
       privateObject.show(); is invalid because show() becomes private in PrivateDerived due to private inheritance.
       // starts a single-line comment.
       The comment explains the error.
       The error message is: show() is private through private inheritance.
       The comment is intentionally disabled so the program can compile. */

    return 0;    /* return 0; indicates successful program execution.
                   0 is returned to the operating system.
                   The semicolon ; ends the statement. */
}   /* Closing brace of the main function. */