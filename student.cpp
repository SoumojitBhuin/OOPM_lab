#include <iostream>
using namespace std;

class Students
{
    private:
        string name;
        int roll_no;
        int marks[3];
        float percentage;
    
    public:
        void getInput()
        {
            cout << "Enter the name of the student: ";
            getline(cin,name);
            
            cout << "Enter the Roll No. of " << name <<": ";
            cin >> roll_no;
            
            for (int i=0; i<3; i++)
            {
                cout << "Enter the marks of subject " << (i+1) << ": ";
                cin >> marks[i];
            }
        }
        
        void calculatePercentage()
        {
            float total;
            for (int i=0; i<3; i++)
            {
                total += marks[i];
            }
            
            percentage = total / 3.0;
        }
        
        void displayData()
        {
            cout << "Name: " << name << "\nRoll No.: " << roll_no << "\n";
            cout << "Marks obtained: \n";
            for (int i=0; i<3; i++)
            {
                cout << "Marks obtained in Subject " << (i+1) << ": " << marks[i] << "\n";
            }
            cout << "Percentage: " << percentage  << "%\n";
        }
    
};

int main()
{
    
    Students s1;

    s1.getInput();
    s1.calculatePercentage();
    s1.displayData();

    return 0;

}
