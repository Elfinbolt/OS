#include <iostream>
using namespace std;

class ProcessScheduler {
private:
    int n;
    int processIds[100];
    int burst[100];
    int arrival[100];
    int wait[100];
    int turn[100];

public:
    // Function to take input
    void inputProcesses() {
        cout << "Enter number of processes: ";
        cin >> n;

        cout << "Enter process IDs, arrival times, and burst times:" << endl;
        for (int i = 0; i < n; i++) {
            cin >> processIds[i] >> arrival[i] >> burst[i];
        }
    }

    // Function to calculate waiting times
    void calculateWaitingTime() {
        int currentTime = 0;

        for (int i = 0; i < n; i++) {
            if (currentTime < arrival[i]) {
                currentTime = arrival[i]; // CPU is idle until the process arrives
            }
            wait[i] = currentTime - arrival[i];
            currentTime += burst[i];
        }
    }

    // Function to calculate turnaround times
    void calculateTurnaroundTime() {
        for (int i = 0; i < n; i++) {
            turn[i] = wait[i] + burst[i];
        }
    }

    // Function to display results
    void displayResults() {
        int totalWait = 0, totalTurnaround = 0;
        float avgWait, avgTurnaround;

        cout << "Process\tArrivalTime\tBurstTime\tWaitingTime\tTurnAroundTime" << endl;
        for (int i = 0; i < n; i++) {
            totalWait += wait[i];
            totalTurnaround += turn[i];

            cout << processIds[i] << "\t\t" << arrival[i] << "\t\t" << burst[i] << "\t\t" << wait[i] << "\t\t" << turn[i] << endl;
        }

        avgWait = (float)totalWait / n;
        avgTurnaround = (float)totalTurnaround / n;

        cout << "Average Waiting Time = " << avgWait << endl;
        cout << "Average Turnaround Time = " << avgTurnaround << endl;
    }
};

int main() {
    ProcessScheduler scheduler;

    scheduler.inputProcesses();
    scheduler.calculateWaitingTime();
    scheduler.calculateTurnaroundTime();
    scheduler.displayResults();

    return 0;
}
