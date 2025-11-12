#include <iostream>
using namespace std;

int main() {
    int n, capacity;
    cout << "Enter number of files: ";
    cin >> n;

    cout << "Enter total storage capacity (in GB): ";
    cin >> capacity;

    int size[20], importance[20];   // assuming max 20 files
    cout << "Enter size and importance of each file:\n";
    for (int i = 1; i <= n; i++) {
        cout << "File " << i << " - Size: ";
        cin >> size[i];
        cout << "File " << i << " - Importance: ";
        cin >> importance[i];
    }

    int dp[20][50];  // dp[i][w] → max importance with i files and capacity w
    // initialize
    for (int i = 0; i <= n; i++)
        for (int w = 0; w <= capacity; w++)
            dp[i][w] = 0;

    // Build DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (size[i] <= w)
                dp[i][w] = max(importance[i] + dp[i - 1][w - size[i]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Backtrack to find which files are selected
    int w = capacity;
    int selected[20], count = 0;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected[count++] = i;
            w -= size[i];
        }
    }

    // Display selected files
    cout << "\nSelected Files:\n";
    int totalSize = 0, totalImportance = 0;
    for (int i = count - 1; i >= 0; i--) {
        int idx = selected[i];
        cout << "File " << idx << " (Size: " << size[idx]
             << ", Importance: " << importance[idx] << ")\n";
        totalSize += size[idx];
        totalImportance += importance[idx];
    }

    cout << "\nTotal Size Used: " << totalSize << " GB";
    cout << "\nTotal Importance Score: " << totalImportance << endl;

    return 0;
}
