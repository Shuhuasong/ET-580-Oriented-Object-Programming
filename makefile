# variables
CXXFLAGS := -std=c++11

# executable file to create and its dependancies
prog.exe : driver.o Student.o Instructor.o Course.o
	g++ -std=c++11 -o prog driver.o Student.o Instructor.o Course.o

# file dependencies
driver.o : Student.h Course.h
	g++ -std=c++11 -c driver.cpp
Student.o : Student.h
Course.o : Instructor.h Course.h
	g++ -std=c++11 -c Course.cpp
Instructor.o : Instructor.h
	g++ -std=c++11 -c Instructor.cpp

# files to remove
clean:
	del driver.o Student.o Instructor.o Course.o
	del prog.exe
