#include <iostream>
#include <string>
using namespace std;

class Human {
protected:
  string name;
  long phoneNumber;

public:
  // Setters
  void setName(string name) { this->name = name; }
  void setPhone(long phoneNumber) { this->phoneNumber = phoneNumber; }

  // Getters
  string getName() { return name; }
  long getPhone() { return phoneNumber; }
};

class Student : public Human {
private:
  int level;
  float gpa;
  struct {
    string subName, subId;
    int hours;
    float points, finalPoints;
  } subject;

public:
  // Setters
  void setLevel(int level) { this->level = level; }
  void setGpa(float gpa) { this->gpa = gpa; }
  void setSub(string subName, string subId, int hours, float points) {
    subject.subName = subName;
    subject.subId = subId;
    subject.hours = hours;
    subject.points = points;
    subject.finalPoints = hours * points;
  }

  // Getters
  int getLevel() { return level; }
  float getGpa() { return gpa; }
  void getSub() {
    cout << endl;
    cout << "Subject name: " << subject.subName << endl;
    cout << "Subject id: " << subject.subId << endl;
    cout << "Subject credit hours: " << subject.hours << endl;
    cout << "Subject total points: " << subject.finalPoints << endl;
    cout << endl;
  }
};

class Teacher : public Human {
private:
  float salary, hours;
  string department;

public:
  // Getters
  void setSalary(float salary) { this->salary = salary; }
  void setHours(float hours) { this->hours = hours; }
  void setDepartment(string department) { this->department = department; }

  // Setters
  float getSalary() { return salary; }
  float getHours() { return hours; }
  string getDepartment() { return department; }
};
