//  11/15/2018 Shuhua Song

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



int main()
{
  // set decimal precision to two places
  cout.setf(ios::fixed);
  cout.precision(2);

  Student *s1 = new Student{"Johnny","Dep"};
  Student *s2 = new Student{"Jack","Sparrow"};
  cout << "s1: ";
  s1->display( );

  cout << "Add Grade 100, 73, 30 :" << endl;
  cout << "s1: ";
  s1->addGrade(100);
  s1->addGrade(73);
  s1->addGrade(30);
  //s1->addGrade(77);//
  //s1->addGrade(88);//
  //s1->addGrade(99);//
  s1->display( );

  s1->removeGrade(1);
  s1->addGrade(55);
  s1->addGrade(89);
  s1->display( );

  s2->addGrade(78);
  s2->addGrade(56);

  cout << "s2: ";
  s2->display();

  Student *s3 = new Student{*s2};
  s3->display();

  *s2 = *s1;
  s2->display();



  return 0;
}
