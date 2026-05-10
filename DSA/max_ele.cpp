#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    int max_ele = 0;
    cout << "Enter the elements: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << "[";
    for(int i=0; i<n; i++){
        cout << arr[i];
        if(i != n-1){
            cout << ", ";
        }
    }
    cout << "]" << endl;

    for(int i=0; i<n; i++){
        if(arr[i] > max_ele){
            max_ele = arr[i];
        }
    }

    cout << "The maximum element is: " << max_ele << endl;
    return 0;
}