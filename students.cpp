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
    students = new Student[maxStudents];
	numStudents = 0;
}

//Clean up student data.
void cleanUpStudents()
{
    delete[] students;
}

int binarySearch(std::string name)
{
    int first = 0;
    int last = numStudents - 1;
    int mid;

    bool found = false;

    while (first <= last && !found)
    {
        mid = (first + last) / 2;

        if (students[mid].name == name)
            found = true;
        else
            if (name < students[mid].name)
                last = mid - 1;
            else
                first = mid + 1;
    }

    if (found)
        return mid;
    else
        return -1;
}

int addInOrder (Student& value)
{
  // Make room for the insertion
  int toBeMoved = numStudents - 1;
  while (toBeMoved >= 0 && value.name < students[toBeMoved].name) {
    students[toBeMoved+1] = students[toBeMoved];
    --toBeMoved;
  }
  // Insert the new value
  students[toBeMoved+1] = value;
  ++numStudents;
  return toBeMoved+1;
}

//Add a student starting with 0 credits.  Return position where inserted.
int addStudent (std::string studentsName)
{
    int n = binarySearch(studentsName);
	if (n >= 0)
		return n;

	Student s;
	s.credits = 0;
	s.name = studentsName;
	n = addInOrder(s);

	return n;

}
//Add a number of credits taken by a student
int addCredits (std::string studentName, int credits)
{
    int n = addStudent(studentName);

	students[n].credits += credits;
	return students[n].credits;
}
