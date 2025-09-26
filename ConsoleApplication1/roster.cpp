
#include "roster.h"
#include <iostream>
#include <sstream>  
using std::cout;
using std::endl;

Roster::Roster() {}

Roster::~Roster() {
    
    for (Student* s : classRosterArray) {
        delete s;
    }
    classRosterArray.clear();
}

// Helper
int Roster::findIndexByID(const string& studentID) const {
    for (int i = 0; i < static_cast<int>(classRosterArray.size()); ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) return i;
    }
    return -1;
}

//  add)
void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
    int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
    DegreeProgram degreeProgram) {
    Student* s = new Student(studentID, firstName, lastName,
        emailAddress, age,
        daysInCourse1, daysInCourse2, daysInCourse3,
        degreeProgram);
    classRosterArray.push_back(s);
}

//  remove()
void Roster::remove(string studentID) {
    int idx = findIndexByID(studentID);
    if (idx == -1) {
        cout << "ERROR: Student with ID " << studentID << " not found." << endl;
        return;
    }
    delete classRosterArray[idx];
    classRosterArray.erase(classRosterArray.begin() + idx);
}


void Roster::printAll() const {
    for (const Student* s : classRosterArray) {
        s->print();
    }
}

// print avg days in course
void Roster::printAverageDaysInCourse(string studentID) const {
    int idx = findIndexByID(studentID);
    if (idx == -1) {
        cout << "ERROR: Student with ID " << studentID << " not found." << endl;
        return;
    }
    const int* d = classRosterArray[idx]->getDaysInCourse();
    double avg = (d[0] + d[1] + d[2]) / 3.0;
    cout << "Average days in course for " << studentID << ": " << avg << endl;
}

//  print Invalid Emails
void Roster::printInvalidEmails() const {
    for (const Student* s : classRosterArray) {
        string e = s->getEmailAddress();
        bool hasAt = (e.find('@') != string::npos);
        bool hasDot = (e.find('.') != string::npos);
        bool hasSpace = (e.find(' ') != string::npos);

        if (!hasAt || !hasDot || hasSpace) {
            cout << "Invalid email: " << e << endl;
        }
    }
}

//  printByDegreeProgram(...)
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (const Student* s : classRosterArray) {
        if (s->getDegreeProgram() == degreeProgram) {
            s->print();
        }
    }
}

// Helper, parse a CSV row 
void Roster::parseAndAdd(const string& csvRow) {
    std::stringstream ss(csvRow);
    string token;
    string fields[9];
    int i = 0;
    while (std::getline(ss, token, ',') && i < 9) {
        fields[i++] = token;
    }
    // Map fields
    string id = fields[0];
    string first = fields[1];
    string last = fields[2];
    string email = fields[3];
    int age = std::stoi(fields[4]);
    int d1 = std::stoi(fields[5]);
    int d2 = std::stoi(fields[6]);
    int d3 = std::stoi(fields[7]);

    DegreeProgram dp = SOFTWARE;
    if (fields[8] == "SECURITY") dp = SECURITY;
    else if (fields[8] == "NETWORK") dp = NETWORK;
    else dp = SOFTWARE;

    //add
    add(id, first, last, email, age, d1, d2, d3, dp);
}

    void Roster::loadFromTable(const std::vector<string>&rows) {
        for (const auto& row : rows) {
            parseAndAdd(row);
        }
}



