#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int burstTimes[n],waitingTimes[n], turnaroundTimes[n];
    waitingTimes[0] = 0;
    
    cout << "Enter burst times for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> burstTimes[i];
    }

    // Calculate waiting times
    for (int i = 1; i < n; i++) {
        waitingTimes[i] = waitingTimes[i - 1] + burstTimes[i - 1];
    }

    // Calculate turnaround times
    for (int i = 0; i < n; i++) {
        turnaroundTimes[i] = waitingTimes[i] + burstTimes[i];
    }

    // Display results
    cout << "Parameter\t\t\t";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t\t";
    }
    cout << "\n";

    cout << "Burst Time\t\t\t";
    for (int i = 0; i < n; i++) {
        cout << burstTimes[i] << "\t\t";
    }
    cout << "\n";

    cout << "Waiting Time\t\t\t";
    for (int i = 0; i < n; i++) {
        cout << waitingTimes[i] << "\t\t";
    }
    cout << "\n";

    cout << "Turnaround Time\t\t\t";
    for (int i = 0; i < n; i++) {
        cout << turnaroundTimes[i] << "\t\t";
    }
    cout << "\n";

    // Calculate averages
    float totalWaiting = 0, totalTurnaround = 0;
    for (int i = 0; i < n; i++) {
        totalWaiting += waitingTimes[i];
        totalTurnaround += turnaroundTimes[i];
    }

    cout << "Average Waiting Time: " << totalWaiting / n << endl;
    cout << "Average Turnaround Time: " << totalTurnaround / n << endl;
    return 0;
}
