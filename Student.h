//11/24/2018  Shuhua Song
//separately compiled structure

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
using namespace std;

class Student
{
public:
  //constructor
  Student():Student("",""){ }
  Student(string f, string l): firstName(f), lastName(l), size(0), capacity(5),grades(new int[5]){ }

  //accessors & mutatorscap
  void setFirstName(string f) { firstName = f; }
  string getFirstName(){ return firstName; }
  void setLastName(string l) { lastName = l;}
  string getLastName(){ return lastName;}
  void setFullName(string f,string l) { string fullName = f +" " +l;}
  string getFullName() { return (firstName+lastName);}

  //array manipulation function
  void addGrade(int gradeData);
  void removeGrade(int index);
  void updateGrade(int index,int num);
  void displayByIndex(int index)const ;

  void displayGrade()const ;
  void display()const ;
  double GPA( ) const;
  void grow();

  //Copy constructor
  Student(const Student& s);

  //Assignment overload
  Student& operator=(const Student& s);
  //Deconstrucor
  ~Student();
private:
  string firstName;
  string lastName;
  int size;
  int capacity{10};
  int* grades;
};

#endif
