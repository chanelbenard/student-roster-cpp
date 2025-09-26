
#pragma once
#include <vector>
#include <string>
#include "student.h"

using std::string;

class Roster {
private:
   
    std::vector<Student*> classRosterArray;

    // declare helpers
    int findIndexByID(const string& studentID) const;
    void parseAndAdd(const string& csvRow);
    

public:
    Roster();
    ~Roster(); // delete Student*

    //  PUBLIC FUNCTIONS
    void add(string studentID, string firstName, string lastName, string emailAddress,
        int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
        DegreeProgram degreeProgram);

    void remove(string studentID);

    void printAll() const;

    void printAverageDaysInCourse(string studentID) const;

    void printInvalidEmails() const;

    void printByDegreeProgram(DegreeProgram degreeProgram) const;

    void loadFromTable(const std::vector<string>& rows);
   
};
