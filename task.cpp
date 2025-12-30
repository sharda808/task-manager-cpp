#include "task.h"
#include<iostream>
#include <string>
using namespace std;
Task:: Task(string n, string s, string p, string d){
  name = n;
  status = s;
  priority = p;
  duedate = d;
}
void Task:: setName(string n){
  name = n;
  }
  void Task:: setStatus(string s){
    status = s;

  }
  void Task:: setPriority(string p){
priority = p;
  }
 void Task:: setDueDate(string d) {
  duedate = d;
 }
 string Task:: getName(){
  return name;
 }
string Task:: getStatus(){
  return status;
}
string Task:: getPriority(){
  return priority;
}
string Task:: getDueDate(){
  return duedate;
}
void Task:: displayTask(){
  cout<<"Name: "<<name<<endl;
  cout<<"Status: "<<status<<endl;
cout<<"Priority: "<<priority<<endl;
cout<<"Due Date: "<<duedate<<endl;
cout<<"-----------------------" <<endl;
}
