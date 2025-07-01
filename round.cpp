#include <iostream>
using namespace std;

class RoundRobinScheduler
{
private:
    int n;           
    int quantum;     
    int processes[100];  
    int burstTime[100];  
    int waitingTime[100];
    int turnaroundTime[100];

public:

    RoundRobinScheduler(int num)
    {
        n = num;
    }

    void inputProcesses()
    {
        cout << "Enter process IDs: ";
        for (int i = 0; i < n; i++)
        {
            cin >> processes[i];
        }

        cout << "Enter burst times: ";
        for (int i = 0; i < n; i++)
        {
            cin >> burstTime[i];
        }

        cout << "Enter time quantum: ";
        cin >> quantum;
    }

    void findWaitingTime()
    {
        int rem_bt[100];
        for (int i = 0; i < n; i++)
            rem_bt[i] = burstTime[i];

        int t = 0;
        while (true)
        {
            bool done = true;
            for (int i = 0; i < n; i++)
            {
                if (rem_bt[i] > 0)
                {
                    done = false;
                    if (rem_bt[i] > quantum)
                    {
                        t += quantum;
                        rem_bt[i] -= quantum;
                    }
                    else
                    {
                        t += rem_bt[i];
                        waitingTime[i] = t - burstTime[i];
                        rem_bt[i] = 0;
                    }
                }
            }
            if (done)
                break;
        }
    }

    void findTurnaroundTime()
    {
        for (int i = 0; i < n; i++)
            turnaroundTime[i] = burstTime[i] + waitingTime[i];
    }

    void calculateTimes()
    {
        findWaitingTime();
        findTurnaroundTime();

        cout << "\nPN\tBT\tWT\tTAT\n";
        float total_wt = 0, total_tat = 0;
        for (int i = 0; i < n; i++)
        {
            total_wt += waitingTime[i];
            total_tat += turnaroundTime[i];
            cout << processes[i] << "\t" << burstTime[i] << "\t" << waitingTime[i] << "\t" << turnaroundTime[i] << endl;
        }

        cout << "Average Waiting Time: " << total_wt / n << endl;
        cout << "Average Turnaround Time: " << total_tat / n << endl;
    }
};

int main()
{
    int num;
    cout << "Enter number of processes: ";
    cin >> num;

    RoundRobinScheduler scheduler(num);
    scheduler.inputProcesses();
    scheduler.calculateTimes();

    return 0;
}