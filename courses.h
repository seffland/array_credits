#ifndef COURSES_H
#define COURSES_H

#include <iostream>
#include <string>


struct Course {
  std::string name; // course name
  int credits;      // number of credits this course is worth
};

extern int numCourses;
extern Course* courses; // array of courses


// Initialize all course data, allowing for at least the indicated
//   number of courses
void initializeCourses(int maxCourses);

// Clean up course data
void cleanUpCourses();


// Read course info from an input stream
void readCourses (std::istream& in);

// Add a course with the indicated number of credits
void addCourse (std::string courseName, int credits);

// Get the number of credits for a course
int getCredits (std::string courseName);

#endif
