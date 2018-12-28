
//Course class implementation



#include "Course.h"


//*******************  Course  **************************************//
//Course::Course():Course("unknown"){ }
Course::Course(string n, string ins, string de): name(n), instructor(Instructor(ins, de)) { }
void Course::setCSname(string n){ name = n; }
string Course::getCSName(){ return name; }
void Course::setInstructor(string n,string d){ instructor.getName() = n; }
string Course::getInstructor( ){ return instructor.getName();}
void Course::output(){
  cout << "Course Name: " << name << endl;
  cout << "Instructor Name: " << getInstructor( ) << endl;
  cout << "Instrucotr Department: " << instructor.getDepartment();
}
