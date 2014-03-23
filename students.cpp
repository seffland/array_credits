#include "students.h"
#include "arrayUtils.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Student* students;
int numStudents;
string* studentNames;
int* studentCredits;

//Initialize all student data, allowing for at least the indicated
//number of students.
void initializeStudents (int maxStudents)
{
    numStudents = 0;
    studentNames = new string [maxStudents];
    studentCredits = new int [maxStudents];
}

//Clean up student data.
void cleanUpStudents()
{
    delete [] studentNames;
    delete [] studentCredits;
}

//Add a student starting with 0 credits.  Return position where inserted.
int addStudent (std::string studentsName)
{
    int whereInserted = addInOrder (studentNames, numStudents, studentsName);
    --numStudents;
    addElement (studentCredits, numStudents, whereInserted, 0);
    return whereInserted;

}
//Add a number of credits taken by a student
int addCredits (std::string studentName, int credits)
{
    int pos = binarySearch (studentNames, numStudents, studentName);
    if (pos < 0)
    {
        pos = addStudent (studentName);
    }
    studentCredits[pos] += credits;
}
