#ifndef  FILE_MANAGER_H
#define FILE_MANAGER_H
#include <vector>
#include<string>
#include "task.h"
using  namespace std;
class FileManager {
  public:
  static void saveTasks(vector<Task> &tasks, string filename);
  static void loadTasks(vector<Task> &tasks, string filename);
};
#endif