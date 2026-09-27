#include <iostream>   // For input and output
#include <string>     // For string data type
#include <vector>     // For vector container

using namespace std;

// ==========================================================
// Base Class : Vehicle
// Stores common details of all vehicles
// ==========================================================
class Vehicle
{
protected:
    string registrationNumber; // Vehicle registration number
    double ratePerDay;         // Rent charged per day
    bool isAvailable;          // Availability status

public:
    // Constructor to initialize vehicle details
    Vehicle(string reg, double rate, bool available)
    {
        registrationNumber = reg;
        ratePerDay = rate;
        isAvailable = available;
    }

    // Virtual display function
    // Can be overridden by derived classes
    virtual void display()
    {
        cout << "Registration Number : "
             << registrationNumber << endl;

        cout << "Rate Per Day        : "
             << ratePerDay << endl;

        // Check vehicle availability
        if (isAvailable)
            cout << "Status              : Available" << endl;
        else
            cout << "Status              : Not Available" << endl;
    }

    // Virtual function to calculate rent
    virtual double calculateRent(int days)
    {
        return ratePerDay * days;
    }

    // Virtual destructor
    virtual ~Vehicle() {}
};

// ==========================================================
// Derived Class : Car
// Inherits Vehicle class
// Adds number of doors
// ==========================================================
class Car : public Vehicle
{
private:
    int doors; // Number of doors in car

public:
    // Constructor
    Car(string reg, double rate, bool available, int d)
        : Vehicle(reg, rate, available)
    {
        doors = d;
    }

    // Override display function
    void display() override
    {
        Vehicle::display(); // Call base class display

        cout << "Doors               : "
             << doors << endl;
    }
};

// ==========================================================
// Derived Class : Bike
// Inherits Vehicle class
// Adds engine capacity
// ==========================================================
class Bike : public Vehicle
{
private:
    int engineCapacity; // Engine capacity in CC

public:
    // Constructor
    Bike(string reg, double rate, bool available, int cc)
        : Vehicle(reg, rate, available)
    {
        engineCapacity = cc;
    }

    // Override display function
    void display() override
    {
        Vehicle::display();

        cout << "Engine Capacity     : "
             << engineCapacity
             << " cc" << endl;
    }
};

// ==========================================================
// Derived Class : Bus
// Inherits Vehicle class
// Adds seating capacity
// ==========================================================
class Bus : public Vehicle
{
private:
    int seats; // Number of seats in bus

public:
    // Constructor
    Bus(string reg, double rate, bool available, int s)
        : Vehicle(reg, rate, available)
    {
        seats = s;
    }

    // Override display function
    void display() override
    {
        Vehicle::display();

        cout << "Seats               : "
             << seats << endl;
    }
};

// ==========================================================
// Main Function
// Program execution starts here
// ==========================================================
int main()
{
    // Vector of Vehicle pointers
    // Used to store Car, Bike and Bus objects together
    vector<Vehicle*> vehicles;

    int choice;

    // Menu-driven loop
    do
    {
        cout << "\n==================================" << endl;
        cout << "      VEHICLE RENTAL SYSTEM" << endl;
        cout << "==================================" << endl;

        cout << "1. Add Car" << endl;
        cout << "2. Add Bike" << endl;
        cout << "3. Add Bus" << endl;
        cout << "4. Display All Vehicles" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter Choice : ";
        cin >> choice;

        // Adding vehicle
        if (choice >= 1 && choice <= 3)
        {
            string reg;
            double rate;
            bool available;

            // Common inputs for all vehicles
            cout << "\nEnter Registration Number : ";
            cin >> reg;

            cout << "Enter Rate Per Day : ";
            cin >> rate;

            cout << "Available? (1 = Yes, 0 = No) : ";
            cin >> available;

            // Add Car
            if (choice == 1)
            {
                int doors;

                cout << "Enter Number of Doors : ";
                cin >> doors;

                vehicles.push_back(
                    new Car(reg, rate, available, doors));

                cout << "Car Added Successfully!" << endl;
            }

            // Add Bike
            else if (choice == 2)
            {
                int cc;

                cout << "Enter Engine Capacity (cc) : ";
                cin >> cc;

                vehicles.push_back(
                    new Bike(reg, rate, available, cc));

                cout << "Bike Added Successfully!" << endl;
            }

            // Add Bus
            else if (choice == 3)
            {
                int seats;

                cout << "Enter Number of Seats : ";
                cin >> seats;

                vehicles.push_back(
                    new Bus(reg, rate, available, seats));

                cout << "Bus Added Successfully!" << endl;
            }
        }

        // Display all stored vehicles
        else if (choice == 4)
        {
            cout << "\n========== VEHICLE LIST ==========\n";

            // Loop through vector
            for (int i = 0; i < vehicles.size(); i++)
            {
                cout << "\nVehicle "
                     << i + 1
                     << endl;

                // Runtime Polymorphism
                // Calls correct display() function
                vehicles[i]->display();

                cout << "Rent for 3 Days : "
                     << vehicles[i]->calculateRent(3)
                     << endl;
            }
        }

    } while (choice != 5); // Continue until Exit selected

    // ==================================================
    // Memory Cleanup
    // Delete dynamically created objects
    // ==================================================
    for (int i = 0; i < vehicles.size(); i++)
    {
        delete vehicles[i];
    }

    cout << "\nProgram Ended Successfully!" << endl;

    return 0;
}