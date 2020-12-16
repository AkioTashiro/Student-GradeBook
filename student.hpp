#ifndef student_hpp
#define student_hpp

#include <iostream>
#include <string>
#include <list>

using namespace std;

class student{
public:
    student();
    student(string n, char g);
    //void setNameGrade(string name, char grade);
    string getName();
    char getGrade();
    //void setName(string nm);  //didn't need it
    void setGrade(char grade);
    void AddStudent();
    void DeleteStudent();
    void UpdateGrade();
    void Search();
    void Display();
    void Select();
private:
    string name;
    char grade;
    list<student>* sList; // linked list for students
};

#endif
