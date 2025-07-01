#include <iostream>
using namespace std;

class ProcessScheduler {
private:
    int n;
    int process[100];       // Process ID
    int arrival[100];       // Arrival Time
    int burst[100];         // Burst Time
    int wait[100];          // Waiting Time
    int turn[100];          // Turnaround Time
    int remaining[100];     // Remaining Time
    int completeTime[100];  // Completion Time
    int quantum;

public:
    void inputProcesses() {
        cout << "Enter number of processes: ";
        cin >> n;

        cout << "Enter Time Quantum: ";
        cin >> quantum;

        cout << "Enter Process ID for each process:\n";
        for (int i = 0; i < n; i++) {
            cout << "Process " << i + 1 << " ID: ";
            cin >> process[i];
        }

        cout << "Enter Arrival Time for each process:\n";
        for (int i = 0; i < n; i++) {
            cout << "Arrival Time for Process " << process[i] << ": ";
            cin >> arrival[i];
        }

        cout << "Enter Burst Time for each process:\n";
        for (int i = 0; i < n; i++) {
            cout << "Burst Time for Process " << process[i] << ": ";
            cin >> burst[i];
            remaining[i] = burst[i]; // Initialize remaining time
        }
    }

    void scheduleProcesses() {
        int c = n;
        float time = 0;
        float a[100], b[100];
        for (int i = 0; i < n; i++) {
            a[i] = arrival[i];
            b[i] = burst[i];
        }

        int index = -1;
        bool flag = false;
        while (c != 0) {
            float mini = 1e9;
            flag = false;

            for (int i = 0; i < n; i++) {
                float p_time = time + 0.1;
                if (a[i] <= p_time && mini > a[i] && b[i] > 0) {
                    index = i;
                    mini = a[i];
                    flag = true;
                }
            }

            if (!flag) {
                time++;
                continue;
            }

            if (b[index] <= quantum) {
                time += b[index];
                b[index] = 0;
            } else {
                time += quantum;
                b[index] -= quantum;
            }

            if (b[index] > 0) {
                a[index] = time + 0.1;
            }

            if (b[index] == 0) {
                c--;
                completeTime[index] = time;
                wait[index] = completeTime[index] - arrival[index] - burst[index];
                turn[index] = burst[index] + wait[index];
            }
        }
    }

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
        cout << "Average Turnaround Time = " << totalTurn / n << endl;
    }
};

int main() {
    ProcessScheduler scheduler;
    scheduler.inputProcesses();
    scheduler.scheduleProcesses();
    scheduler.displayResults();
    return 0;
}
