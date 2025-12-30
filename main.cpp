#include<iostream>
#include<vector>
#include<string>
#include "task.h" // Task class include 
#include "file_manager.h"
using namespace std;
vector<Task> tasks;
string filename = "tasks.txt";
void showMenu();
void addTask();
void viewTask();
void completeTask();
void deleteTask();
int main(){
  FileManager ::loadTasks(tasks, filename);

  int choice;
  do {
    showMenu();
    cout<<"Enter your choice:";
    cin>>choice;
    cin.ignore(); 
    switch(choice){
      case 1:
      addTask();
      break;
      case 2: 
viewTask();
break;
case 3:
completeTask();
break;
case 4:
deleteTask();
break;
case 5:
cout<<"Exiting program. Goodbye!" <<endl;
break;
default:
cout<<"Invalid choice! Try again." <<endl;
    }

  } while(choice!=5);
  return 0;
}
void showMenu(){
  cout<<"\n==== Simple Task Manager ====\n";
  cout<<"1. Add Task\n";
  cout<<"2. View Tasks\n";
  cout<<"3. Complete Task\n";
  cout<<"4. Delete Task\n";
  cout<<"5. Exit\n";
}
void addTask(){
  string name,priority, dueDate;
  cout<<"Enter task name: ";
  getline(cin, name);
  cout<<"Enter priority (High/Medium/Low):";
  getline(cin,priority);
  cout<<"Enter due date (DD/MM/YYYY): ";
  getline(cin, dueDate);
  Task t(name, "Pending", priority, dueDate);
  tasks.push_back(t);
  FileManager::saveTasks(tasks,filename);
  cout<<"Task added successfully!\n";
}
void viewTask(){
  if(tasks.empty()){
    cout<<"No tasks found!\n";
    return;
  }
  cout<< "\n-----All Tasks -----\n";
  for(int i=0; i<tasks.size(); i++){
    cout<<"Task ID: " << i+1 <<endl;
    tasks[i].displayTask();
  }
}
void completeTask(){
  if(tasks.empty()){
    cout<<"No tasks found!\n";
    return;
  }
  int id;
  viewTask();
  cout<<" Enter Task ID to mark as completed: ";
  cin>>id;
  cin.ignore();
  if(id < 1 || id > tasks.size()){
    cout<< "Invalid Task Id! \n";
    return;
  }
  tasks[id-1].setStatus("Completed");
  FileManager::saveTasks(tasks, filename);
  cout<<"Task marked as completed!\n";
}
void deleteTask(){
  if(tasks.empty()){
    cout<<"No tasks found!\n";
    return;
  }
  int id;
  viewTask();
  cout<<"Enter Task ID to delete: ";
  cin>>id;
  cin.ignore();
  if(id < 1 || id > tasks.size()){
    cout<<"Invalid Task Id!\n";
    return;
  }
  tasks.erase(tasks.begin() + id -1);
  FileManager::saveTasks(tasks, filename);
  cout<<"Task deleted successfully!\n";
}