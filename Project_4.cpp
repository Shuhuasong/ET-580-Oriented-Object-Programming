//12/11/2018 Shuhua Song

#include <iostream>
#include <iomanip>
#include<string>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;

const string inFile = "/Users/shuhuasong/2018-Fall/ET-580/C++/Project/Project_4/database.txt";
const string outFile = "/Users/shuhuasong/2018-Fall/ET-580/C++/Project/Project_4/database.txt";
const string inCfile = "/Users/shuhuasong/2018-Fall/ET-580/C++/Project/Project_4/data.txt";
const string outCfile = "/Users/shuhuasong/2018-Fall/ET-580/C++/Project/Project_4/data.txt";
const string inAfile = "/Users/shuhuasong/2018-Fall/ET-580/C++/Project/Project_4/Alldata.txt";
const string outAfile = "/Users/shuhuasong/2018-Fall/ET-580/C++/Project/Project_4/Alldata.txt";


//*******************  Student Class **************************************//
class Student
{
public:
  //constructor
  Student():Student("",""){ }
  Student(string f, string l): firstName(f), lastName(l), numGrade(0), capacity(10),grades(new int[5]){ }

  //accessors & mutators
  void setFirstName(string f) { firstName = f; }
  string getFirstName() const { return firstName; }
  void setLastName(string l) { lastName = l;}
  string getLastName() const { return lastName;}
  void setFullName(string f,string l) { string fullName = f +" " +l;}
  string getFullName()const { return (firstName+lastName);}
  void setnumGrade(int s) { numGrade = s; }
  int getnumGrade() const { return numGrade; }

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

  // Overload
  //Assignment Overload
  Student& operator=(const Student& s);
  int operator[](int index);
  //Equation Overload
  bool operator ==(const Student& s);
  //Overload Extraction Operator
  friend istream& operator >>(istream& instream, Student& student);
  //overload insertion operator for console output
  friend ostream& operator <<(ostream& outstream, const Student& s);
  //overload insertion operator for file output
  friend ofstream& operator <<(ofstream& outstream, const Student& s);

  //Destructor
  ~Student();
private:
  string firstName;
  string lastName;
  int numGrade;
  //int numExam;
  int capacity;
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
  //void setInstructor(string n,string d);
  void setInstructor(string n);
  string getInstructor()const;
  int getCSgrade() const;
  void output();
  void grow();
  Course(const Course& c);
  ~Course();
  Course& operator =(const Course& c);
  Student& operator[](int index);
  void addStudent(const Student& s);
  //overload insertion operator in console
  friend istream& operator >>(istream& instream, Course& c);
  //overload insertion operator for console output
  friend ostream& operator <<(ostream& outstream, const Course& c);
  //overload insertion operator for file output
  friend ofstream& operator <<(ofstream& outstream, const Course& c);
  //void listStudents();
  //void displayCourse();


private:
  string name;
  int capacity{20};
  int numStudent;
  int numCSgrade;
  Instructor instructor;
  Student *students;
};


//******************* Student implementation **********************************//
//array manipulation function
void Student::addGrade(int gradeData){
  //cout << "Add grade 100, 73, 30 :" << endl;
  if(numGrade > capacity){
  cout << "The array is so full.";
}else{
  grades[numGrade] = gradeData;
  numGrade++;
}
}


/*void Student::addGrade(int gradeData){
  if(numGrade ==capacity){
    grow();
  }
  grades[numGrade] = gradeData;
  numGrade++;
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
  for(int i=index; i<numGrade; i++){
    grades[i] = grades[i+1];
  }
   numGrade--;
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
  //numGrade = numGrade -1;
  double sum = 0.0;
  double gpa = 0.0;
  if(numGrade==0){
    return gpa;
  }else{
  for(int i=0; i<numGrade; i++){
    sum = sum + grades[i];
  }
  gpa = sum/numGrade;
  return gpa;}
}


void Student::displayGrade( )const {
  for(int i=0;i<numGrade; i++){
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
  numGrade = s.numGrade;
  grades = new int[s.numGrade];
  for(int i=0;i<numGrade;i++){
    grades[i] = s.grades[i];
  }
}

//Destructor
Student::~Student(){
delete [] grades;
}

//Assignment overload
Student& Student::operator=(const Student& s){
  //cout << "==>Student Assignment Operator Called." << endl;
  if(this != &s){
    firstName = s.firstName;
     lastName = s.lastName;
     if(numGrade != s.numGrade){
       delete [] grades;
       numGrade = s.numGrade;
       grades = new int[s.numGrade];
     }
     for(int i=0; i<numGrade;i++){
       grades[i] = s.grades[i];
     }
  }
  return *this;
}
  int Student::operator[](int index){
      if(index<0 || index >capacity-1) {
          cout << "There is no grade" << endl;
          exit(1);
      }
      return grades[index];
  }

bool Student::operator ==(const Student& s){
  return ((firstName == s.firstName) && (lastName == s.lastName));
}


istream& operator >>(istream& instream, Student& stu){
  string first, last;
  int grade;
  cout << "Enter a first name: " ;
  cin >> first;
  cout << "Enter a last name: " ;
  cin >> last;
  //instream >>first >> last;
  cout << endl;
  do{
    cout << "Enter a grade or -1 when done: ";
    cin >> grade;
    //instream >> grade;
    stu.addGrade(grade);
  } while(grade != -1);

  stu.firstName = first;
  stu.lastName = last;

  return instream;
}

ostream& operator <<(ostream& outstream, const Student& s){ //insertion
  outstream << s.firstName<< " " << s.lastName  << " " << "GPA: " <<
  s.GPA() << " " << "Grades: " ;
  for(int i=0; i<s.numGrade-1; i++){
    outstream << s.grades[i] << " ";
  }
  cout << endl;
  return outstream;
}


ofstream& operator <<(ofstream& outstream, const Student& s){
   outstream << "Student" << "|" << s.firstName << "|" << s.lastName <<
      "|";
      for(int i=0; i<s.getnumGrade(); i++){
        outstream << s.grades[i] << "," ;
      }
      return outstream;
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
Course::Course(string n, string ins, string de): name(n), instructor(Instructor(ins, de)),numStudent(0),numCSgrade(0),students(new Student[capacity]) { }
void Course::setCSname(string n){ name = n; }
string Course::getCSName()const{ return name; }
int Course::getCSgrade() const { return numCSgrade; }
//void Course::setInstructor(string n,string d){ instructor.getName() = n; instructor.getDepartment() = d;}
void Course::setInstructor(string n){ instructor.setName(n);}
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

Student& Course::operator[](int index){
    if(index<0 || index >capacity-1) {
        cout << "There is no student." << endl;
        exit(1);
    }
    return students[index];
}

void Course::addStudent(const Student& s){
  if(numStudent == capacity){
    grow();
  }
  students[numStudent] = s;
  numStudent++; //the number of Student in this Course
  //s.getnumGrade() = s.getnumGrade() + 1; //the number of the grade for this student
  numCSgrade++;// the number of grade in this Course object
  //s.numExam++;
}


 istream& operator >>(istream& instream, Course& c){
   string name, teacher;
   int numgrade, maximum;
   cout << "Enter the Course title: " ;
   cin >> name ;
   cout << "Enter the name of the instructor: " ;
   cin >> teacher;
   cout << "Enter the number of examinations: " ;  //why I can't use the variable member???
   cin >> numgrade;
   cout << "Enter the maximum number of students: ";
   cin >> maximum;
   c.name = name;
   c.setInstructor(teacher);
   c.numCSgrade = numgrade;
   c.capacity = maximum;
   return instream;

 }



//Overload insertion(output) into the console
 ostream& operator <<(ostream& outstream, const Course& c){
   cout << endl;
   cout << c.name << "  " << "Instructor: " << c.getInstructor() << "  "
   << "Enrolled: " << c.numCSgrade <<  "  "<<  "MaxSeats: " << c.capacity;
   return outstream;
 }

 /*ofstream& operator <<(ofstream& outstream, const Student& s){
    outstream << "Student" << "|" << s.firstName << "|" << s.lastName <<
       "|";
       for(int i=0; i<s.getnumGrade(); i++){
         outstream << s.grades[i] << "," ;
       }
       return outstream;
 } */

 /*Course|ET575|Trowbridge|4|4|20
 Student|Anthony|Hopkins|74,94,76,40,56,
 Student|John|Cusack|34,54,76,40,86,
 Student|Joan|Rivers|77,66,56,97,56,
 Student|Jared|Leto|76,45,77,88,95, */
 /* string name;
   int capacity{20};
   int numStudent;
   int numCSgrade;
   Instructor instructor;
   Student *students;  */

//bool append(Course *c, const int& CAPACITY, int& numStudent, string name, )

/*void load(Course *c, const int& CAPACITY, int& numStudent){
  bool fileToLarge = false;
  ifstream fin(inCfile);
  string line, textField, token;

  int position = 0;

  while(getline(fin, line)){
    istringstream ss(line);
    getline(ss, textField, '|');
    if( textField == "Course"){
      getline(ss,textField, '|');
      string courseName = textField;
      getline(ss,textField, '|');
      string teacher = textField;
      getline(ss,textField, '|');
      int numCSgrade = textField;
      getline(ss,textField, '|');
      int numStudent = textField;
      getline(ss,textField, '|');
      int capacity = textField;

      }

    }

    getline(ss,textField, '|');
    string lastName = textField;
    getline(ss,textField,',');
    int grade =
  }

} */


//Overload insertion(output Course Object) into the File
 ofstream& operator <<(ofstream& outstream, const Course& c){
    cout << endl;
    outstream << "Course" << "|" << c.getCSName() << "|" << c.getInstructor() <<
       "|" << c.getCSgrade() << "|" << c.numStudent << "|" << c.capacity << endl;


       for(int i=0; i<c.numStudent; i++){
       //write all student  object in this Course into file
      // ofstream foutA(inAfile);
      outstream << c.students[i] << endl;

       //foutA.close();

      /* ifstream finA(outAfile);
       string Aline;
       while(getline(finA, Aline)){
         cout << Aline << endl;
       }
       finA.close();*/
     }
       return outstream;
 }

/*void Course::listStudents(){
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
}*/

//load file data into local memory(the array)
//void load(Course *c, const int& CAPACITY, int& numStudent){

//}

//dump local memory (the array)into the file before ending program.
void save(Course *c, const int& numStudent){
  ofstream fout(outFile);
  for(int i=0; i<numStudent; i++){
    fout << c[i] ;
  }
  fout.close();
}

int main(){
  Course c1{"ET580", "Trowbridge"," "};
  Course c4;

  Student s1{"Jim", "Beam"}, s3;
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
  //c1.displayCourse();

  Course c2(c1);
  cout << "C2: ";
//  c2.displayCourse();
  Course c3;
  c3 = c2;
  cout << "C3: ";
  //c3.displayCourse();

  cout << "s1[2]: " << s1[2] << endl;

  cout << "S1 output: " << s1;

  cin >> s3;
  cout << s3;

//write Student object to file
  ofstream fout(inFile);
  fout << s1;
  fout.close();

  ifstream fin(outFile);
  string line;
  while(getline(fin, line)){
    cout << line << endl;
  }
  fin.close();

cout << "Output the 1st Student's 2nd Grades  c1[0][1] : " ;
 cout << c1[0][1] << endl;



 Course c5{"ET575", "Trowbridge"," "};

 Student s5{"Anthony", "Hopkins"};
 s5.addGrade(74);
 s5.addGrade(94);
 s5.addGrade(76);
 s5.addGrade(40);
 s5.addGrade(56);

 Student s6{"John", "Cusack"};
 s6.addGrade(34);
 s6.addGrade(54);
 s6.addGrade(76);
 s6.addGrade(40);
 s6.addGrade(86);

 Student s7{"Joan", "Rivers"};
 s7.addGrade(77);
 s7.addGrade(66);
 s7.addGrade(56);
 s7.addGrade(97);
 s7.addGrade(56);

 Student s8{"Jared", "Leto"};
 s8.addGrade(76);
 s8.addGrade(45);
 s8.addGrade(77);
 s8.addGrade(88);
 s8.addGrade(95);

 c5.addStudent(s5);
 c5.addStudent(s6);
 c5.addStudent(s7);
 c5.addStudent(s8);

 cin >> c4;
 cout << c4;

 //write Course object to file
 ofstream foutC(inCfile);
 foutC << c5;
 foutC.close();

 ifstream finC(outCfile);
 string Cline;
 while(getline(finC, Cline)){
   cout << Cline << endl;
 }
 finC.close();


 const int CAPACITY = 100;
 Course *c = new Course[CAPACITY];
 save(c, 4);

return 0;
}
