#include<bits/stdc++.h>
using namespace std;

int main(){

    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    vector<int> alljobs;


    int choice;
    do{

        cout << "\n--- Job Priority Menu ---\n";
        cout << "1. Insert a new job (with priority)\n";
        cout << "2. Display highest and lowest priority jobs\n";
        cout << "3. Delete the job with highest priority\n";
        cout << "4. Display all jobs in order of priority\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cin.clear(); // clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        if(choice == 1){
            int p;
            cout << "Enter job priority: ";
            cin >> p;
            maxheap.push(p);
            minheap.push(p);
            alljobs.push_back(p);
            cout << "Job with priority " << p << " inserted." << endl;
        }

        else if(choice == 2){
            if(maxheap.empty()){
                cout << "No jobs available" << endl;
            }
            else{
                cout << "Highest priority job : " << maxheap.top() << endl;
                cout << "Lowest priority job : "<< minheap.top() << endl;
            }
        }

        else if(choice == 3){
            if(maxheap.empty()){
                cout << "No jobs to delete." << endl;
                continue;
            }
            
                int highest = maxheap.top();
                maxheap.pop();
            
            vector<int> temp;

            while(!minheap.empty() && minheap.top() != highest){
                temp.push_back(minheap.top());
                minheap.pop();
            }
            if(!minheap.empty()){minheap.pop();};
            for(int x : temp){
                minheap.push(x);
            }

            auto it = find(alljobs.begin(), alljobs.end(), highest);
            if (it != alljobs.end()) {
                alljobs.erase(it);
            }
            cout << "Deleted highest priority job : " << highest << endl;
        }

        else if(choice == 4){
            if(maxheap.empty()){
                cout << "No jobs to display." << endl;
            }
            else{
                sort(alljobs.begin(), alljobs.end(), greater<int>());
                cout << "Jobs in order of priority (Highest to lowest) : ";
                for(int x : alljobs){
                    cout << x << " ";
                }
                cout << endl;
            }
        }
        else if(choice == 5){
            cout << "Exiting...\n";
        }
        else{
            cout << "Invalid choice! Try again.\n";
        }

    }while(choice!=5);

    
    
    
    return 0;
}