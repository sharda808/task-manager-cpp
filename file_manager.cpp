#include "file_manager.h"
#include<fstream>
#include<iostream>
using namespace std;
void FileManager::saveTasks(vector<Task> &tasks, string filename){
  ofstream fout(filename);
  if(!fout){
    cout<<"Error opening file for writing!" <<endl;
    return;
  }
  for(Task t :tasks){
    fout << t.getName()<<"|"<<t.getStatus() << "|"
    <<t.getPriority() << "|" << t.getDueDate() <<endl;
  }
  fout.close();
}
void FileManager :: loadTasks(vector<Task> &tasks, string filename) {
  ifstream fin(filename);
  if(!fin){
    return;
  }
  tasks.clear();
  string line;
  while (getline(fin, line)){
    size_t pos1 = line.find("|");
    size_t pos2 = line.find("|", pos1+1);
    size_t pos3 = line.find("|", pos2+1);
    string name = line.substr(0, pos1);
    string status = line.substr(pos2+1, pos2-pos1-1);
    string priority = line.substr(pos2+1, pos3-pos2-1);
    string dueDate = line.substr(pos3+1);

    Task t(name, status, priority, dueDate);
   tasks.push_back(t);
  }
  fin.close();
}