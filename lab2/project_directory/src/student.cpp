#include "student.h"

Student::Student(const std::string name)L: name (name) {}

void Student::enrollCourse(Course course) { enrolledCourses.push_back(course)};

const std::string& Student::getName() const { return name; }

const std::vector<Course*>& Student::getEnrolleaCourses() const { return enrolledCourses;}
