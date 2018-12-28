
//Instructor class interface

#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <iostream>
using namespace std;

class Instructor{
public:
  Instructor();
  Instructor(string n, string d);
  void setName(string n);
  string getName();
  void setDepartment(string d);
  string getDepartment();
private:
  string name;
  string department;
};


#endif
