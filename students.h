#ifndef STUDENTS_H
#define STUDENTS_H

#include <string>

struct Student {
  std::string name;  // name of this student
  int credits;       // total number of credits for this student
};

extern int numStudents;

extern Student* students; // array of students


// Initialize all student data, allowing for at least the indicated
//   number of students
void initializeStudents(int maxStudents);

// Clean up student data
void cleanUpStudents();


// Add a student, starting with 0 credits. Return position where
//   inserted.
int addStudent (std::string studentsName);

// Add a number of credits taken by a student
int addCredits (std::string studentName, int credits);


#endif
