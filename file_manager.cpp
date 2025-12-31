


#include "file_manager.h"
#include <fstream>
#include <iostream>
using namespace std;

// Save tasks to file
void saveTasks(const vector<Task>& tasks, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: File not opened for writing\n";
        return;
    }
    for (const auto& t : tasks) {
        file << t.getName() << "|"
             << t.getStatus() << "|"
             << t.getPriority() << "|"
             << t.getDueDate() << endl;
    }
    file.close();
    cout << "Tasks saved successfully to: " << filename << "\n";
}

// Load tasks from file
void loadTasks(vector<Task>& tasks, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "No existing tasks file found. New file will be created.\n";
        return;
    }

    tasks.clear();
    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find("|");
        size_t pos2 = line.find("|", pos1 + 1);
        size_t pos3 = line.find("|", pos2 + 1);

        string name = line.substr(0, pos1);
        string status = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string priority = line.substr(pos2 + 1, pos3 - pos2 - 1);
        string duedate = line.substr(pos3 + 1);

        Task t(name, status, priority, duedate);
        tasks.push_back(t);
    }
    file.close();
}
