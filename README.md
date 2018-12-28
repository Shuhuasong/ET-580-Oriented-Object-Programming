# ET-580-Oriented-Object-Programming
Projects(including: Constructor, Operator Overload, Seperate Compilation, Pointer, Inheritance, Polymorphism, Template Programming, Link Data Structure)
Project 1: 
Student Class
1) All Student objects must be created on the heap.
2) Data members should only be allocated on the heap if necessary.
Data members:
a) first name
b) last name
c) grades (dynamic partially filled array with an initial capacity of 10)
Member functions
1. Constructors:
a) default constructor
b) user defined constructor that initializes an array of size 10 c) implement constructor delegation
2. Implement these accessors/mutators: a) set/get first name
b) set/get last name
c) set/get name (entire name)
3. Implement these array manipulation functions: a) add grade
b) remove grade by index
c) update grade by index
d) display grades by index
4. Implement a function that calculates and returns the student GPA.
5. Implement two separate display functions:
displayGrades()
a) displays student grades with a fixed precision of two decimal places b) displays the GPA with a fixed precision of two decimal places
display()
a) displays the student name
b) calls the displayGrades function
Implement a driver program to test all class members including (see output):
a) test all array manipulation functions
b) test display functions
c) demonstrate the copy constructor and assignment overload by temporarily
adding cout echos to these functions (see output)

Project 3:
Student Class
a. Copy Constructor: b. Assignment Overload:
Instructor Class
No changes
Course Class
Comment out the console echo statements. Comment out the console echo statements.
   Additional data member:
a. students (partially filled dynamic array of student objects)
Description:
a. The default capacity of students should be set to 5.
b. Implement a grow function to double students capacity.
c. Implement “the big three” (add console echo statements)
d. Create an addStudent function to add student objects to the array.
e. Create a listStudents function to display students contents.
Note that this should use the Student class display function.
f. Create a display function to display:
1) course name
2) course instructor
3) students contents (call the listStudent function)
g. Verify that course constructors create a new Instructor object with instructor name and department information included.
Driver Class
a. Create a new course c1.
b. Add two students to the course.
c. Display course c1.
d. Use the copy constructor to create a new course c2, from c1.
e. Display course c2.
f. Use the assignment operator to populate a new course c3, from c2. g. Display course c3.
See output on next page.
Jim Beam
1: 80
2: 90
3: 100
GPA: 90.00
Jack Daniels
1: 50
2: 60
3: 70
GPA: 60.00
==> (course) copy constructor called
Course: ET575 Instructor: Trowbridge ======================================================== Jim Beam
1: 80
2: 90
3: 100
GPA: 90.00
Jack Daniels
1: 50
2: 60
3: 70
GPA: 60.00
==> (course) assignment overload called
Course: ET575 Instructor: Trowbridge ======================================================== Jim Beam
1: 80
2: 90
3: 100
GPA: 90.00
Jack Daniels
1: 50
2: 60
3: 70
GPA: 60.00


Project 4:
Student Class
Additional Functions:
a. Comment out the display and displayGrades functions. These functions will
be removed in the next version. Use them for debugging this version.
b. Add an accessor and mutator for the variable that tracks the current
number of values in the grades array (hereby referred to as numExams).
c. Overload the [] operator to access a Student object’s grades array.
Thus if ‘s’ is a Student object, s[2] will return the 3rd test grade.
d. Overload the == operator to compare if two Student objects are equivalent
(identical last and first names)
e. Overload the >> operator to input a Student object from the console.
The following should be requested:
Enter a first name: John
Enter a last name: Smith
Enter a grade or -1 when
Enter a grade or -1 when
Enter a grade or -1 when
Grades must be between 0
Enter a grade or -1 when
Enter a grade or -1 when
Student created.
done: 50
done: 20
done: 154
and 100.
done: 10
done: -1
Note that this function updates an existing object. It is similar to the copy constructor. All fields must be updated and dynamic memory handled.
f. Overload the << operator to output a Student object to console as follows: firstname lastname GPA: gpaValue Grades: Grade1 Grade2 Grade3...
Console output example:
Anthony Hopkins GPA: 60.00 Grades: 74 94 76 40 56
g. Overload the << operator to output a Student object to file as follows: Student|firstname|lastname|Grade1,Grade2,Grade3
Note the use of two different delimiters, the ‘|’ character separates the data fields, the ‘,’ character separates individual array entries. The first field with the word Student indicates this is a Student object, while the other fields should display corresponding data for the object. Note that the number of grades will vary.
   File output example:
Student|Anthony|Hopkins|74,94,76,40,56
Course Class
Additional Data Members:
a. A variable to track the number of grades for this Course object.
Additional Functions:
a. Comment out the display and listStudent functions.
b. Update the user defined Course constructor to accept a value for the
number of grades and total number of seats in the class.
c. Update the addStudents function so that it updates the Student data
member numExams to match the new Course variable for number of exams.
c. Overload the [] operator to access Student objects in the array by index.
This will be used in combination with the overloaded [] for student. If ‘c’ is a Course object, c[1][2] will return the 3rd test grade of the 2nd student registered for the course.
d. Overload the >> operator to input a Course object from the console. The following should be requested:
Enter the course title: ET240
Enter the name of the instructor: Larry Sanders Enter the number of examinations: 4
Enter the maximum number of students: 23
Note that this function updates an existing object.
e. Overload the << operator to output a Course object to console as follows:
Course_name Inst: Instructor_Name Enrolled: #students MaxSeats: capacity Console output example:
2
   ET580 Inst: Steve Trowbridge Enrolled: 4 MaxSeats: f. Overload the << operator to output a Course object to
   1. Course data:
Course|name|instructor|# exams|#enrolled|#maxSeats
      File output example:
Course|ET575|Steve Trowbridge|5|4|20
2. All students in this Course (students array of the
should also be output to file using the Student <<
20
file as follows:
Course object) operator overload.
File output example for a Course object with four enrolled students: Course|ET575|Steve Trowbridge|5|4|20 Student|Anthony|Hopkins|74,94,76,40,56 Student|John|Cusack|34,54,68,54,24 Student|Joan|Rivers|77,66,56,97,56 Student|Jared|Leto|76,45,77,88,95
Driver Program
Data:
a. A global constant named database which names an external I/O text file.
Download attached file for your database.
b. A partially filled dynamic array named Courses which stores Course
objects. Set this array to a maximum size of 100.
Functions:
a. A save function which dumps all course data to the database file.
This function is simple, don’t make it more complex than it is. The function should loop through each Course object in the Courses array using the overloaded << operator to output object data to the database file.
b. A load function will loads the database file into the Courses array.
This function is complex, since we do not have overloaded >> operators for file input in the Student and Course class. You should reference the person database program from Operating_Overloading_Homework.zip for ideas on how to use stringstream, getline and delimiters.
This function will read in a database file like this:
Course|ET575|Joann Sun|4|3|20 Student|Anthony|Hopkins|74,94,76,40, Student|John|Cusack|34,54,68,54, Student|Joan|Rivers|77,66,56,97, Course|ET580|Steve Trowbridge|3|2|12 Student|Anthony|Hopkins|43,87,89 Student|John|Cusack|37,88,68
An algorithm for this function is:
1. Connect to the database file.
2. Create local variables that will be read into from
3. Create a loop that reads every line until the file
the file.
is empty. a. Create a stringstream object for parsing the line by ‘|’.
Use stringstream for converting ints to strings (as needed) in b-d.
b. Read in the first data field and determine if the line is
for a Course or a Student.
c. If it is a Course, read the remaining data one field at a time into
local variables. Create a Course object using these variables
and add it to the Courses array. Update array vars.
d. If it is for a Student, read the remaining data one field at a time
into local variables. Create a Student object. Generate a second stringstream object for parsing by ‘,’. Use this and the Student addGrade function to read grades into the Student grades array.
4. Close the file connection.
c. The save/load functions and file/array variables will remain in the final program. Test any/all new features added in this version.
