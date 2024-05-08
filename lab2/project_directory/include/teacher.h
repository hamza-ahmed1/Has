#ifndef TEACHER_H

#define TEACHER_H

#include <string>

#include <vector>

#include "course.h"

class Course; 
//Forward declaration

class Teacher {

private:

std::string name;

std::vector<Course*> teachingCourses;

public:

Teacher (const std::string& name);
void teachCourse(Course course);
const std::string& getName() const;
const std::vector<Course*>& getTeachingCourses() const;
};



#endif
