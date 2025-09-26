// main.cpp
#include <iostream>
#include <vector>
#include "roster.h"

int main() {
    // G1 Header  
    std::cout << "Course Title: Scripting and Programming Applications C867" << std::endl;  
    std::cout << "Programming Language Used: C++" << std::endl;
    std::cout << "WGU Student ID: 011721351" << std::endl;   
    std::cout << "Name: Chanel Benard" << std::endl;        
    std::cout << std::endl;

    // G2  roster instance 
    Roster classRoster;

    //  G3 students
    
    const std::vector<std::string> studentData = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Chanel,Benard,cbenar7@wgu.edu,25,10,20,30,SOFTWARE"
    };

    classRoster.loadFromTable(studentData);

    //  G4 Convert the pseudo code 
    classRoster.printAll();
    std::cout << std::endl;

    classRoster.printInvalidEmails();
    std::cout << std::endl;

    // loop and print average days for each student
    const char* ids[] = { "A1","A2","A3","A4","A5" };
    for (const char* id : ids) {
        classRoster.printAverageDaysInCourse(id);
    }
    std::cout << std::endl;

    classRoster.printByDegreeProgram(SOFTWARE);
    std::cout << std::endl;

    classRoster.remove("A3");
    std::cout << std::endl;

    classRoster.printAll();
    std::cout << std::endl;

    classRoster.remove("A3");  
    std::cout << std::endl;

    
    return 0;
}
