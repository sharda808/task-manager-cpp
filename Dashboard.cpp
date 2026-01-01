#include "Dashboard.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;
string getTodayDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string year = to_string(1900 + ltm->tm_year);
    string month = to_string(1 + ltm->tm_mon);
    string day = to_string(ltm->tm_mday);
    if (month.length() == 1) month = "0" + month;
    if (day.length() == 1) day = "0" + day;
    return year + "-" + month + "-" + day;
}
void showDashboard(const vector<Task>& tasks) {
    int total = tasks.size();
    int completed = 0, pending = 0, overdue = 0;
    int high = 0, medium = 0, low = 0;

    string today = getTodayDate();

    for (const auto& t : tasks) {

        if (t.getStatus() == "Completed")
            completed++;
        else {
            pending++;

        if  (!t. getDueDate().empty() && t.getDueDate() < today)
                overdue++;
        }

        if (t.getPriority() == "High") high++;
        else if (t.getPriority() == "Medium") medium++;
        else if (t.getPriority() == "Low") low++;
    }

    int score = (total == 0) ? 0 : (completed * 100) / total;

    cout << "\n========== DASHBOARD SUMMARY ==========\n";
    cout << "Total Tasks      : " << total << endl;
    cout << "Completed Tasks  : " << completed << endl;
    cout << "Pending Tasks    : " << pending << endl;
    cout << "Overdue Tasks    : " << overdue << endl;

    cout << "\nPriority Breakdown:\n";
    cout << "High   : " << high << endl;
    cout << "Medium : " << medium << endl;
    cout << "Low    : " << low << endl;

    cout << "\nProductivity Score: " << score << "%\n";
    cout << "=========================================\n";
}
 int dateToDays(const string& date) {
   
      if (date.length() != 10 || date[4] != '/' || date[7] != '/') {
        return -1;  
    }

    try {
        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8, 2));
        return y * 365 + m * 30 + d;
    }
    catch (...) {
        return -1;  
    }
}
    void weeklyReport(const vector<Task>& tasks){
        int completed = 0, pending = 0, overdue =0;
     string today = getTodayDate();
        int todayDays = dateToDays(today);
        for(const auto& t: tasks){
            if(t.getDueDate().empty()) continue;
            int taskDay = dateToDays(t.getDueDate());
            if(todayDays -taskDay <=7){
                if(t.getStatus() =="Completed")
                completed++;
                else{
                    pending++;
                    if(taskDay < todayDays)
                    overdue++;
                }
            }
        }
       cout<<"\nWeekly Report (Last 7 days)\n" ;
       cout<<"Completed : "<<completed<<endl;
       cout<<"Pending : "<<pending<<endl;
        cout<<"Overdue : "<<overdue<<endl; 
    }


void exportDashboardToFile(const vector<Task>& tasks) {

    ofstream file("dashboard_report.txt");
    if (!file) {
        cout << "File open nahi ho rahi\n";
        return;
    }

    int total = tasks.size();
    int completed = 0, pending = 0, overdue = 0;
    int high = 0, medium = 0, low = 0;

    string today = getTodayDate();

    for (const auto& t : tasks) {

        if (t.getStatus() == "Completed")
            completed++;
        else {
            pending++;
            if (!t.getDueDate().empty() && t.getDueDate() < today)
                overdue++;
        }

        if (t.getPriority() == "High") high++;
        else if (t.getPriority() == "Medium") medium++;
        else if (t.getPriority() == "Low") low++;
    }

    int score = (total == 0) ? 0 : (completed * 100) / total;

    file << "DASHBOARD REPORT\n";
    file << "=================\n";
    file << "Total Tasks     : " << total << endl;
    file << "Completed Tasks : " << completed << endl;
    file << "Pending Tasks   : " << pending << endl;
    file << "Overdue Tasks   : " << overdue << endl;

    file << "\nPriority Summary:\n";
    file << "High   : " << high << endl;
    file << "Medium : " << medium << endl;
    file << "Low    : " << low << endl;

    file << "\nProductivity Score: " << score << "%\n";

    file.close();

    cout << " Dashboard exported successfully (dashboard_report.txt)\n";
}