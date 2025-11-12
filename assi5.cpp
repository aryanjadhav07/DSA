#include<bits/stdc++.h>
using namespace std;

struct Package{
    int weight;
    int benifit;
    double ratio;
};

bool compare(Package a, Package b){
    return a.ratio > b.ratio;
}

int main(){
    int n;
    double capacity;

    cout << "Enter the number of packages : ";
    cin >> n;

    cout << "Enter the capacity : " ;
    cin >> capacity;

    vector<Package> packages(n);

    cout << "Enter the weight and benifit for each package : " << endl;

    for(int i = 0; i < n; i++){
        cout << "Package " << i+1 << " weight : ";
        cin >> packages[i].weight;
        cout << "Package " << i+1 << " benifit : ";
        cin >> packages[i].benifit;
        packages[i].ratio = double(packages[i].benifit) / packages[i].weight;
    }
    
    sort(packages.begin(), packages.end(), compare);

    double totalBenifit = 0.0;
    double totalWeight = 0.0;

    cout << "Selected Packages : " << endl;
    cout << "Weight\tBenifit\tRatio\tFraction" << endl;

    for(int i = 0; i < n; i++){
        if(totalWeight + packages[i].weight <= capacity){
            totalWeight += packages[i].weight;
            totalBenifit += packages[i].benifit;
            cout << packages[i].weight << "\t" << packages[i].benifit << "\t" << packages[i].ratio << "\t" << "1.00" << endl;
        }
        else {
            double remain = capacity - totalWeight;
            double fraction = remain / packages[i].weight;
            totalWeight += packages[i].weight * fraction;
            totalBenifit += packages[i].benifit * fraction;
            cout << packages[i].weight << "\t" << packages[i].benifit << "\t" << packages[i].ratio << "\t" << fraction << endl;
            break;
        }
    }

    cout << "Total Weight in Truck : " << totalWeight << endl;
    cout << "Total Benifit : " << totalBenifit << endl;

    return 0;

}