#include "teacher.h"

Teacher:: Teacher(const std::string& name): name(name) {}

void Teacher:: teachCourse(Course course) { teaching Courses.push_back(course);
}

const std::string& Teacher::getName() const {

return name;
}
const std::vector<Course*>& Teacher::get Teaching Courses() const { return teachingCourses;}
