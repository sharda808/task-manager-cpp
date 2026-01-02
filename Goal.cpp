#include<iostream>
#include <fstream>
#include <limits>
using namespace std;
void setWeekGoal(){
  int target;
  cout<<" Enter weekly target tasks: ";
 if(! (cin>>target)){
  cout<<"Invalid input! pleae enter a number.\n";
  cin.clear();
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return;
 }
  ofstream file("weekly_goals.txt");
  file<< "Target:  "<<target <<endl;
  file<< "Completed: 0"<<endl;
  file<< "Status: In Progress "<<endl;
  file.close();
  cout<<" Weekly goal set successfully!\n";
}
void updateWeekGoal() {
    ifstream file("weekly_goals.txt");
    if (!file) return;

    string line;
    int target = 0, completed = 0;

    getline(file, line);
    sscanf(line.c_str(), "Target: %d", &target);

    getline(file, line);
    sscanf(line.c_str(), "Completed: %d", &completed);

    file.close();

    completed++;

    ofstream out("weekly_goals.txt");
    out << "Target: " << target << endl;
    out << "Completed: " << completed << endl;

    if (completed >= target) {
        out << "Status: Achieved" << endl;
        cout << "🎉 Weekly Goal Achieved!\n";
    } else {
        out << "Status: In Progress" << endl;
    }

    out.close();
}

void showWeekGoal(){
  ifstream file("weekly_goals.txt");
  if(!file){
    cout<<"No weekly goal set.\n";
    return;
  }
  string line;
  cout<<" Weekly goals status:\n";
  while(getline(file, line))
  cout<<line <<endl;
  file.close();
}