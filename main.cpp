#include "human.h"
#include "buildings.h"
#include <iostream>
#include <string>
using namespace std;

void startingUI() {
  cout << endl;
  cout << "==================================" << endl;
  cout << "Welcome to O6U console application" << endl;
  cout << "==================================" << endl;
  cout << endl;
  cout << ">> This is a console program to maintain data for o6u students, "
          "teachers, staff, etc"
       << endl;
}

int main() {
  startingUI();

  int teachers, students;
  long num;
  string name;

  // Student variables
  int level, subHours, subNum;
  string subName, subId;
  float gpa, points;

  // Teacher variables
  float salary, hours;
  string department;

  cout << "Enter number of students, teachers(students teachers): ";
  cin >> students >> teachers;
  Student s[students];
  Teacher t[teachers];
  for (int i = 0; i < students; i++) {
    cout << "\t\t\tSTUDENT No." << i + 1 << ":" << endl;
    cout << "Enter student's name: ";
    cin >> name;
    cout << "Enter student's number: ";
    cin >> num;
    cout << "Enter student level: ";
    cin >> level;
    cout << "Enter student's gpa: ";
    cin >> gpa;
    cout << "Enter subject's num: ";
    cin >> subNum;
    for (int i = 0; i < subNum; i++) {
      cout << "Enter subject name: ";
      cin >> subName;
      cout << "Enter subject's id: ";
      cin >> subId;
      cout << "Enter subject's hours: ";
      cin >> subHours;
      cout << "Enter subject's grade points: ";
      cin >> points;
    }

    s[i].setName(name);
    s[i].setPhone(num);
    s[i].setLevel(level);
    s[i].setGpa(gpa);
    s[i].setSub(subName, subId, subHours, points);
    s[i].getSub();
  }

  for (int i = 0; i < teachers; i++) {
    cout << "\t\t\tTEACHER NO. " << i + 1 << ":" << endl;
    cout << "Enter teacher's name: ";
    cin >> name;
    cout << "Enter teacher's phone: ";
    cin >> num;
    cout << "Enter teacher's salary: ";
    cin >> salary;
    cout << "Enter teacher's department: ";
    cin >> department;
    cout << "Enter teacher's working hours: ";
    cin >> hours;

    t[i].setName(name);
    t[i].setPhone(num);
    t[i].setSalary(salary);
    t[i].setDepartment(department);
    t[i].setHours(hours);
  }
  return 0;
}
