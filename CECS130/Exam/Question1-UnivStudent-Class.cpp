#include <iostream>
#include <cstdlib>
#include <ctype.h>

using namespace std;

class Major
{
private:
  string Name;
public:
  Major(string N)
  {
    Name = N;
  }
  void Print()
  {
    cout<<Name<<endl;
  }
};

class Student
{
private:
  string Name;
  int ID;
public:
  Student(string N, int I)
  {
    Name = N;
    ID = I;
  }
  void Print()
  {
    cout<<Name<<endl;
    cout<<ID<<endl;
  }
};

class UnivStudent: public Major, public Student
{
private:
  string majorName;
  string studentName;
  int studentID;
public:
  int numberOfCourses;
  UnivStudent(string major, string name, int ID, int courses): Major(major), Student(name, ID)
  {
    majorName = major;
    studentName = name;
    studentID = ID;
    numberOfCourses = courses;
  }
  Major MyMajor(string majorName);
  Student Student1(string studentName, int studentID);
  void printDetails()
  {
    cout<<"Name: "<<studentName<<endl;
    cout<<"ID: "<<studentID<<endl;
    cout<<"Major: "<<majorName<<endl;
    cout<<"Num of Courses: "<<numberOfCourses<<endl;
  }
};


int main()
{
  UnivStudent JoeDowns("CSE", "Joe Downs", 123456, 7);
  JoeDowns.printDetails();
}
