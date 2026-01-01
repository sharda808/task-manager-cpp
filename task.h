#ifndef TASK_H
#define TASK_H
#include <string>
using namespace std;
class Task {
  private:
  int id;
  string name;
  string status;
  string priority;
  string duedate;

  public:
  Task( int i =0, string n = "", string s = "pending", string p = "Medium", string d = "");
  void setName(string n);
  void setStatus(string s);
  void setPriority(string p);
  void setDueDate(string d);
  int getId() const;
  string getName() const;
  string getStatus() const;
  string getPriority() const;
  string getDueDate() const;
  void displayTask() const;
};
#endif