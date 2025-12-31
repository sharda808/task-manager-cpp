#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <vector>
#include "task.h"
using namespace std;
void saveTasks(const vector<Task> &tasks,  const string& filename);
void loadTasks(vector<Task> &tasks, const string& filename);
#endif