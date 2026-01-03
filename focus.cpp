#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
void startFocusMode(){
  int minutes;
cout<<"\n Enter focus time(minutes): ";
cin>>minutes;
cout<<"\n Foucs MOde ON. Stay concentrated..\n";
for(int i = minutes; i>0; i--){
  cout<<" Remaining: " << i << " minutes(s)\r";
  cout.flush();
Sleep(60000); // wait 60,000 ms = 1 minute
}
cout<<"\n\n Focus Completed!\n";
ofstream file("foucs_log.txt", ios::app);
if(file.is_open()){
file << "Focus session: " << minutes << " "
<< (minutes == 1 ? "minute" : "minutes")
<< " completed\n";
file.close();
}
else{
  cout <<" Error opening log file!\n";
}
}