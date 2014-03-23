#include "arrayUtils.h"
#include "courses.h"

using namespace std;


int numCourses;
Course* courses; // array of courses


// Initialize all course data, allowing for at least the indicated
//   number of courses
void initializeCourses(int maxCourses)
{
  numCourses = 0;
  courses = new Course[maxCourses];
}


// Clean up course data
void cleanUpCourses()
{
  delete [] courses;
}


// Read course info from an input stream
void readCourses (std::istream& in)
{
  int maxCourses;
  in >> maxCourses;
  initializeCourses (maxCourses);
  string name;
  while (in >> name)
    {
      int credit;
      in >> credit;
      //cerr << name << " " << credit << endl;
      addCourse (name, credit);
    }
}


// Search an array for a given value, returning the index where 
//    found or -1 if not found.
int seqSearch(const Course list[], int listLength, std::string searchItem)
{
    int loc;

    for (loc = 0; loc < listLength; loc++)
        if (list[loc].name == searchItem)
            return loc;

    return -1;
}




// Add a course with the indicated number of credits
void addCourse (std::string courseName, int credits)
{
  courses[numCourses].name = courseName;
  courses[numCourses].credits = credits;
  ++numCourses;
}

// Get the number of credits for a course
int getCredits (std::string courseName)
{

  int pos = seqSearch (courses, numCourses, courseName);
  if (pos >= 0)
    return courses[pos].credits;
  else
    return 0;
}


