#include <iostream>
using namespace std;

class ProcessScheduler {
private:
    int n;
    int process[100];     // Process ID
    int arrival[100];     // Arrival Time
    int burst[100];       // Burst Time
    int priority[100];    // Priority
    int wait[100];        // Waiting Time
    int turn[100];        // Turnaround Time
    int remaining[100];   // Remaining Time
    int completeTime[100];// Completion Time

public:
    void inputProcesses() {
        cout << "Enter number of processes: ";
        cin >> n;

        cout << "Enter Process ID, Arrival Time, Burst Time, and Priority:\n";
        for (int i = 0; i < n; i++) {
            cout << "Process " << i + 1 << ":\n";
            cout << "PID: ";
            cin >> process[i];
            cout << "Arrival Time: ";
            cin >> arrival[i];
            cout << "Burst Time: ";
            cin >> burst[i];
            cout << "Priority (Lower number = Higher priority): ";
            cin >> priority[i];
            remaining[i] = burst[i];
        }
    }

    void scheduleProcesses() {
        int time = 0, completed = 0;
        const int INF = 100000;
        int dummyPriority = INF;

        while (completed < n) {
            int idx = -1;
            int minPriority = dummyPriority;

            for (int i = 0; i < n; i++) {
                if (arrival[i] <= time && remaining[i] > 0 && priority[i] < minPriority) {
                    minPriority = priority[i];
                    idx = i;
                }
            }

            if (idx != -1) {
                remaining[idx]--;
                time++;

                if (remaining[idx] == 0) {
                    completed++;
                    completeTime[idx] = time;
                }
            } else {
                time++; // No process is ready, CPU is idle
            }
        }
    }

    void calculateWaitingTime() {
        for (int i = 0; i < n; i++) {
            turn[i] = completeTime[i] - arrival[i];
            wait[i] = turn[i] - burst[i];
        }
    }

    void displayResults() {
        float totalWait = 0, totalTurn = 0;

        cout << "\nProcess\tArrival\tBurst\tPriority\tCompletion\tWaiting\tTurnaround\n";
        for (int i = 0; i < n; i++) {
            cout << process[i] << "\t" << arrival[i] << "\t" << burst[i] << "\t" 
                 << priority[i] << "\t\t" << completeTime[i] << "\t\t" 
                 << wait[i] << "\t" << turn[i] << endl;
            totalWait += wait[i];
            totalTurn += turn[i];
        }

        cout << "\nAverage Waiting Time = " << totalWait / n;
        cout << "\nAverage Turnaround Time = " << totalTurn / n << endl;
    }
};

int main() {
    ProcessScheduler scheduler;
    scheduler.inputProcesses();
    scheduler.scheduleProcesses();
    scheduler.calculateWaitingTime();
    scheduler.displayResults();
    return 0;
}
