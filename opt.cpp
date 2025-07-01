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

// Function to find the index of the page to replace using optimal logic
int findOptimalIndex(int pages[], int frameSize, string inputString, int currentIndex) {
    int farthest = currentIndex;
    int index = -1;

    for (int i = 0; i < frameSize; i++) {
        bool found = false;
        for (int j = currentIndex + 1; j < inputString.length(); j++) {
            if (pages[i] == inputString[j] - '0') {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                found = true;
                break;
            }
        }
        if (!found) {
            // If not found in future, replace this page
            return i;
        }
    }

    // If all pages are found in future, replace the farthest one
    return (index == -1) ? 0 : index;
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
    for (int i = 0; i < frameSize; i++) {
        pages[i] = -1;
    }

    int page_fault = 0;

    for (int i = 0; i < inputStringSize; i++) {
        int currentPage = inputString[i] - '0';

        int pos = in_array(pages, currentPage, frameSize);

        if (pos == -1) {
            // Page fault
            int replaceIndex;

            // If there's still space in frame
            bool placed = false;
            for (int j = 0; j < frameSize; j++) {
                if (pages[j] == -1) {
                    pages[j] = currentPage;
                    placed = true;
                    break;
                }
            }

            if (!placed) {
                replaceIndex = findOptimalIndex(pages, frameSize, inputString, i);
                pages[replaceIndex] = currentPage;
            }

            page_fault++;
        }
        // else: page hit, do nothing
    }

    cout << "Page faults: " << page_fault << endl;
    return 0;
}
