#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
using namespace std;

struct Student {
    int studentID;
    char name[50];
    char course[30];
    float midtermGrade;
    float finalGrade;
    float computedAverage;
    char academicStatus[20]; // "Passed" or "Failed"
    float scholarshipGrant; // Monetary value based on average
};

void inputStudents(Student *stud, int size);
void computePerformance(Student *stud, int size);
void displayReport(Student *stud, int size);
void searchStudent(Student *stud, int size);
void displayTopStudent(Student *stud, int size);


int main() {

    Student stud[10];

    inputStudents(stud, 10);
    computePerformance(stud, 10);
    displayReport(stud, 10);
    searchStudent(stud, 10);
    displayTopStudent(stud, 10);

    return 0;
}

void inputStudents(Student *stud, int size) {

    cout << "================================================" << endl;
    cout << "          ENTER STUDENT RECORD DETAILS          " << endl;
    cout << "================================================" << endl;

    for (int i = 0; i < size; i++) {
        cout << "STUDENT #" << (i + 1) << endl;
        cout << "ID: ";
        cin >> stud[i].studentID;
        cin.ignore(); 

        cout << "Name: ";
        cin.getline(stud[i].name, 50);

        cout << "Course: ";
        cin.getline(stud[i].course, 30);

        cout << "Midterm Grade: ";
        cin >> stud[i].midtermGrade;

        cout << "Final Grade: ";
        cin >> stud[i].finalGrade;

        cout << "----------------------------------------------" << endl;
    }
}

void computePerformance(Student *stud, int size) {
    
    for (int i = 0; i < size; i++) 
    {
        (stud + i)->computedAverage = (((stud + i)->midtermGrade * .40) + ((stud + i)->finalGrade) * .60);

        if ((stud + i)->computedAverage >= 75) {
            strcpy((stud + i)->academicStatus, "Passed");
        } else {
            strcpy((stud + i)->academicStatus, "Failed");
        }

        if ((stud + i)->computedAverage >= 92.0) {
            (stud + i)->scholarshipGrant = 15000.00; 
        } else if ((stud + i)->computedAverage > 92.0 || (stud + i)->computedAverage >= 85.0) {
            (stud + i)->scholarshipGrant = 7500.00; 
        } else {
            (stud + i)->scholarshipGrant = 0.00; 
        }
    }
}

void displayReport(Student *stud, int size) {

    cout << "====================================================================================================" << endl;
    cout << "                                    STUDENT ACADEMIC REPORT                                         " << endl;
    cout << "====================================================================================================" << endl;

    cout << fixed << setw(8) << "ID" << setw(20) << "NAME" << setw(20) << "COURSE" << setw(9) << "MIDTERM" << setw(9) << "FINAL" << setw(9) << "AVERAGE" << setw(9) << "STATUS" << setw(9) <<  "GRANT" << endl;

    for (int i = 0; i < size; i++) 
    {
        computePerformance(stud, size);

        cout << fixed << setw(8) << (stud + i)->studentID << setw(20) << (stud + i)->name << setw(20) << (stud + i)->course << setw(9) << setprecision(2) << (stud + i)->midtermGrade << setw(9) << (stud + i)->finalGrade << setw(9) << (stud + i)->computedAverage << setw(9) << (stud + i)->academicStatus << setw(9) << (stud + i)->scholarshipGrant << endl;
    }

    cout << "====================================================================================================" << endl;
}

void searchStudent(Student *stud, int size) {

    int searchID = 0, max = 0;

    cout << "Enter Student ID to search: ";
    cin >> searchID;

    cout << "--------------------------------------------------" << endl;

    for (int i = 0; i < size; i++)
    {
        if ((stud + i)->studentID == searchID)
        {
            cout << "RECORD FOUND\n\n";
            cout << "Name: " << (stud + i)->name << endl;
            cout << "Course: " << (stud + i)->course << endl;
            cout << "Computed Average: " << (stud + i)->computedAverage << endl;
            cout << "Academic Status: " << (stud + i)->academicStatus << endl;

            cout << "--------------------------------------------------" << endl;
        }
        else if ((stud + i)->studentID != searchID)
        {
            max++;
            if (max == size)
            {
                cout << "\nRECORD NOT FOUND !\n";
                cout << "--------------------------------------------------" << endl;
            }
        }
    }
}

void displayTopStudent(Student *stud, int size) {

    int studTopStudent = 0;

    for (int i = 0; i < size; i++)
    {
        if ((stud + i)->computedAverage > (stud + studTopStudent)->computedAverage)
        {
            studTopStudent = i;
        }
    }

    cout << "================================================" << endl;
    cout << "              TOP ACADEMIC PERFORMER            " << endl;
    cout << "================================================" << endl;

    cout << "ID: " << (stud + studTopStudent)->studentID << endl;
    cout << "Name: " << (stud + studTopStudent)->name << endl;
    cout << "Course: " << (stud + studTopStudent)->course << endl;
    cout << "Highest Average: " << (stud + studTopStudent)->computedAverage << endl;
    cout << "Scholarship Awarded: Php " << (stud + studTopStudent)->scholarshipGrant << endl;
    
    cout << "================================================" << endl;
}



