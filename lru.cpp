#include <iostream>
using namespace std;

// Function to check if element exists in the array
int in_array(int pages[], int currentPage, int frameSize) {
    for (int i = 0; i < frameSize; i++) {
        if (pages[i] == currentPage)
            return i; // return index if found
    }
    return -1; // return -1 if not found
}

int main() {
    string inputString;
    cout << "enter input string:" << endl;
    cin >> inputString;
    int inputStringSize = inputString.length();
    int frameSize;

    cout << "Enter frame size: ";
    cin >> frameSize;

    int pages[frameSize];
    int time[frameSize]; // to track usage time for LRU
    for (int i = 0; i < frameSize; i++) {
        pages[i] = -1;
        time[i] = 0;
    }

    int page_fault = 0;
    int currentTime = 0;

    for (int i = 0; i < inputStringSize; i++) {
        int currentPage = inputString[i] - '0';
        currentTime++;

        int pos = in_array(pages, currentPage, frameSize);

        if (pos == -1) {
            // Page fault
            int lruIndex = 0;
            for (int j = 1; j < frameSize; j++) {
                if (time[j] < time[lruIndex]) {
                    lruIndex = j;
                }
            }
            pages[lruIndex] = currentPage;
            time[lruIndex] = currentTime;
            page_fault++;
        } else {
            // Page hit: update time
            time[pos] = currentTime;
        }
    }

    cout << "Page faults: " << page_fault << endl;
    return 0;
}
