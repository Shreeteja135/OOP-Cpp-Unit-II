#include <iostream>   // Used for input and output operations
using namespace std;
// ==========================================================
// Abstract Base Class : Shape
// Contains a pure virtual function area()
// Any class inheriting Shape must implement area()
// ==========================================================
class Shape
{
public:
    // Pure virtual function
    // Makes Shape an abstract class
    virtual double area() const = 0;

    // Virtual destructor
    virtual ~Shape() = default;
};

// ==========================================================
// Derived Class : Rectangle
// Inherits Shape
// Calculates area of a rectangle
// ==========================================================
class Rectangle : public Shape
{
private:
    double length; // Length of rectangle
    double width;  // Width of rectangle

public:
    // Constructor to initialize length and width
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth)
    {
    }

    // Override area() function
    // Formula: Area = Length × Width
    double area() const override
    {
        return length * width;
    }
};

// ==========================================================
// Derived Class : Circle
// Inherits Shape
// Calculates area of a circle
// ==========================================================
class Circle : public Shape
{
private:
    double radius; // Radius of circle

public:
    // Constructor to initialize radius
    explicit Circle(double givenRadius)
        : radius(givenRadius)
    {
    }

    // Override area() function
    // Formula: Area = π × r²
    double area() const override
    {
        return  3.1415* radius * radius;
    }
};

// ==========================================================
// Main Function
// Program execution starts here
// ==========================================================
int main()
{
    // Create Rectangle object
    
    Rectangle rectangle(9, 6);

    // Create Circle object
    Circle circle(5);

    // Display rectangle area
    cout << "Rectangle Area : "<< rectangle.area() << endl;

    // Display circle area
    cout << "Circle Area    : "
         << circle.area()
         << endl;

    return 0;
}