
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

        file << t.getId()<< "|"
       << t.getName() << "|"
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
         size_t pos4 = line.find("|", pos3 + 1);
         if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos || pos4 == string::npos) {
        cout << "Skipping malformed line: " << line << endl;
        continue;
    }
 int id = 0;
    try {
        id = stoi(line.substr(0, pos1));
    } catch (...) {
        cout << "Skipping line with invalid ID: " << line << endl;
        continue;
    }
       string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
    string status = line.substr(pos2 + 1, pos3 - pos2 - 1);
    string priority = line.substr(pos3 + 1, pos4 - pos3 - 1);
    string duedate = line.substr(pos4 + 1);

        Task t(id,name, status, priority, duedate);
        tasks.push_back(t);
    }
    file.close();
}
