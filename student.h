
#pragma once
#include <string>
#include "degree.h"

using std::string;

class Student {
private:
    
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[3];   //  3 courses
    DegreeProgram degreeProgram;

public:
    // constructor
    Student(string studentID, string firstName, string lastName,
        string emailAddress, int age,
        int daysInCourse1, int daysInCourse2, int daysInCourse3,
        DegreeProgram degreeProgram);

    // accessors 
    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    const int* getDaysInCourse() const;
    DegreeProgram getDegreeProgram() const;

    //  setters
    void setStudentID(string id);
    void setFirstName(string first);
    void setLastName(string last);
    void setEmailAddress(string email);
    void setAge(int a);
    void setDaysInCourse(int d1, int d2, int d3);
    void setDegreeProgram(DegreeProgram dp);

      
    void print() const;
};

