#include "student.hpp"
#include <iomanip>
#include <string>


student::student(){};
student::student(string n, char g){
    this->name = n;
    this->grade = g;
    sList = new list<student>();
}
string student::getName() {
   return name;
}
char student::getGrade() {
   return grade;
}
void student::setGrade(char gr) {
   this->grade = gr;
}

void student::AddStudent() {
    string name;
    char grade;
    
    cout << "Enter student's name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter grade: ";
    cin >> grade;
    
    //setNameGrade(name, grade);    //did not work
    student st(name, grade);   // creating the student object
    sList->push_back(st);   // now add st(which has nme and grade) to the list
}
void student::DeleteStudent() {
   cout << "Enter student's name to delete: ";
   string name;
    cin.ignore();
   getline(cin, name);
   bool isDeleted = false; // create the bool to see if student is deleted.
   
   list<student>::iterator itr = sList->begin();   //search the list. create iterator which is similar to pointer.
   for (int i = 0; i < sList->size(); i++) {
       if (itr->getName().compare(name) == 0) {  // check if student exist at curent location
           list<student>::iterator end = itr;
           end++;
           sList->erase(itr,end);
           isDeleted = true;
           break;
       }
       itr++;
   }
   // check if student is removed
   if(!isDeleted) {
       cout << "Student does not exist in the list." << endl;
   }
}
void student::UpdateGrade() {
    int sid;
    char grade;
    Display();
    cout << "Select ID to update the Student's Grade: " << endl;
    cin >> sid;
    if (sid<1 || sid>sList->size()) {   //check if the id is in the list
        cout << "The ID does not exist." << endl;
    }
    else {   //if it exist, then come here.
        cout << "Enter new grade: ";
        cin >> grade; // get user input
        
        list<student>::iterator itr = sList->begin();// get the student in list create iterator
        for (int i = 1; i < sid; i++) {   //run until the chosen number
            itr++;      //make itr pointer's number grow and stop at the same spot with std
        }
        itr->setGrade(grade);    // then now i can update the student's grade
   }
}
void student::Search() {
    string name;
    cout << "Enter student's name: ";
    cin.ignore();
    getline(cin, name);
    
    bool isSearch = false;     //bool to see if student is there
    list<student>::iterator itr = sList->begin();//use iterator again (it's pre useful I shold get used to use this)
    for (int i = 0; i < sList->size(); i++) {  // let's check whole list.
        if (itr->getName().compare(name) == 0) {  //compare reads the string 0 means match. maybe i shoudl use id again?
           cout << "Name: " << itr->getName() << "\t" << "Grade: " << itr->getGrade() << endl;
           isSearch = true; // set the bool to true
           break;
       }
       itr++;   
   }
   if (!isSearch) {
       cout << "The student does not exist in the list." << endl;
   }
}
void student::Select(){   //just symple selection menue like the other game program.
    int select = 0;
    student st("Default", 'N');
    
    while(select != 6){
           cout << "Select Menue:" << endl;
           cout << "[1] Add a student" << endl;
           cout << "[2] Delete a student" << endl;
           cout << "[3] Update grade" << endl;
           cout << "[4] Search student" << endl;
           cout << "[5] Display the list" << endl;
           cout << "[6] EXIT" << endl;
           cin >> select;
          if (select<1 || select>6) {
              cout << "Error!!!" << endl;
          }
          else{
              switch(select){
                  case 1: st.AddStudent(); break;
                  case 2: st.DeleteStudent(); break;
                  case 3: st.UpdateGrade(); break;
                  case 4: st.Search(); break;
                  case 5: st.Display(); break;
                  case 6: cout<<"Exit."<<endl; break;
                  default: break;
              }
          }
       }
}
void student::Display() {   //display the list.
   cout << "----------------------------------" << endl;
   cout << setw(4) << left << "No";
   cout << setw(20) << left << "Name";
   cout << left << "Grade" << endl;
   cout << "----------------------------------" << endl;
   
   list<student>::iterator itr = sList->begin(); //again use the iterator.
   for (int i = 0; i < sList->size(); i++) {
       cout << setw(4) << left << (i+1);
       cout << setw(20) << left << itr->getName();
       cout << " " << left << itr->getGrade() << endl;
       itr++;
   }
   cout << "----------------------------------" << endl;
}
