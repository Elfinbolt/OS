#include<iostream>
using namespace std;

int main(){
int n,sum1=0,sum2=0;
float avg1,avg2;
//input
cout<<"Enter number of processes"<<endl;
cin>>n;
int process[n],burst[n];
cout<<"Enter processes and burst times:"<<endl;
for(int i=0;i<n;i++){
    cin>>process[i];
    cin>>burst[i];
}
//waiting time
int wait[n];
wait[0]=0;
int wit=0;
for(int i=0;i<n;i++){
    wit=wit+burst[i];
    wait[i+1]=wit;
}

//turn around time
int turn[n];
    for(int i=0;i<n;i++){
        turn[i]=wait[i]+burst[i];
    }

//display
cout<<"Process\t\tBurstTime\t\tWaitingTime\t\tturn around time"<<endl;
for(int i=0; i<n; i++){
  sum1+=wait[i];
  sum2+=turn[i];
  cout<<process[i]<<"\t\t"<<burst[i]<<"\t\t\t"<<wait[i]<<"\t\t\t"<<turn[i]<<endl;
}
avg1=sum1/n;
avg2=sum2/n;
cout<<"AverageWaitingTime ="<<avg1<<endl;
cout<<"AverageTurnaroundtime ="<<avg2<<endl;
return 0;
}