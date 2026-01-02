#ifndef DASHBOARD_H
#define DASHBOARD_H
#include<vector>
#include<string>
#include "task.h"
using namespace std;
void showDashboard(const vector<Task>& tasks);
void exportDashboardToFile( const vector<Task>& tasks);
void weeklyReport(const vector<Task> & tasks);
void smartInsights(const vector<Task> &tasks);
int recalcStreak(int completedToday);
string getTodayDate();
#endif