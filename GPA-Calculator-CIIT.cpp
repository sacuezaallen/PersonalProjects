#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int choice; // User's choice in the menu (u‿ฺu✿ฺ)

string SubjectName;
int GradeFS; // Grade For Subject
int UnitFS; // Amount of units for that subject
string Name;

int Empty = 0;

int Grades[15];
int Units[15];
string Subjects[15];
string StudentNames [5];
int CGrades[5]; // Calculated Grades

// declaration of functions vv o(=•ェ•=)o ``~!
void Menu(); 
void NewGrade();
int emptyGrade();

int main()
    {
        cout << "NOTE: This program uses CIIT's grade point equivalency\nand weighted GPA calculation system\n";
        cout << "Learn more about it on CIIT's Student Handbook (Section 9.1)\n";

        cout << "\nPlease abbreviate long subject names for better readability.\n";

        do
        {
            Menu();

            if (choice == 1)
            {
                NewGrade();
            }
            else
            {
                cout << "Invalid. Choice is not within the answers available.\n";
                cout << "Please enter a new number from the provided.\n";
            }

        } while (choice != 4);

        return 0;
    }

void Menu() // Reusable code for MENU
{
        cout << "\n=======================\n";
        cout << "   GPA CALCULATOR\n";
        cout << "=======================\n";
        cout << "Enter a number of choice:\n";
        cout << "1. Add new grade\n";
        cout << "2. Calculate GPA\n";
        cout << "3. Display ALL\n";
        cout << "4. Start over\n";
        cout << "5. Exit program\n\n";  
        
        cin >> choice;
}

void NewGrade()
{

    emptyGrade();

    if (Empty == 0)
    {
        cout << "Maximum amount of grades have been added.";
    }
    else
    {
        cout << "Enter NAME of subject: ";
        cin >> SubjectName;
            cin.ignore();
        cout << "Enter GRADE for that subject: ";
        cin >> GradeFS;
        cout << "Enter amount of UNITS for that subject: ";
        cin >> UnitFS;

        for (int i = 0; i < 15; i++) // check for nearest empty index
            {
                if (Grades[i] == 0)
                {
                    Subjects[i] = SubjectName;
                    Grades[i] = GradeFS;
                    Units[i] = UnitFS;
                }
            }

        cout << "\n\nGrades successfully added!";
    }
}

void displayALL()
{
    for (int i = 0; i < 15; i++)
    {
        //wait lang tinatamad na ako
    }
}

int emptyGrade()
{
    for (int i = 0; i < 15; i++) // check if array is full
    {
        if (Grades[i] == 0)
        {
            Empty++; // Empty indexes are present in the array
        }
    }
    
    return Empty;
}