#include <iostream>
using namespace std;

// Function to check if element exists in the array
int in_array(int pages[], int currentPage, int frameSize) {
    for (int i = 0; i < frameSize; i++) {
        if (pages[i] == currentPage)
            return 1;
    }
    return 0;
}

int main() {
    string inputString;
    cout<<"enter input string:"<<endl;
    cin>>inputString;
    int inputStringSize = inputString.length();
    int frameSize;

    cout << "Enter frame size: ";
    cin >> frameSize;

    int pages[frameSize];
    for (int i = 0; i < frameSize; i++) {
        pages[i] = -1; // initialize with an invalid page
    }

    int page_fault = 0;
    int oldestIndex = 0;

    for (int i = 0; i < inputStringSize; i++) {
        int currentPage = inputString[i] - '0'; // convert char to int

        if (!in_array(pages, currentPage, frameSize)) {
            // Page not in frame — replace
            pages[oldestIndex] = currentPage;
            oldestIndex = (oldestIndex + 1) % frameSize;
            page_fault++;
        }
        // else: page hit, do nothing
    }

    cout << "Page faults: " << page_fault << endl;
    return 0;
}
