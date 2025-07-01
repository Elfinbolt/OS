#include <iostream>
using namespace std;

class ProcessScheduler {
private:
    int n;
    int process[100];     // Process ID
    int arrival[100];     // Arrival Time
    int burst[100];       // Burst Time
    int wait[100];        // Waiting Time
    int turn[100];        // Turnaround Time
    int remaining[100];   // Remaining Time
    int completeTime[100];// Completion Time

public:
    // Input function
    void inputProcesses() {
        cout << "Enter number of processes: ";
        cin >> n;

        cout << "Enter Process ID, Arrival Time and Burst Time for each process:\n";
        for (int i = 0; i < n; i++) {
            cout << "Process " << i + 1 << ":\n";
            cout << "PID: ";
            cin >> process[i];
            cout << "Arrival Time: ";
            cin >> arrival[i];
            cout << "Burst Time: ";
            cin >> burst[i];
            remaining[i] = burst[i];
        }
    }

    // SJF with Arrival Time (Preemptive)
    void scheduleProcesses() {
        int time = 0, completed = 0, minIndex;
        bool found;

        while (completed < n) {
            found = false;
            minIndex = -1;

            for (int i = 0; i < n; i++) {
                if (arrival[i] <= time && remaining[i] > 0) {
                    if (minIndex == -1 || remaining[i] < remaining[minIndex]) {
                        minIndex = i;
                        found = true;
                    }
                }
            }

            if (found) {
                remaining[minIndex]--;
                time++;

                if (remaining[minIndex] == 0) {
                    completeTime[minIndex] = time;
                    completed++;
                }
            } else {
                time++;
            }
        }
    }

    // Calculate Waiting Time
    void calculateWaitingTime() {
        for (int i = 0; i < n; i++) {
            turn[i] = completeTime[i] - arrival[i];
            wait[i] = turn[i] - burst[i];
        }
    }

    // Display results
    void displayResults() {
        float totalWait = 0, totalTurn = 0;

        cout << "\nProcess\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\n";
        for (int i = 0; i < n; i++) {
            cout << process[i] << "\t" << arrival[i] << "\t" << burst[i] << "\t" 
                 << completeTime[i] << "\t\t" << wait[i] << "\t" << turn[i] << endl;
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
