//11/24/2018  Shuhua Song
//separately compiled structure


#include "Student.h"

//array manipulation function
void Student::addGrade(int gradeData){
  //cout << "Add grade 100, 73, 30 :" << endl;
  if(size > capacity){
  cout << "The array is so full.";
}else{
  grades[size] = gradeData;
  size++;
}
}


/*void Student::addGrade(int gradeData){
  if(size ==capacity){
    grow();
  }
  grades[size] = gradeData;
  size++;
}

void Student::grow(){
  cout << "Grow funciton called." << endl;
  int *temp = new int[(capacity*2)+1];
  for(int i=0; i<capacity;i++){
    temp[i] = grades[i];
  }
  capacity = capacity*2+1;
  delete [] grades;
  grades = temp;
} */


void Student::removeGrade(int index){
  cout << "Remove grade 73, add grade 55,89: " << endl;
  for(int i=index; i<size; i++){
    grades[i] = grades[i+1];
  }
   size--;
}

void Student::updateGrade(int index,int num)
{
   grades[index] = num;
}

void Student::displayByIndex(int index) const {
    cout << grades[index];
}

//Calculate and return the student GPA
double Student::GPA( ) const {
  //size = size -1;
  double sum = 0;
  double gpa = 0.0;
  if(size==0){
    return gpa;
  }else{
  for(int i=0; i<size; i++){
    sum = sum + grades[i];
  }
  gpa = sum/size;
  return gpa;}
}


void Student::displayGrade( )const {
  for(int i=0;i<size; i++){
    cout << (i+1) << ": " ;
    cout << fixed << setprecision(2) << grades[i] << endl;
  }
   cout << "GPA: " << GPA( ) << endl;
}

void Student::display( ) const {
  cout << firstName << " " << lastName;
  //cout << getFullName();
  cout << endl;
  displayGrade( );
  cout << endl;
}
//Copy constructor
Student::Student(const Student& s){
  cout << "==>Copy Constructor Called." << endl;
  firstName = s.firstName;
  lastName = s.lastName;
  size = s.size;
  grades = new int[s.size];
  for(int i=0;i<size;i++){
    grades[i] = s.grades[i];
  }
}

//Deconstrucor
Student::~Student(){
delete [] grades;
}

//Assignment overload
Student& Student::operator=(const Student& s){
  cout << "==>Assignment Operator Called." << endl;
  if(this != &s){
    firstName = s.firstName;
     lastName = s.lastName;
     if(size != s.size){
       delete [] grades;
       size = s.size;
       grades = new int[s.size];
     }
     for(int i=0; i<size;i++){
       grades[i] = s.grades[i];
     }
  }
  return *this;
}
