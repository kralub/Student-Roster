#pragma once
#include <string>
#include "student.h"
using namespace std;

class Roster {
    public:
        Student* classRosterArray[5];
        //E.3. roster functions declarations
        void add(
            int index,
            string studentID, 
            string firstName, 
            string lastName, 
            string emailAddress, 
            int age, 
            int numDaysArray[],
            DegreeProgram studentDegreeProgram
        );
        void remove(string studentID);
        void printAverageDaysInCourse(string studentID);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram degreeProgram); 
        void printAll();
        ~Roster();    
};

