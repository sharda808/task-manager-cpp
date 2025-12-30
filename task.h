#ifndef TASK_H
#define TASK_H
#include <string>
using  namespace std;
class Task {
  private:
  string name;
  string status;
  string priority;
  string duedate;

  public:
  Task(string n = "", string s = "pending", string p = "Medium", string d = "");
  void setName(string n);
  void setStatus(string s);
  void setPriority(string p);
  void setDueDate(string d);
  string getName();
  string getStatus();
  string getPriority();
  string getDueDate();
  void displayTask();
};
#endif