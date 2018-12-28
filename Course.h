
//Class Course interface

#ifndef COURSE_H
#define COURSE_H

#include "Instructor.h"
#include <iostream>
using namespace std;



class Course
{
public:
  //Course();
  Course(string n, string ins, string de);
  void setCSname(string n);
  string getCSName();
  void setInstructor(string n,string d);
  string getInstructor();
  void output();

private:
  string name;
  Instructor instructor;
};

#endif
