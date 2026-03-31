#include <iostream>
#include <string>
#include <iomanip>
#include <thread>
#include <chrono>
using namespace std;

int choice; // User's choice in the menu (u‿ฺu✿ฺ)

string SubjectName;
float GradeFS; // Grade For Subject
int UnitFS; // Amount of units for that subject
string Name;

float totalGPA;
float finalGPA;
int totalUnits;

int Empty = 0;

float Grades[15] = {0};
int Units[15];
float GPA[15] = {0};
string Subjects[15];

// declaration of functions vv o(=•ェ•=)o ``~!
void Menu(); 
void NewGrade();
void CalcGPA();
void displayALL();
void restart();

int emptyGrade();
int emptyIndex();

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
            else if (choice == 2)
            {
                CalcGPA();
            }
            else if (choice == 3)
            {
                displayALL();
            }
            else if (choice == 4)
            {
                Grades[15] = {0};
            }
            else if (choice <= 0 || choice >= 6)
            {
                cout << "Invalid. Choice is not within the answers available.\n";
                cout << "Please enter a new number from the provided.\n";
            }

        } while (choice != 5);

        cout << "\nExiting program...";
        this_thread::sleep_for(500ms);
        cout << "\n...";
        this_thread::sleep_for(500ms);
        cout << "Thank you!";

        return 0;
    }

void Menu()
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
        cin.ignore();
        getline(cin, SubjectName);
        cout << "Enter GRADE for that subject: ";
        cin >> GradeFS;
        cout << "Enter amount of UNITS for that subject: ";
        cin >> UnitFS;

        Empty = 0;

        for (int i = 0; i < 15; i++) 
            {
                if (Grades[i] == 0 && Empty == 0)
                {
                    Subjects[i] = SubjectName;
                    Grades[i] = GradeFS;
                    Units[i] = UnitFS;

                    Empty++;
                }
            }

            Empty = 0;

        cout << "\n\nGrades successfully added!";
    }
}

void CalcGPA()
{
    for (int i = 0; i < 15; i++)
    {
        if (Grades[i] != 0)
        {
            GPA[i] = Grades[i] * Units[i];

            totalUnits += Units[i];
        }

        totalGPA += GPA[i];
    }

    finalGPA = totalGPA / totalUnits;

    cout << "\nYour final GPA is: " << finalGPA;
}

void displayALL()
{
    emptyIndex();

    cout << left << setw(15) << "Subject"
         << left << setw(5) << "Grade"
         << right << setw(10) << "Units\n"
         << "===================================\n";

    for (int i = 0; i < 15; i++)
    {
        if (Grades[i] != 0)
        {
            cout << left << setw(15) << Subjects[i]
                 << left << setw(5) << Grades[i]
                 << right << setw(10) << Units[i] << endl;
        }
    }

    Empty = 0;
}

int emptyGrade() //checks if array has empty indexes
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

int emptyIndex()
{
    // find nearest empty index in the array

    for (int i = 0; i < 15; i++)
    {
        if (Grades[i] != 0)
        {
            Empty++;
        }
    }

    return Empty;
}

