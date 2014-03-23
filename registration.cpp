#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>


#include "courses.h"
#include "students.h"


using namespace std;



/*
 * Read the enrollment requests, processing each one and tracking
 * the number of students successfully enrolled into each course.
 */
void processEnrollments (istream& enrollmentRequestsFile)
{
  int maxStudents;
  enrollmentRequestsFile >> maxStudents;
  initializeStudents (maxStudents);

  string courseName;
  enrollmentRequestsFile >> courseName;
  while (enrollmentRequestsFile) {
    enrollmentRequestsFile >> ws;
    string studentName;
    getline (enrollmentRequestsFile, studentName);

    cerr << studentName << " " << courseName << endl;

    int credits = getCredits (courseName);
    addCredits (studentName, credits);

    enrollmentRequestsFile >> courseName;
  }
}


// Print an alphabetical list of students, with the
// total number of credits taken by each.
void printReport (ostream& out)
{
  string padding (30, ' ');
  string header = "Student" + padding;
  header = header.substr(0,30) + " Credits";
  cout << header << endl;
  int totalCredits = 0;
  for (int i = 0; i < numStudents; ++i)
    {
      string line = students[i].name + padding;
      cout << line.substr(0,30) << " " << students[i].credits << endl;
      totalCredits += students[i].credits;
      out << '"' << students[i].name << '"' << ","
	  << students[i].credits << endl;
    }
  cout << numStudents << " students registered for a total of "
       << totalCredits << " credits." << endl;
}


int main (int argc, char** argv)
{
  if (argc != 4)
    {
      cerr << "Usage: " << argv[0] << " courseFile enrollmentFile reportFile" << endl;
      return -1;
    }

  // Take input and output file names from the command line
  ifstream coursesIn (argv[1]);
  readCourses (coursesIn);
  coursesIn.close();


  ifstream enrollmentIn (argv[2]);
  processEnrollments (enrollmentIn);
  enrollmentIn.close();


  ofstream reportOut (argv[3]);
  printReport (reportOut);
  reportOut.close();

  cleanUpCourses();
  cleanUpStudents();


  return 0;
}



