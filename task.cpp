#include "task.h"
#include<iostream>
#include <string>
using namespace std;
Task:: Task( int i,string n, string s, string p, string d){
  id = i;
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
 string Task:: getName() const{
  return name;
 }
string Task:: getStatus() const{
  return status;
}
string Task:: getPriority() const{
  return priority;
}
string Task:: getDueDate() const{
  return duedate;
}
int Task:: getId() const {
  return id;
}
void Task:: displayTask() const {
  cout<<"ID: "<<getId()<<endl;
  cout<<"Name: "<<name<<endl;
  cout<<"Status: "<<status<<endl;
cout<<"Priority: "<<priority<<endl;
cout<<"Due Date: "<<duedate<<endl;
cout<<"-----------------------" <<endl;
}
