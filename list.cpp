/*
Student List allows a user to input and keep track of student information
Mihira Sogal
10/17/2017
Modified on 12/5/2017 to implement a Linked List for Linked List Part 1
 */
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"
#include "Node.h"

using namespace std;
//this struct is used to store name ,gpa, and id for all students


void addStudent(char name[], int id, float gpa);
void print(Node* start);

Node* head = NULL;

int main(){
  bool inuse = true;
  while(inuse){
    //get input on what the user wants to do
    char action[20];
    cout<<"Type in what you want to do"<<endl;
    cin.get(action, 20);
    cin.ignore(80, '\n');
    //if user wants to add a student, prompt and collect the information for that student, then add it to the linked list
    if(strcmp(action, "ADD")==0){
      char *name = new char[80];
      int id = 0;
      float gpa = 0.0;
      cout<<"Name of student: "<<endl;
      cin.get(name, 80);
      cin.ignore(100, '\n');
      cout<<"Student ID Number: "<<endl;
      cin>>id;
      cin.ignore(80,'\n');
      cout<<"GPA of Student: " <<endl;
      cin>>gpa;
      cin.ignore(80, '\n');
      cout<<"Adding student... "<<"Name: "<<name<<"ID: "<<id<<"GPA: "<<gpa <<endl;
      addStudent(name, id, gpa);
    }
    //if user wants to print, go through the nodes, and print the info for each student
    if(strcmp(action,"PRINT")==0){
      print(head);
      
    }
    //exit the loop
    if(strcmp(action, "QUIT")==0){
      cout<<"Exiting..."<<endl;
      inuse = false;
    }
    //delete a student based in the ID that the user gives you
  }
  cout<<"EXITED LOOP"<<endl;
  
  return 0;
}

void addStudent(char sname[80], int sid, float sgpa){
  // cout<<"Entered addStudent"<<endl;
  Student* s = new Student(sname, sid, sgpa);
  // cout<<"Student* created"<<endl;
  Node* current = head;
  if(current == NULL){
    head =new Node();
    head->setValue(s);
  }else{
    while(current->getNext()!= NULL){
      cout<<"Serching for the end..."<<endl;
      current = current->getNext();
      cout<<"End found..."<<endl;
    }
    current->setNext(new Node());
    cout<<"Adding"<<endl;
    current->getNext()->setValue(s);
    cout<<"Setting"<<endl;
    cout<<"Added"<<endl;
    
  }
}
void print(Node* start){
  if(start != NULL){
    start->getValue()->printS();
  }
  cout<<"Checking for next..."<<endl;
  if(start->getNext() != NULL){
    cout<<"Continuing..."<<endl;
    print(start->getNext());
  }
}
