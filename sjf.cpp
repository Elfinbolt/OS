#include <iostream>
using namespace std;

class ProcessScheduler {
private:
    int n;               
    int process[100];    
    int burst[100];      
    int wait[100];       
    int turn[100];       

public:
    // Function to take input
    void inputProcesses() {
        cout << "Enter number of processes: ";
        cin >> n;

        cout << "Enter processes and burst times:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Process ID: ";
            cin >> process[i];
            cout << "Burst Time: ";
            cin >> burst[i];
        }
    }

    // Function to sort processes based on burst time (SJF Scheduling)
    void sortByBurstTime() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (burst[j] > burst[j + 1]) {
                    // Swap burst times
                    int temp = burst[j];
                    burst[j] = burst[j + 1];
                    burst[j + 1] = temp;

                    // Swap process IDs
                    int tempProcess = process[j];
                    process[j] = process[j + 1];
                    process[j + 1] = tempProcess;
                }
            }
        }
    }

    // Function to calculate waiting times
    void calculateWaitingTime() {
        wait[0] = 0;
        for (int i = 1; i < n; i++) {
            wait[i] = wait[i - 1] + burst[i - 1];
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
        int totalWait = 0, totalTurn = 0;
        float avgWait, avgTurn;

        cout << "Process\tBurstTime\tWaitingTime\tTurnAroundTime" << endl;
        for (int i = 0; i < n; i++) {
            totalWait += wait[i];
            totalTurn += turn[i];
            cout << process[i] << "\t\t" << burst[i] << "\t\t" << wait[i] << "\t\t" << turn[i] << endl;
        }

        avgWait = (float)totalWait / n;
        avgTurn = (float)totalTurn / n;

        cout << "\nAverage Waiting Time = " << avgWait << endl;
        cout << "Average Turnaround Time = " << avgTurn << endl;
    }
};

int main() {
    ProcessScheduler scheduler;

    scheduler.inputProcesses();
    scheduler.sortByBurstTime();
    scheduler.calculateWaitingTime();
    scheduler.calculateTurnaroundTime();
    scheduler.displayResults();

    return 0;
}
