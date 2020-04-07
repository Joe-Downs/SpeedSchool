#include <iostream>
#include <cstdlib>
#include <ctype.h>

using namespace std;

class Single
{
protected:
  string name;
  int age;
public:
  Single()
  {
    name = "";
    age = 1;
  }
  Single(string s, int  a)
  {
    name = s;
    age = a;
  }
  void print()
  {
    cout<<"Name: "<<name<<endl<<"Age = "<<age<<endl;
  }
};

class Married: public Single
{
private:
  string soulmateName;
  int familyIncome = 0;
protected:
  string childrenNames[15];
  int childrenNumber;
public:
  Married();
  Married(string personName, string soulmateName, int age, int income, int children);
  void newChildBorn(string newChildName);
  void printInfo();
  double incomePerMember();
};

Married::Married()
{
  name = "";
  age = 0;
}

Married::Married(string personName, string soulmateName, int age, int income, int children): Single(personName, age)
{
  soulmateName = soulmateName;
  familyIncome = income;
  childrenNumber = children;
}

void Married::newChildBorn(string newChildName)
{
  childrenNames[childrenNumber] = newChildName;
  childrenNumber += 1;
}

void Married::printInfo()
{
  int n;
  cout<<"Name: "<<name<<endl;
  cout<<"Age: "<<age<<endl;
  cout<<"Soulmate Name: "<<soulmateName<<endl;
  cout<<"Family Income: "<<familyIncome<<endl;
  cout<<"Children Number: "<<childrenNumber<<endl;
  cout<<"Children Names: ";
  for (n = 0; n < childrenNumber; n++)
    {
      cout<<childrenNames[n]<<" ";
    }
  cout<<endl;
}

double Married::incomePerMember()
{
  return familyIncome / (2 + childrenNumber);
}


int main()
{
  Married M1;
  M1.newChildBorn("CC");
  M1.newChildBorn("DD");

  Married M2("AA", "BB", 30, 999, 0);
  M2.print();
  M1.printInfo();
}
