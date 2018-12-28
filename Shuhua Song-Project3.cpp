//12/04/2018 Shuhua Song

#include <iostream>
#include <iomanip>
using namespace std;

//*******************  Student Class **************************************//
class Student
{
public:
  //constructor
  Student():Student("",""){ }
  Student(string f, string l): firstName(f), lastName(l), size(0), capacity(5),grades(new int[5]){ }

  //accessors & mutatorscap
  void setFirstName(string f) { firstName = f; }
  string getFirstName() const { return firstName; }
  void setLastName(string l) { lastName = l;}
  string getLastName() const { return lastName;}
  void setFullName(string f,string l) { string fullName = f +" " +l;}
  string getFullName()const { return (firstName+lastName);}

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
  //Destrucor
  ~Student();
private:
  string firstName;
  string lastName;
  int size;
  int capacity{10};
  int* grades;
};

//*******************  Instructor Class **************************************//
class Instructor{
public:
  Instructor();
  Instructor(string n, string d);
  void setName(string n);
  string getName()const;
  void setDepartment(string d);
  string getDepartment()const;
private:
  string name;
  string department;
};

//******************* Course Class **************************************//
class Course
{
public:
  Course();
  Course(string n, string ins, string de);
  void setCSname(string n);
  string getCSName()const;
  void setInstructor(string n,string d);
  string getInstructor()const;
  void output();
  void grow();
  Course(const Course& c);
  ~Course();
  Course& operator =(const Course& c);
  void addStudent(const Student& s);
  void listStudents();
  void displayCourse();


private:
  string name;
  int capacity{5};
  int numStudent;
  Instructor instructor;
  Student *students;
};


//******************* Student implementation **********************************//
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
  cout << "==>Student Copy Constructor Called." << endl;
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
  //cout << "==>Student Assignment Operator Called." << endl;
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


//*******************  Instructor implementation **************************************//
Instructor::Instructor(): Instructor("unknown","unknown"){ }
Instructor::Instructor(string n, string d): name(n), department(d){ }
void Instructor::setName(string n){ name = n; }
string Instructor::getName() const { return name; }
void Instructor::setDepartment(string d){ department = d; }
string Instructor::getDepartment()const{ return department;}



//*******************  Course implementation **************************************//
Course::Course():Course("unknown","unknown","unknown"){ }
Course::Course(string n, string ins, string de): name(n), instructor(Instructor(ins, de)),numStudent(0),students(new Student[capacity]) { }
void Course::setCSname(string n){ name = n; }
string Course::getCSName()const{ return name; }
void Course::setInstructor(string n,string d){ instructor.getName() = n; }
string Course::getInstructor( )const{ return instructor.getName();}
void Course::output(){
  cout << "Course Name: " << name << "  ";
  cout << "Instructor Name: " << getInstructor( ) << endl;
  //cout << "Instrucotr Department: " << instructor.getDepartment() << endl;
}

void Course::grow(){
  cout << "Course Grow Function Called." << endl;
  Student *temp = new Student[capacity*2];
  for(int i=0; i<numStudent; i++){
    temp[i] = students[i];
  }
  capacity = capacity * 2;
  delete [] students;
  students = temp;
}

Course::Course(const Course& c){
  cout << "==>>(Course) Copy Constructor Called." << endl;
   name = c.name;
   instructor = c.instructor;
   numStudent = c.numStudent;
   students = new Student[capacity];
   for(int i=0; i<numStudent;i++){
     students[i] = c.students[i];
   }
}

Course::~Course(){
  //cout << "Course destructor Called." << endl;
  delete [] students;
}

Course& Course::operator =(const Course& c){
  cout << "==>>(Course) Assignment Overload Called." << endl;
  if(this != &c){
    name = c.name;
    instructor = c.instructor;
    if(numStudent != c.numStudent){
      numStudent = c.numStudent;
    }
    for(int i=0; i<numStudent; i++){
      students[i] = c.students[i];
    }
  }
  return *this;
}

void Course::addStudent(const Student& s){
  if(numStudent == capacity){
    grow();
  }
  students[numStudent] = s;
  numStudent++;
}
void Course::listStudents(){
  if(numStudent>=0){
    for(int i=0;i<numStudent;i++){
      students[i].display();
    }
  }
  else
  cout << "There is no student." << endl;
}
void Course::displayCourse(){
  //output();
  cout << "Course: " << name << "  " << "Instrucotr: " << getInstructor( ) <<  endl;
  cout << "==============================================================" << endl;
  listStudents();
}

int main(){
  Course c1{"ET580", "Trowbridge"," "};

  Student s1{"Jim", "Beam"};
  s1.addGrade(80);
  s1.addGrade(90);
  s1.addGrade(100);
  Student s2{"Jack", "Daniels"};
  s2.addGrade(50);
  s2.addGrade(60);
  s2.addGrade(70);

  c1.addStudent(s1);
  c1.addStudent(s2);
  cout << "C1: ";
  c1.displayCourse();

  Course c2(c1);
  cout << "C2: ";
  c2.displayCourse();
  Course c3;
  c3 = c2;
  cout << "C3: ";
  c3.displayCourse();

return 0;
}
