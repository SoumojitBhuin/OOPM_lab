#include <iostream>
#include <random>
using namespace std;

class BankAccount
{
    private:
        string account_holder;
        unsigned long long account_no;
        float balance;
    
    public:
        void createAccount()
        {
            cout << "Enter the name of the Account Holder: ";
            getline(cin,account_holder);
            
            std::random_device rd;
            std::mt19937_64 gen(rd()); 
            
            std::uniform_int_distribution<unsigned long long> dist(100000000000, 999999999999);
        
            account_no = dist(gen);
            
            balance = 0.0;
            
            displayDetails();
            
        }
        
        float checkBalance()
        {
            return balance;
        }
        
        void deposit()
        {
            float amount;
            cout << "Enter the amount to be deposited "  ;
            cin >> amount;
            
            balance += amount;
            displayDetails();
        }
        
        void withdraw()
        {
            float amount;
            float remaining_balance;
            remaining_balance = checkBalance();
            if (remaining_balance > 0)
            {
                cout << "Enter the amount to be withdrawn ";
                cin >> amount;
                
                if (remaining_balance >= amount)
                {
                    balance -= amount;
                    displayDetails();
                }
                
                else
                {
                    cout << "Insufficent Balance " << "\n";
                    displayDetails();
                }
            }
            else
            {
                cout << "Insufficent Balance " << "\n";
                displayDetails();
            }
            
            
        }
        
        void displayDetails()
        {
            cout << "Account Number: " << account_no << "\n";
            cout << "Account Holder: " << account_holder << "\n";
            cout << "Balance: " << balance << "\n";
        }
    
};

int main()
{
    
    BankAccount acc1;
    acc1.createAccount();
    
    int choice;
    cout << "\nChoose an operation:\n";
    cout << "1. Deposit\n";
    cout << "2. Withdraw\n";
    cout << "3. Exit\n";
    
    while (1)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
            case 1:
                acc1.deposit();
                break;
            case 2:
                acc1.withdraw();
                break;
            default:
                cout << "Invalid choice.\n";
        }
        if (choice==3)
        {
            break;
        }
        
    }

    return 0;
}

   
