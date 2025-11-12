#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    priority_queue<int> maxHeap; // for highest priority
    priority_queue<int, vector<int>, greater<int>> minHeap; // for lowest priority
    vector<int> allJobs; // to display all jobs later

    int choice;
    do {
        cout << "\n--- Job Priority Menu ---\n";
        cout << "1. Insert a new job (with priority)\n";
        cout << "2. Display highest and lowest priority jobs\n";
        cout << "3. Delete the job with highest priority\n";
        cout << "4. Display all jobs in order of priority\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int p;
            cout << "Enter job priority: ";
            cin >> p;
            maxHeap.push(p);
            minHeap.push(p);
            allJobs.push_back(p);
            cout << "Job with priority " << p << " inserted.\n";
        }

        else if (choice == 2) {
            if (maxHeap.empty()) {
                cout << "No jobs available!\n";
            } else {
                cout << "Highest Priority Job: " << maxHeap.top() << endl;
                cout << "Lowest Priority Job: " << minHeap.top() << endl;
            }
        }

        else if (choice == 3) {
            if (maxHeap.empty()) {
                cout << "No jobs to delete!\n";
            } else {
                int highest = maxHeap.top();
                maxHeap.pop();

                // Also remove from minHeap and vector
                vector<int> temp;
                while (!minHeap.empty() && minHeap.top() != highest) {
                    temp.push_back(minHeap.top());
                    minHeap.pop();
                }
                if (!minHeap.empty()) minHeap.pop(); // remove highest from minHeap
                for (int x : temp) minHeap.push(x);

                allJobs.erase(remove(allJobs.begin(), allJobs.end(), highest), allJobs.end());
                cout << "Deleted highest priority job: " << highest << endl;
            }
        }

        else if (choice == 4) {
            if (allJobs.empty()) {
                cout << "No jobs to display!\n";
            } else {
                sort(allJobs.begin(), allJobs.end(), greater<int>());
                cout << "Jobs in order of priority (High → Low): ";
                for (int p : allJobs) cout << p << " ";
                cout << endl;
            }
        }

        else if (choice == 5) {
            cout << "Exiting...\n";
        }

        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
