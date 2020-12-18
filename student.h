#pragma once
#include <cstring>
#include <string>
#include "degree.h"
using namespace std;

class Student {
    public:
        Student();
        Student(
            string studentId, 
            string firstName,
            string lastName, 
            string emailAddress, 
            int age, 
            int* numDaysForCompletion, 
            DegreeProgram studentDegreeProgram
        );

        //D.2.A. Accesors Declaration:
        string getId();
        string getFirstName();
        string getLastName();
        string getEmailAddress();
        int getAge();
        int* getNumDaysForCompletion(); 
        DegreeProgram getDegP(); 
        
        //D.2.B. Mutators Declaration: 
        void setId(string studId);
        void setFirstName(string studFirstName);
        void setLastName(string studLastName);
        void setEmailAddress(string studEmailAddress);
        void setAge(int studAge);
        void setNumDaysForCompletion(int daysInCourse[]);
        void setDegP(DegreeProgram studDegProgram);
        
        virtual void print();
        //~Student();

    private:
        string studentId;
        string firstName;
        string lastName;
        string emailAddress;
        int age;
        int* numDaysForComlpletion;
        DegreeProgram studentDegreeProgram;
};

