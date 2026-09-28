#include <iostream>   // Used for cout and endl

using namespace std;

// Account class stores bank account information
class Account
{
private:
    double balance;   // Account balance (private data)

    // Auditor class can access private members of Account
    friend class Auditor;

public:
    // Constructor to set initial balance
    Account(double initialBalance)
    {
        balance = initialBalance;
    }
};

// Auditor class checks account details
class Auditor
{
public:
    // Function to display account balance
    void inspect(const Account& account) const
    {
        // Accessing private member balance because Auditor is a friend class
        cout << "Account Balance: "
             << account.balance
             << endl;
    }
};

int main()
{
    // Create account object with balance 5000
    Account account(5000.0);

    // Create auditor object
    Auditor auditor;

    // Auditor checks and displays account balance
    auditor.inspect(account);

    // Program ends successfully
    return 0;
}