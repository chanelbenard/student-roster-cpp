
#include "student.h"
#include <iostream>
using std::cout;
using std::endl;

// constructor
Student::Student(string studentID, string firstName, string lastName,
    string emailAddress, int age,
    int daysInCourse1, int daysInCourse2, int daysInCourse3,
    DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysInCourse[0] = daysInCourse1;
    this->daysInCourse[1] = daysInCourse2;
    this->daysInCourse[2] = daysInCourse3;
    this->degreeProgram = degreeProgram;
}

// getters
string Student::getStudentID() const { return studentID; }
string Student::getFirstName() const { return firstName; }
string Student::getLastName() const { return lastName; }
string Student::getEmailAddress() const { return emailAddress; }
int Student::getAge() const { return age; }
const int* Student::getDaysInCourse() const { return daysInCourse; }
DegreeProgram Student::getDegreeProgram() const { return degreeProgram; }

// setters
void Student::setStudentID(string id) { studentID = id; }
void Student::setFirstName(string first) { firstName = first; }
void Student::setLastName(string last) { lastName = last; }
void Student::setEmailAddress(string email) { emailAddress = email; }
void Student::setAge(int a) { age = a; }
void Student::setDaysInCourse(int d1, int d2, int d3) {
    daysInCourse[0] = d1;
    daysInCourse[1] = d2;
    daysInCourse[2] = d3;
}
void Student::setDegreeProgram(DegreeProgram dp) { degreeProgram = dp; }


void Student::print() const {
    cout << studentID << "\t"
        << "First Name: " << firstName << "\t"
        << "Last Name: " << lastName << "\t"
        << "Email: " << emailAddress << "\t"
        << "Age: " << age << "\t"
        << "daysInCourse: {" << daysInCourse[0] << ", "
        << daysInCourse[1] << ", "
        << daysInCourse[2] << "} "
        << "Degree Program: ";

    if (degreeProgram == SECURITY) cout << "SECURITY";
    else if (degreeProgram == NETWORK) cout << "NETWORK";
    else cout << "SOFTWARE";

    cout << endl;
}
