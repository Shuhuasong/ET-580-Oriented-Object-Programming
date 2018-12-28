
//Instructor class implementation

#include "Instructor.h"


//*******************  Instructor  **************************************//
Instructor::Instructor(): Instructor("unknown","unknown"){ }
Instructor::Instructor(string n, string d): name(n), department(d){ }
void Instructor::setName(string n){ name = n; }
string Instructor::getName() { return name; }
void Instructor::setDepartment(string d){ department = d; }
string Instructor::getDepartment(){ return department;}
