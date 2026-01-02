#include "ReportManager.h"
#include<fstream>
#include<string>
#include<ctime>
using namespace std;
void saveInsightsToFile(const string& insight){
ofstream file("insights_report.txt");
if(!file)
return;
time_t now = time(0);
char *dt = ctime(&now);
file<<"------------------------------\n";
file<< "Date: "<< dt;
file<< "Insight: "<<insight << "\n";
file.close();
}