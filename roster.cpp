#include <iostream>
#include <iomanip> 
#include <cstring>
#include <sstream>
#include <string>
#include "roster.h"
using namespace std;

void Roster::add(
            int index,
            string studentID, 
            string firstName, 
            string lastName, 
            string emailAddress, 
            int age, 
            int numDaysArray[],
            DegreeProgram studentDegreeProgram){ 
                //create new student pointer
                Student* student = nullptr;
                //allowcate new student object in memory
                student = new Student(studentID, firstName, lastName, 
                emailAddress, age, numDaysArray, studentDegreeProgram);
                //assign new student to this roster
                this->classRosterArray[index] = student;
};

void Roster::remove(string studentID){
    cout << "Attempting to remove student " << studentID << endl; 
    for(int i = 0; i < 5; i++){
        if(classRosterArray[i] == nullptr){
            cout << "Student not found!" << endl << endl;
            break;
        }
        if(studentID == classRosterArray[i]->getId()) {
            classRosterArray[i] = nullptr;
            cout << "Student removed from system." << endl << endl;
        }
    }
};

void Roster::printAverageDaysInCourse(string studentID){
    for(int i = 0; i < 5; i++){
        if(classRosterArray[i] == nullptr){
            cout << "Printing avegage day result: Student not found!" << endl;
            break;
        }
        if(studentID == classRosterArray[i]->getId()) {
            cout << "The average days for student " << classRosterArray[i]->getId();
            int average;
            int sum = 0;
            int amount = 3;
            int* days = classRosterArray[i]->getNumDaysForCompletion();
            sum = days[0] + days[1] + days[2];
            average = sum / amount;
            cout << " is: " << average << "." << endl;
        }
    }
};

void Roster::printInvalidEmails(){
    cout << "Here are all of the invalid email addresses: " << endl;
    for(int i = 0; i < 5; i++){
        string Id = classRosterArray[i]->getId();
        string studentEmail = classRosterArray[i]->getEmailAddress();
        bool isValid = true;
        bool isFound = true;
        size_t found1 = studentEmail.find(".");
        size_t found2 = studentEmail.find("@");
        int stringLength = studentEmail.length();
        for(int j = 0; j < stringLength;j++){
            // invalid char search test 
            if(studentEmail[j] == ' ' ){
                isValid = false; 
                break;
            };
            // since the value of npos is a huge number then im going to just make sure the value
            // is under 100 which means the value has been found
            if(found1 > 50 || found2 > 50){
                isFound = false;
                break;
            };
            
        }
        // print this if invalid for this student
        if(isFound == false || isValid == false){
        cout << Id << ":   " << studentEmail << endl;
        };
    }
};

void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
    string degree;
    if(degreeProgram == NETWORK) degree = "NETWORK";
    else if(degreeProgram == SOFTWARE) degree = "SOFTWARE";
    else degree = "SECURITY";
    cout << "These are the students that are enrolled in the " << degree << " degree program:" << endl;
    for(int i = 0; i < 5;i++){
        if(classRosterArray[i]->getDegP() == degreeProgram){
            classRosterArray[i]->print();
        }
    }
};

void Roster::printAll() {
    cout << "Printing all students in database: " << endl;
	for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
};

Roster::~Roster() {
	for (int i = 0; i < 5; i++){
		if (classRosterArray[i] != nullptr){
			delete classRosterArray[i];
        }
    }
};
