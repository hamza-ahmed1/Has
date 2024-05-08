#include <iostream>

#include "course.h"

#include "student.h"

#include "teacher.h"

int main() {

// Creating students, teachert ind court

Student s1("Alice"); Student s2("Bob");
 Teacher t1("Professor Smith"); Teacher t2("Professor Johnson); 
Course c1("Rathematics"); Course c2("Physics");

// Populating courses with students and teachers

cl.addStudent(&s1);
cl.addStudent (&s2);
c1.addTeacher(&t1); 
c2.addTeacher (&t2)

// Accessing data

std::cout << "Students enrolled in" << cl.getName()<<"\n"; 
for (const auto &student: cl.getStudents())
{ std::cout << student->getName() << std::endl;}

std::cout << "\nTeachers teaching" << cl.getName()<< ":\n";
for(const auto &teacher cl.getTeachers()) {

std::cout << teacher->getname() << std::endl;
}
std::cout << "\nstudents enrolled in << c2.getName() <<":\n";
for (const auto &student cl.getStudents())
 { std::cout << student->getName() << std::endl};

std::cout << "\nTeachers teaching "<< c2.getName()<<":\n";
 for (const auto teacher: c2.getTeachers())
 { std::cout ce teacher->getName() << std::endl};

return 0;
}