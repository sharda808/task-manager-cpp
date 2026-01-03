
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <windows.h>
#include "Dashboard.h"
#include "task.h"
#include "file_manager.h"
#include "Goal.h"
#include "focus.h"
using namespace std;

vector<Task> tasks;
string filename = "tasks.txt";
int nextId = 1;

void showMenu();
void addTask();
void viewTask();
void completeTask();
void deleteTask();
void searchTask(const vector<Task>& tasks);
void sortByPriority(vector<Task> &tasks);
void dueDateReminder(const vector<Task> & tasks);
int dateToNumber(const string& date);
void autoUpdateOverdueTasks(vector<Task>& tasks);
string getTodayDate();
int recalcStreak(int  completedToday);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    loadTasks(tasks, filename);
    autoUpdateOverdueTasks(tasks);

    if (!tasks.empty()) {
        nextId = tasks.back().getId() + 1;
    }

    int choice;
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
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
                searchTask(tasks);
                break;
            case 6:
                sortByPriority(tasks);
                break;
            case 7:
                showDashboard(tasks);
                break;
            case 8:
                dueDateReminder(tasks);
                break;
            case 9:
                exportDashboardToFile(tasks);
                break;
            case 10:
               weeklyReport(tasks);
                break;
           case 11:
    setWeekGoal();
    break;
        case 12:
        showWeekGoal();
        break;   
        case 13:
        startFocusMode();
        break;
            case 14:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 14);

    return 0;
}

void showMenu() {
    cout << "\n==== Simple Task Manager ====\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Complete Task\n";
    cout << "4. Delete Task\n";
    cout << "5. Search Task\n";
    cout << "6. Sort Tasks by Priority\n";
    cout << "7. Show Dashboard\n";
    cout << "8. DueDateReminders\n";
    cout << "9. Export Dashboard Report\n";
    cout << "10. weeklyReporttasks\n";
    cout<<" 11. set Weekly Goal\n";
    cout <<" 12. View Weekly Goal\n";
    cout<<"13. Focus Mode\n";
    cout << "14. Exit\n";
}

void addTask() {
    string name, priority, dueDate;
    cout << "Enter task name: ";
    getline(cin, name);

    cout << "Enter priority (High/Medium/Low): ";
    getline(cin, priority);

    cout << "Enter due date (DD/MM/YYYY): ";
    getline(cin, dueDate);

    Task t(nextId, name, "Pending", priority, dueDate);
    tasks.push_back(t);
    nextId++;
    saveTasks(tasks, filename);
    cout << "Task added successfully!\n";
}

void viewTask() {
    if (tasks.empty()) {
        cout << "No tasks found!\n";
        return;
    }

    cout << "\n----- All Tasks -----\n";
    for (const auto& task : tasks) {
        task.displayTask();
    }
}

void completeTask() {
    if (tasks.empty()) {
        cout << "No tasks found!\n";
        return;
    }

    int id;
    viewTask();
    cout << "Enter Task ID to mark as completed: ";
    cin >> id;
    cin.ignore();

    bool found = false;
    for (auto& task : tasks) {
        if (task.getId() == id) {
            task.setStatus("Completed");
            found = true;
            break;
        }
    }

    if (found) {
        saveTasks(tasks, filename);
        cout << "Task marked as completed!\n";
updateWeekGoal();
        int completedToday = count_if(tasks.begin(), tasks.end(), []
        
         (const Task& t){
           return t.getStatus() == "Completed"; 
        });
        int streak = recalcStreak(completedToday);
        cout << "Current Productivity Streak: " << streak << " day(s)\n";
    } else {
        cout << "Task ID not found!\n";
    }
}

void deleteTask() {
    if (tasks.empty()) {
        cout << "No tasks found!\n";
        return;
    }
    int id;
    viewTask();
    cout << "Enter Task ID to delete: ";
    cin >> id;
    cin.ignore();

    bool found = false;
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].getId() == id) {
            tasks.erase(tasks.begin() + i);
            found = true;
            break;
        }
    }

    if (found) {
        saveTasks(tasks, filename);
        cout << "Task deleted successfully!\n";
  
        int completedToday = count_if(tasks.begin(), tasks.end(),[]
      
      (const Task& t) { 
      return t.getStatus() == "Completed"; 
    });
        int streak = recalcStreak(completedToday);
        cout << "Current Productivity Streak: " << streak << " day(s)\n";
    } else {
        cout << "Task ID not found!\n";
    }
}

void searchTask(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available\n";
        return;
    }

    int option;
    cout << "\nSearch by:\n";
    cout << "1. Task ID\n";
    cout << "2. Task Name\n";
    cout << "Choose option: ";
    cin >> option;
    cin.ignore();

    bool found = false;

    if (option == 1) {
        int id;
        cout << "Enter Task ID: ";
        cin >> id;

        for (const auto& task : tasks) {
            if (task.getId() == id) {
                cout << "\nTask Found:\n";
                task.displayTask();
                found = true;
                break;
            }
        }
    } else if (option == 2) {
        string name;
        cout << "Enter Task Name: ";
        getline(cin, name);

        for (const auto& task : tasks) {
            if (task.getName() == name) {
                cout << "\nTask Found:\n";
                task.displayTask();
                found = true;
            }
        }
    } else {
        cout << "Invalid option!\n";
        return;
    }

    if (!found) {
        cout << "No matching task found.\n";
    }
}

void sortByPriority(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to sort\n";
        return;
    }

    sort(tasks.begin(), tasks.end(),
        [](const Task& a, const Task& b) {
            auto priorityValue = [](string p) {
                if (p == "High") return 1;
                if (p == "Medium") return 2;
                return 3;
            };
            return priorityValue(a.getPriority()) < priorityValue(b.getPriority());
        }
    );

    saveTasks(tasks, filename);
    cout << "Tasks sorted by priority successfully!\n";
}

void setColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void dueDateReminder(const vector<Task> & tasks){
    if(tasks.empty()){
        cout<<" No tasks available\n";
        return;
    }

    string today = getTodayDate();
    int todayNum = dateToNumber(today);
    bool found = false;
    cout <<"\n AUTO DUE DATE REMINDER\n";
    cout<<" Today: " << today <<"\n\n";

    for(const auto& t:tasks){
        int dueNum = dateToNumber(t.getDueDate());
        if(t.getStatus() == "Pending"){
            if(dueNum < todayNum) {
                setColor(12);
                cout<<" ⚠️  OverDUE: " <<t.getName() <<" (Due: " << t.getDueDate() << ")\n";
                found = true;
            }
            else if(dueNum == todayNum){
                setColor(14);
                cout<<" 🔔 DUE TODAY  "<<t.getName()<<endl;
                found = true;
            }
        }
    }
    setColor(7);
    if(!found)
        cout<<" NO due reminders today\n";
}

int dateToNumber(const string& date) {
    int d, m, y;
    char c1, c2;
    stringstream ss(date);
    ss >> d >> c1 >> m >> c2 >> y;
    if (ss.fail() || c1 != '/' || c2 != '/')
        return -1;
    return y * 10000 + m * 100 + d;
}

void autoUpdateOverdueTasks(vector<Task>& tasks){
    int todayNum = dateToNumber(getTodayDate());
    for(auto& t: tasks){
        if(t.getStatus() == "Pending" && !t.getDueDate().empty()){
            int dueNum = dateToNumber(t.getDueDate());
            if(dueNum < todayNum){
                t.setStatus("Overdue");
            }
        }
    }
}


