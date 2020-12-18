#include <cstring>
#include <iostream>
#include "student.h"
using namespace std;
//default const.
Student::Student()
	: studentId(""), firstName(""), lastName(""), emailAddress(""), age(-1), numDaysForComlpletion(new int[3])
{
	for (int i = 0; i < 3; ++i) {
		this->numDaysForComlpletion[i] = 0;
	}
}
// main const.
Student::Student(
            string studentId, 
            string firstName,
            string lastName, 
            string emailAddress, 
            int age, 
            int numDaysForCompletion[], 
            DegreeProgram studentDegreeProgram) {
                this->studentId = studentId;
                this->firstName = firstName;
                this->lastName = lastName;
                this->emailAddress = emailAddress;
                this->age = age;
                this->numDaysForComlpletion = new int[3];
                for (int i = 0; i < 3; ++i){
                    this->numDaysForComlpletion[i] = numDaysForCompletion[i];
                }
                this->studentDegreeProgram = studentDegreeProgram;
            }

//D.2.A. Accesors Definition DONE
string Student::getId(){
    return studentId;
}
string Student::getFirstName(){
    return firstName;
}
string Student::getLastName(){
    return lastName;
}
string Student::getEmailAddress(){
    return emailAddress;
}
int Student::getAge(){
    return age;
}
int* Student::getNumDaysForCompletion(){
    return numDaysForComlpletion;
}
DegreeProgram Student::getDegP(){
    return studentDegreeProgram;
}
//D.2.B. Mutators Definition: 
void Student::setId(string studId){
    this->studentId = studId;
}
void Student::setFirstName(string studFirstName){
    this->firstName = studFirstName;
}
void Student::setLastName(string studLastName){
    this->lastName = studLastName;
}
void Student::setEmailAddress(string studEmailAddress){
    this->emailAddress = studEmailAddress;
}
void Student::setAge(int studAge){
    this->age = studAge;
}
void Student::setNumDaysForCompletion(int numDaysForComlpletion[]){
    this->numDaysForComlpletion = new int[3];
    for (int i = 0; i < 3; ++i) this->numDaysForComlpletion[i] = numDaysForComlpletion[i];
}
void Student::setDegP(DegreeProgram studDegProgram){
    this->studentDegreeProgram = studDegProgram;
} 
void Student::print() {
	std::cout << this->getId();
	std::cout << "\tFirst name: " << this->getFirstName();
	std::cout << "\tLast name: " << this->getLastName();
	std::cout << "\tAge: " << this->getAge();
    std::cout << "\t\tEmail: " << this->getEmailAddress();
    int* days = getNumDaysForCompletion();
	std::cout << "\t  Days in course: " << days[0] << ", " << days[1] << ", " << days[2];
	string degreeString = "";
	switch (this->getDegP()) {
	case NETWORK:
		degreeString = "NETWORK";
		break;
	case SECURITY:
		degreeString = "SECURITY";
		break;
	case SOFTWARE:
		degreeString = "SOFTWARE";
		break;
	}
	std::cout << "\tDegree: " << degreeString << std::endl;
}



