#ifndef STUDENT_H 
#define STUDENT_H

#include <string> 
#include <vector>

#include "course.h"

class Course; // Forward declaration

class Student {

private:

std::string name;

std::vector<Course*> enrolledCourses;

public:

Student(const std::string& name); 
const std::string& getName() const;
const std::vector<Course*>& getEnrolledCourses() const;
void enrollCourse(Course course);

#endif // STUDENT H
