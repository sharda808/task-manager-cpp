// #include "Dashboard.h"
// #include "ReportManager.h"
// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <ctime>

// using namespace std;
// string smartInsights(int total, int completed, int pending, int overdue) {
//     string insight;

//     if (total > 0 && (completed * 100 / total) >= 70)
//         insight += "Great job! You are highly productive.\n";
//     else
//         insight += "Focus needed. Try completing more tasks.\n";

//     if (overdue > 0)
//         insight += "Warning: You have overdue tasks.\n";
//     else
//         insight += "No overdue tasks. Well managed.\n";

//     insight += "Tip: Small progress every day leads to big success.\n";

//     return insight;
// }
// string getTodayDate() {
//     time_t now = time(0);
//     tm *ltm = localtime(&now);
//     string year = to_string(1900 + ltm->tm_year);
//     string month = to_string(1 + ltm->tm_mon);
//     string day = to_string(ltm->tm_mday);
//     if (month.length() == 1) month = "0" + month;
//     if (day.length() == 1) day = "0" + day;
//     return year + "/" + month + "/" + day;
// }
//  int dateToDays(const string& date) {
   
//       if (date.length() != 10 || date[4] != '/' || date[7] != '/') {
//         return -1;  
//     }

//     try {
//         int y = stoi(date.substr(0, 4));
//         int m = stoi(date.substr(5, 2));
//         int d = stoi(date.substr(8, 2));
//         return y * 365 + m * 30 + d;
//     }
//     catch (...) {
//         return -1;  
//     }
// }
// int loadStreak(string &lastDate){
//  ifstream file("streak.txt");
//  int streak = 0;
//  if(file.is_open()){
//  if(file >> lastDate >> streak)  
//  file.close();
//  }
//  return streak; 
// }
// int recalcStreak(int completedToday){
//     string lastdate;
//     int streak = loadStreak(lastdate);
//     string today = getTodayDate();
//     if(today == lastdate){
//     if(completedToday == 0)
//     streak = 0;
//     }
  
//     if(completedToday >0)
//     streak++;
//     else
//     streak =0;
//     ofstream file("streak.txt");
//     file<<today << " " << streak;
//     file.close();
//     return streak;
// }

// void showDashboard(const vector<Task>& tasks) {
//     int total = tasks.size();
//     int completed = 0, pending = 0, overdue = 0;
//     int high = 0, medium = 0, low = 0;

//     string today = getTodayDate();
//     for (const auto& t : tasks) {
//         if (t.getStatus() == "Completed")
//             completed++;
//         else {
//             pending++;

//         if  (!t. getDueDate().empty() && t.getDueDate() < today)
//                 overdue++;
//         }

//         if (t.getPriority() == "High") high++;
//         else if (t.getPriority() == "Medium") medium++;
//         else if (t.getPriority() == "Low") low++;
//     }

//     int score = (total == 0) ? 0 : (completed * 100) / total;

//     cout << "\n========== DASHBOARD SUMMARY ==========\n";
//     cout << "Total Tasks      : " << total << endl;
//     cout << "Completed Tasks  : " << completed << endl;
//     cout << "Pending Tasks    : " << pending << endl;
//     cout << "Overdue Tasks    : " << overdue << endl;

//     cout << "\nPriority Breakdown:\n";
//     cout << "High   : " << high << endl;
//     cout << "Medium : " << medium << endl;
//     cout << "Low    : " << low << endl;

//     cout << "\nProductivity Score: " << score << "%\n";
//     cout << "=========================================\n";
//     string insight = smartInsights(total, completed, pending, overdue);

// cout << "\n🧠 SMART INSIGHT\n";
// cout << "----------------\n";
// cout << insight << endl;

// saveInsightsToFile(insight);
// }

//     void weeklyReport(const vector<Task>& tasks){
//         int completed = 0, pending = 0, overdue =0;
//      string today = getTodayDate();
//         int todayDays = dateToDays(today);
//         for(const auto& t: tasks){
//             if(t.getDueDate().empty()) continue;
//             int taskDay = dateToDays(t.getDueDate());
//             int diff = todayDays - taskDay;
//             if(diff >=0 && diff <=7 ){
            
//                 if(t.getStatus() =="Completed"){
//                 completed++;
//                 }
//                 else{
//                     pending++;
//                     if(taskDay < todayDays)
//                     overdue++;
//                 }
//             }
//         }
//        cout<<"\nWeekly Report (Last 7 days)\n" ;
//        cout<<"Completed : "<<completed<<endl;
//        cout<<"Pending : "<<pending<<endl;
//         cout<<"Overdue : "<<overdue<<endl; 
//     }


// void exportDashboardToFile(const vector<Task>& tasks) {

//     ofstream file("dashboard_report.txt");
//     if (!file) {
//         cout << "File open nahi ho rahi\n";
//         return;
//     }

//     int total = tasks.size();
//     int completed = 0, pending = 0, overdue = 0;
//     int high = 0, medium = 0, low = 0;

//     string today = getTodayDate();

//     for (const auto& t : tasks) {

//         if (t.getStatus() == "Completed")
//             completed++;
//         else {
//             pending++;
//             if (!t.getDueDate().empty() && t.getDueDate() < today)
//                 overdue++;
//         }

//         if (t.getPriority() == "High") high++;
//         else if (t.getPriority() == "Medium") medium++;
//         else if (t.getPriority() == "Low") low++;
//     }

//     int score = (total == 0) ? 0 : (completed * 100) / total;

//     file << "DASHBOARD REPORT\n";
//     file << "=================\n";
//     file << "Total Tasks     : " << total << endl;
//     file << "Completed Tasks : " << completed << endl;
//     file << "Pending Tasks   : " << pending << endl;
//     file << "Overdue Tasks   : " << overdue << endl;

//     file << "\nPriority Summary:\n";
//     file << "High   : " << high << endl;
//     file << "Medium : " << medium << endl;
//     file << "Low    : " << low << endl;

//     file << "\nProductivity Score: " << score << "%\n";

//     file.close();

//     cout << " Dashboard exported successfully (dashboard_report.txt)\n";
// }
#include "Dashboard.h"
#include "ReportManager.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

/* ---------------- SMART INSIGHTS ---------------- */
string smartInsights(int total, int completed, int pending, int overdue) {
    string insight;

    if (total > 0 && (completed * 100 / total) >= 70)
        insight += "Great job! You are highly productive.\n";
    else
        insight += "Focus needed. Try completing more tasks.\n";

    if (overdue > 0)
        insight += "Warning: You have overdue tasks.\n";
    else
        insight += "No overdue tasks. Well managed.\n";

    insight += "Tip: Small progress every day leads to big success.\n";
    return insight;
}

/* ---------------- DATE UTILITIES ---------------- */
string getTodayDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    string day = to_string(ltm->tm_mday);
        string month = to_string(1 + ltm->tm_mon);
    string year = to_string(1900 + ltm->tm_year);


    if (day.length() == 1) day = "0" + day;
    if (month.length() == 1) month = "0" + month;


    return day + "/" + month + "/" + year;
}

int dateToDays(const string& date) {
    if (date.length() != 10 || date[2] != '/' || date[5] != '/')
        return -1;

    try {
        int y = stoi(date.substr(0, 2));
        int m = stoi(date.substr(3, 2));
        int d = stoi(date.substr(6, 4));
        return y * 365 + m * 30 + d;
    }
    catch (...) {
        return -1;
    }
}

/* ---------------- STREAK ---------------- */
int loadStreak(string& lastDate) {
    ifstream file("streak.txt");
    int streak = 0;

    if (file >> lastDate >> streak)
        file.close();

    return streak;
}

int recalcStreak(int completedToday) {
    string lastDate;
    int streak = loadStreak(lastDate);
    string today = getTodayDate();

    if (today == lastDate) {
        if (completedToday == 0)
            streak = 0;
    }
    else {
        if (completedToday > 0)
            streak++;
        else
            streak = 0;
    }

    ofstream file("streak.txt");
    file << today << " " << streak;
    file.close();

    return streak;
}

/* ---------------- DASHBOARD ---------------- */
void showDashboard(const vector<Task>& tasks) {
    int total = tasks.size();
    int completed = 0, pending = 0, overdue = 0;
    int high = 0, medium = 0, low = 0;

    string today = getTodayDate();
    int todayDays = dateToDays(today);

    for (const auto& t : tasks) {
        if (t.getStatus() == "Completed")
            completed++;
        else {
            pending++;
            if (!t.getDueDate().empty() &&
                dateToDays(t.getDueDate()) < todayDays)
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

    string insight = smartInsights(total, completed, pending, overdue);

    cout << "\n🧠 SMART INSIGHT\n";
    cout << "----------------\n";
    cout << insight << endl;

    saveInsightsToFile(insight);
}

/* ---------------- WEEKLY REPORT ---------------- */
void weeklyReport(const vector<Task>& tasks) {
    int completed = 0, pending = 0, overdue = 0;

    string today = getTodayDate();
    int todayDays = dateToDays(today);

    for (const auto& t : tasks) {
        if (t.getDueDate().empty()) continue;

        int taskDay = dateToDays(t.getDueDate());
        int diff = todayDays - taskDay;

        if (diff >= 0 && diff <= 7) {
            if (t.getStatus() == "Completed")
                completed++;
            else {
                pending++;
                if (taskDay < todayDays)
                    overdue++;
            }
        }
    }

    cout << "\nWeekly Report (Last 7 days)\n";
    cout << "Completed : " << completed << endl;
    cout << "Pending   : " << pending << endl;
    cout << "Overdue   : " << overdue << endl;
}

/* ---------------- EXPORT ---------------- */
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
    int todayDays = dateToDays(today);

    for (const auto& t : tasks) {
        if (t.getStatus() == "Completed")
            completed++;
        else {
            pending++;
            if (!t.getDueDate().empty() &&
                dateToDays(t.getDueDate()) < todayDays)
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

    cout << "Dashboard exported successfully (dashboard_report.txt)\n";
}
