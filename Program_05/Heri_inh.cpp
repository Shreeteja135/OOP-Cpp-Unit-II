// # = preprocessor symbol
// include = include library
// < = start header
// iostream = input output library
// > = end header
#include <iostream>

// # = preprocessor symbol
// include = include library
// < = start header
// string = string library
// > = end header
#include <string>

// # = preprocessor symbol
// include = include library
// < = start header
// utility = utility library
// > = end header
#include <utility>

// class = create class
// Vehicle = class name
class Vehicle

// { = class body start
{
    
// protected = accessible in derived classes
protected:

    // std = standard namespace
    // :: = scope resolution operator
    // string = string data type
    // registrationNumber = variable name
    // ; = statement end
    std::string registrationNumber;


// public = accessible everywhere
public:

    // explicit = prevents automatic conversion
    // Vehicle = constructor name
    // ( = parameter list start
    // std = standard namespace
    // :: = scope resolution operator
    // string = string data type
    // registration = parameter name
    // ) = parameter list end
    explicit Vehicle(std::string registration)

        // : = initializer list start
        // registrationNumber = data member
        // ( = function call start
        // std = standard namespace
        // :: = scope resolution operator
        // move = move function
        // ( = function call start
        // registration = parameter
        // ) = function call end
        // ) = function call end
        : registrationNumber(std::move(registration))

    // { = constructor body start
    {
    // } = constructor body end
    }

    // void = no return value
    // start = function name
    // ( ) = no parameters
    // const = object not modified
    void start() const

    // { = function body start
    {
        // std = standard namespace
        // :: = scope resolution operator
        // cout = output object
        // << = insertion operator
        // "Vehicle " = text
        // << = insertion operator
        // registrationNumber = variable
        // << = insertion operator
        // " started successfully\n" = text
        // ; = statement end
        std::cout << "Vehicle "
                  << registrationNumber
                  << " started successfully\n";
    // } = function body end
    }

// } = class body end
};
    

// class = create class
// Car = class name
// : = inheritance symbol
// public = public inheritance
// Vehicle = base class
class Car : public Vehicle

// { = class body start
{

public:

    // explicit = prevents automatic conversion
    // Car = constructor name
    // ( = parameter list start
    // std = standard namespace
    // :: = scope resolution operator
    // string = string type
    // registration = parameter name
    // ) = parameter list end
    explicit Car(std::string registration)

        // : = initializer list
        // Vehicle = base constructor
        // ( = function call start
        // std = standard namespace
        // :: = scope resolution operator
        // move = move function
        // ( registration ) = pass parameter
        // ) = function call end
        : Vehicle(std::move(registration))

    {
    }

    // void = no return value
    // openBoot = function name
    // ( ) = no parameters
    // const = object not modified
    void openBoot() const
    {
        // std = standard namespace
        // :: = scope resolution operator
        // cout = output object
        // << = insertion operator
        // "Car boot opened\n" = text
        std::cout << "Car boot opened\n";
    }

// } = class body end
};


// class = create class
// Bike = class name
// : = inheritance symbol
// public = public inheritance
// Vehicle = base class
class Bike : public Vehicle

// { = class body start
{

public:

    // explicit = prevents automatic conversion
    // Bike = constructor name
    // ( = parameter list start
    // std = standard namespace
    // :: = scope resolution operator
    // string = string type
    // registration = parameter name
    // ) = parameter list end
    explicit Bike(std::string registration)

        // : = initializer list
        // Vehicle = base constructor
        // ( = function call start
        // std = standard namespace
        // :: = scope resolution operator
        // move = move function
        // ( registration ) = parameter
        // ) = function call end
        : Vehicle(std::move(registration))

    {
    }

    // void = no return value
    // helmetReminder = function name
    // ( ) = no parameters
    // const = object not modified
    void helmetReminder() const
    {
        // std = standard namespace
        // :: = scope resolution operator
        // cout = output object
        // << = insertion operator
        // "Always wear helmet for safety\n" = text
        std::cout << "Always wear helmet for safety\n";
    }

// } = class body end
};


// int = integer return type
// main = program starting function
// ( ) = no parameters
int main()

// { = main body start
{

    // Car = class name
    // car = object name
    // ( = constructor call start
    // "TN07AB4567" = registration value
    // ) = constructor call end
    // ; = statement end
    Car car("TN07AB4567");

    // Bike = class name
    // bike = object name
    // ( = constructor call start
    // "GJ01ZX9876" = registration value
    // ) = constructor call end
    // ; = statement end
    Bike bike("GJ01ZX9876");

    // car = object
    // . = member access operator
    // start = function
    // ( ) = function call
    // ; = statement end
    car.start();

    // car = object
    // . = member access operator
    // openBoot = function
    // ( ) = function call
    // ; = statement end
    car.openBoot();

    // bike = object
    // . = member access operator
    // start = function
    // ( ) = function call
    // ; = statement end
    bike.start();

    // bike = object
    // . = member access operator
    // helmetReminder = function
    // ( ) = function call
    // ; = statement end
    bike.helmetReminder();

    // return = return value
    // 0 = successful execution
    // ; = statement end
    return 0;

// } = main body end
}