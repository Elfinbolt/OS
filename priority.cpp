#include <iostream>
using namespace std;

int main()
{
    int bt[20], p[20], wt[20], tat[20], pri[20];
    int i, j, n, total = 0, pos, temp;
    float avg_wt, avg_tat;

    cout << "Enter Total Number of Process: ";
    cin >> n;

    cout << "\nEnter Burst Time and Priority\n";
    for (i = 0; i < n; i++)
    {
        cout << "\nP[" << i + 1 << "]\n";
        cout << "Burst Time: ";
        cin >> bt[i];
        cout << "Priority: ";
        cin >> pri[i];
        p[i] = i + 1; // contains process number
    }

    // Sorting burst time, priority and process number in ascending order using selection sort
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (pri[j] < pri[pos])
                pos = j;
        }

        // Swap priority
        temp = pri[i];
        pri[i] = pri[pos];
        pri[pos] = temp;

        // Swap burst time
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        // Swap process number
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0;  // First process has no waiting time

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];  // Waiting time = previous waiting time + previous burst time
        total += wt[i];
    }

    avg_wt = (float)total / n; // average waiting time
    total = 0;

    cout << "\nProcess\t    Burst Time\t    Waiting Time\tTurnaround Time";
    for (i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i]; // calculate turnaround time
        total += tat[i];
        cout << "\nP[" << p[i] << "]\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t\t" << tat[i];
    }

    avg_tat = (float)total / n; // average turnaround time

    cout << "\n\nAverage Waiting Time = " << avg_wt;
    cout << "\nAverage Turnaround Time = " << avg_tat;

    return 0;
}
