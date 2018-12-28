//11/24/2018  Shuhua Song
//separately compiled structure

#include "Student.h"
#include "Course.h"

int main()
{
  // set decimal precision to two places
  cout.setf(ios::fixed);
  cout.precision(2);

  Student *s1 = new Student{"Johnny","Dep"};
  Student *s2 = new Student{"Jack","Sparrow"};
  cout << "s1: ";
  cout << "Student Information: " << endl;
  s1->display( );

  cout << "Add Grade 90, 73, 96 :" << endl;
  cout << "s1: ";
  s1->addGrade(90);
  s1->addGrade(73);
  s1->addGrade(96);
  //s1->addGrade(77);//
  //s1->addGrade(88);//
  //s1->addGrade(99);//
  s1->display( );

  /* s1->removeGrade(1);
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
  s2->display(); */

cout << "Course and Instructor Information: " << endl;
  Course course{"Joe","John","Computer Department"};
  course.setInstructor("Mark","Math Department");
  course.output();


  return 0;
}
